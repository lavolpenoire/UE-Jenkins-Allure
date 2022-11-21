// Fill out your copyright notice in the Description page of Project Settings.


#include "LearningReports/Tests/HelloWorld_OldStyle.h"
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"


IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMaximumInteger, "MyOwn.Hello World.Old Style Max Int Check" ,	EAutomationTestFlags::ApplicationContextMask			|
																								EAutomationTestFlags::ProductFilter						|
 																								EAutomationTestFlags::HighPriorityAndAbove				);


bool FMaximumInteger::RunTest(const FString& Parameters)
{
	AddInfo("Testing equaliation of two numbers");

	struct Dataset
	{
		int32 A;
		int32 B;
		int32 CorrectResult;
	};

	const TArray<Dataset> TestDataset {{1,2,2},{-3,-5,-3}, {0, 1, 1},{0,-1,0} };

	for (const auto Data: TestDataset)
	{
		const FString InfoString = FString::Printf(TEXT("expected that in pair of %i and %i correct result will be %i "), Data.A, Data.B, Data.CorrectResult);
		TestEqual(InfoString,FMath::Max(Data.A,Data.B), Data.CorrectResult);
	}
	
	return true;
}







