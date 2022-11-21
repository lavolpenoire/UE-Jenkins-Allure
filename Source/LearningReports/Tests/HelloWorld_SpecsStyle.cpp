// Fill out your copyright notice in the Description page of Project Settings.


#include "HelloWorld_SpecsStyle.h"
#include "CoreMinimal.h"
#include "LearningReports/LearningReportsCharacter.h"
#include "Misc/AutomationTest.h"


DEFINE_SPEC(FSpecBooleanEqualiation, "MyOwn.Hello World.Specs Style Max Int Check",
																		EAutomationTestFlags::ApplicationContextMask	|
																		EAutomationTestFlags::ProductFilter				|
																		EAutomationTestFlags::HighPriorityAndAbove		);

void FSpecBooleanEqualiation::Define()
{
	Describe("Testing basic math operations", [this]
	{
		BeforeEach([this]
		{
			
		});
		
		It("Should test bigest number of pair", [this]()
		{
			AddInfo("Testing equaliation of two numbers");

			struct Dataset
			{
				int32 A;
				int32 B;
				int32 CorrectResult;
			};

			const TArray<Dataset> TestDataset {{1,2,2},
												{-3,-5,-3},
												{0, 1, 1},
												{0,-1,0} };

			for (const auto Data: TestDataset)
			{
				const FString InfoString = FString::Printf(TEXT("expected that in pair of %i and %i correct result will be %i "), Data.A, Data.B, Data.CorrectResult);
				if (TestEqual(InfoString,FMath::Max(Data.A,Data.B), Data.CorrectResult))
				{
					return true;
				}
				else
				{
					return false;
				}
			}

			return true;
		});

		It("", [this]
		{
			return true;
		});

		AfterEach([this]
		{
			
		});
	});
}


