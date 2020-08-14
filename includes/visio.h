/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visio.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torange <@student.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 15:18:44 by torange           #+#    #+#             */
/*   Updated: 2020/08/14 22:08:09 by torange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISIO_H
# define VISIO_H

# include "libft.h"
# include "libftprintf.h"
# include <stdio.h>
# include "SDL.h"

# define SCREEN_WIDTH 1980
# define SCREEN_HEIGHT 1020

enum KeyPressSurfaces
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};



//The window we'll be rendering to
SDL_Window *g_Window;

//The surface contained by the window
SDL_Surface *g_ScreenSurface;

//The image we will load and show on the screen
SDL_Surface *g_HelloWorld;
SDL_Event g_event;

//Loads individual image
SDL_Surface* loadSurface(const char *path);

//The surface contained by the window
SDL_Surface* g_ScreenSurface;

//The images that correspond to a keypress
SDL_Surface* g_KeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];

//Current displayed image
SDL_Surface* g_CurrentSurface;


//Starts up SDL and creates window
bool init();

bool loadMedia();

void g_close();

#endif
