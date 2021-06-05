// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SarumanUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class SARUMAN_API USarumanUserWidget : public UUserWidget
{
	GENERATED_BODY()

	public:

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnHealthChanged(float health);
};
