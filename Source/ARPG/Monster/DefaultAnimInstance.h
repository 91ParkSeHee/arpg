// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "DefaultAnimInstance.generated.h"

/**
 * 
 */
// ���� �ش� ���� ��ġ�� monster �Դϴ� ���� player �� �ٸ����� ����Ѵٸ� �̵����� �ּ���
UCLASS()
class ARPG_API UDefaultAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	void SetAimRotation(const FRotator& NewAimRotation) { AimRotation = NewAimRotation; }
	const FRotator& GetAimRotation() { return AimRotation; }

protected:
	UPROPERTY()
	class UPawnMovementComponent* MovementComponent;

	UPROPERTY(BlueprintReadOnly)
	double Speed = 0.0;

	UPROPERTY(BlueprintReadOnly)
	double Direction = 0.0;

	UPROPERTY(BlueprintReadOnly)
	bool bShoudMove = false;

	/*���� �Ⱦ��� ����� + fall anim not exist */
	UPROPERTY(BlueprintReadOnly)
	bool bIsCrouch = false;
	UPROPERTY(BlueprintReadOnly)
	bool bIsFalling = false;

	UPROPERTY(BlueprintReadOnly)
	FRotator AimRotation;

	//Playerable Character Var
	UPROPERTY(BlueprintReadOnly)
	bool ZoomAnim;
	
	
	
};
