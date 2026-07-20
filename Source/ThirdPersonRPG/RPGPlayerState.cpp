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