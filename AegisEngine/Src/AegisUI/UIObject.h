#pragma once
#include <string>
//Im�genes renderizadas a partir de una textura
//En esta clase se a�ade la posici�n x e y

namespace Ogre {
	class OverlayContainer;
	class OverlayManager;
	class OverlaySystem;
	class Overlay;
}

//enum de metricas?


class UIObject {
protected:
	Ogre::OverlayManager* overlayMng =nullptr;
	Ogre::OverlayContainer* overlayCont = nullptr;
	Ogre::Overlay* overlay = nullptr;

	Ogre::OverlaySystem* overlaySys = nullptr; //no esta inicializado
private:

	double x, y, w, h;
	std::string material;
	std::string name;


public:
	UIObject(const std::string& n, int order);
	virtual ~UIObject();

	void show();
	void hide();

	//void setMetricsMode(MetricsMode mmode);
	void setPosition(int x, int y);
	void setScale(int x, int y);
	void setSize(int w, int h);
	void setMaterial(std::string m);
	void setRenderDepth(int d); //PROFUNDIDAD
	void setName(std::string n);

	std::string getName() { return name; };
	std::pair<int, int> getPosition() { return { x, y }; }
	std::pair<int, int> getSize() { return { w, h }; }
	std::string getMaterial() { return  material; }
	Ogre::Overlay* getOverlay() { return overlay; }
	//UIObject(double x_, double y_, double w_, double h_, Texture* texture_);

	//void render();
};
