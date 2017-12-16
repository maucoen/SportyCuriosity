// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SportyCuriosityGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class SPORTYCURIOSITY_API ASportyCuriosityGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	

public:
	ASportyCuriosityGameModeBase();


private:
	TSubclassOf<class UUserWidget> InputListClass;
	class UUserWidget* InputList;

	void ToggleViewport();

	virtual void StartPlay() override;

	bool bDraw = false;

};