// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include "Components/BoxComponent.h"
#include "Components/WidgetComponent.h"


AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_itemMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("_itemMesh"));

	SetRootComponent(_itemMesh);

	_collisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("_collisionBox"));
	_collisionBox->SetupAttachment(_itemMesh);
	
	// Setting collision box to be hit by the line trace.
	// Setting collision response to be ignore to all channels.
	_collisionBox->SetCollisionResponseToChannels(ECollisionResponse::ECR_Ignore);
	// Set collision to block only the channel we  are interested. In this case the Visibility channel will be blocked when the line trace hit the widget.
	_collisionBox->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECR_Block);

	_pickupWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("_pickUpWidget"));
	_pickupWidget->SetupAttachment(GetRootComponent());
}


void AItem::BeginPlay()
{
	Super::BeginPlay();

	// Hide pickup widget
	_pickupWidget->SetVisibility(false);
}


void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

