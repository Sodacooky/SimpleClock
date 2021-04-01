#include "ElmGenerator.h"

static tm g_tm;

void ElmGenerator::UpdateTime() {
	auto now_timet = time(nullptr);
	localtime_s(&g_tm, &now_timet);
}

SDL_Surface* ElmGenerator::GenerateTimeStringSurface(SDL_Renderer* pRen, TTF_Font* pFont) {
	return TTF_RenderUTF8_Blended(pFont, __GenerateTimeString().c_str(), { 255,255,255 });;
}

void ElmGenerator::DrawTimeCircleTo(SDL_Renderer* pRen, const SDL_Rect* dst) {
	float r = (dst->w + dst->h) / 4.f;
	if (r <= 0) throw "illegal input";

	SDL_Point center ={ dst->x + (dst->w / 2),dst->y + (dst->h / 2) };
	SDL_Point endPoint;

	int degreeNeedDraw = static_cast<int>((g_tm.tm_sec / 60.f) * 360);
	for (int degreeNow = 0; degreeNow <= degreeNeedDraw; degreeNow++) {
		endPoint =
		{ center.x +
		static_cast<int>(r * SDL_sinf(6.28f * (degreeNow / 360.f))),
		center.y -
		static_cast<int>(r * SDL_cosf(6.28f * (degreeNow / 360.f))) };
		SDL_SetRenderDrawColor(pRen,
							   255 - (degreeNow * 0.6f),
							   255 - (degreeNow * 0.6f),
							   255 - (degreeNow * 0.6f),
							   SDL_ALPHA_OPAQUE);
		SDL_RenderDrawLine(pRen, center.x, center.y, endPoint.x, endPoint.y);
	}

	SDL_SetRenderDrawColor(pRen, 0, 0, 0, SDL_ALPHA_OPAQUE);
}

std::string ElmGenerator::__GenerateTimeString() {
	std::string result_str;

	//hour
	if (g_tm.tm_hour < 10) result_str.push_back('0');
	result_str.append(fmt::format("{}:", g_tm.tm_hour));
	//min
	if (g_tm.tm_min < 10) result_str.push_back('0');
	if (g_tm.tm_sec % 2 == 0) {
		result_str.append(fmt::format("{}:", g_tm.tm_min));
	}
	else {
		result_str.append(fmt::format("{} ", g_tm.tm_min));
	}
	//sec
	if (g_tm.tm_sec < 10) result_str.push_back('0');
	result_str.append(fmt::format("{}", g_tm.tm_sec));

	return result_str;
}