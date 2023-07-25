// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Mesa.generated.h"

UCLASS()
class PREGUNTA3_4_API AMesa : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMesa();
	UPROPERTY()
		UStaticMeshComponent* TablaMesh;
	UPROPERTY()
		TArray<UStaticMeshComponent*> PatasMesh;
	UPROPERTY()
		UMaterial* MaterialDeTabla;
	UPROPERTY()
		UMaterial* MaterialDePatas;
	TArray<float> CoordenadasDeTabla;
	TArray<std::pair<float, std::pair<float, float>>> CoordenadasDePatas;
	FVector PosicionDeTabla;
	TArray<FVector> PosicionesDePatas;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	class IEstrategiaMesa* Estrategia;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void CrearMesa() PURE_VIRTUAL(AMesa::CrearMesa, );
	virtual void EstablecerEstrategia(class IEstrategiaMesa* _Estrategia);
	virtual void Accionar() PURE_VIRTUAL(AMesa::Accionar, );

};
