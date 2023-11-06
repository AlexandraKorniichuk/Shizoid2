// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "AttackAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(AttackAttributeSet, AttackPower) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(AttackAttributeSet, AttackPower) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(AttackPower) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(AttackPower) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(AttackPower)

UCLASS()
class SHIZOID2_API UAttackAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="AttackPower")
	FGameplayAttributeData AttackPower;
	ATTRIBUTE_ACCESSORS(UAttackAttributeSet, AttackPower)
};
