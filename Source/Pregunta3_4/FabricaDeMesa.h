// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FabricaDeMesa.generated.h"

UCLASS()
class PREGUNTA3_4_API AFabricaDeMesa : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFabricaDeMesa();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	class AMesa* Fabricar(int _numeromesa, FVector _Locacion, FRotator _Rotacion);
};
