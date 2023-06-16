// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "YCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class PROJECTUE_API AYCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AYCharacter();

protected:
	//���Թ���
	UPROPERTY(VisibleAnywhere);
	//��ʼ����ָ��
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere);
	UCameraComponent* CameraComp;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	//��ǰ�ƶ�����ֵ��1��ǰ��-1���
	void MoveForward(float Value);
	void MoveRight(float Value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
