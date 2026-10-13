// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorActor.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "ThirdPersonRPG.h"



ADoorActor::ADoorActor()
{
	PrimaryActorTick.bCanEverTick = true;	// 액터의 Tick 켜기

	// 경첩 (회전축) 생성 후 이 액터의 루트로 지정
	DoorPivot = CreateDefaultSubobject<USceneComponent>(TEXT("DoorPivot"));
	RootComponent = DoorPivot;

	// 문 메쉬를 경첩의 자식으로 매달기
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


	// 닫힌 문을 열 때만 방향을 새로 정하기
	if (bDoorOpen == false && Interactor != nullptr)
	{
		// 문에서 상호작용한 대상을 향하는 방향
		FVector ToInteractor = Interactor->GetActorLocation() - GetActorLocation();

		// 이 문 메시는 Y축이 앞뒤 방향이므로, Y축 기준으로 판단함
		// 액터의 Y축 방향과 액터에서 캐릭터를 향하는 방향의 두 방향이 이루는 각이 90도보다 좁으면 양수, 넓으면 음수
		float Dot = FVector::DotProduct(GetActorRightVector(), ToInteractor);

		// 대상의 반대쪽으로 열리도록 각도 부호 결정하기
		if (Dot > 0.0f)
		{
			OpenAngle = -90.0f;
		}
		else
		{
			OpenAngle = 90.0f;
		}
	}

	bDoorOpen = !bDoorOpen;
}

void ADoorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 상태에 따라 목표 각도 설정 (열림, 닫힘)
	FRotator TargetRotation = ClosedRotation;
	
	if (bDoorOpen)
	{
		TargetRotation = ClosedRotation + FRotator(0.0f, OpenAngle, 0.0f);
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


