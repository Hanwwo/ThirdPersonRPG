// Fill out your copyright notice in the Description page of Project Settings.


#include "RPGPlayerState.h"
#include "ThirdPersonRPG.h"

void ARPGPlayerState::AddGold(int32 Amount)
{
	Gold += Amount;

	UE_LOG(LogThirdPersonRPG, Log, TEXT("Gold Added -> %d (Total: %d)"), Amount, Gold);
}

int32 ARPGPlayerState::GetGold() const
{
	return Gold;
}

bool ARPGPlayerState::TrySpendGold(int32 Amount)
{
	// 재화 부족하면 거래 실패
	if (Gold < Amount)
	{
		UE_LOG(LogThirdPersonRPG, Log, TEXT("Not Enough Gold (Have : %d, Need : %d)"), Gold, Amount);
		return false;
	}

	Gold -= Amount;

	UE_LOG(LogThirdPersonRPG, Log, TEXT("%d Gold Spent(Remain : %d)"), Amount, Gold);
	return true;
}