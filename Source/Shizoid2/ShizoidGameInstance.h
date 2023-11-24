// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ShizoidGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class SHIZOID2_API UShizoidGameInstance : public UGameInstance
{
	GENERATED_BODY()
	UShizoidGameInstance();
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int RandomNumber = 0;
};
