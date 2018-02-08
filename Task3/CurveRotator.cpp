// Fill out your copyright notice in the Description page of Project Settings.

#include "CurveRotator.h"

static const FName Pitch(TEXT("Pitch"));
static const FName Yaw(TEXT("Yaw"));
static const FName Roll(TEXT("Roll"));


FRotator UCurveRotator::GetRotatorValue(float InTime) const
{
	FRotator Result;
	Result.Pitch	= FloatCurves[0].Eval(InTime);
	Result.Yaw		= FloatCurves[1].Eval(InTime);
	Result.Roll		= FloatCurves[2].Eval(InTime);
	return Result;
}

TArray<FRichCurveEditInfoConst> UCurveRotator::GetCurves() const
{
	TArray<FRichCurveEditInfoConst> Curves;
	Curves.Add(FRichCurveEditInfoConst(&FloatCurves[0], Roll));
	Curves.Add(FRichCurveEditInfoConst(&FloatCurves[1], Pitch));
	Curves.Add(FRichCurveEditInfoConst(&FloatCurves[2], Yaw));
	return Curves;
}

TArray<FRichCurveEditInfo> UCurveRotator::GetCurves()
{
	TArray<FRichCurveEditInfo> Curves;
	Curves.Add(FRichCurveEditInfo(&FloatCurves[0], Roll));
	Curves.Add(FRichCurveEditInfo(&FloatCurves[1], Pitch));
	Curves.Add(FRichCurveEditInfo(&FloatCurves[2], Yaw));
	return Curves;
}

bool UCurveRotator::operator==(const UCurveRotator & Curve) const
{
	return (FloatCurves[0] == Curve.FloatCurves[0]) && (FloatCurves[1] == Curve.FloatCurves[1]) && (FloatCurves[2] == Curve.FloatCurves[2]);
}

bool UCurveRotator::IsValidCurve(FRichCurveEditInfo CurveInfo)
{
	return	CurveInfo.CurveToEdit == &FloatCurves[0] ||
			CurveInfo.CurveToEdit == &FloatCurves[1] ||
			CurveInfo.CurveToEdit == &FloatCurves[2];
}
