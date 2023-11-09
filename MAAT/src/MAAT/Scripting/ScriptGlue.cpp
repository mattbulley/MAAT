#include "mtpch.h"
#include "ScriptGlue.h"
#include "ScriptEngine.h"

#include "MAAT/Core/UUID.h"
#include "MAAT/Core/KeyCodes.h"
#include "MAAT/Core/Input.h"

#include "MAAT/Scene/Scene.h"
#include "MAAT/Scene/Entity.h"

#include "mono/metadata/object.h"

namespace MAAT {

#define MAAT_ADD_INTERNAL_CALL(Name) mono_add_internal_call("MAAT.InternalCalls::" #Name, Name)

	static void NativeLog(MonoString* string, int parameter)
	{
		char* cStr = mono_string_to_utf8(string);
		std::string str(cStr);
		mono_free(cStr);
		std::cout << str << ", " << parameter << std::endl;
	}

	static void NativeLog_Vector(glm::vec3* parameter, glm::vec3* outResult)
	{
		MAAT_CORE_WARN("Value: {0}", *parameter);
		*outResult = glm::normalize(*parameter);
	}

	static float NativeLog_VectorDot(glm::vec3* parameter)
	{
		MAAT_CORE_WARN("Value: {0}", *parameter);
		return glm::dot(*parameter, *parameter);
	}

	static void Entity_GetTranslation(UUID entityID, glm::vec3* outTranslation)
	{
		Scene* scene = ScriptEngine::GetSceneContext();
		Entity entity = scene->GetEntityByUUID(entityID);
		*outTranslation = entity.GetComponent<TransformComponent>().Translation;
	}

	static void Entity_SetTranslation(UUID entityID, glm::vec3* translation)
	{
		Scene* scene = ScriptEngine::GetSceneContext();
		Entity entity = scene->GetEntityByUUID(entityID);
		entity.GetComponent<TransformComponent>().Translation = *translation;
	}

	static bool Input_IsKeyDown(KeyCode keycode)
	{
		return Input::IsKeyPressed(keycode);
	}

	void ScriptGlue::RegisterFunctions()
	{
		MAAT_ADD_INTERNAL_CALL(NativeLog);
		MAAT_ADD_INTERNAL_CALL(NativeLog_Vector);
		MAAT_ADD_INTERNAL_CALL(NativeLog_VectorDot);

		MAAT_ADD_INTERNAL_CALL(Entity_GetTranslation);
		MAAT_ADD_INTERNAL_CALL(Entity_SetTranslation);

		MAAT_ADD_INTERNAL_CALL(Input_IsKeyDown);
	}
}