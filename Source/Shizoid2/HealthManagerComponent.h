// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "Components/ActorComponent.h"
#include "HealthManagerComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHealthChangedDelegate, float, CurrentHP);

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

protected:
	
	virtual void BeginPlay() override;

private:

	void MakeHealthChangedNotify(UAbilitySystemComponent* Component, const FGameplayEffectSpec& Spec, FActiveGameplayEffectHandle Handle);

	void OnComponentCreated() override;
	
public:
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void AddHealthEffect(TSubclassOf<UGameplayEffect> Effect);

private:

	UAbilitySystemComponent* AbilitySystemComponent;

	bool WasHealthInitialized = false;
};
