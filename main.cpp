/*
 * main.cpp
 *
 *  Created on: 15 de ago. de 2016
 *      Author: colosu
 */

#include "Map.h"
#include "Planes.h"
#include "Sprite.h"
#include "SDL2/SDL.h"

SDL_Window *screen;
SDL_Renderer renderizado;
SDL_Joystick *joystick;
int joyx, joyy;
int done = 0;
Map mapa;
Planes *jugador;
Planes *enemigo;

void DrawScene(SDL_Renderer *renderizado) {

	SDL_RenderClear(renderizado);
	mapa.draw(renderizado);
	jugador->draw(renderizado);
	enemigo->draw(renderizado);
	// ¿ha colisionado con la nave?
	if (enemigo->colision(jugador) == true) {
		done=1;
	}
	SDL_RenderPresent(renderizado);
}
