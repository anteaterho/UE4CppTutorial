// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class UE4CPPTUTORIAL_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditAnywhere)
	UShapeComponent* Root;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MyMesh;

	float RuniningTime;
	
	UPROPERTY(EditAnywhere)
	float SpeedScale;

	FVector PlayerStartingLocation = FVector(1.0f, 0.0f, 0.0f);

	FVector RootSize = FVector(1.5f, 1.5f, 1.5f);

	UFUNCTION()
	void TriggerEnter(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OhtherBodyIndex, bool bFromSweep, const FHitResult& SweepRessult);
	
	UPROPERTY(EditAnywhere)
	bool bMovesYAxis = true;
};
