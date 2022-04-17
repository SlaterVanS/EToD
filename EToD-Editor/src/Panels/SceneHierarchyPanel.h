#pragma once

#include "ETOD/Core/Core.h"
#include "ETOD/Core/Log.h"
#include "ETOD/Scene/Scene.h"

#include "ETOD/Scene/Entity.h"

namespace ETOD {

	class SceneHierarchyPanel
	{
	public:
		SceneHierarchyPanel() = default;
		SceneHierarchyPanel(const Ref<Scene>& scene);

		void SetContext(const Ref<Scene>& scene);

		void OnImGuiRender();
	private:
		void DrawEntityNode(Entity entity);
		void DrawComponents(Entity entity);
	private:
		Ref<Scene> m_Context;
		Entity m_SelectionContext;
	};

}