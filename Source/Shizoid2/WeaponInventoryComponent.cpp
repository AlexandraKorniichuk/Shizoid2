// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponInventoryComponent.h"

#include "AttackAttributeSet.h"
#include "Containers/UnrealString.h"
#include "Shizoid2Character.h"

// Sets default values for this component's properties
UWeaponInventoryComponent::UWeaponInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UWeaponInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	Owner = Cast<AShizoid2Character>(GetOwner());
	
	InitWeapons();
	CurrentWeapon = Weapons[0];
	EquipWeapon(0);
}

void UWeaponInventoryComponent::InitWeapons()
{
	for (int i = 0; i<Weapons.Num(); i++)
	{
		UStaticMeshComponent* WeaponMesh = Owner->SpawnWeaponMesh(Weapons[i].GetDefaultObject()->WeaponMesh);

		WeaponsMeshes.Add(WeaponMesh);
		WeaponMesh->SetVisibility(false, true);
	}
}

void UWeaponInventoryComponent::OnComponentCreated()
{
	Super::OnComponentCreated();
	
	AbilitySystemComponent = GetOwner()->FindComponentByClass<UAbilitySystemComponent>();
	AbilitySystemComponent->AddSet<UAttackAttributeSet>();
}

void UWeaponInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UWeaponInventoryComponent::EquipWeapon(int WeaponID)
{
	for(int i = 0; i<WeaponsMeshes.Num();i++)
	{
		WeaponsMeshes[i]->SetVisibility(false, true);
	}
	WeaponsMeshes[WeaponID]->SetVisibility(true, true);
	
	if(AbilitySystemComponent)
	{
		UGameplayEffect* AttackModifier = Weapons[WeaponID].GetDefaultObject()->PlayerAttackEffect.GetDefaultObject();

		FGameplayEffectContextHandle handle;
		AbilitySystemComponent->ApplyGameplayEffectToSelf(AttackModifier, 0, handle);
		AbilitySystemComponent->RemoveActiveGameplayEffectBySourceEffect(CurrentWeapon.GetDefaultObject()->PlayerAttackEffect, AbilitySystemComponent);
	}
	CurrentWeapon = Weapons[WeaponID];
}