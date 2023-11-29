// Fill out your copyright notice in the Description page of Project Settings.


#include "MoneyComponent.h"

#include "MoneySaving.h"
#include "Kismet/GameplayStatics.h"

UMoneyComponent::UMoneyComponent()
{

}


void UMoneyComponent::BeginPlay()
{
	Super::BeginPlay();
	
	GetStringType();
	LoadMoney();
}

bool UMoneyComponent::CanPay(int Price) const
{
	return Currency >= Price;
}

void UMoneyComponent::LoadMoney()
{
	if (UMoneySaving* Loaded =
		Cast<UMoneySaving>(UGameplayStatics::LoadGameFromSlot(StringType, 0)))
	{
		Currency = Loaded->GetCurrecy(Type);
	}
	else
	{
		Currency = DefaultValue;
	}
}

FString UMoneyComponent::GetStringType()
{
	switch (Type)
	{
	case ECurrencyType::Shiziki:
		return "Shiziki";
	case ECurrencyType::Inspirations:
		return "Inspirations";
	default:
		return "Error";
	}
}

void UMoneyComponent::Pay(int Price)
{
	if (!CanPay(Price)) return;
	
	Currency -= Price;
	SaveMoney();
}

void UMoneyComponent::Add(int Value)
{
	Currency += Value;
	SaveMoney();
}

void UMoneyComponent::SaveMoney() const
{
	if (UMoneySaving* Saving =
		Cast<UMoneySaving>(UGameplayStatics::CreateSaveGameObject(USaveGame::StaticClass())))
	{
		Saving->SetCurrecy(Type, Currency);
		UGameplayStatics::SaveGameToSlot(Saving, StringType, 0);
	}
}


