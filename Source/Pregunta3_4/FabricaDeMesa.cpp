// Fill out your copyright notice in the Description page of Project Settings.


#include "FabricaDeMesa.h"
#include "Mesa.h"
#include "MesaCuadrada.h"
#include "MesaRedonda.h"
#include "MesaTriangular.h"


// Sets default values
AFabricaDeMesa::AFabricaDeMesa()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFabricaDeMesa::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFabricaDeMesa::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

AMesa* AFabricaDeMesa::Fabricar(int _numeromesa, FVector _Locacion, FRotator _Rotacion)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Fabricando Mesa %d"), _numeromesa));
	switch (_numeromesa)
	{
	case 1:
		return GetWorld()->SpawnActor<AMesaCuadrada>();
	case 2:
		return GetWorld()->SpawnActor<AMesaRedonda>();
	default:
		return GetWorld()->SpawnActor<AMesaTriangular>();
	}
}

