// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawner.h"

// Sets default values
AEnemySpawner::AEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();
	World = GetWorld();
	BeginSpawn();
}

void AEnemySpawner::BeginSpawn()
{
	SpawnWave(EnemyWaves[0]);
}

void AEnemySpawner::SpawnWave(FEnemyWave Wave)
{
	for(const auto EnemyGroup : Wave.EnemyGroups)
	{
		SpawnEnemiesGroup(EnemyGroup);
	}
}

void AEnemySpawner::SpawnEnemiesGroup(FEnemyGroupData Group)
{
	for(int i = 0; i < Group.EnemiesAmount; i++)
	{
		FActorSpawnParameters SpawnInfo;
		AEnemy* Enemy = World->SpawnActor<AEnemy>(Group.EnemiesType, GetActorTransform(), SpawnInfo);
		if(Enemy)
		{
			Enemy->HealthManagerComponent->OnZeroHealth.AddDynamic(this, &AEnemySpawner::ProceedEnemyDeath);
			EnemiesLeftInCurrentWave++;
		}
	}
}

void AEnemySpawner::ProceedEnemyDeath()
{
	EnemiesLeftInCurrentWave--;
	if(EnemiesLeftInCurrentWave==0)
	{
		CurrentWave++;
		SpawnWave(EnemyWaves[CurrentWave]);
	}
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

