// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractPromptWidget.h"
#include "Components/TextBlock.h"

void UInteractPromptWidget::SetPromptText(FText NewText)
{
	if (PromptText != nullptr)
	{
		PromptText->SetText(NewText);
	}
		
}