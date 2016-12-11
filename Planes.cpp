/*
 * Planes.cpp
 *
 *  Created on: 15 de ago. de 2016
 *      Author: colosu
 */

#include "Planes.h"
#include "Sprite.h"
#include "SDL2/SDL.h"

Planes::Planes() {

	x = 0;
	y = 0;
	img = NULL;
}

Planes::Planes(int posx, int posy, int nf, string direccion, char* file, SDL_Renderer *renderizado) {

	x = posx;
	y = posy;
	img = new Sprite [nf];
	img->addFrame(direccion, file, renderizado);
}

Planes::~Planes() {

}

void Planes::draw(SDL_Renderer *renderizado) {

	img->setx(x);
	img->sety(y);
	img->draw(renderizado);
}
