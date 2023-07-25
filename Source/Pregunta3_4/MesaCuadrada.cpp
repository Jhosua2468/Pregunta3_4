// Fill out your copyright notice in the Description page of Project Settings.


#include "MesaCuadrada.h"
#include "EstrategiaMesa.h"

AMesaCuadrada::AMesaCuadrada()
{
	TablaMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TablaMesh"));
	PatasMesh = {};
	PosicionesDePatas = {};
	PatasMesh.Add(CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Pata1Mesh")));
	PatasMesh.Add(CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Pata2Mesh")));
	PatasMesh.Add(CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Pata3Mesh")));
	PatasMesh.Add(CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Pata4Mesh")));
	MaterialDeTabla = LoadObject<UMaterial>(nullptr, TEXT("Material'/Game/StarterContent/Materials/M_Wood_Oak.M_Wood_Oak'"));
	MaterialDePatas = LoadObject<UMaterial>(nullptr, TEXT("Material'/Game/StarterContent/Materials/M_Wood_Oak.M_Wood_Oak'"));
	CoordenadasDeTabla = { 0.0f, -50.0f, 140.0f };
	CoordenadasDePatas = { {120.0f, {220.0f, -10.0f}}, {120.0f, {-40.0f, -10.0f}}, {-120.0f, {220.0f, -10.0f}},  {-120.0f, {-40.0f, -10.0f}} };
	static ConstructorHelpers::FObjectFinder<UStaticMesh> TablaAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> PataAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'"));
	TablaMesh->SetStaticMesh(TablaAsset.Object);
	for (auto& Patas : PatasMesh)
	{
		Patas->SetStaticMesh(PataAsset.Object);
	}
}

void AMesaCuadrada::BeginPlay()
{
	Super::BeginPlay();
	CrearMesa();
}

void AMesaCuadrada::Tick(float DeltaTime)
{
}

void AMesaCuadrada::CrearMesa()
{
	TablaMesh->SetMaterial(0, MaterialDeTabla);
	TablaMesh->SetRelativeLocation(FVector(CoordenadasDeTabla[0], CoordenadasDeTabla[1], CoordenadasDeTabla[2]));
	PosicionDeTabla = TablaMesh->GetRelativeLocation();
	TablaMesh->SetRelativeScale3D(FVector(3.0f, 0.1f, 3.1f));
	TablaMesh->SetRelativeRotation(FRotator(0.0f, 0.0f, 90.0f));
	int contador = 0;
	for (auto& Patas : PatasMesh)
	{
		Patas->SetRelativeLocation(FVector(CoordenadasDePatas[contador].first, CoordenadasDePatas[contador].second.first, CoordenadasDePatas[contador].second.second));
		PosicionesDePatas.Add(Patas->GetRelativeLocation());
		Patas->SetRelativeRotation(FRotator::ZeroRotator);
		Patas->SetRelativeScale3D(FVector(0.2f, 0.2f, 1.5f));
		Patas->SetMaterial(0, MaterialDePatas);
		contador++;
	}
}

void AMesaCuadrada::Accionar()
{
	Estrategia->AccionarMesa(this);
}

