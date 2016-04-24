// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4CppTutorial.h"
#include "FinishLine.h"


// Sets default values
AFinishLine::AFinishLine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	RootComponent = Root;

	Root->bGenerateOverlapEvents = true;
	Root->OnComponentBeginOverlap.AddDynamic(this, &AFinishLine::TriggerEnter);
}

// Called when the game starts or when spawned
void AFinishLine::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFinishLine::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AFinishLine::TriggerEnter(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSwap, const FHitResult & SweepResult)
{
	if (OtherActor->IsA(AActor::StaticClass()))
	{
		// access player audio component.
		UGameplayStatics::PlaySoundAttached(MySound, OtherActor->GetRootComponent());
	}
}