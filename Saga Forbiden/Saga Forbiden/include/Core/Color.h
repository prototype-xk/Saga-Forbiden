#pragma once

#include <SDL3/SDL.h>

// Format: 0xRRGGBBAA (Red, Green, Blue, Alpha)
#define BTN_BACKGROUND_COLOR  0xC4C4C4FF  // Gris clair pour les boutons
#define COLOR_WHITE           0xFFFFFFFF  // Blanc pur
#define COLOR_BLACK           0x000000FF  // Noir pur
#define COLOR_RED             0xFF0000FF  // Rouge
#define COLOR_GREEN           0x00FF00FF  // Vert
#define COLOR_BLUE            0x0000FFFF  // Bleu

#define RGBA_RED(color)     ((Uint8)(((color) >> 24) & 0xFF))  // Extrait les bits rouges
#define RGBA_GREEN(color)   ((Uint8)(((color) >> 16) & 0xFF))  // Extrait les bits verts
#define RGBA_BLUE(color)    ((Uint8)(((color) >> 8)  & 0xFF))  // Extrait les bits bleus
#define RGBA_ALPHA(color)   ((Uint8)(((color) >> 0)  & 0xFF))  // Extrait les bits alpha


inline void SDL_SetRenderDrawColorRGBA(SDL_Renderer* renderer, Uint32 color)
{
    SDL_SetRenderDrawColor(
        renderer,
        RGBA_RED(color),
        RGBA_GREEN(color),
        RGBA_BLUE(color),
        RGBA_ALPHA(color)
    );
}

inline SDL_Color SDL_ColorFromRGBA(Uint32 color)
{
    return {
        RGBA_RED(color),
        RGBA_GREEN(color),
        RGBA_BLUE(color),
        RGBA_ALPHA(color)
    };
}
