#pragma once

#define WITH_IMGUI 1
// #ifdef IMGUI_API
// #else
// #define WITH_IMGUI 0
// #endif // IMGUI_API

#if WITH_IMGUI
#include <ImGuiModule.h>
#include <ImGuiDelegates.h>

#include <imgui.h>
#endif // WITH_IMGUI