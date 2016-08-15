/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * vista.h
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

#ifndef _VISTA_H_
#define _VISTA_H_

#include "Ventana.h"
#include "Sprite.h"
#include "Fuentes.h"

class Vista {
public:

	Vista();
	~Vista();
	Ventana* getWindow();
	void addSprite();
	void addFont();
	void updateVista();
	bool mostrarInicio(int &ancho, int &alto);
	bool mostrarFinal(int &ancho, int &alto);
	string getDireccion(const string &direccion = ""); //Obtiene la dirección de los recursos.
protected:

private:

	Ventana *window;
	Sprite *sprites;
	Fuentes *fonts;
	int max;
	int punt;
};

#endif // _VISTA_H_

