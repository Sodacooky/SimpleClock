#include "SDLBase.h"

static SDL_Window* g_pWin;
static SDL_Renderer* g_pRen;
static TTF_Font* g_pFont;

void SDLBase::Init() {
	SDL_Init(SDL_INIT_EVERYTHING);
	g_pWin = SDL_CreateWindow(u8"GraphClock",
							  SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
							  320, 240,
							  SDL_WINDOW_SHOWN);
	g_pRen = SDL_CreateRenderer(g_pWin, -1,
								SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	TTF_Init();
	g_pFont = TTF_OpenFont("Ubuntu-R.ttf", 64);
	//simple error handing
	if (g_pWin == nullptr || g_pRen == nullptr || g_pFont == nullptr) {
		throw "init failed";
	}
}

void SDLBase::Cleanup() {
	SDL_DestroyRenderer(g_pRen);
	SDL_DestroyWindow(g_pWin);
	TTF_CloseFont(g_pFont);
	SDL_Quit();
}

SDL_Window* SDLBase::GetWindowPtr() {
	return g_pWin;
}

SDL_Renderer* SDLBase::GetRendererPtr() {
	return g_pRen;
}

TTF_Font* SDLBase::GetFontPtr() {
	return g_pFont;
}

SDL_Texture* SDLBase::ConvertSur2Tex(SDL_Surface* pSur) {
	return SDL_CreateTextureFromSurface(g_pRen, pSur);
}