


#include "TPSInvenotryItem.h"

#include "LearningReports/Tests/Components/TPSInventoryComponent.h" 


ATPSInvenotryItem::ATPSInvenotryItem()
{
 	
	PrimaryActorTick.bCanEverTick = false;

	CollisionComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
	if (CollisionComponent != nullptr)
	{
		CollisionComponent->InitSphereRadius(30.0f);
		CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
		CollisionComponent->SetCollisionResponseToAllChannels(ECR_Overlap);
		SetRootComponent(CollisionComponent);
		
	}

}

void ATPSInvenotryItem::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	
	const auto Pawn = Cast<APawn>(OtherActor);
	const auto PawnInventory = Pawn->FindComponentByClass<UTPSInventoryComponent>();
	if (Pawn)
	{
		if(PawnInventory)
		{
			if ((PawnInventory != nullptr) && (PawnInventory->TryToAddItem(InventoryData)))
			{
				Destroy();
				
			}
			
		}
	}
	/*
	if (const auto Pawn = Cast<APawn>(OtherActor))
	{
		if(const auto PawnInventory = Pawn->FindComponentByClass<UTPSInventoryComponent>())
		{
			if ((PawnInventory != nullptr) && (PawnInventory->TryToAddItem(InventoryData)))
			{
				Destroy();
				
			}
			
		}
	}
	*/
}


