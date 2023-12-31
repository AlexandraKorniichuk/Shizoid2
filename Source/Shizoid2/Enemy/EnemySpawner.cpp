// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawner.h"

#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"

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
	InitializeSpawnPoints();
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
		AEnemy* Enemy = World->SpawnActor<AEnemy>(Group.EnemiesType, SelectRandomSpawnPoint()->GetActorTransform(), SpawnInfo);
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
		OnLevelCreared.Broadcast();
		CurrentWave++;
		SpawnWave(EnemyWaves[CurrentWave]);
	}
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnemySpawner::InitializeSpawnPoints()
{
	for(TActorIterator<AEnemySpawnPoint> Iterator(World); Iterator; ++Iterator)
	{
		SpawnPoints.Add(*Iterator);
	}
}

AEnemySpawnPoint* AEnemySpawner::SelectRandomSpawnPoint()
{
	if(SpawnPoints.Num()==0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("There are zero enemy spawn points on the level."));
	}
	return SpawnPoints[FMath::RandRange(0, SpawnPoints.Num()-1)];
}

