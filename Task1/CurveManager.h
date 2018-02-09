// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Curves/CurveVector.h"
#include "CurveManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EXERCISEFINALIZED_API UCurveManager : public USceneComponent
{
	GENERATED_BODY()

public:	
	UCurveManager();

	UPROPERTY(EditAnywhere)
		UCurveVector * VectorCurve;

	UPROPERTY(EditAnywhere)
		float Speed;

	UPROPERTY(EditAnywhere)
		bool CurveIsLocal;

	UPROPERTY(EditAnywhere)
		FVector CurveScale;

	UPROPERTY(EditAnywhere)
		bool Loop;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;

private:
	float ElapsedSeconds;
	float CurveDuration;
};
