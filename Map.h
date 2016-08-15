/*
 * Map.h
 *
 *  Created on: 15 de ago. de 2016
 *      Author: colosu
 */

#ifndef MAP_H_
#define MAP_H_

#include "Sprite.h"
#include "SDL2/SDL.h"

class Map {
public:
	Map(int nf);
	~Map();
	void addSprite(string direccion, char* file, SDL_Renderer *renderizado);
	void draw(SDL_Renderer *renderizado);

private:

	int mapa[100]= {0,0,0,0,0,0,0,0,0,0,
	 	 	0,0,0,0,0,2,0,0,0,0,
			0,0,1,0,0,0,0,1,0,0,
			2,0,0,0,0,0,0,0,0,0,
			0,0,0,0,1,0,0,0,2,0,
			0,0,0,0,0,0,0,0,0,0,
			0,2,0,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,1,0,0,
			0,0,1,0,0,0,0,0,0,0,
			0,0,0,0,0,0,0,0,0,0};
	int nframes;
	int cont;
	Sprite *suelo;
};

#endif /* MAP_H_ */
