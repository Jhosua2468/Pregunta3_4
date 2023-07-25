// Fill out your copyright notice in the Description page of Project Settings.


#include "Mesa.h"

// Sets default values
AMesa::AMesa()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMesa::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMesa::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMesa::EstablecerEstrategia(IEstrategiaMesa* _Estrategia)
{
	Estrategia = _Estrategia;
}

