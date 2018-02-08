#include "CurveManager.h"

UCurveManager::UCurveManager()
{
	PrimaryComponentTick.bCanEverTick = true;
	Speed = 1.0f;
	CurveIsLocal = true;
	Loop = false;
	CurveScale = FVector(1.0f, 1.0f, 1.0f);
}

void UCurveManager::BeginPlay()
{
	Super::BeginPlay();
	ElapsedSeconds = 0.0f;
	float MinTime;
	VectorCurve->GetTimeRange(MinTime, CurveDuration);
}

void UCurveManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	ElapsedSeconds += DeltaTime * Speed;
	if (ElapsedSeconds > CurveDuration)
	{
		if (!Loop)
		{
			return;
		}

		ElapsedSeconds = 0.0f;
	}

	FVector CurveFrame = CurveScale * VectorCurve->GetVectorValue(ElapsedSeconds);

	AActor * Owner = GetOwner();

	if (CurveIsLocal)
	{
		Owner->SetActorRelativeLocation(CurveFrame, false, nullptr, ETeleportType::None);
	}
	else
	{
		Owner->SetActorLocation(CurveFrame, false);
	}
}

