#include "CurveRotatorFactory.h"

UCurveRotatorFactory::UCurveRotatorFactory(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SupportedClass = UCurveRotator::StaticClass();
	CurveClass = UCurveRotator::StaticClass();
}

UObject * UCurveRotatorFactory::FactoryCreateNew
(
	UClass * Class,
	UObject * InParent,
	FName Name, EObjectFlags Flags,
	UObject * Context,
	FFeedbackContext * Warn
)
{
	UCurveBase* NewCurve = nullptr;
	if (CurveClass != nullptr)
	{
		NewCurve = NewObject<UCurveBase>(InParent, CurveClass, Name, Flags);
	}

	return NewCurve;
}

bool UCurveRotatorFactory::ConfigureProperties()
{
	return true;
}

bool UCurveRotatorFactory::ShouldShowInNewMenu() const
{
	return false;
}
