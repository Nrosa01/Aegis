#pragma once

#ifndef UI_SYSTEM_H
#define UI_SYSTEM_H

#include "Singleton.h"
#include "WindowManager.h"
#include "LuaManager.h"
#include <vector>

class OgreOverlay;
class SDL_Image; 
class UIObject;
class InputSystem;

namespace Ogre {
	class OverlayManager;
	class OverlaySystem;
	class Overlay;
	class SceneManager;
}

class UISystem : public Singleton<UISystem> {
private:
	WindowManager* windowManager = nullptr;
	Ogre::OverlayManager* overlayMng = nullptr;
	Ogre::OverlaySystem* overlaySys = nullptr;
	Ogre::Overlay* overlay = nullptr;

	std::vector<UIObject*>ui_objects;

	void addUIObject(UIObject* object_);
public:
	UISystem(Ogre::SceneManager* mScene, WindowManager* window);
	~UISystem();
	void free();
	UIObject* createUIElem(luabridge::LuaRef luaref);
	void deleteUIObject(const UIObject* obj_);
	void update(float deltaTime);
	// Aqui se pueden a�adir otros eventos como onClickRelease y demas, 
	// En concreto onClickRelease podria ser util para implementar un slider
	// o un draggable
	void onClickEvent();
	InputSystem* getInputSystem();
	WindowManager* getWindowManager();
	Ogre::Overlay* getOverlay();
	


	static void ConvertToLua(lua_State* state);
};

# endif