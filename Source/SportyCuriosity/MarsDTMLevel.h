// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "MarsDTMLevel.generated.h"

/**
*
*/
UCLASS()
class SPORTYCURIOSITY_API AMarsDTMLevel : public ALevelScriptActor
{
	GENERATED_BODY()

public:
	//Actor interface override
	void BeginPlay() override;
	
private:
	class UGameInstance* Game;
	
	APlayerController* Controller;
	
	void InLoadMenu();

	void Quit();
};
