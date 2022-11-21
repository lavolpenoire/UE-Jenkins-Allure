
#include "LearningReports/Tests/BasicGameplayTests.h"
#include "CoreMinimal.h"
#include "LearningReports/LearningReportsCharacter.h"
#include "LearningReports/LearningReportsGameMode.h"
#include "Misc/AutomationTest.h"
#include "Physics/Tests/PhysicsTestHelpers.h"
#include "Tests/AutomationCommon.h"
//#include "Tests/AutomationEditorCommon.h"
#include "Utils/Utils.h"


BEGIN_DEFINE_SPEC(FBasicTestsSet, "MyOwn.Basic Gameplay",
                  EAutomationTestFlags::ApplicationContextMask |
                  EAutomationTestFlags::ProductFilter |
                  EAutomationTestFlags::HighPriorityAndAbove);
UWorld* TestWorld;
FTimespan Timeout;
//ACharacter* PlayerCharacter;
END_DEFINE_SPEC(FBasicTestsSet);


FTimespan Timeout(0,0,2);

void FBasicTestsSet::Define()
{
	Describe("Testing basic gameplay elements", [this]
	{
		
		BeforeEach([this]
		{
			const auto LoadLevel =  AutomationOpenMap(TEXT("/Game/ThirdPerson/Maps/TestLevel"));
			UWorld* TestWorld = Utils::GetWorld();
			TestNotNull("Testing to our map is loading normally",TestWorld);
		});
		
		
		It("Autotest should open level for 5 second", [this]
		{
			return true;
		});
		

		It("Autotest should to spawn PlayerCharacter", [this]
		{
			
			return true;
		});
		
		It("Autotest should to move forward spawned PlayerCharacter", [this]
		{
			return true;
			
		});
		
		AfterEach( [this]
		{
			
			Utils::Exit();
		});
	});
}
