#include "Game.hpp"
#include "Invoker.hpp"

namespace Big
{
	GameVariables::GameVariables():
		m_GameState(Signature("83 3D ? ? ? ? ? 75 17 8B 42 20 25").Scan().Add(2).Rip().As<decltype(m_GameState)>()),
		m_FrameCount(Signature("F3 0F 10 0D ? ? ? ? 44 89 6B 08").Scan().Add(4).Rip().Sub(8).As<decltype(m_GameState)>()),
		m_ModelSpawnBypass(Signature("48 8B C8 FF 52 30 84 C0 74 05 48").Scan().Add(8).As<decltype(m_ModelSpawnBypass)>()),
		m_WorldPointer(Signature(("48 8B C3 48 83 C4 20 5B C3 0F B7 05 ? ? ? ?")).Scan().Sub(11).Add(3).Rip().As<decltype(m_WorldPointer)>()),
		m_GameWindow(FindWindowA("grcWindow", "Grand Theft Auto V")),
		m_Swapchain(Signature("48 8B 0D ? ? ? ? 48 8B 01 44 8D 43 01 33 D2 FF 50 40 8B C8").Scan().Add(3).Rip().As<decltype(m_Swapchain)&>()),
		m_NativeRegistrations(Signature("48 83 EC 20 48 8D 0D ? ? ? ? E8 ? ? ? ? 0F B7 15 ? ? ? ? 33 FF").Scan().Add(7).Rip().As<decltype(m_NativeRegistrations)>()),
		m_NativeReturn(Signature("FF E3").Scan().Add(0).As<decltype(m_NativeReturn)>()),
		m_GlobalBase(Signature("4C 8D 4D 08 48 8D 15 ? ? ? ? 4C 8B C0").Scan().Add(7).Rip().As<decltype(m_GlobalBase)>()),
		m_ScriptGlobals(Signature(("48 8D 15 ? ? ? ? 4C 8B C0 E8 ? ? ? ? 48 85 FF 48 89 1D")).Scan().Add(3).Rip().As<decltype(m_ScriptGlobals)>()),
		m_Is_Session_Started(Signature(("40 38 35 ? ? ? ? 75 0E 4C 8B C3 49 8B D7 49 8B CE")).Scan().Add(3).Rip().As<decltype(m_Is_Session_Started)>())
	{
		auto sig = Signature("48 83 EC 60 48 8D 0D ? ? ? ? E8").Scan().Sub(17);
		m_GameBuild = sig.Add(265 + 3).Rip().As<decltype(m_GameBuild)>();
	}

	void GameVariables::PostInit()
	{
	}

	GameFunctions::GameFunctions():
		m_Fix_Vectors(Signature("83 79 18 00 48 8B D1 74 4A FF 4A 18 48 63 4A 18 48 8D 41 04 48 8B 4C CA").Scan().As<decltype(m_Fix_Vectors)>()),
		m_IsDlcPresent(Signature("84 C0 74 0D 8D 53 0C").Scan().Sub(63).As<decltype(m_IsDlcPresent)>()),
		m_WndProc(Signature("48 8B 0D ? ? ? ? 48 8D 55 EF FF 15").Scan().Sub(853).As<decltype(m_WndProc)>()),
		m_GetEventData(Signature("48 85 C0 74 14 4C 8B 10").Scan().Sub(28).As<decltype(m_GetEventData)>()),
		m_GetLabelText(Signature("75 ? E8 ? ? ? ? 8B 0D ? ? ? ? 65 48 8B 04 25 ? ? ? ? BA ? ? ? ? 48 8B 04 C8 8B 0C 02 D1 E9").Scan().Sub(19).As<decltype(m_GetLabelText)>())
	{
	}
}
