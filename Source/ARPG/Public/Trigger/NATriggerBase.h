// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBase.h"
#include "NATriggerBase.generated.h"

UENUM()
enum class eRequirement : uint8
{
	None,
	KillMonster,	// 토벌
	HasItem,		// 아이템 소유여부
	HasAbility,		// 어빌리티 소유여부 + 수치
	Custom,
	Max
};

UENUM()
enum class eTriggerCondition : uint8
{
	None,
	Collision,		// 트리거박스와 충돌
	Click,			// 마우스로 클릭
	Max
};

class UNARequirement : public UObject
{
	// 각종 요구사항 (ex. 어떤 ability를 보유중, 몬스터 @마리 토벌)
private:
	
};



//------------------------------------------------------------------------------------------------------
//
//	ANATriggerBase
//
//		@feature:
//			- 조건(Condition)만족 (충돌, 클릭 등) -> Requirement 만족 -> Trigger 발동
//			- ex) npc를 클릭 -> 아이템 N개를 보유중인가? Y -> 클리어 dialogue 출력
//													N -> 실패 dialogue 출력
//
//			- ex) 특정 트리거에 충돌 -> 몬스터 소환
//

UCLASS()
class ARPG_API ANATriggerBase : public ATriggerBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ANATriggerBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	void SetAction(TScriptDelegate<> Delegate);
	
public:
	UPROPERTY()
	eTriggerCondition TriggerCondtion;
	
	TScriptDelegate<> Action;		// 트리거가 발동되었을때 실행할 함수
};
