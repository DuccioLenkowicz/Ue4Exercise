#pragma once

#include "CoreMinimal.h"
#include "Curves/CurveBase.h"
#include "UObject/ObjectMacros.h"
#include "Curves/RichCurve.h"
#include "CurveRotator.generated.h"

// bad degrees interpolation, but ok for the sake of an exercise
UCLASS()
class EXERCISEFINALIZED_API UCurveRotator : public UCurveBase
{
	GENERATED_BODY()
	
	UPROPERTY()
	FRichCurve FloatCurves[3];
	
public:
	UFUNCTION(BlueprintCallable, Category = "Math|Curves")
	FRotator GetRotatorValue(float InTime) const;

	virtual TArray<FRichCurveEditInfoConst> GetCurves() const override;

	virtual TArray<FRichCurveEditInfo> GetCurves() override;

	bool operator == (const UCurveRotator& Curve) const;

	virtual bool IsValidCurve(FRichCurveEditInfo CurveInfo) override;

};
