// Fill out your copyright notice in the Description page of Project Settings.

#include "SportyCuriosityGameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

ASportyCuriosityGameModeBase::ASportyCuriosityGameModeBase()
	: Super()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/msl/Curiosity"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	ConstructorHelpers::FClassFinder<UUserWidget> InputClassBP(TEXT("/Game/msl/WBP_InputsList"));
	if (InputClassBP.Class)
	{
		InputListClass = InputClassBP.Class;
	}
}

void ASportyCuriosityGameModeBase::StartPlay()
{
	Super::StartPlay();

	if (InputListClass)
	{
		InputList = CreateWidget<UUserWidget>(GetGameInstance(), InputListClass);
	}


	if (InputList)
	{
		InputList->AddToViewport();
	}

	auto Controller = UGameplayStatics::GetPlayerController(this, 0);

	if (Controller)
	{
		InputComponent = NewObject<UInputComponent>(this);
		if (InputComponent)
		{
			InputComponent->BindKey(EKeys::M, EInputEvent::IE_Pressed, this, &ASportyCuriosityGameModeBase::ToggleViewport);
			EnableInput(Controller);
		}
	}
}


void ASportyCuriosityGameModeBase::ToggleViewport()
{
	if (bDraw)
	{
		InputList->AddToViewport();
	}

	else
	{
		InputList->RemoveFromViewport();
	}
	bDraw = !bDraw;
}


