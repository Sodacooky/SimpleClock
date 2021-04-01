#include <iostream>
#include <chrono>
#include <string>

#include <fmt/format.h>

#include "SDLBase.h"
#include "ElmGenerator.h"

#undef main
int main() {
	SDLBase::Init();
	SDL_SetWindowSize(SDLBase::GetWindowPtr(), 320, 64);

	SDL_Event msg;
	while (true) {
		SDL_PollEvent(&msg);
		if (msg.type == SDL_QUIT) break;

		SDL_RenderClear(SDLBase::GetRendererPtr());

		ElmGenerator::UpdateTime();

		SDL_Rect timeCircleRenderRect ={ 0,0,64,64 };
		ElmGenerator::DrawTimeCircleTo(SDLBase::GetRendererPtr(), &timeCircleRenderRect);

		auto sur = ElmGenerator::GenerateTimeStringSurface(SDLBase::GetRendererPtr(), SDLBase::GetFontPtr());
		SDL_Rect timeStringRenderRect ={ 64,-8,sur->w,sur->h };
		auto tex = SDLBase::ConvertSur2Tex(sur);
		SDL_FreeSurface(sur);
		SDL_RenderCopy(SDLBase::GetRendererPtr(), tex, nullptr, &timeStringRenderRect);
		SDL_DestroyTexture(tex);

		SDL_RenderPresent(SDLBase::GetRendererPtr());

		SDL_Delay(1000);
	}

	SDLBase::Cleanup();
	return 0;
}