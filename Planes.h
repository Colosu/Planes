/*
 * Planes.h
 *
 *  Created on: 15 de ago. de 2016
 *      Author: colosu
 */

#ifndef PLANES_H_
#define PLANES_H_

#include "Sprite.h"
#include "SDL2/SDL.h"

class Planes {
public:
	Planes();
	Planes(int posx, int posy, int nf, string direccion, char* file, SDL_Renderer *renderizado);
	~Planes();
	void addframe(string direccion, char* file, SDL_Renderer *renderizado) {img->addframe(direccion, file, renderizado);};
	void selframe(int nf) {img->selframe(nf);};
	int frames() {return img->frames();}
	void addx(int c) {img->addx(c);}
	void addy(int c) {img->addy(c);}
	int getx() {return x;}
	int gety() {return y;}
	int getw() {return img->getw();}
	int geth() {return img->geth();}
	void draw(SDL_Renderer *renderizado);
	bool colision(Planes* sp) {return img->colision(*sp->img);};

private:
	int x;
	int y;
	Sprite* img;
};

#endif /* PLANES_H_ */
