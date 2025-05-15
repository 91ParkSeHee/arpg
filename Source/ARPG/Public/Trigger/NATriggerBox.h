// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NATriggerBase.h"
#include "NATriggerBox.generated.h"

UCLASS()
class ARPG_API ANATriggerBox : public ANATriggerBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ANATriggerBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;



	
protected:
	UPROPERTY()
	UShapeComponent* CollisionPrimitive;
};
