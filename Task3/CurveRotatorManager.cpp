#include "CurveRotatorManager.h"


UCurveRotatorManager::UCurveRotatorManager()
{
	PrimaryComponentTick.bCanEverTick = true;
	Speed = 1.0f;
}

void UCurveRotatorManager::BeginPlay()
{
	Super::BeginPlay();
}

void UCurveRotatorManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	ElapsedSeconds += Speed * DeltaTime;
	FRotator Current = RotatorCurve->GetRotatorValue(ElapsedSeconds);
	AActor * Owner = GetOwner();
	Owner->SetActorRotation(Current, ETeleportType::None);
}

