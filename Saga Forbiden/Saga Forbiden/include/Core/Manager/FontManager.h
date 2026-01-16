#pragma once

#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

#include <string>
#include <vector>
#include <iostream>

class FontManager
{
public:
    static FontManager& getInstance();

    void initialize();

    bool loadFont(const std::string& id, const std::string& filePath, int size);
    TTF_Font* getFont(const std::string& id);
    void unloadFont(const std::string& id);

    void clearFonts();

    ~FontManager();

private:
    FontManager() = default;

    struct FontEntry {
        std::string id;
        TTF_Font* font;
        int size;
    };

    bool initialized = false;
    std::vector<FontEntry> fonts;
};
