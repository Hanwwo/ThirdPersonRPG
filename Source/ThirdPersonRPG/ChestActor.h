// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableActor.h"
#include "ChestActor.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONRPG_API AChestActor : public AInteractableActor
{
	GENERATED_BODY()

public:

	AChestActor();

	// 부모의 Interact()를 상자 기능으로 재정의
	virtual void Interact(AActor* Interactor) override;

	
protected:
	// 상자의 열림 유무
	UPROPERTY(VisibleAnywhere)
	bool bIsOpened = false;

	// 이 상자가 줄 재화량
	UPROPERTY(EditAnywhere, Category = "Chest")
	int32 GoldAmount = 100;
};


