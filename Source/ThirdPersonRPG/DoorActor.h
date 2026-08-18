// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableActor.h"
#include "DoorActor.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONRPG_API ADoorActor : public AInteractableActor
{
	GENERATED_BODY()
	
public:
	ADoorActor();

	// 부모의 Interact()를 새로이 문 기능으로 작성하겠다는 뜻
	virtual void Interact(AActor* Interactor) override;

	virtual FText GetInteractPrompt() override;

	// 매 프레임 문을 목표 각도로 회전
	virtual void Tick(float DeltaTime) override;

protected:
	// 회전축 (경첩) - 이걸 돌리면 여기에 매단 문이 열림
	UPROPERTY(VisibleAnywhere)
	USceneComponent* DoorPivot;
	UPROPERTY(VisibleAnywhere)
	bool bDoorOpen = false;
};
