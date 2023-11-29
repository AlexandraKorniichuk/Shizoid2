// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MoneyComponent.generated.h"

UENUM()
enum ECurrencyType 
{
	Shiziki UMETA(DisplayName = "Shiziki"),
	Inspirations UMETA(DisplayName = "Inspirations"),
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHIZOID2_API UMoneyComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UMoneyComponent();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditDefaultsOnly, Category = "Money")
	TEnumAsByte<ECurrencyType> Type = ECurrencyType::Shiziki;
	UPROPERTY(EditDefaultsOnly, Category = "Money")
	int DefaultValue = 0;

	UFUNCTION(BlueprintCallable)
	bool CanPay(int Price) const;

	UFUNCTION(BlueprintCallable, Category="Shop")
	void Pay(int Price);
	UFUNCTION(BlueprintCallable, Category="Shop")
	void Add(int Value);

private:
	int Currency = 0;
	FString StringType = "Shiziki";
	
	void SaveMoney() const;
	void LoadMoney();

	FString GetStringType();

};
