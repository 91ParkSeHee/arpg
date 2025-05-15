// Fill out your copyright notice in the Description page of Project Settings.


#include "Trigger/NATriggerBox.h"
#include "Components/BoxComponent.h"


// Sets default values
ANATriggerBox::ANATriggerBox()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionPrimitive = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	RootComponent = CollisionPrimitive;

	
	if (eTriggerCondition::Collision == TriggerCondtion)	
		CollisionPrimitive->OnComponentBeginOverlap.Add(Action);

	
}

// Called when the game starts or when spawned
void ANATriggerBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANATriggerBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

