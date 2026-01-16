#pragma once

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <string>
#include <vector>
#include <iostream>

class TextureManager
{
public:
    static TextureManager& getInstance();

    void initialize(SDL_Renderer* renderer);

    bool loadTexture(const std::string& id, const std::string& filePath);
    SDL_Texture* getTexture(const std::string& id);
    void unloadTexture(const std::string& id);

    void clearTextures();

    ~TextureManager();

private:
    TextureManager() = default;

    struct TextureEntry {
        std::string id;
        SDL_Texture* texture;
    };

    SDL_Renderer* renderer = nullptr;
    std::vector<TextureEntry> textures;
};
