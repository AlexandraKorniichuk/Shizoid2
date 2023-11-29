// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "HealthAttributeSet.h"
#include "Components/ActorComponent.h"
#include "HealthManagerComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHealthChangedDelegate, float, CurrentHP);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnZeroHealthDelegate);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHIZOID2_API UHealthManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GAS")
	TSubclassOf<UGameplayEffect> HealthInitEffect;
	
	UHealthManagerComponent();

	UPROPERTY(BlueprintReadWrite, Category="Events", BlueprintAssignable)
	FHealthChangedDelegate HealthChangedDelegate;

	UPROPERTY(BlueprintReadWrite, Category="Events", BlueprintAssignable)
	FOnZeroHealthDelegate OnZeroHealth;

protected:
	
	virtual void BeginPlay() override;

private:

	void MakeHealthChangedNotify(UAbilitySystemComponent* Component, const FGameplayEffectSpec& Spec, FActiveGameplayEffectHandle Handle);

	virtual void OnComponentCreated() override;
	
public:

	UFUNCTION(BlueprintCallable)
	void AddHealthEffect(TSubclassOf<UGameplayEffect> Effect);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetMaxHealth() { return AbilitySystemComponent->GetSet<UHealthAttributeSet>()->GetMaxHealth(); }

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetCurrentHealth() { return AbilitySystemComponent->GetSet<UHealthAttributeSet>()->GetHealth(); }

private:

	UAbilitySystemComponent* AbilitySystemComponent;
};
