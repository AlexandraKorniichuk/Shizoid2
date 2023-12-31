// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "../Health/HealthManagerComponent.h"
#include "AbilitySystemComponent.h"
#include "../Health/IHealthHaving.h"
#include "Enemy.generated.h"

UCLASS()
class SHIZOID2_API AEnemy : public ACharacter, public IIHealthHaving
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	

	UPROPERTY(EditAnywhere, Category="GAS", BlueprintReadWrite)
	UHealthManagerComponent* HealthManagerComponent;

	UPROPERTY(EditAnywhere, Category="GAS", BlueprintReadWrite)
	UAbilitySystemComponent* AbilitySystemComponent;
	
};
