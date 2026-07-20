// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "InteractableActor.generated.h"


UCLASS()
class THIRDPERSONRPG_API AInteractableActor : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractableActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// 눈에 보이는 몸 (모양은 각 자식이 지정)
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshComp;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	// IInteractable 계약 이행 : 이 액터 상호작용 정의하기
	virtual void Interact(AActor* Interactor) override;

};
