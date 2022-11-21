
#include "InventoryTests.h"

#include "LearningReports/Tests/BasicGameplayTests.h"
#include "CoreMinimal.h"
#include "LearningReports/LearningReportsCharacter.h"
#include "LearningReports/LearningReportsGameMode.h"
#include "Misc/AutomationTest.h"
#include "Physics/Tests/PhysicsTestHelpers.h"
#include "Tests/AutomationCommon.h"
//#include "Tests/AutomationEditorCommon.h"
#include "Utils/Utils.h"


BEGIN_DEFINE_SPEC(FInventoryTestsSet, "MyOwn.Basic Gameplay",
				  EAutomationTestFlags::ApplicationContextMask |
				  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::NonNullRHI);
UWorld* TestWorld;
END_DEFINE_SPEC(FInventoryTestsSet);




void FInventoryTestsSet::Define()
{
	Describe("Testing basic Inventory Component", [this]
	{
		
		BeforeEach([this]
		{
			AutomationOpenMap(TEXT("/Game/TestLevel"));
			UWorld* TestWorld = Utils::GetWorld();
			TestNotNull("Testing to our map is loading normally",TestWorld);
		});

		It("Check autotest to initialise InventoryComponent", [this]
		{
			return true;
		});

		It("Check attachment of Inventory to PlayerCharacter", [this]
		{
			return true;
		});
		
		It("Check autotest to collision with Inventory Item", [this]
		{
			return true;
		});

		It("Check autotest to interact and PickUp an Inventory Item", [this]
		{
			return true;
		});
		
		AfterEach( [this]
		{
			Utils::Exit();
		});
	});
}
