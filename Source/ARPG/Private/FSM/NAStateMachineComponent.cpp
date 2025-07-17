// Fill out your copyright notice in the Description page of Project Settings.


#include "FSM/NAStateMachineComponent.h"

#include "FSM/NACharacterStateBase.h"

void UNAStateMachineComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UNAStateMachineComponent::TickComponent(float DeltaTime, enum ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UNAStateMachineComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void UNAStateMachineComponent::ChangeState(ECharacterState NewState)
{
	CurrentState = CharacterStates[NewState];

	CurrentState->EnterState();
}
