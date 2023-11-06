// Fill out your copyright notice in the Description page of Project Settings.

#include "Containers/UnrealString.h"
#include "WeaponInventoryComponent.h"

// Sets default values for this component's properties
UWeaponInventoryComponent::UWeaponInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UWeaponInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
	
	AbilitySystemComponent = GetOwner()->FindComponentByClass<UAbilitySystemComponent>();

	InitWeapons();
	
}

void UWeaponInventoryComponent::InitWeapons()
{
	for (int i = 0; i<Weapons.Num(); i++)
	{
		UStaticMeshComponent* WeaponMesh = NewObject<UStaticMeshComponent>(GetOwner(), UStaticMeshComponent::StaticClass(), TEXT("WeaponStaticMesh"));
		WeaponMesh->RegisterComponent();
		WeaponMesh->AttachToComponent(GetOwner()->GetRootComponent(), FAttachmentTransformRules::SnapToTargetIncludingScale, FName(TEXT("RightHand")));
		WeaponMesh->CreationMethod = EComponentCreationMethod::Instance;

		WeaponMesh->SetStaticMesh(Weapons[i].GetDefaultObject()->WeaponMesh);

		//WeaponsMeshes[i] = WeaponMesh;
		//WeaponMesh->SetVisibility(false, false);
	}
}

void UWeaponInventoryComponent::OnComponentCreated()
{
	Super::OnComponentCreated();
	
	AbilitySystemComponent = GetOwner()->FindComponentByClass<UAbilitySystemComponent>();
}

void UWeaponInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UWeaponInventoryComponent::EquipWeapon(int WeaponID)
{
	for(int i = 0; i<WeaponsMeshes.Num();i++)
	{
		WeaponsMeshes[i]->SetVisibility(false, false);
	}
	WeaponsMeshes[WeaponID]->SetVisibility(true, false);
	
	FGameplayEffectContextHandle handle;
	if(AbilitySystemComponent)
	{
		AbilitySystemComponent->ApplyGameplayEffectToSelf(Weapons[WeaponID].GetDefaultObject()->PlayerAttackEffect.GetDefaultObject(), 0, handle);
	}
}