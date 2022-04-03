
#include "Component.h"
#include "../Entity/Entity.h"

Component::Component(): 
	mEntity_(nullptr), isActive_(true)
{
	
}

Component::Component(std::string componentName, Entity* entity) : componentName(componentName), mEntity_(entity), isActive_(true) {}

void Component::ConvertToLua(lua_State* state)
{
	getGlobalNamespace(state).
		beginNamespace("Aegis").
		beginClass<Component>("ComponentBase").
		addProperty("name", &Component::GetComponentName, &Component::SetComponentNameLua).
		addProperty("entity", &Component::GetEntity, &Component::setEntityLua).
		endClass().
		endNamespace();
}
