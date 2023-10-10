// Fill out your copyright notice in the Description page of Project Settings.


#include "ShizoidController.h"


void AShizoidController::BeginPlay()
{
	Super::BeginPlay();

	MainUIWidget = CreateWidget<UUserWidget>(this, WidgetClass);
	MainUIWidget->AddToViewport(0);
}
