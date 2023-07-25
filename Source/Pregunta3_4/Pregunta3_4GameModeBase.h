// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Pregunta3_4GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class PREGUNTA3_4_API APregunta3_4GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	APregunta3_4GameModeBase();
	virtual void Tick(float DeltaTime) override;
	UPROPERTY()
		class AMesa* Mesa;
	UPROPERTY()
		class AFabricaDeMesa* FabricaMesa;
protected:
	virtual void BeginPlay() override;
private:
	class AEstrategiaAscenderMesa* EstrategiaAscenderMesa;
	class AEstrategiaDesarmarMesa* EstrategiaDesarmarMesa;
	class AEstrategiaMoverMesa* EstrategiaMoverMesa;
	FVector PosicionMesa;
	FRotator RotacionMesa;
	float Tiempo;
	class IEstrategiaMesa* ObtenerNuevaEstrategia(int _numeroestrategia);
	
};
