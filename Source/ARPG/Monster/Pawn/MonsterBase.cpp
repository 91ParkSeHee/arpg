// Fill out your copyright notice in the Description page of Project Settings.

#include "../Pawn/MonsterBase.h"
//#include "Pawn/Monster/MonsterBase.h"


// Sets default values
AMonsterBase::AMonsterBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	RootComponent = DefaultSceneRoot;

	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));

	SkeletalMeshComponent->SetupAttachment(DefaultSceneRoot);
	SkeletalMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	/*Not Use right now*/

	/*if someone Use UFloatingPawnMovement Delete this Comment And Used it plz or someone do not need this delete all this codes*/
	//MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MovementComponent"));
	//check(MovementComponent);

	/*Use this Afeter Create StateComponent*/
	//StatusComponent = CreateDefaultSubobject<UStatusComponent>(TEXT("StatusComponent"));
	//check(StatusComponent);
	
	/*Use this Afeter Create SkillComponent(Finishkill) */
	//SkillComponent = CreateDefaultSubobject<USkillComponent>(TEXT("MonsterSkillComponent"));
	//check(SkillComponent);
}

void AMonsterBase::SetData(const FDataTableRowHandle& InDataTableRowHandle)
{
	MonsterDataTableRowHandle = InDataTableRowHandle;
	if (MonsterDataTableRowHandle.IsNull()) { return; }
	FMonsterBaseTableRow* Data = MonsterDataTableRowHandle.GetRow<FMonsterBaseTableRow>(TEXT("Enemy"));
	if (!Data) { ensure(false); return; }
	MonsterData = Data;
	
	//AI Controller Parts 
	/*Add AI After Create*/
	//AIControllerClass = MonsterData->AIControllerClass;

	//Speed Control from Monster Data
	/*UFloatingPawnMovement ���� �ٸ��� ����� ��� MovementComponent�� �ش� Ÿ���� ����� �ٸ��ɷ� �ٲ��ּ���*/
	MovementComponent->MaxSpeed = MonsterData->MovementMaxSpeed;

	SkeletalMeshComponent->SetSkeletalMesh(MonsterData->SkeletalMesh);
	SkeletalMeshComponent->SetAnimClass(MonsterData->AnimClass);
	SkeletalMeshComponent->SetRelativeTransform(MonsterData->MeshTransform);

	/*Collision Component�� ���� �ȸ���������� ������ ����*/

}

// Called when the game starts or when spawned
void AMonsterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMonsterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMonsterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

