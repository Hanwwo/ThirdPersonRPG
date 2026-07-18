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
	virtual void Interact() override;

protected:
	// 회전축 (경첩) - 이걸 돌리면 여기에 매단 문이 열림
	UPROPERTY(VisibleAnywhere)
	USceneComponent* DoorPivot;

	// 눈에 보이는 몸 (큐브 메시, 테스트용 임시)
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshComp;


};
