// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Camera/CameraComponent.h"
#include "Components/SphereComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "FloatingPawn.generated.h"

UCLASS()
class EXERCISEFINALIZED_API AFloatingPawn : public APawn
{
	GENERATED_BODY()

public:
	AFloatingPawn();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent * SideViewCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent * CameraBoom;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent * Mesh;

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void MoveRight(float Val);

	virtual void MoveUp(float Val);

protected:
	virtual void BeginPlay() override;

private:
	UFloatingPawnMovement * MovementComponent;
};
