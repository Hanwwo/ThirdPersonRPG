// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorActor.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"



ADoorActor::ADoorActor()
{
	// 경첩 (회전축) 생성 후 이 액터의 루트로 지정
	DoorPivot = CreateDefaultSubobject<USceneComponent>(TEXT("DoorPivot"));
	RootComponent = DoorPivot;

	// 큐브(임시)를 경첩의 자식으로 매달기
	MeshComp->SetupAttachment(DoorPivot);

	// 큐브(임시)를 문 모양으로
	MeshComp->SetRelativeScale3D(FVector(0.1f, 1.0f, 2.0f));

	// 큐브를 옆으로 절반만큼 밀어, 경첩이 큐브 가장자리에 오게 만들기
	MeshComp->SetRelativeLocation(FVector(0.0f, 50.0f, 0.0f));
}

void ADoorActor::Interact(AActor* Interactor)
{
	Super::Interact(Interactor);  // 부모 함수 사용하기

	SetActorRotation(FRotator(0.0f, 90.0f, 0.0f));
}

