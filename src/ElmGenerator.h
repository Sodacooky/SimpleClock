#pragma once

#include <chrono>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <fmt/format.h>

//使用前记得更新时间
class ElmGenerator {
public:
	//更新内部储存的时间
	static void UpdateTime();
	//使用内部储存的时间来生成一个时间文字suface
	static SDL_Surface* GenerateTimeStringSurface(SDL_Renderer* pRen, TTF_Font* pFont);
	//使用内部储存的时间来在指定位置画一个表盘
	static void DrawTimeCircleTo(SDL_Renderer* pRen, const SDL_Rect* dst);
private:
	static std::string __GenerateTimeString();
};
