
#include "HealthManagerComponent.h"
#include "HealthAttributeSet.h"

UHealthManagerComponent::UHealthManagerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	
}

void UHealthManagerComponent::BeginPlay()
{
	Super::BeginPlay();
	
	AddHealthEffect(HealthInitEffect);
}

void UHealthManagerComponent::MakeHealthChangedNotify(UAbilitySystemComponent* Component, const FGameplayEffectSpec& Spec, FActiveGameplayEffectHandle Handle)
{
	float CurrentHealth = AbilitySystemComponent->GetSet<UHealthAttributeSet>()->GetHealth();
	
	if(CurrentHealth <=0 && OnZeroHealth.IsBound())
	{
		OnZeroHealth.Broadcast();
	}
	
	if(HealthChangedDelegate.IsBound())
	{
		HealthChangedDelegate.Broadcast(CurrentHealth);
	}
}

void UHealthManagerComponent::OnComponentCreated()
{
	Super::OnComponentCreated();

	AbilitySystemComponent = GetOwner()->FindComponentByClass<UAbilitySystemComponent>();
	
	if(AbilitySystemComponent)
	{
		AbilitySystemComponent->OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UHealthManagerComponent::MakeHealthChangedNotify);
		
		AbilitySystemComponent->AddSet<UHealthAttributeSet>();
	}
}


void UHealthManagerComponent::AddHealthEffect(TSubclassOf<UGameplayEffect> Effect)
{
	FGameplayEffectContextHandle handle;
	if(AbilitySystemComponent)
	{
		AbilitySystemComponent->ApplyGameplayEffectToSelf(Effect.GetDefaultObject(), 0, handle);
	}
}

