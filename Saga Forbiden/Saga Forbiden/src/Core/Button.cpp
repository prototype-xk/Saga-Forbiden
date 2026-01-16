#include "include/Core/Button.h"

Button::Button(SDL_Renderer* renderer, SDL_Texture* backgroundtexture, TTF_Font* font, const std::string& text, float x, float y, float w, float h)
	: backgroundTexture(backgroundtexture)
{
	rect = { x, y, w, h };
	backgroundColor = BTN_BACKGROUND_COLOR;
	createTextTexture(renderer, font, text, COLOR_WHITE);
}

Button::Button(SDL_Renderer* renderer, TTF_Font* font, const std::string& text, float x, float y, float w, float h)
{
	rect = { x, y, w, h };
	backgroundTexture = nullptr;
	backgroundColor = BTN_BACKGROUND_COLOR;
	createTextTexture(renderer, font, text,	COLOR_WHITE);
}

void Button::createTextTexture(SDL_Renderer* renderer, TTF_Font* font, const std::string& text, Uint32 textColor)
{
	if (!renderer || !font) {
		std::cerr << "[ERROR] Button::createTextTexture - renderer or font is nullptr\n";
		return;
	}

	if (textTexture) {
		SDL_DestroyTexture(textTexture);
		textTexture = nullptr;
	}

	SDL_Color color = SDL_ColorFromRGBA(textColor);
	SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(),0 , color);
	if (!surface) {
		std::cerr << "[ERROR] Button::createTextTexture - TTF_RenderText_Blended failed: " << SDL_GetError() << "\n";
		return;
	}

	textTexture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_DestroySurface(surface);
	if (!textTexture) {
		std::cerr << "[ERROR] Button::createTextTexture - SDL_CreateTextureFromSurface failed: " << SDL_GetError() << "\n";
		return;
	}
}

void Button::HandleEvent(SDL_Event* e)
{
	if (!e) return;

	clicked = false;

	if (e->type == SDL_EVENT_MOUSE_MOTION) {
		float mx = e->motion.x;
		float my = e->motion.y;

		ishovered =
			mx >= rect.x && mx <= rect.x + rect.w &&
			my >= rect.y && my <= rect.y + rect.h;
	}
	else if (e->type == SDL_EVENT_MOUSE_BUTTON_DOWN &&
		e->button.button == SDL_BUTTON_LEFT)
	{
		float mx = e->button.x;
		float my = e->button.y;

		bool inside =
			mx >= rect.x && mx <= rect.x + rect.w &&
			my >= rect.y && my <= rect.y + rect.h;

		if (inside) {
			ispressed = true;
			wasPressedOn = true;
		}
	}
	else if (e->type == SDL_EVENT_MOUSE_BUTTON_UP &&
		e->button.button == SDL_BUTTON_LEFT)
	{
		float mx = e->button.x;
		float my = e->button.y;

		bool inside =
			mx >= rect.x && mx <= rect.x + rect.w &&
			my >= rect.y && my <= rect.y + rect.h;

		if (wasPressedOn && inside) {
			clicked = true;
		}

		ispressed = false;
		wasPressedOn = false;
	}
}



void Button::Render(SDL_Renderer* renderer){
	if (!renderer) return;
	SDL_FRect drawRect = rect;
	if (ishovered) {
		drawRect.y -= hoverOffset;
	}
	if (backgroundTexture) {
		SDL_RenderTexture(renderer, backgroundTexture, nullptr, &drawRect);
	}
	else {
		SDL_SetRenderDrawColorRGBA(renderer, backgroundColor);
		SDL_RenderFillRect(renderer, &drawRect);
	}

	if (textTexture) {
		float tw = 0.f;
		float th = 0.f;
		if (SDL_GetTextureSize(textTexture, &tw, &th)) {
			SDL_FRect textDst;
			textDst.w = tw;
			textDst.h = th;
			textDst.x = drawRect.x + (drawRect.w - textDst.w) / 2;
			textDst.y = drawRect.y + (drawRect.h - textDst.h) / 2;

			SDL_RenderTexture(renderer, textTexture, nullptr, &textDst);
		}
	}
}

void Button::setPosition(float x, float y) {
	rect.x = x;
	rect.y = y;
}

void Button::setSize(float w, float h) {
	rect.w = w;
	rect.h = h;
}