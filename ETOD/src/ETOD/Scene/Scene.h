#pragma once

#include "entt.hpp"

#include "ETOD/Core/Timestep.h"

namespace ETOD {

	class Entity;
	class Scene
	{
	public:
		Scene();
		~Scene();

		Entity CreateEntity(const std::string& name = std::string());

		void OnUpdata(Timestep ts);
	private:
		entt::registry m_Registry;

		friend class Entity;
	};

}