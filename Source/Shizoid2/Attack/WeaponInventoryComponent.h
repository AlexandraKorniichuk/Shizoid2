// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "Weapon.h"
#include "Components/ActorComponent.h"
#include "WeaponInventoryComponent.generated.h"

class AShizoid2Character;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable )
class SHIZOID2_API UWeaponInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWeaponInventoryComponent();
	
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
    UPROPERTY(BlueprintReadWrite)
	USkeletalMeshComponent* PlayerMesh;
	
	UFUNCTION(BlueprintCallable)
	void EquipWeapon(int WeaponID);
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<TSubclassOf<AWeapon>> Weapons;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<UGameplayEffect> TestEffect;
	
	UFUNCTION(BlueprintCallable)
	void InitWeapons();
	
private:
	virtual void OnComponentCreated() override;

	TSubclassOf<AWeapon> CurrentWeapon;

	AShizoid2Character* Owner;
	
	UAbilitySystemComponent* AbilitySystemComponent;

	TArray<UStaticMeshComponent*> WeaponsMeshes;

	
};
