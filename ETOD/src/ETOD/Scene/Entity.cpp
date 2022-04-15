#include "etodpch.h"
#include "Entity.h"

namespace ETOD {

	Entity::Entity(entt::entity handle, Scene* scene)
		: m_EntityHandle(handle), m_Scene(scene)
	{

	}
}