

	#include "TPSInventoryComponent.h"


UTPSInventoryComponent::UTPSInventoryComponent()
{
	
	PrimaryComponentTick.bCanEverTick = false;

}

bool UTPSInventoryComponent::TryToAddItem(const FInventoryData& Data)
{
	if (Data.Score < 0)
	{
		return false;
	}
	if (!Inventory.Contains(Data.Type))
	{
		Inventory.Add(Data.Type,0);
	}

	const auto NextScore = Inventory[Data.Type] + Data.Score;
	if(NextScore > InventoryLimits[Data.Type])
	{
		return false;
	}
	else
	{
		Inventory[Data.Type] = NextScore;
		return true;
	}
    
	
}

int32 UTPSInventoryComponent::GetInventoryAmountByType(EInventoryItemType Type) const
{
	return Inventory.Contains(Type) ? Inventory[Type] : 0;
}

void UTPSInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	const auto InvEnum = StaticEnum<EInventoryItemType>();
	
	for (int32 i =0; i < InvEnum->NumEnums()- 1; ++i)
	{
		const EInventoryItemType EnumElement = static_cast<EInventoryItemType>(i);
		const FString EnumElementName = UEnum::GetValueAsString(EnumElement);
		const bool LimitCheckCondition = InventoryLimits.Contains(EnumElement) && InventoryLimits[EnumElement] >= 0;
		//checkf(LimitCheckCondition, TEXT("Limit for %s don`t exist"), EnumElementName);
		if (!LimitCheckCondition)
		{
			InventoryLimits.Add(EnumElement, 100);
		}
		
	}
}



