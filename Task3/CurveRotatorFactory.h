#pragma once

#include "CoreMinimal.h"
#include "Factories/CurveFactory.h"
#include "CurveRotator.h"
#include "CurveRotatorFactory.generated.h"

UCLASS()
class EXERCISEFINALIZED_API UCurveRotatorFactory : public UCurveFactory
{
	GENERATED_BODY()
	
public:
	UCurveRotatorFactory(const FObjectInitializer& ObjectInitializer);

	virtual UObject* FactoryCreateNew
	(
		UClass * Class,
		UObject* InParent,
		FName Name,
		EObjectFlags Flags,
		UObject* Context,
		FFeedbackContext* Warn
	) override;

	virtual bool ConfigureProperties() override;

	virtual bool ShouldShowInNewMenu() const override;
};
