// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffect.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UCLASS()
class SHIZOID2_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:
	
	AWeapon();

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WeaponData")
	TSubclassOf<UGameplayEffect> PlayerAttackEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="WeaponData")
	UStaticMesh* WeaponMesh;
	

protected:
	
	virtual void BeginPlay() override;

private:

	
	
};
