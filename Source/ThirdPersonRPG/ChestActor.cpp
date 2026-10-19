// Fill out your copyright notice in the Description page of Project Settings.


#include "ChestActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "ThirdPersonRPG.h"
#include "RPGPlayerState.h"


AChestActor::AChestActor()
{
	// 경첩 생성 후 상자아래몸통 자식으로 매달기
	ChestPivot = CreateDefaultSubobject<USceneComponent>(TEXT("ChestPivot"));
	ChestPivot->SetupAttachment(MeshComp);

	// 뚜껑 생성 후 경첩 자식으로 매달기
	ChestComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ChestComp"));
	ChestComp->SetupAttachment(ChestPivot);
}

void AChestActor::Interact(AActor* Interactor)
{
	if (bIsOpened)
	{
		return;
	}

	Super::Interact(Interactor);	// 부모의 기능, 공통 로그

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

	bIsOpened = true;	// 이제 이 상자는 열린 것
	PS->AddGold(GoldAmount);	// 재화 추가

	UE_LOG(LogThirdPersonRPG, Log, TEXT("Chest Opened -> %s"), *GetName());
}

FText AChestActor::GetInteractPrompt()
{
	return FText::FromString(TEXT("열기"));
}

bool AChestActor::CanInteract()
{
	return !bIsOpened;
}

void AChestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 상태에 따라 목표 각도 설정 (0도 일시 닫힘 판정)
	FRotator TargetRotation = FRotator::ZeroRotator;

	if (bIsOpened)
	{
		TargetRotation = FRotator(ChestOpenAngle, 0.0f, 0.0f);
	}

	// 현재 각도에서 목표 각도로
	FRotator NewRotation = FMath::RInterpTo(ChestPivot->GetRelativeRotation(),
		TargetRotation, DeltaTime, 2.0f);

	// 계산된 각도 적용 
	ChestPivot->SetRelativeRotation(NewRotation);
}