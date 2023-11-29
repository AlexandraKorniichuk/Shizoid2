// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MoneyComponent.h"
#include "GameFramework/SaveGame.h"
#include "../ShizoidGameInstance.h"
#include "MoneySaving.generated.h"

/**
 * 
 */
UCLASS()
class SHIZOID2_API UMoneySaving : public USaveGame
{
	GENERATED_BODY()
	
public:
	void SetCurrecy(ECurrencyType MoneyType, int Value);
	int GetCurrecy(ECurrencyType MoneyType);
	
private:
	int Shiziki = 0;
	int Inspirations = 0;
	UShizoidGameInstance* GameInstance;
};
