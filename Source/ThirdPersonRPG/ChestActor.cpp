// Fill out your copyright notice in the Description page of Project Settings.


#include "ChestActor.h"
#include "Components/StaticMeshComponent.h"
#include "ThirdPersonRPG.h"
#include "RPGPlayerState.h"


AChestActor::AChestActor()
{
	// 상자 모양으로 : 납작하게
	MeshComp->SetRelativeScale3D(FVector(1.0f, 1.0f, 0.6f));

}

void AChestActor::Interact(AActor* Interactor)
{
	if (bIsOpened)
	{
		return;
	}

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

	Super::Interact(Interactor);	// 부모의 기능, 공통 로그

	bIsOpened = true;	// 이제 이 상자는 열린 것
	PS->AddGold(GoldAmount);	// 재화 추가

	UE_LOG(LogThirdPersonRPG, Log, TEXT("Chest Opened -> %s"), *GetName());
}

