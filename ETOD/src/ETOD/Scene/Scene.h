#pragma once

#include "entt.hpp"

#include "ETOD/Core/Timestep.h"

namespace ETOD {

	class Scene
	{
	public:
		Scene();
		~Scene();

		entt::entity CreateEntity();

		// TEMP
		entt::registry& Reg() { return m_Registry; }

		void OnUpdata(Timestep ts);
	private:
		entt::registry m_Registry;
	};

}