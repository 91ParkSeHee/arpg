// Fill out your copyright notice in the Description page of Project Settings.
#include "../Monster/DefaultAnimInstance.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UDefaultAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	APawn* Pawn = TryGetPawnOwner();
	if (GIsEditor && FApp::IsGame() && !Pawn)
	{
		checkf(false, TEXT("UDefaultAnimInstance�� ����Ϸ��� �������ڰ� Pawn�̿��� �մϴ�."));
		return;
	}
	else if (!Pawn) { return; }

	// TODO:: ADD Movement plz
	MovementComponent = Pawn->GetMovementComponent();
	check(MovementComponent);
}

void UDefaultAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (!MovementComponent) { return; }

	Speed = UKismetMathLibrary::VSizeXY(MovementComponent->Velocity);

	bShoudMove = !FMath::IsNearlyZero(Speed);

	APawn* Pawn = TryGetPawnOwner();
	FRotator Rotation = Pawn->GetActorRotation();
	//
	Direction = CalculateDirection(MovementComponent->Velocity, Rotation);



	//Player controller �κ��Դϴ� �ʿ�� �ش� �ּ��� ��� Ǯ�� ����ϰų� �ʿ� ���� ��� �����ּ���
	//this is Player controller Parts 
	// if someone need this delete this Commets And Used it plz or someone do not need this delete all this codes
	/*
	//Pawn->GetController();
	//ABasePlayerController* OwnPlayerController = Cast<ABasePlayerController>(Pawn->GetController());
	//if (OwnPlayerController)
	//{
	//	ZoomAnim = OwnPlayerController->IsZoom;
	//}
	// 
	// 
	//Updating Rotation
	//Direction = AimRotation.Yaw;
	//if (Direction > 180.0) { Direction -= 360.0; }
	//else if (Direction < -180.0) { Direction += 360.0; }


	//���� �Ⱦ��� ����� + fall anim not exist
	//bIsCrouch = MovementComponent->IsCrouching();	
	//bIsFalling = MovementComponent->IsFalling();
	*/
}
