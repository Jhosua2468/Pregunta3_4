// Fill out your copyright notice in the Description page of Project Settings.


#include "EstrategiaAscenderMesa.h"


// Sets default values
AEstrategiaAscenderMesa::AEstrategiaAscenderMesa()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEstrategiaAscenderMesa::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstrategiaAscenderMesa::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstrategiaAscenderMesa::AccionarMesa(AMesa* _mesa)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("AccionarMesa"));
	_mesa->TablaMesh->SetRelativeLocation(_mesa->PosicionDeTabla);
	int contador = 0;
	for (auto& Patas : _mesa->PatasMesh) {
		Patas->SetRelativeLocation(_mesa->PosicionesDePatas[contador]);
		contador++;
	}
	auto PosicionNueva = _mesa->PosicionDeTabla;
	PosicionNueva += FVector(0.0f, 0.0f, FMath::RandRange(3, 7) * 10);
	_mesa->TablaMesh->SetRelativeLocation(PosicionNueva);
	for (auto& Patas : _mesa->PatasMesh) {
		PosicionNueva = Patas->GetRelativeLocation() + FVector(0.0f, 0.0f, FMath::RandRange(3, 7) * 10);
		Patas->SetRelativeLocation(PosicionNueva);
	}
}

