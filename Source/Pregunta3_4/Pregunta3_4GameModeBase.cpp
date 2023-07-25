// Copyright Epic Games, Inc. All Rights Reserved.


#include "Pregunta3_4GameModeBase.h"
#include "Mesa.h"
#include "FabricaDeMesa.h"
#include "EstrategiaMesa.h"
#include "EstrategiaAscenderMesa.h"
#include "EstrategiaDesarmarMesa.h"
#include "EstrategiaMoverMesa.h"

APregunta3_4GameModeBase::APregunta3_4GameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
	PosicionMesa = FVector(0.0f, 0.0f, 0.0f);
	RotacionMesa = FRotator::ZeroRotator;
	Tiempo = 0.0f;
}

void APregunta3_4GameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Tiempo >= 5.0f)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("EstrategiaAplicar"));
		Mesa->EstablecerEstrategia(ObtenerNuevaEstrategia(FMath::RandRange(1, 3)));
		Mesa->Accionar();
		Tiempo = 0.0f;
	}
	Tiempo += DeltaTime;
}

void APregunta3_4GameModeBase::BeginPlay()
{
	Super::BeginPlay();
	EstrategiaAscenderMesa = GetWorld()->SpawnActor<AEstrategiaAscenderMesa>(AEstrategiaAscenderMesa::StaticClass());
	EstrategiaDesarmarMesa = GetWorld()->SpawnActor<AEstrategiaDesarmarMesa>(AEstrategiaDesarmarMesa::StaticClass());
	EstrategiaMoverMesa = GetWorld()->SpawnActor<AEstrategiaMoverMesa>(AEstrategiaMoverMesa::StaticClass());
	FabricaMesa = GetWorld()->SpawnActor<AFabricaDeMesa>(AFabricaDeMesa::StaticClass());
	Mesa = FabricaMesa->Fabricar(FMath::RandRange(1, 3), PosicionMesa, RotacionMesa);
}

IEstrategiaMesa* APregunta3_4GameModeBase::ObtenerNuevaEstrategia(int _numeroestrategia)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Numero de Estrategia: %d"), _numeroestrategia));
	switch (_numeroestrategia) {
	case 1:
		return EstrategiaAscenderMesa;
	case 2:
		return EstrategiaDesarmarMesa;
	default:
		return EstrategiaMoverMesa;
	}
}
