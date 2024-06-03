// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "UnityResolve.hpp"
using I = UnityResolve;
using IM = UnityResolve::Method;
using IC = UnityResolve::Class;
using IT = UnityResolve::Type;
using IF = UnityResolve::Field;
using IA = UnityResolve::Assembly;
using II = UnityResolve::UnityType;

void Main() {
    UnityResolve::Init(GetModuleHandleA("GameAssembly.dll"), UnityResolve::Mode::Il2Cpp); //IL2Cpp Function :D
    UnityResolve::Assembly* pClass = UnityResolve::Get("Assembly-CSharp.dll");
    const auto carClass = pClass->Get("CareerConstants");
    carClass->SetValue<std::uint32_t>(nullptr, "s_startingCash", 99999999);
}
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(Main), 0, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

