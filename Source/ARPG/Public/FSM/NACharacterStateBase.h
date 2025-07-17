// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "NACharacterStateBase.generated.h"

/**
 * 
 */

class UNAStateMachineComponent;

UINTERFACE()
class UCharacterState : public UInterface
{
	GENERATED_BODY()
};


class ARPG_API ICharacterState 
{
	GENERATED_BODY()
	
public:
	ICharacterState() {}
	
protected:
	UFUNCTION()
	virtual void EnterState() = 0;

	UFUNCTION()
	virtual void UpdateState() = 0;

	UFUNCTION()
	virtual void EndState() = 0;

protected:
	TSoftClassPtr<UNAStateMachineComponent> OwnerStateMachine;
};

UCLASS()
class ARPG_API UCharacterStateBase : public UObject, public ICharacterState
{
	GENERATED_BODY()

public:
	UFUNCTION()
	virtual void EnterState() override {}

	UFUNCTION()
	virtual void UpdateState() override {}

	UFUNCTION()
	virtual void EndState() override {}
};