// Fill out your copyright notice in the Description page of Project Settings.

#include "MarsDTMLevel.h"
#include "Kismet/GameplayStatics.h"
#include "InputCoreTypes.h"
#include "TimerManager.h"
#include "Engine.h"

void AMarsDTMLevel::BeginPlay()
{
	Super::BeginPlay();

	Controller = UGameplayStatics::GetPlayerController(this, 0);

	if (Controller)
	{
		InputComponent = NewObject<UInputComponent>(this);
		if (InputComponent)
		{
	
			InputComponent->BindKey(EKeys::Escape, EInputEvent::IE_Pressed, this, &AMarsDTMLevel::InLoadMenu);
		}
	}
}

void AMarsDTMLevel::InLoadMenu()
{
	
	if (GEngine) { GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, TEXT("Bye bye!"), true, FVector2D(2, 2)); }
	FTimerHandle GameStartTimer;

	GetWorldTimerManager().SetTimer(GameStartTimer, this, &AMarsDTMLevel::Quit, 2);
}

void AMarsDTMLevel::Quit()
{
	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	APlayerController* PlayerController = World->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	PlayerController->ConsoleCommand("quit");
}
