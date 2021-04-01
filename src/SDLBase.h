#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class SDLBase {
public:
	//init all sdl sys
	static void Init();
	//quit and clean sdl sys
	static void Cleanup();

	//get the sdl_window ptr
	static SDL_Window* GetWindowPtr();
	//get the sdl_renderer ptr
	static SDL_Renderer* GetRendererPtr();
	//get the ttf_font ptr
	static TTF_Font* GetFontPtr();

	//convert surface to texture, willn't delete surface memory
	static SDL_Texture* ConvertSur2Tex(SDL_Surface* pSur);
};