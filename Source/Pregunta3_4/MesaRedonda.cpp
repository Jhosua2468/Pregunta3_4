// Fill out your copyright notice in the Description page of Project Settings.


#include "MesaRedonda.h"
#include "EstrategiaMesa.h"

AMesaRedonda::AMesaRedonda()
{
	TablaMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TablaMesh"));
	PatasMesh = {};
	PosicionesDePatas = {};
	PatasMesh.Add(CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Pata1Mesh")));
	PatasMesh.Add(CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Pata2Mesh")));
	PatasMesh.Add(CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Pata3Mesh")));
	MaterialDeTabla = LoadObject<UMaterial>(nullptr, TEXT("Material'/Game/StarterContent/Materials/M_Wood_Oak.M_Wood_Oak'"));
	MaterialDePatas = LoadObject<UMaterial>(nullptr, TEXT("Material'/Game/StarterContent/Materials/M_Wood_Oak.M_Wood_Oak'"));
	CoordenadasDeTabla = { 0.0f, 70.0f, 140.0f };
	CoordenadasDePatas = { {10.0f, {210.0f, -10.0f}}, {-130.0f, {-40.0f, -10.0f}}, {120.0f, {-40.0f, -10.0f}} };
	static ConstructorHelpers::FObjectFinder<UStaticMesh> TablaAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> PataAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'"));
	TablaMesh->SetStaticMesh(TablaAsset.Object);
	for (auto& Patas : PatasMesh)
	{
		Patas->SetStaticMesh(PataAsset.Object);
	}
}

void AMesaRedonda::BeginPlay()
{
	Super::BeginPlay();
	CrearMesa();
}

void AMesaRedonda::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMesaRedonda::CrearMesa()
{
	TablaMesh->SetMaterial(0, MaterialDeTabla);
	TablaMesh->SetRelativeLocation(FVector(CoordenadasDeTabla[0], CoordenadasDeTabla[1], CoordenadasDeTabla[2]));
	PosicionDeTabla = TablaMesh->GetRelativeLocation();
	TablaMesh->SetRelativeScale3D(FVector(4.0f, 4.0f, 0.1f));
	TablaMesh->SetRelativeRotation(FRotator::ZeroRotator);
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

void AMesaRedonda::Accionar()
{
	Estrategia->AccionarMesa(this);
}

