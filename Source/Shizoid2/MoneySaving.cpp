// Fill out your copyright notice in the Description page of Project Settings.


#include "MoneySaving.h"


void UMoneySaving::SetCurrecy(ECurrencyType MoneyType, int Value)
{
	GameInstance = Cast<UShizoidGameInstance>(GetWorld()->GetGameInstance());
	int ValueToSave = Value / GameInstance->RandomNumber;
	
	switch (MoneyType)
	{
	case ECurrencyType::Shiziki:
		Shiziki = ValueToSave;
		break;
	case ECurrencyType::Inspirations:
		Inspirations = ValueToSave;
		break;
	}
}

int UMoneySaving::GetCurrecy(ECurrencyType MoneyType)
{
	GameInstance = Cast<UShizoidGameInstance>(GetWorld()->GetGameInstance());
	switch (MoneyType)
	{
	case ECurrencyType::Shiziki:
		return Shiziki * GameInstance->RandomNumber;
	case ECurrencyType::Inspirations:
		return Inspirations * GameInstance->RandomNumber;
	}
	
	return 0;
}
