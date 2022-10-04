// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ImGuiCommon.h"
#include "ImGuiWindowFlags.h"
#include "ImGuiBluePrint.generated.h"

UCLASS()
class UBPImGui : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "ImGui")
	static void SetupInput();

	UFUNCTION(BlueprintCallable, Category = "ImGui", meta = (ToolTip = "Call it only once during geme initialization, e.g. BeginPlay"))
	static void ScaleAllSizes(float scale = 1.0f);

	UFUNCTION(BlueprintCallable, Category = "ImGui")
	static void EnableInput();
	
	UFUNCTION(BlueprintCallable, Category = "ImGui")
	static void BeginGUI(FString label, FVector2D pos, FVector2D pivot, FVector2D size, FImGuiWindowFlags flags);

	UFUNCTION(BlueprintCallable, Category = "ImGui")
	static void EndGUI();


	UFUNCTION(BlueprintCallable, Category = "ImGui|Widget")
	static bool AddSliderFloat(FString label, UPARAM(ref) float &v, float minValue, float maxValue);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Widget")
	static bool AddSliderFloat2(FString label, UPARAM(ref) FVector2D &v, float minValue, float maxValue);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Widget")
	static bool AddSliderFloat3(FString label, UPARAM(ref) FVector &v, float minValue, float maxValue);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Widget")
	static bool AddSliderFloat4(FString label, UPARAM(ref) FVector4 &v, float minValue, float maxValue);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Widget")
	static bool AddSliderAngle(FString label, UPARAM(ref) float &v);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Widget")
	static bool AddSliderInt(FString label, UPARAM(ref) int &v, int minValue, int maxValue);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Widget")
	static bool AddSliderInt2(FString label, UPARAM(ref) FIntPoint &v, int minValue, int maxValue);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Widget")
	static bool AddSliderInt3(FString label, UPARAM(ref) FIntVector &v, int minValue, int maxValue);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Widget")
	static bool AddDragInt(FString label, UPARAM(ref) int &v, int speed = 1, int minValue = 0, int maxValue = 0);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Widget")
	static bool AddDragIntRange(FString label, UPARAM(ref) FIntPoint &v, int speed = 1, int minValue = 0, int maxValue = 0);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Widget")
	static bool AddDragFloat(FString label, UPARAM(ref) float &v, float speed = 1.0f, float minValue = 0.0f, float maxValue = 0.0f);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Widget")
	static bool AddDragFloatRange(FString label, UPARAM(ref) FVector2D &v, float speed = 1.0f, float minValue = 0.0f, float maxValue = 0.0f);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Widget")
	static bool AddCheckbox(FString label, UPARAM(ref) bool& v);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Widget")
	static bool AddColor(FString label, UPARAM(ref) FLinearColor& v);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Widget")
	static bool AddRadioButton(FString label, UPARAM(ref) int& v, int value);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Widget")
	static bool AddButton(FString label);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Widget")
	static bool AddSmallButton(FString label);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Widget")
	static bool AddArrowButton(FString strId, EImGuiDir dir);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Widget")
	static bool AddCombo(FString label, UPARAM(ref) int &v, TArray<FString> item);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Widget")
	static bool AddListBox(FString label, UPARAM(ref) int &v, TArray<FString> item, int heightItem = 4);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Widget")
	static void AddText(FString label);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Widget")
	static void AddLabelText(FString label, FString text);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Widget")
	static void AddTextColored(FString label, FLinearColor color);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Widget")
	static void AddBulletText(FString label);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Widget")
	static void AddBullet();

	UFUNCTION(BlueprintCallable, Category = "ImGui|Widget")
	static void PlotLines(FString label, TArray<float> array, int size);


	UFUNCTION(BlueprintCallable, Category = "ImGui|Widget|Input")
	static bool AddTextInput(FString label, UPARAM(ref) FString &v, int size = 64);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Widget|Input")
	static bool AddIntInput(FString label, UPARAM(ref) int &v);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Widget|Input")
	static bool AddFloatInput(FString label, UPARAM(ref) float &v, float step, float stepFast);


	UFUNCTION(BlueprintCallable, Category = "ImGui|Layout")
	static bool BeginTreeNodes(FString label, bool open);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Layout")
	static void EndTreeNode();

	UFUNCTION(BlueprintCallable, Category = "ImGui|Layout")
	static void Separator();

	UFUNCTION(BlueprintCallable, Category = "ImGui|Layout")
	static void SameLine(float offset = 0.0f, float spacing = -1.0f);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Layout")
	static void Spacing();

	UFUNCTION(BlueprintCallable, Category = "ImGui|Layout")
	static void BeginGroup();

	UFUNCTION(BlueprintCallable, Category = "ImGui|Layout")
	static void EndGroup();

	UFUNCTION(BlueprintCallable, Category = "ImGui|Layout")
	static void SetItemWidth(float width);

	UFUNCTION(BlueprintCallable, Category = "ImGui|Layout")
	static bool CollapsingHeader(FString label, bool open);


	UFUNCTION(BlueprintCallable, Category = "ImGui|Utility")
	static void HelpMaker(FString label, bool saneLine);

	UFUNCTION(BlueprintPure, Category = "ImGui|Utility")
	static float CalcItemWidth();

	UFUNCTION(BlueprintPure, Category = "ImGui|Utility")
	static FVector2D CalcTextSize(FString text);

	UFUNCTION(BlueprintPure, Category = "ImGui|Utility")
	static float GetFontSize();

private:
	static void PreventKeyboardInput();
};
