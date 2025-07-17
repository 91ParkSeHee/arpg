// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "NAStateMachineComponent.generated.h"


class UCharacterStateBase;
class ICharacterStateBase;
UENUM()
enum class ECharacterState : uint8
{
	None,
	Idle,
	Max
};



/************************************************************************************************************
 *
 *		UNAStateMachineComponent
 *
 *		@feature: 소유자의 State를 변경 및 관리
 *
 *		
 */
UCLASS()
class ARPG_API UNAStateMachineComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

protected:
	UFUNCTION()
	void ChangeState(ECharacterState NewState);
	
protected:
	UPROPERTY()
	TMap<ECharacterState, UCharacterStateBase*> CharacterStates;

	UPROPERTY()
	UCharacterStateBase* CurrentState;

	TSoftClassPtr<AActor> Owner;
};
