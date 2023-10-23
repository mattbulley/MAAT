#include "mtpch.h"
#include "Entity.h"

namespace MAAT {

	Entity::Entity(entt::entity handle, Scene* scene)
		: m_EntityHandle(handle), m_Scene(scene)
	{

	}
}