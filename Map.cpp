/*
 * Map.cpp
 *
 *  Created on: 15 de ago. de 2016
 *      Author: colosu
 */

#include "Map.h"
#include "Sprite.h"
#include "SDL2/SDL.h"

Map::Map(int nf) {

	suelo = new Sprite[nf];
	nframes = nf;
	cont = 0;
}

Map::~Map() {

	for (int i = 0 ; i <= nframes-1 ; i++)
		suelo[i].~Sprite();
}

void Map::addSprite(string direccion, char* file, SDL_Renderer *renderizado) {

	if (cont < nframes) {
		suelo[cont].addframe(direccion, file, renderizado);
		cont++;
	}
}

void Map::draw(SDL_Renderer *renderizado) {

	int t, x, y;

	for (int i = 0 ; i < 10 ; i++) {
		for (int j = 0 ; j < 10 ; j++) {
			t = mapa[i*10 + j];
			// calculo de la posición del tile
			x = j*64;
			y = (i - 1)*64;

			// dibujamos el tile
			suelo[t].setx(x);
			suelo[t].sety(y);
			suelo[t].draw(renderizado);
		}
	}
}
