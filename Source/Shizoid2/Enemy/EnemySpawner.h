// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "EnemySpawnPoint.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"

USTRUCT(Blueprintable)
struct FEnemyGroupData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AEnemy> EnemiesType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int EnemiesAmount = 0;
};

USTRUCT(Blueprintable)
struct FEnemyWave
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FEnemyGroupData> EnemyGroups;
};


UCLASS()
class SHIZOID2_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void SpawnWave(FEnemyWave Wave);

	UFUNCTION(BlueprintCallable)
	void SpawnEnemiesGroup(FEnemyGroupData Group);

	UFUNCTION(BlueprintCallable)
	void BeginSpawn();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FEnemyWave> EnemyWaves;

	UFUNCTION(BlueprintCallable)
	void ProceedEnemyDeath();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UWorld* World;

	int EnemiesLeftInCurrentWave = 0;
	int CurrentWave = 0;

	TArray<AEnemySpawnPoint*> SpawnPoints;

	void InitializeSpawnPoints();

	AEnemySpawnPoint* SelectRandomSpawnPoint();

};

