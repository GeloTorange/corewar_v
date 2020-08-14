/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torange <@student.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 15:18:35 by torange           #+#    #+#             */
/*   Updated: 2020/08/14 21:55:37 by torange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visio.h"

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO) < 0 )
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		g_Window = SDL_CreateWindow("Corewar", \
									SDL_WINDOWPOS_UNDEFINED, \
									SDL_WINDOWPOS_UNDEFINED, \
									SCREEN_WIDTH, \
									SCREEN_HEIGHT, \
									SDL_WINDOW_SHOWN);
		if(g_Window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Get window surface
			g_ScreenSurface = SDL_GetWindowSurface(g_Window);
		}
	}
	return success;
}

bool loadMedia()
{
	bool success = true;

	g_KeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] = loadSurface("img/imag1.bmp");
	if(g_KeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT] == NULL)
	{
		printf("Failed to load default image!\n");
		success = false;
	}

	g_KeyPressSurfaces[KEY_PRESS_SURFACE_UP] = loadSurface("img/imag2.bmp");
	if(g_KeyPressSurfaces[KEY_PRESS_SURFACE_UP] == NULL)
	{
		printf("Failed to load up image!\n");
		success = false;
	}

	return success;
}

SDL_Surface* loadSurface(const char *path)
{
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = SDL_LoadBMP(path);
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL Error: %s\n", path, SDL_GetError() );
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface( loadedSurface, g_ScreenSurface->format, 0 );
		if( optimizedSurface == NULL )
		{
			printf( "Unable to optimize image %s! SDL Error: %s\n", path, SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	return optimizedSurface;
}

void g_close()
{
	//Deallocate surface
	SDL_FreeSurface( g_HelloWorld );
	g_HelloWorld = NULL;

	//Destroy window
	SDL_DestroyWindow( g_Window );
	g_Window = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}
