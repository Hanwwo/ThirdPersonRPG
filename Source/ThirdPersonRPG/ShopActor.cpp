// Fill out your copyright notice in the Description page of Project Settings.


#include "ShopActor.h"
#include "Components/StaticMeshComponent.h"
#include "RPGPlayerState.h"
#include "ThirdPersonRPG.h"

AShopActor::AShopActor()
{

}

void AShopActor::Interact(AActor* Interactor)
{
	// 상호작용한 대상에게서 RPGPlayerState 찾아서 가져가기
	APawn* InteractorPawn = Cast<APawn>(Interactor);
	if (InteractorPawn == nullptr)
	{
		return;
	}

	ARPGPlayerState* PS = Cast<ARPGPlayerState>(InteractorPawn->GetPlayerState());
	if (PS == nullptr)
	{
		return;
	}

	Super::Interact(Interactor);

	// 재화 소비 시도 : 실패 시 거래 취소
	if (PS->TrySpendGold(Price) == false)
	{
		return;
	}

	UE_LOG(LogThirdPersonRPG, Log, TEXT("Purchase Success"));
}

FText AShopActor::GetInteractPrompt()
{
	return FText::FromString(TEXT("상점"));
}