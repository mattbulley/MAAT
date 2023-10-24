#pragma once

#include "MAAT/Core/Core.h"
#include "MAAT/Core/Log.h"
#include "MAAT/Scene/Scene.h"
#include "MAAT/Scene/Entity.h"

namespace MAAT {

	class SceneHierarchyPanel
	{
	public:
		SceneHierarchyPanel() = default;
		SceneHierarchyPanel(const Ref<Scene>& scene);

		void SetContext(const Ref<Scene>& scene);

		void OnImGuiRender();
	private:
		void DrawEntityNode(Entity entity);
	private:
		Ref<Scene> m_Context;
		Entity m_SelectionContext;
	};

}