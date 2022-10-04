// Fill out your copyright notice in the Description page of Project Settings.


#include "ImGuiBluePrint.h"

void UBPImGui::SetupInput()
{
	FImGuiModule::Get().GetProperties().SetKeyboardInputShared(true);
	FImGuiModule::Get().GetProperties().SetMouseInputShared(true);
}

void UBPImGui::ScaleAllSizes(float scale)
{
	ImGui::GetStyle().ScaleAllSizes(scale);
	ImGui::GetIO().FontGlobalScale = scale;
}

void UBPImGui::EnableInput()
{
	FImGuiModule::Get().GetProperties().SetInputEnabled(true);
}

void UBPImGui::BeginGUI(FString label, FVector2D pos, FVector2D pivot, FVector2D size, FImGuiWindowFlags flags)
{
	ImGuiWindowFlags windowFlags = 0;
	if (!flags.Movable)              windowFlags |= ImGuiWindowFlags_NoMove;
	if (!flags.Resizeable)           windowFlags |= ImGuiWindowFlags_NoResize;
	if (flags.NoCollapse)            windowFlags |= ImGuiWindowFlags_NoCollapse;
	if (flags.NoBackground)          windowFlags |= ImGuiWindowFlags_NoBackground;
	if (flags.NoBringToFrontOnFocus) windowFlags |= ImGuiWindowFlags_NoBringToFrontOnFocus;
	if (flags.NoScrollbar)           windowFlags |= ImGuiWindowFlags_NoScrollbar;
	if (flags.NoTitleBar)            windowFlags |= ImGuiWindowFlags_NoTitleBar;

	ImGuiCond movableCond = flags.Movable ? ImGuiCond_Once : ImGuiCond_Always;
	ImGuiCond resizableCond = flags.Resizeable ? ImGuiCond_Once : ImGuiCond_Always;

	ImGui::SetNextWindowPos(ImVec2(pos[0],pos[1]), movableCond, ImVec2(pivot[0], pivot[1]));
	ImGui::SetNextWindowSize(ImVec2(size[0], size[1]), resizableCond);

	ImGui::Begin(TCHAR_TO_UTF8(*label), nullptr, windowFlags);
}

void UBPImGui::EndGUI()
{
	ImGui::End();
}


bool UBPImGui::AddSliderFloat(FString label, float &v, float minValue, float maxValue)
{
	return ImGui::SliderFloat(TCHAR_TO_UTF8(*label), &v, minValue, maxValue);
}

bool UBPImGui::AddSliderFloat2(FString label, FVector2D &v, float minValue, float maxValue)
{
	float a[2] = {v.X, v.Y};
	auto r = ImGui::SliderFloat2(TCHAR_TO_UTF8(*label), a, minValue, maxValue);

	v = FVector2D(a[0],a[1]);

	return r;
}

bool UBPImGui::AddSliderFloat3(FString label, FVector &v, float minValue, float maxValue)
{
	float a[3] = {v.X, v.Y, v.Z};
	auto r = ImGui::SliderFloat3(TCHAR_TO_UTF8(*label), a, minValue, maxValue);

	v = FVector(a[0],a[1],a[2]);

	return r;
}

bool UBPImGui::AddSliderFloat4(FString label, FVector4 &v, float minValue, float maxValue)
{
	float a[4] = {v.X, v.Y, v.Z, v.W};
	auto r = ImGui::SliderFloat4(TCHAR_TO_UTF8(*label), a, minValue, maxValue);

	v = FVector4(a[0],a[1],a[2],a[3]);

	return r;
}

bool UBPImGui::AddSliderAngle(FString label, float &v)
{
	return ImGui::SliderAngle(TCHAR_TO_UTF8(*label), &v);
}

bool UBPImGui::AddSliderInt(FString label, int& v, int minValue, int maxValue)
{
	return ImGui::SliderInt(TCHAR_TO_UTF8(*label), &v, minValue, maxValue);
}

bool UBPImGui::AddSliderInt2(FString label, FIntPoint& v, int minValue, int maxValue)
{
	int a[2] = {v.X, v.Y};
	auto r = ImGui::SliderInt2(TCHAR_TO_UTF8(*label), a, minValue, maxValue);

	v = FIntPoint(a[0],a[1]);

	return r;
}

bool UBPImGui::AddSliderInt3(FString label, FIntVector& v, int minValue, int maxValue)
{
	int a[3] = {v.X, v.Y, v.Z};
	auto r = ImGui::SliderInt3(TCHAR_TO_UTF8(*label), a, minValue, maxValue);

	v = FIntVector(a[0], a[1], a[2]);

	return r;
}

bool UBPImGui::AddDragInt(FString label, int& v, int speed, int minValue, int maxValue)
{
	return ImGui::DragInt(TCHAR_TO_UTF8(*label), &v, speed, minValue, maxValue);
}

bool UBPImGui::AddDragIntRange(FString label, FIntPoint &v, int speed, int minValue, int maxValue)
{
	int x = v.X;
	int y = v.Y;
	auto r = ImGui::DragIntRange2(TCHAR_TO_UTF8(*label), &x, &y, speed, minValue, maxValue);
	v = FIntPoint(x, y);
	return r;
}

bool UBPImGui::AddDragFloat(FString label, float& v, float speed, float minValue, float maxValue)
{
	return ImGui::DragFloat(TCHAR_TO_UTF8(*label), &v, speed, minValue, maxValue);
}

bool UBPImGui::AddDragFloatRange(FString label, UPARAM(ref) FVector2D &v, float speed, float minValue, float maxValue)
{
	float x = v.X;
	float y = v.Y;
	auto r = ImGui::DragFloatRange2(TCHAR_TO_UTF8(*label), &x, &y, speed, minValue, maxValue);
	v = FVector2D(x, y);
	return r;
}

bool UBPImGui::AddCheckbox(FString label, bool& v)
{
	return ImGui::Checkbox(TCHAR_TO_UTF8(*label), &v);
}

bool UBPImGui::AddColor(FString label, FLinearColor& v)
{
	float col[4] = { v.R, v.G, v.B, v.A };
	auto r = ImGui::ColorEdit4(TCHAR_TO_UTF8(*label), col);
	v = FLinearColor(col[0], col[1], col[2], col[3]);

	return r;
}


bool UBPImGui::AddButton(FString label)
{
	return ImGui::Button(TCHAR_TO_UTF8(*label));
}

bool UBPImGui::AddSmallButton(FString label)
{
	return ImGui::SmallButton(TCHAR_TO_UTF8(*label));
}

bool UBPImGui::AddRadioButton(FString label, int &v, int value)
{
	return ImGui::RadioButton(TCHAR_TO_UTF8(*label), &v, value);
}

bool UBPImGui::AddArrowButton(FString strId, EImGuiDir dir)
{
	return ImGui::ArrowButton(TCHAR_TO_UTF8(*strId), (ImGuiDir)dir);
}

void UBPImGui::AddText(FString label)
{
	ImGui::Text(TCHAR_TO_UTF8(*label));
}

void UBPImGui::AddLabelText(FString label, FString text)
{
	ImGui::LabelText(TCHAR_TO_UTF8(*label), TCHAR_TO_UTF8(*text));
}

void UBPImGui::AddTextColored(FString label, FLinearColor color)
{
	ImGui::TextColored(ImVec4(color.R, color.G, color.B, color.A), TCHAR_TO_UTF8(*label));
}

void UBPImGui::AddBulletText(FString label)
{
	ImGui::BulletText(TCHAR_TO_UTF8(*label));
}

void UBPImGui::AddBullet()
{
	ImGui::Bullet();
}

void UBPImGui::PlotLines(FString label, TArray<float> array, int size)
{
	ImGui::PlotLines(TCHAR_TO_UTF8(*label), array.GetData(), size);
}


bool UBPImGui::AddCombo(FString label, int& v, TArray<FString> item)
{
	std::string c_item;

	for (int i = 0; i < item.Num(); i++)
	{
		c_item += TCHAR_TO_UTF8(*(item[i]));
		c_item.push_back('\0');
	}

	return ImGui::Combo(TCHAR_TO_UTF8(*label), &v, c_item.c_str(), item.Num());
}

bool UBPImGui::AddListBox(FString label, int& v, TArray<FString> item, int heightItem)
{
	std::string c_item;

	for (int i = 0; i < item.Num(); i++)
	{
		c_item += TCHAR_TO_UTF8(*(item[i]));
		c_item.push_back('\0');
	}

	return ImGui::ListBox(TCHAR_TO_UTF8(*label), &v, c_item.c_str(), heightItem);
}

bool UBPImGui::AddTextInput(FString label, FString& v, int size)
{
	char* buffer = new char[size];
	FMemory::Memcpy(buffer, TCHAR_TO_UTF8(*v), v.Len()+1);

	bool r = ImGui::InputText(TCHAR_TO_UTF8(*label), buffer, size, ImGuiInputTextFlags_CharsNoBlank);
	v = UTF8_TO_TCHAR(buffer);

	PreventKeyboardInput();
	delete[] buffer;

	return r;
}

bool UBPImGui::AddIntInput(FString label, int& v)
{
	auto r = ImGui::InputInt(TCHAR_TO_UTF8(*label), &v);
	PreventKeyboardInput();
	return r;
}

bool UBPImGui::AddFloatInput(FString label, float& v, float step, float stepFast)
{
	auto r = ImGui::InputFloat(TCHAR_TO_UTF8(*label), &v, step, stepFast);
	PreventKeyboardInput();
	return r;
}


bool UBPImGui::BeginTreeNodes(FString label, bool open)
{
	ImGui::SetNextItemOpen(open, ImGuiCond_Once);
	return ImGui::TreeNode(TCHAR_TO_UTF8(*label));
}

void UBPImGui::EndTreeNode()
{
	ImGui::TreePop();
}

void UBPImGui::Separator()
{
	ImGui::Separator();
}

void UBPImGui::SameLine(float offset, float spacing)
{
	ImGui::SameLine(offset, spacing);
}

void UBPImGui::Spacing()
{
	ImGui::Spacing();
}

void UBPImGui::BeginGroup()
{
	ImGui::BeginGroup();
}

void UBPImGui::EndGroup()
{
	ImGui::EndGroup();
}

void UBPImGui::SetItemWidth(float width)
{
	ImGui::SetNextItemWidth(width);
}

bool UBPImGui::CollapsingHeader(FString label, bool open)
{
	ImGui::SetNextItemOpen(open, ImGuiCond_Once);
	return ImGui::CollapsingHeader(TCHAR_TO_UTF8(*label));
}

void UBPImGui::HelpMaker(FString desc, bool sameLine)
{
	if (sameLine) ImGui::SameLine();

	ImGui::TextDisabled("(?)");
	if (ImGui::IsItemHovered())
	{
		ImGui::BeginTooltip();
		ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
		ImGui::TextUnformatted(TCHAR_TO_UTF8(*desc));
		ImGui::PopTextWrapPos();
		ImGui::EndTooltip();
	}
}

float UBPImGui::CalcItemWidth()
{
	return ImGui::CalcItemWidth();
}

FVector2D UBPImGui::CalcTextSize(FString text)
{
	auto r = ImGui::CalcTextSize(TCHAR_TO_UTF8(*text));
	return FVector2D(r.x, r.y);
}

float UBPImGui::GetFontSize()
{
	return ImGui::GetFontSize();
}

void UBPImGui::PreventKeyboardInput()
{
	if (ImGui::IsItemActive())
	{
		FImGuiModule::Get().GetProperties().SetKeyboardInputShared(false);
	}
	else
	{
		FImGuiModule::Get().GetProperties().SetKeyboardInputShared(true);
	}
}