
#include "HealthManagerComponent.h"
#include "HealthAttributeSet.h"

UHealthManagerComponent::UHealthManagerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UHealthManagerComponent::BeginPlay()
{
	Super::BeginPlay();

	//AddHealthEffect(HealthInitEffect);
}

void UHealthManagerComponent::MakeHealthChangedNotify(UAbilitySystemComponent* Component, const FGameplayEffectSpec& Spec, FActiveGameplayEffectHandle Handle)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Event received"));
	if(HealthChangedDelegate.IsBound())
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Event called"));
		HealthChangedDelegate.Broadcast(AbilitySystemComponent->GetSet<UHealthAttributeSet>()->GetHealth());
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

void UHealthManagerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(WasHealthInitialized==false)
	{
		AddHealthEffect(HealthInitEffect);
		WasHealthInitialized = true;
	}
}

void UHealthManagerComponent::AddHealthEffect(TSubclassOf<UGameplayEffect> Effect)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("HealthEffectApplied"));
	FGameplayEffectContextHandle handle;
	AbilitySystemComponent->ApplyGameplayEffectToSelf(Effect.GetDefaultObject(), 0, handle);
}
