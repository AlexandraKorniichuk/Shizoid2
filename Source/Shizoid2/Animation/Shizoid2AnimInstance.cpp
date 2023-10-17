// Copyright Epic Games, Inc. All Rights Reserved.

#include "Shizoid2AnimInstance.h"
#include "AbilitySystemComponent.h"

void UShizoid2AnimInstance::NativeInitializeAnimation()
{
	if (AActor* MyActor = GetOwningActor())
	{
		UAbilitySystemComponent* AbilityComponent = MyActor->FindComponentByClass<UAbilitySystemComponent>();
		if (AbilityComponent)
		{
			InitializeWithAbilitySystem(AbilityComponent);
		}
	}

	Super::NativeInitializeAnimation();
}

void UShizoid2AnimInstance::InitializeWithAbilitySystem(UAbilitySystemComponent* AbilityComponent)
{
	GameplayTagPropertyMap.Initialize(this, AbilityComponent);
	ReceiveAbilitySystem(AbilityComponent);
}