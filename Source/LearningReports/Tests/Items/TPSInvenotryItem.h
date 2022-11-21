// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TPSTypes.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "TPSInvenotryItem.generated.h"

UCLASS()
class LEARNINGREPORTS_API ATPSInvenotryItem : public AActor
{
	GENERATED_BODY()
	
public:	

	ATPSInvenotryItem();

	
	UFUNCTION()
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

protected:
	UPROPERTY(VisibleAnywhere)
	USphereComponent* CollisionComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FInventoryData InventoryData;

};
