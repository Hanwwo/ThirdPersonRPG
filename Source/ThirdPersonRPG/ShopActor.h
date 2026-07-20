// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableActor.h"
#include "ShopActor.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONRPG_API AShopActor : public AInteractableActor
{
	GENERATED_BODY()
	
public:
	AShopActor();

	// 부모의 Interact()를 상점 기능으로 재정의
	virtual void Interact(AActor* Interactor) override;

protected:
	UPROPERTY(EditAnywhere, Category = "Shop")
	int32 Price = 300;
};
