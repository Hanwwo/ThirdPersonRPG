// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueWidget.h"
#include "Components/TextBlock.h"

void UDialogueWidget::SetDialogueText(FText NewText)
{
	if (DialogueText != nullptr)
	{
		DialogueText->SetText(NewText);
	}
}
