// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

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
public:
	// �Ϲ� Ư�� ����Ʈ �߰����� ���� ���		�⺻���ݸ� / ��ų��밡�� / Ư�� ���� / ��� �� �߰��ϰ� ������ �߰� �����ϰ����� ����
	uint8 MonsterType = 0;



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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
