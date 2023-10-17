// Fill out your copyright notice in the Description page of Project Settings.


#include "ShizoidAssetManager.h"
#include "AbilitySystemGlobals.h"

void UShizoidAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	UAbilitySystemGlobals::Get().InitGlobalData();
}
