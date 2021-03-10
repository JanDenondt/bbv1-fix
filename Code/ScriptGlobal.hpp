#pragma once
#include "Game.hpp"

namespace Big
{
	class ScriptGlobal
	{
	public:
		constexpr explicit ScriptGlobal(std::size_t index):
			m_Index(index)
		{}

		constexpr ScriptGlobal Add(std::size_t index)
		{
			return ScriptGlobal(m_Index + index);
		}

		constexpr ScriptGlobal Add(std::size_t index, std::size_t x)
		{
			return Add(1 + (index * x));
		}

		template <typename T>
		std::enable_if_t<std::is_pointer<T>::value, T> As() const
		{
			return reinterpret_cast<T>(IndexToPtr(m_Index));
		}

		template <typename T>
		std::enable_if_t<std::is_lvalue_reference<T>::value, T> As() const
		{
			return *reinterpret_cast<std::add_pointer_t<std::remove_reference_t<T>>>(IndexToPtr(m_Index));
		}

		template <typename T>
		std::enable_if_t<std::is_same<T, std::uintptr_t>::value, T> As() const
		{
			return reinterpret_cast<std::uintptr_t>(As<void*>());
		}
	private:
		static void* IndexToPtr(std::size_t index)
		{
			return (g_GameVariables->m_GlobalBase[index >> 0x12 & 0x3F]) + (index & 0x3FFFF);
		}

		std::uintptr_t m_Index;
	};

	class globalHandle /*For the Nano bois*/
	{
	private:
		void* _handle;
		std::uint64_t** IndexToPtr()
		{
			return g_GameVariables->m_GlobalBase;
		}

	public:
		globalHandle(int index)
			: _handle(&IndexToPtr()[index >> 18 & 0x3F][index & 0x3FFFF])
		{ }

		globalHandle(void* p)
			: _handle(p)
		{ }

		globalHandle(const globalHandle& copy)
			: _handle(copy._handle)
		{ }

		globalHandle At(int index)
		{
			return globalHandle(reinterpret_cast<void**>(this->_handle) + (index));
		}

		globalHandle At(int index, int size)
		{
			// Position 0 = Array Size
			return this->At(1 + (index * size));
		}

		template <typename T>
		T* Get()
		{
			return reinterpret_cast<T*>(this->_handle);
		}

		template <typename T>
		T& As()
		{
			return *this->Get<T>();
		}
	};

	class script_global /*For the bbv2 bois*/
	{
	public:
		explicit script_global(std::size_t index);

		script_global at(std::ptrdiff_t index);
		script_global at(std::ptrdiff_t index, std::size_t size);

		template <typename T>
		std::enable_if_t<std::is_pointer_v<T>, T> as()
		{
			return static_cast<T>(get());
		}

		template <typename T>
		std::enable_if_t<std::is_lvalue_reference_v<T>, T> as()
		{
			return *static_cast<std::add_pointer_t<std::remove_reference_t<T>>>(get());
		}
	private:
		void* get();
		std::size_t m_index;
	};
}
