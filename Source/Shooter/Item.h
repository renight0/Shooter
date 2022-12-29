// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class SHOOTER_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

protected:

	virtual void BeginPlay() override;

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
// ~private variables~ //
private:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item Properties", meta = (AllowPrivateAccess = true));
	// Skeletal Mesh for the item.
	USkeletalMeshComponent* _itemMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Properties", meta = (AllowPrivateAccess = true));
	// Line trace collides with box to show HUD widgets.
	class UBoxComponent* _collisionBox;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item Properties", meta = (AllowPrivateAccess = true));
	// Popup widget for when the player looks at the item.
	class UWidgetComponent* _pickupWidget;

	
	
// ~ Public getters and setters ~ //
public:
	FORCEINLINE UWidgetComponent* GetPickupWidget() const { return _pickupWidget; }	
};
