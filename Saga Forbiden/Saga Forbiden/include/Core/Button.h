#pragma once

#include <SDL3/SDL.h>
#include <SDL3_TTF/SDL_ttf.h>
#include <string>
#include <iostream>
#include "include/Utils/Color.h"

class Button {
public:
	Button(SDL_Renderer* renderer, SDL_Texture* backgroundtexture, TTF_Font* font, const std::string& text, float x, float y, float w, float h);
	Button(SDL_Renderer* renderer, TTF_Font* font, const std::string& text, float x, float y, float w, float h);

	void HandleEvent(SDL_Event* e);
	void Render(SDL_Renderer* renderer);

	bool IsHovered() const { return ishovered; }
	bool IsPressed() const { return ispressed; }
	bool WasClicked() const { return clicked; }

	void setPosition(float x, float y);
	void setSize(float w, float h);

private:
	void createTextTexture(SDL_Renderer* renderer, TTF_Font* font, const std::string& text, Uint32 textColor);

	SDL_FRect rect;
	float hoverOffset = 3.0f;

	bool ishovered = false;
	bool ispressed = false;
	bool wasPressedOn = false;
	bool clicked = false;

	SDL_Texture* backgroundTexture = nullptr;
	SDL_Texture* textTexture = nullptr;

	Uint32 backgroundColor = BTN_BACKGROUND_COLOR;
};