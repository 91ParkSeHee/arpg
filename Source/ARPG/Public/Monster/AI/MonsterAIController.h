// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTree.h"

#include "CoreMinimal.h"
#include "AIController.h"
#include "MonsterAIController.generated.h"

/**
 * 
 */
UCLASS()
class ARPG_API AMonsterAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;
	virtual void Tick(float DeltaTime) override;

protected:
	/*Spawn ��ġ ���� ���� ���� �������� Ȯ���ϴ� ���*/
	void CheckSpawnRadius();

	//Ability system �ϼ��Ŀ� ������ �Ұ� ����
	//UFUNCTION()
	//void OnDamaged(float CurrentHP, float MaxHP);

	
};
