/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * vista.cc
 * Copyright (C) 2016 Colosu <alfredocolosu@gmail.com>
 *
 * 2048 is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * 2048 is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include "Vista.h"
#include "Ventana.h"
#include "Sprite.h"
#include "Fuentes.h"
#include "Settings.h"
#include "SDL2/SDL.h"

Vista::Vista() {
	try {
		window = new Ventana(COLUMNS * SPRITE_W, ROWS * SPRITE_H, 0, 0, "2048");
		sprites = new Sprite [N_SPRITES];
		fonts = new Fuentes [N_FONTS];
		max = 0;
		punt = 0;
	} catch (exception *e) {
		throw e;
	}
}

Vista::~Vista() {
	delete window;
}

Ventana* Vista::getWindow() {

	return window;
}

void Vista::updateVista() {
	SDL_Texture *textura = NULL;
	SDL_RenderClear(window->getRenderizado());
	for (int i = 0; i < controlador->getPartida()->getTab()->getRows(); i++) {
		for (int j = 0; j < controlador->getPartida()->getTab()->getColumns(); j++) {
			switch (controlador->getPartida()->getTab()->getCasilla(i,j)->getNumber()) {
				case 2: textura = sprites->getTexturas()->getDos(); break;
				case 4: textura = sprites->getTexturas()->getCuatro(); break;
				case 8: textura = sprites->getTexturas()->getOcho(); break;
				case 16: textura = sprites->getTexturas()->getDieciseis(); break;
				case 32: textura = sprites->getTexturas()->getTreintaydos(); break;
				case 64: textura = sprites->getTexturas()->getSesentaycuatro(); break;
				case 128: textura = sprites->getTexturas()->getCientoveintiocho(); break;
				case 256: textura = sprites->getTexturas()->getDoscientoscincuentayseis(); break;
				case 512: textura = sprites->getTexturas()->getQuinientosdoce(); break;
				case 1024: textura = sprites->getTexturas()->getMilveinticuatro(); break;
				case 2048: textura = sprites->getTexturas()->getDosmilcuarentayocho(); break;
				default: textura = sprites->getTexturas()->getCero();
			}
			window->getTexturas()->renderizarTextura(textura, j*100, i*100);
		}
	}
	max = controlador->getPartida()->getMax();
	punt = controlador->getPartida()->getPunt();
	window->getTexturas()->renderizarTextura(window->getTexturas()->getPuntuacion(), 50, ROWS*100 + 40);
	window->getTexturas()->setMaximo(max);
	window->getTexturas()->setPuntos(punt);
	window->getTexturas()->renderizarTextura(window->getTexturas()->getMaximo(), 100, ROWS*100 + 40);
	window->getTexturas()->renderizarTextura(window->getTexturas()->getPuntos(), 280, ROWS*100 + 40);
	SDL_RenderPresent(window->getRenderizado());
}

bool Vista::mostrarInicio(int &ancho, int &alto) {

	bool iniciado = false;
	SDL_Texture *titulo = NULL;
	SDL_Texture *inicio = NULL;
	SDL_Texture *automatico = NULL;
	SDL_Texture *manual = NULL;
	SDL_Color color = { 255, 255, 255, 255 };

	inicio = window->getTexturas()->cargarTextura(window->getDireccion() + "inicio.png");
	titulo = window->getTexturas()->renderizarTexto(window->getTexturas()->getFuentes()->getFuentePrincipal(), "2048", color);
	automatico = window->getTexturas()->renderizarTexto(window->getTexturas()->getFuentes()->getFuenteSecundaria(), "Automático", color);
	manual = window->getTexturas()->renderizarTexto(window->getTexturas()->getFuentes()->getFuenteSecundaria(), "Manual", color);

	if (inicio != NULL && titulo != NULL && automatico != NULL && manual != NULL) {

		SDL_RenderClear(window->getTexturas()->getRenderizado());

		SDL_QueryTexture(inicio, NULL, NULL, &ancho, &alto);
		window->getTexturas()->renderizarTextura(inicio, (window->getX() / 2) - (ancho / 2), ((window->getY() + window->getExtraY()) / 10)*5 - (alto / 2));
		window->getTexturas()->renderizarTextura(inicio, (window->getX() / 2) - (ancho / 2), ((window->getY() + window->getExtraY()) / 10)*8 - (alto / 2));
		SDL_QueryTexture(titulo, NULL, NULL, &ancho, &alto);
		window->getTexturas()->renderizarTextura(titulo, (window->getX() / 2) - (ancho / 2), ((window->getY() + window->getExtraY()) / 5) - (alto / 2));
		SDL_QueryTexture(automatico, NULL, NULL, &ancho, &alto);
		window->getTexturas()->renderizarTextura(automatico, (window->getX() / 2) - (ancho / 2), ((window->getY() + window->getExtraY()) / 10)*5 - (alto / 2));
		SDL_QueryTexture(manual, NULL, NULL, &ancho, &alto);
		window->getTexturas()->renderizarTextura(manual, (window->getX() / 2) - (ancho / 2), ((window->getY() + window->getExtraY()) / 10)*8 - (alto / 2));

		SDL_RenderPresent(window->getTexturas()->getRenderizado());

		iniciado = true;
	} else {

		iniciado = false;
	}

	SDL_QueryTexture(inicio, NULL, NULL, &ancho, &alto);

	SDL_DestroyTexture(inicio);
	SDL_DestroyTexture(titulo);
	SDL_DestroyTexture(automatico);
	SDL_DestroyTexture(manual);

	return iniciado;
}

bool Vista::mostrarFinal(int &ancho, int &alto) {

	bool iniciado = false;
	SDL_Texture *titulo = NULL;
	SDL_Texture *inicio = NULL;
	SDL_Texture *automatico = NULL;
	SDL_Texture *manual = NULL;
	SDL_Color color = { 255, 255, 255, 255 };

	inicio = window->getTexturas()->cargarTextura(window->getDireccion() + "inicio.png");
	if (controlador->getPartida()->getMax() == 2048) {

		titulo = window->getTexturas()->renderizarTexto(window->getTexturas()->getFuentes()->getFuentePrincipal(), "Ganaste", color);
	} else {

		titulo = window->getTexturas()->renderizarTexto(window->getTexturas()->getFuentes()->getFuentePrincipal(), "Perdiste", color);
	}
	automatico = window->getTexturas()->renderizarTexto(window->getTexturas()->getFuentes()->getFuenteSecundaria(), "Reintentar", color);
	manual = window->getTexturas()->renderizarTexto(window->getTexturas()->getFuentes()->getFuenteSecundaria(), "Salir", color);

	if (inicio != NULL && titulo != NULL && automatico != NULL && manual != NULL) {

		SDL_RenderClear(window->getTexturas()->getRenderizado());

		SDL_QueryTexture(inicio, NULL, NULL, &ancho, &alto);
		window->getTexturas()->renderizarTextura(inicio, (window->getX() / 2) - (ancho / 2), ((window->getY() + window->getExtraY()) / 10)*6 - (alto / 2));
		window->getTexturas()->renderizarTextura(inicio, (window->getX() / 2) - (ancho / 2), ((window->getY() + window->getExtraY()) / 20)*17 - (alto / 2));
		SDL_QueryTexture(titulo, NULL, NULL, &ancho, &alto);
		window->getTexturas()->renderizarTextura(titulo, (window->getX() / 2) - (ancho / 2), ((window->getY() + window->getExtraY()) / 5) - (alto / 2));
		SDL_QueryTexture(automatico, NULL, NULL, &ancho, &alto);
		window->getTexturas()->renderizarTextura(automatico, (window->getX() / 2) - (ancho / 2), ((window->getY() + window->getExtraY()) / 10)*6 - (alto / 2));
		SDL_QueryTexture(manual, NULL, NULL, &ancho, &alto);
		window->getTexturas()->renderizarTextura(manual, (window->getX() / 2) - (ancho / 2), ((window->getY() + window->getExtraY()) / 20)*17 - (alto / 2));

		max = controlador->getPartida()->getMax();
		punt = controlador->getPartida()->getPunt();
		window->getTexturas()->renderizarTextura(window->getTexturas()->getPuntuacion(), 50, 150 + 40);
		window->getTexturas()->setMaximo(max);
		window->getTexturas()->setPuntos(punt);
		window->getTexturas()->renderizarTextura(window->getTexturas()->getMaximo(), 100, 150 + 40);
		window->getTexturas()->renderizarTextura(window->getTexturas()->getPuntos(), 280, 150 + 40);

		SDL_RenderPresent(window->getTexturas()->getRenderizado());

		iniciado = true;
	} else {

		iniciado = false;
	}

	SDL_QueryTexture(inicio, NULL, NULL, &ancho, &alto);

	SDL_DestroyTexture(inicio);
	SDL_DestroyTexture(titulo);
	SDL_DestroyTexture(automatico);
	SDL_DestroyTexture(manual);

	return iniciado;
}

string Vista::getDireccion(const string &direccion) {

#ifdef _WIN32
	const char PATH_SEP = '\\';
#else
	const char PATH_SEP = '/';
#endif

	static string baseRes;

	if (baseRes.empty()) {

		char *basePath = SDL_GetBasePath();
		if (basePath) {

			baseRes = basePath;
			SDL_free(basePath);
		}
		else {

			cerr << "Error obteniendo la ruta de datos: " << SDL_GetError() << endl;
			return "";
		}

		size_t pos = baseRes.find_last_of("bin") - 2;
		baseRes = baseRes.substr(0, pos) + "resources" + PATH_SEP;
	}

	return direccion.empty() ? baseRes : baseRes + direccion + PATH_SEP;
}
