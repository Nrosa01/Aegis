#include "Scene.h"
#include "Entity.h"
#include "Scripting.h"

using namespace luabridge;

void Scene::InitEntities()
{
	for (Entity* entity : *uninitializedEntities)
	{
		entity->init();
	}

	uninitializedEntities->clear();
}

// Es posible que aqui queramos inicializar una escena de ogre y sincronizarla con las entidades
Scene::Scene(Ogre::SceneNode* ogreNode) :
	accumulator(0), entities(new std::list<Entity*>()), entitiesToDelete(std::list<std::list<Entity*>::iterator>()) , ogreNode(ogreNode), uninitializedEntities(new std::list<Entity*>())
{
}

Scene::~Scene() {
	for (Entity* entity : *entities)
	{
		delete entity;
	}

	delete this->entities;

	RemoveAndFreePendingEntities();
}

void Scene::RemoveAndFreeEntity(std::list<Entity*>::iterator entity) {
	delete *entity;
	this->entities->erase(entity);
}

void Scene::RemoveAndFreePendingEntities() {
	for (std::list<Entity*>::iterator entity : entitiesToDelete)
		RemoveAndFreeEntity(entity);

	this->entitiesToDelete.clear();
}

void Scene::AddEntity(Entity* entity)
{
	this->uninitializedEntities->push_back(entity);
	this->entities->push_back(entity);
}

void Scene::DestroyEntity(std::list<Entity*>::iterator entity) {
	this->entitiesToDelete.push_back(entity);
}

void Scene::FixedUpdate(float dt) {
	accumulator += dt;
	while (accumulator >= PHYSICS_STEP)	{
		// Call entities physics update
		//for (Entity* entity : *entities)
			//entity->integrate();
		accumulator -= PHYSICS_STEP;
	}
}

void Scene::Update(float dt) {
	for (Entity* entity : *entities)
		entity->update(dt);
}

void Scene::LateUpdate(float dt) {
	for (Entity* entity : *entities)
		entity->lateUpdate(dt);
}

void Scene::UpdateScene(float dt) {
	// Esto hay que moverlo al update de la aplicacion, por ahora esta aqui
	// Es decir, en caso de que el update scene se complete mas rapido de lo esperado
	// Hay que esperar antes del siguiente update
	//double current = getCurrentTime();
	//double elapsed = current - previousFrameTime;
	//previousFrameTime = current;
	InitEntities();
	FixedUpdate(dt);
	Update(dt);
	LateUpdate(dt);
	RemoveAndFreePendingEntities();
}

void Scene::Render()
{
	for (Entity* entity : *entities)
		entity->render();
}

//the ogreNode usually is the root scene node so we add this node as a child one
Ogre::SceneNode* Scene::GetOgreNode()
{
	return ogreNode->createChildSceneNode(); 
}

void Scene::ConvertToLua(lua_State* state)
{
	getGlobalNamespace(state).
		beginNamespace("Aegis").
			beginClass<Scene>("Scene").
				addFunction("AddEntity", &Scene::AddEntity).
			endClass().
		endNamespace();
}