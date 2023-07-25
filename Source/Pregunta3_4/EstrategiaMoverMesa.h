// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EstrategiaMesa.h"
#include "Mesa.h"
#include "EstrategiaMoverMesa.generated.h"

UCLASS()
class PREGUNTA3_4_API AEstrategiaMoverMesa : public AActor, public IEstrategiaMesa
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEstrategiaMoverMesa();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void AccionarMesa(AMesa* _mesa) override;
};
