#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CurveRotator.h"
#include "CurveRotatorManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EXERCISEFINALIZED_API UCurveRotatorManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCurveRotatorManager();

	UPROPERTY(EditAnywhere)
		UCurveRotator * RotatorCurve;

	UPROPERTY(EditAnywhere)
		float Speed;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;

private:
	float ElapsedSeconds;

};
