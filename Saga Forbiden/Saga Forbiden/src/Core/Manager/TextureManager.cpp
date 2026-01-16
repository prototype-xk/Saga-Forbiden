#include "include/Core/Manager/TextureManager.h"

TextureManager& TextureManager::getInstance() {
	static TextureManager instance;
	return instance;
}

void TextureManager::initialize(SDL_Renderer* renderer) {
	if (!renderer) {
		std::cerr << "[WARNING] TextureManager::initialize - Render is nullptr.\n";
		return;
	}
	this->renderer = renderer;
	std::cerr << "[INFO] TextureManager initialized successfully.\n";
}

bool TextureManager::loadTexture(const std::string& id, const std::string& filePath) {
	if (!renderer) {
		std::cerr << "[ERROR] TextureManager::loadTexture - Renderer not initialized.\n";
		return false;
	}

	for (const auto& entry : textures) {
        if (entry.id == id) {
            std::cout << "[WARNING] TextureManager::loadTexture - Texture '" << id
                << "' already loaded\n";
            return true;
        }
    }

	SDL_Texture* texture = IMG_LoadTexture(renderer, filePath.c_str());
	if (!texture) {
		std::cerr << "[ERROR] TextureManager::loadTexture - Failed to load texture '"
			<< filePath << "': " << SDL_GetError() << "\n";
		return false;
	}

	TextureEntry entry;
	entry.id = id;
	entry.texture = texture;
	textures.push_back(entry);

	std::cout << "[INFO] TextureManager::loadTexture - Loaded texture '" << id << "' from '"<< filePath << "' successfully.\n";

	return true;
}

SDL_Texture* TextureManager::getTexture(const std::string& id) {
	for (const auto& entry : textures) {
		if (entry.id == id) {
			return entry.texture;
		}
	}
	std::cerr << "[WARNING] TextureManager::getTexture - Texture '" << id << "' not found.\n";
	return nullptr;
}

void TextureManager::unloadTexture(const std::string& id) {
	for (auto it = textures.begin(); it != textures.end(); ++it) {
		if (it->id == id) {
			SDL_DestroyTexture(it->texture);
			textures.erase(it);
			std::cout << "[INFO] TextureManager::unloadTexture - Unloaded texture '" << id << "' successfully.\n";
			return;
		}
	}
	std::cerr << "[WARNING] TextureManager::unloadTexture - Texture '" << id << "' not found.\n";
}

void TextureManager::clearTextures() {
	for (const auto& entry : textures) {
		SDL_DestroyTexture(entry.texture);
	}
	textures.clear();
	std::cout << "[INFO] TextureManager::clearTextures - Cleared all textures successfully.\n";
}

TextureManager::~TextureManager() {
	clearTextures();
	std::cout << "[INFO] TextureManager destroyed and all textures cleared.\n";
}