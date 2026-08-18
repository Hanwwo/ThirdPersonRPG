// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorActor.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"



ADoorActor::ADoorActor()
{
	PrimaryActorTick.bCanEverTick = true;	// 액터의 Tick 켜기

	// 경첩 (회전축) 생성 후 이 액터의 루트로 지정
	DoorPivot = CreateDefaultSubobject<USceneComponent>(TEXT("DoorPivot"));
	RootComponent = DoorPivot;

	// 큐브(임시)를 경첩의 자식으로 매달기
	MeshComp->SetupAttachment(DoorPivot);
}

void ADoorActor::BeginPlay()
{
	Super::BeginPlay();

	// 레벨에 배치된 각도를 기억해 닫힘 상태로 유지시키기
	ClosedRotation = GetActorRotation();
}
void ADoorActor::Interact(AActor* Interactor)
{
	Super::Interact(Interactor);  // 부모 함수 사용하기

	bDoorOpen = !bDoorOpen;
}

void ADoorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 상태에 따라 목표 각도 설정 (열림, 닫힘)
	FRotator TargetRotation = ClosedRotation;
	
	if (bDoorOpen)
	{
		TargetRotation = ClosedRotation + FRotator(0.0f, -90.0f, 0.0f);
	}

	// 현재 각도에서 목표 각도로
	FRotator NewRotation = FMath::RInterpTo(GetActorRotation(), TargetRotation, DeltaTime, 4.0f);

	// 계산된 각도 적용
	SetActorRotation(NewRotation);
}
FText ADoorActor::GetInteractPrompt()
{
	if (bDoorOpen)
	{
		return FText::FromString(TEXT("닫기"));
	}
	else
	{
		return FText::FromString(TEXT("열기"));
	}
}


