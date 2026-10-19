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

	virtual FText GetInteractPrompt() override;

	virtual bool CanInteract() override;

	// 매 프레임 뚜껑을 목표 각도로 회전
	virtual void Tick(float DeltaTime) override;

	
protected:
	// 상자의 열림 유무
	UPROPERTY(VisibleAnywhere)
	bool bIsOpened = false;

	// 이 상자가 줄 재화량
	UPROPERTY(EditAnywhere, Category = "Chest")
	int32 GoldAmount = 100;

	// 뚜껑 회전축 (경첩)
	UPROPERTY(VisibleAnywhere)
	USceneComponent* ChestPivot;

	// 뚜껑 메시
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ChestComp;

	// 뚜껑이 열릴 각도
	UPROPERTY(EditDefaultsOnly, Category="Chest")
	float ChestOpenAngle = 80;
};


