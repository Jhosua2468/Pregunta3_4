// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Mesa.h"
#include "MesaRedonda.generated.h"

/**
 * 
 */
UCLASS()
class PREGUNTA3_4_API AMesaRedonda : public AMesa
{
	GENERATED_BODY()
	
public:
	AMesaRedonda();
	virtual void Tick(float DeltaTime) override;
	virtual void CrearMesa() override;
	virtual void Accionar() override;
protected:
	virtual void BeginPlay() override;
};
