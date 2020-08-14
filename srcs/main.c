/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torange <@student.42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 15:18:35 by torange           #+#    #+#             */
/*   Updated: 2020/08/14 22:09:41 by torange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visio.h"



int main(int argc, char* args[])
{
	bool is_running = true;

	if(init())
	{
		if(loadMedia())
		{
			g_CurrentSurface = g_KeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
			while (is_running)
			{
				while (SDL_PollEvent(&g_event) != 0)
					if (g_event.type == SDL_QUIT)
							is_running = false;
				else if(g_event.type == SDL_KEYDOWN)
				{
					switch(g_event.key.keysym.sym)
					{
					case SDLK_UP:
					g_CurrentSurface = g_KeyPressSurfaces[KEY_PRESS_SURFACE_UP];
					break;

					case SDLK_DOWN:
					g_CurrentSurface = g_KeyPressSurfaces[KEY_PRESS_SURFACE_DOWN];
					break;

					default:
					g_CurrentSurface = g_KeyPressSurfaces[KEY_PRESS_SURFACE_DEFAULT];
					break;
					}
				}
				SDL_Rect stretchRect;
				stretchRect.x = 0;
				stretchRect.y = 0;
				stretchRect.w = SCREEN_WIDTH;
				stretchRect.h = SCREEN_HEIGHT;
				SDL_BlitScaled(g_CurrentSurface, NULL, g_ScreenSurface, &stretchRect);
				SDL_UpdateWindowSurface(g_Window);
			}
		}
		else
			printf( "Failed to load media!\n" );
	}
	else
		printf( "Failed to initialize!\n" );
	g_close();
	return 0;
}
