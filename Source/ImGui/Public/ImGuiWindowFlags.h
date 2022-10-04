// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ImGuiWindowFlags.generated.h"

USTRUCT(BlueprintType)
struct FImGuiWindowFlags
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Movable = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool Resizeable = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool NoCollapse = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool NoBackground = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool NoBringToFrontOnFocus = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool NoScrollbar = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool NoTitleBar = false;
};

UENUM(BlueprintType)
enum class EImGuiDir : uint8
{
	Left = 0,
	Right = 1,
	Up = 2,
	Down = 3
};
