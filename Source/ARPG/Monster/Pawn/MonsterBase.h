// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../AI/MonsterAIController.h"
#include "Aicontroller.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Pawn.h"
#include "MonsterBase.generated.h"
USTRUCT()
struct ARPG_API FMonsterBaseTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:	// Base Resource
	UPROPERTY(EditAnywhere, Category = "Monster")
	USkeletalMesh* SkeletalMesh = nullptr;

	UPROPERTY(EditAnywhere, Category = "Monster")
	FTransform MeshTransform = FTransform::Identity;

	//Make Base Capsule
	UPROPERTY(EditAnywhere, Category = "Monster")
	TSubclassOf<UShapeComponent> CollisionClass = UCapsuleComponent::StaticClass();
	UPROPERTY(EditAnywhere, Category = "Monster")
	float CollisionCapsuleRadius = 50.f;
	UPROPERTY(EditAnywhere, Category = "Monster")
	float CollisionCapsuleHalfHeight = 100.f;

	//Base AiController 
	UPROPERTY(EditAnywhere, Category = "Pawn|AI")
	TSubclassOf<AAIController> AIControllerClass = AMonsterAIController::StaticClass();

public: // Animation
	//�ӽ� animinstance
	UPROPERTY(EditAnywhere, Category = "Monster|Animation")
	TSubclassOf<UAnimInstance> AnimClass;
	UPROPERTY(EditAnywhere, Category = "Monster|Animation")
	TArray<UAnimMontage*> HitReactMontage;
	UPROPERTY(EditAnywhere, Category = "Monster|Animation")
	TArray<UAnimMontage*> DieMontage;
	// ����ü �и� use Upper boddy
	UPROPERTY(EditAnywhere, Category = "Monster|Animation")
	TArray<UAnimMontage*> AttackMontage;

public: //Type & Other Datatable
	// �Ϲ� Ư�� ����Ʈ �߰����� ���� ���		�⺻���ݸ� / ��ų��밡�� / Ư�� ���� / ��� �� �߰��ϰ� ������ �߰� �����ϰ����� ����
	uint8 MonsterType = 0;

	// Ÿ�Կ� ���� Max Speed �� ���� �Ҽ��� �־ �ٲܼ� �ְ� ��
	UPROPERTY(EditAnywhere, Category = "Pawn|Movement")
	float MovementMaxSpeed = 400.f;


	// ���߿� ��ų ������ ��� �Ҷ� datatable ����� �Ϲ� �� ���� �ڽĿ� 
	//UPROPERTY(EditAnywhere, Category = "Pawn|Skill", meta = (RowType = "/Script/ARPG.SkillTableRow"))
	//FDataTableRowHandle OwnSkillData;
	
	// ���߿� ������ ��� ������ �Ҷ� �����
	//UPROPERTY(EditAnywhere, Category = "Pawn|Drop", meta = (RowType = "/Script/ARPG.ItemTableRow"))
	//FDataTableRowHandle OwnDropData;

};

UCLASS()
class ARPG_API AMonsterBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMonsterBase();
	virtual void SetData(const FDataTableRowHandle& InDataTableRowHandle);
protected:
	//Duplacte In Editor
	virtual void PostDuplicate(EDuplicateMode::Type DuplicateMode) override;
	virtual void PostLoad() override;
	virtual void PostLoadSubobjects(FObjectInstancingGraph* OuterInstanceGraph) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void OnConstruction(const FTransform& Transform);
	//Take damage Parts
	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


protected:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USceneComponent> DefaultSceneRoot;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USkeletalMeshComponent> SkeletalMeshComponent;

	UPROPERTY()
	TObjectPtr<UShapeComponent> CollisionComponent;

	// load Monster Data Target
	UPROPERTY(EditAnywhere, meta = (RowType = "/Script/ARPG.MonsterBaseTableRow"))
	FDataTableRowHandle MonsterDataTableRowHandle;

	// Make Better to Useful ����ϱ� ���ϰ� �Ϸ��� ����� �����Դϴ�
	FMonsterBaseTableRow* MonsterData;

	UFloatingPawnMovement* MovementComponent;

protected:
	UPROPERTY(VisibleAnywhere)
	UAnimInstance* AnimInstance;
};
