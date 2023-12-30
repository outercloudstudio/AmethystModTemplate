#include <Windows.h>
#include <stdint.h>
#include <iostream>
#include <fstream>
#include <chrono>

#include <amethyst/Log.h>
#include <amethyst/HookManager.h>

#include <minecraft/src/common/world/item/Item.h>
#include <minecraft/src-client/common/client/renderer/screen/MinecraftUIRenderContext.h>
#include <minecraft/src-client/common/client/gui/ScreenView.h>
#include <minecraft/src-client/common/client/renderer/TexturePtr.h>
#include <minecraft/src-deps/core/string/StringHash.h>
#include <minecraft/src/common/world/item/ItemStackBase.h>

HookManager hookManager;

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    return TRUE;
}

extern "C" __declspec(dllexport) void Initialize(const char* gameVersion) {
    MH_Initialize();
}

extern "C" __declspec(dllexport) void Shutdown() {
    hookManager.Shutdown();
}