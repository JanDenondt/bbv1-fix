#include "Functions.hpp"
#include "../Natives.hpp"
#include "../ScriptGlobal.hpp"
#include "../MemoryManager.hpp"

namespace Big::Functions
{
	void FunctionLoop()
	{
		/*Self Options*/
		GodMode(godmode);
	}

	/*Self Options*/
	bool godmode = false;
	void GodMode(bool enable)
	{
		Memory::set_value<bool>({ 0x08, 0x189 }, enable); // Memory, might change next update
		//ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(), enable); // Native method
	
	}
}