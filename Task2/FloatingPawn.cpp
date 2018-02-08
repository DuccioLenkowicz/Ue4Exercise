// Fill out your copyright notice in the Description page of Project Settings.

#include "FloatingPawn.h"


// Sets default values
AFloatingPawn::AFloatingPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	// Collision and root
	USphereComponent* SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));
	RootComponent = SphereComponent;
	SphereComponent->InitSphereRadius(40.0f);
	SphereComponent->SetCollisionProfileName(TEXT("Pawn"));

	// Mesh
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	Mesh->SetupAttachment(RootComponent);

	// Don't rotate when the controller rotates.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Create a camera boom attached to the root (capsule)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->bAbsoluteRotation = true; // Rotation of the character should not affect rotation of boom
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->TargetArmLength = 500.f;
	CameraBoom->SocketOffset = FVector(0.f, 0.f, 75.f);
	CameraBoom->RelativeRotation = FRotator(0.f, 180.f, 0.f);

	// Create a camera and attach to boom
	SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	SideViewCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	SideViewCameraComponent->bUsePawnControlRotation = false; // We don't want the controller rotating the camera

	//pawn movement setup 
	MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingMovementComponent"));
	MovementComponent->UpdatedComponent = RootComponent;


	// Take control of the default player
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

void AFloatingPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFloatingPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFloatingPawn::MoveRight(float Val)
{
	MovementComponent->AddInputVector(FVector(0.f, -Val, 0.f), true);
}

void AFloatingPawn::MoveUp(float Val)
{
	MovementComponent->AddInputVector(FVector(0.f, 0.f, Val), true);
}

void AFloatingPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveRight", this, &AFloatingPawn::MoveRight);
	PlayerInputComponent->BindAxis("MoveUp", this, &AFloatingPawn::MoveUp);
}


