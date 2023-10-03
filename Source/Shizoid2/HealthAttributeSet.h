

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "HealthAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(HealthAttributeSet, Health) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(HealthAttributeSet, Health) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(Health) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(Health) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(Health)

UCLASS()
class SHIZOID2_API UHealthAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="Health")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UHealthAttributeSet, Health)

	UPROPERTY(BlueprintReadOnly, Category="Health")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UHealthAttributeSet, MaxHealth)
};
