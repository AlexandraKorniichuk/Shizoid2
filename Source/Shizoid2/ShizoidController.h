// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/UserWidget.h"
#include "ShizoidController.generated.h"

/**
 * 
 */
UCLASS()
class SHIZOID2_API AShizoidController : public APlayerController
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="UI")
	UUserWidget* MainUIWidget;

	UPROPERTY(EditDefaultsOnly, Category="UI")
	TSubclassOf<UUserWidget> WidgetClass;
};
