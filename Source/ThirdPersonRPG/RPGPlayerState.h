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
	UFUNCTION(BlueprintPure, Category = "Currency")
	int32 GetGold() const;

	// 구매 시도(재화 충분하면 차감 후 true, 부족하면 false)
	bool TrySpendGold(int32 Amount);

protected:
	// 보유 재화
	UPROPERTY(VisibleAnywhere, Category = "Currency")
	int32 Gold = 0;
};
