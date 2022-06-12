#pragma once
//Im�genes renderizadas a partir de una textura
//En esta clase se a�ade la posici�n x e y
#include "Texture.h"

class UIObject {
private:
	Texture* texture;
	double x, y, w, h;


public:
	UIObject(SDL_Renderer* rend, const std::string& filename, double textWidth, double textHeight, double x_, double y_, double w_, double h_);
	UIObject(double x_, double y_, double w_, double h_, Texture* texture_);

	void render();
};

