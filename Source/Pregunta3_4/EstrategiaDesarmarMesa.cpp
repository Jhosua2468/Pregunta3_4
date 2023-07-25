// Fill out your copyright notice in the Description page of Project Settings.


#include "EstrategiaDesarmarMesa.h"

// Sets default values
AEstrategiaDesarmarMesa::AEstrategiaDesarmarMesa()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEstrategiaDesarmarMesa::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstrategiaDesarmarMesa::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstrategiaDesarmarMesa::AccionarMesa(AMesa* _mesa)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("AccionarMesa"));
	auto PosicionTabla = _mesa->PosicionDeTabla;
	PosicionTabla += FVector(60.0f, 60.0f, 60.0f);
	auto PosicionPata = _mesa->PosicionesDePatas[1];
	PosicionPata += FVector(-60.0f, -60.0f, -60.0f);
	_mesa->TablaMesh->SetRelativeLocation(PosicionTabla);
	for (auto& Patas : _mesa->PatasMesh) {
		Patas->SetRelativeLocation(PosicionPata);
	}
}

