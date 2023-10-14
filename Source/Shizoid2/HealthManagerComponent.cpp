
#include "HealthManagerComponent.h"
#include "HealthAttributeSet.h"

UHealthManagerComponent::UHealthManagerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	AbilitySystemComponent = GetOwner()->FindComponentByClass<UAbilitySystemComponent>();

	Super::OnComponentCreated();
	
	if(AbilitySystemComponent)
	{
		AbilitySystemComponent->OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UHealthManagerComponent::MakeHealthChangedNotify);
		
		AbilitySystemComponent->AddSet<UHealthAttributeSet>();
	}
}

void UHealthManagerComponent::BeginPlay()
{
	Super::BeginPlay();

	
	
	AddHealthEffect(HealthInitEffect);
}

void UHealthManagerComponent::MakeHealthChangedNotify(UAbilitySystemComponent* Component, const FGameplayEffectSpec& Spec, FActiveGameplayEffectHandle Handle)
{
	if(HealthChangedDelegate.IsBound())
	{
		HealthChangedDelegate.Broadcast(AbilitySystemComponent->GetSet<UHealthAttributeSet>()->GetHealth());
	}
}

void UHealthManagerComponent::OnComponentCreated()
{
	
}


void UHealthManagerComponent::AddHealthEffect(TSubclassOf<UGameplayEffect> Effect)
{
	FGameplayEffectContextHandle handle;
	if(AbilitySystemComponent)
	{
		AbilitySystemComponent->ApplyGameplayEffectToSelf(Effect.GetDefaultObject(), 0, handle);
	}
}

