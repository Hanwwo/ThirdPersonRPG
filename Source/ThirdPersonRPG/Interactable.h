// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interactable.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInteractable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class THIRDPERSONRPG_API IInteractable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	// 상호작용 될 때, 실행될 계약 함수 (알맹이는 어짜피 각 액터가 채우기 때문에 =0 을 붙여줌. 순수 가상 함수)
	virtual void Interact(AActor* Interactor) = 0;

	// 프롬프트에 띄울 글씨 가져오기 (상호작용 가능 대상이 무엇인지 화면에 표시)
	virtual FText GetInteractPrompt() = 0;
};
