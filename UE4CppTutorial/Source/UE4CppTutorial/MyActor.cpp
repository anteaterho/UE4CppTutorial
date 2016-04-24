// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4CppTutorial.h"
#include "MyActor.h"


// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	Root->bGenerateOverlapEvents = true;
	Root->OnComponentBeginOverlap.AddDynamic(this, &AMyActor::TriggerEnter);
	Root->SetRelativeScale3D(RootSize);

	RootComponent = Root;

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	MyMesh->AttachTo(RootComponent);

	SpeedScale = 0.0f;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	FVector NewLocation = GetActorLocation();
	float DeltaHeight = FMath::Sin(RuniningTime + DeltaTime);
	if (bMovesYAxis)
		NewLocation.Y += DeltaHeight * SpeedScale;
	else
		NewLocation.X += DeltaHeight * SpeedScale;
	
	RuniningTime += DeltaTime;
	SetActorLocation(NewLocation);
}

void AMyActor::TriggerEnter(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OhtherBodyIndex, bool bFromSweep, const FHitResult& SweepRessult)
{
	// When player is hit by the rock, teleport them back to the start
	OtherActor->SetActorLocation(PlayerStartingLocation);

}
