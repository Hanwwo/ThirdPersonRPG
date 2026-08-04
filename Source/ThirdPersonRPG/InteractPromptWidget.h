// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InteractPromptWidget.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONRPG_API UInteractPromptWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	/** 프롬프트에 띄울 글씨 */
	void SetPromptText(FText NewText);

protected:
	/**  위젯 속 Text Block과 연결 (이름이 같아야 자동으로 연결됨) */
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* PromptText;
};
