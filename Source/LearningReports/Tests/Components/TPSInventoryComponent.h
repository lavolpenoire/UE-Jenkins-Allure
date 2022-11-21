// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LearningReports/Tests/Items/TPSTypes.h"
#include "TPSInventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LEARNINGREPORTS_API UTPSInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	
	UTPSInventoryComponent();

	bool TryToAddItem(const FInventoryData& Data);

	UFUNCTION(BlueprintCallable)
	int32 GetInventoryAmountByType(EInventoryItemType Type) const;
	
protected:
	
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TMap<EInventoryItemType, int32> InventoryLimits;

protected:
	UPROPERTY(VisibleAnywhere)
	TMap<EInventoryItemType, int32> Inventory;
};
