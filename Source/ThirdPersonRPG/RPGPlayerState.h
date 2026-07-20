// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "RPGPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class THIRDPERSONRPG_API ARPGPlayerState : public APlayerState
{
	GENERATED_BODY()
	

public: 
	// 재화 획득
	void AddGold(int32 Amount);

	// 현재 재화 확인
	int32 GetGold() const;

protected:
	// 보유 재화
	UPROPERTY(VisibleAnywhere, Category = "Currency")
	int32 Gold = 0;
};
