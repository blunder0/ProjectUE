// Fill out your copyright notice in the Description page of Project Settings.


#include "YCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Pawn.h"

// Sets default values
AYCharacter::AYCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//���ɱ۶���
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	//���ɱ۰��ڸ������
	SpringArmComp->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);

}

// Called when the game starts or when spawned
void AYCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AYCharacter::MoveForward(float Value)
{
	//�����������������ƶ�
	AddMovementInput(GetActorForwardVector(), Value);
}

void AYCharacter::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector(), Value);
}

// Called every frame
void AYCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AYCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//��ǰ
	PlayerInputComponent->BindAxis("MoveForward", this, &AYCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AYCharacter::MoveRight);

	//��ת
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

}

