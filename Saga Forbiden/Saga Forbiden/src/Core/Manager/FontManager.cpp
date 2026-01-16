#include "include/Core/Manager/FontManager.h"

FontManager& FontManager::getInstance() {
	static FontManager instance;
	return instance;
}

void FontManager::initialize() {
	if (initialized) {
		std::cerr << "[WARNING] FontManager::initialize - Already initialized.\n";
		return;
	}
	initialized = true;
	std::cerr << "[INFO] FontManager initialized successfully.\n";
}

bool FontManager::loadFont(const std::string& id, const std::string& filePath, int size) {
	if (!initialized) {
		std::cerr << "[ERROR] FontManager::loadFont - FontManager not initialized.\n";
		return false;
	}
	for (const auto& entry : fonts) {
		if (entry.id == id) {
			std::cout << "[WARNING] FontManager::loadFont - Font '" << id
				<< "' already loaded\n";
			return true;
		}
	}
	TTF_Font* font = TTF_OpenFont(filePath.c_str(), size);
	if (!font) {
		std::cerr << "[ERROR] FontManager::loadFont - Failed to load font '"
			<< filePath << "': " << SDL_GetError() << "\n";
		return false;
	}
	FontEntry entry;
	entry.id = id;
	entry.font = font;
	entry.size = size;
	fonts.push_back(entry);
	std::cout << "[INFO] FontManager::loadFont - Loaded font '" << id << "' from '"<< filePath << "' successfully.\n";
	return true;
}

TTF_Font* FontManager::getFont(const std::string& id) {
	for (const auto& entry : fonts) {
		if (entry.id == id) {
			return entry.font;
		}
	}
	std::cerr << "[WARNING] FontManager::getFont - Font '" << id << "' not found.\n";
	return nullptr;
}

void FontManager::unloadFont(const std::string& id) {
	for (auto it = fonts.begin(); it != fonts.end(); ++it) {
		if (it->id == id) {
			TTF_CloseFont(it->font);
			fonts.erase(it);
			std::cout << "[INFO] FontManager::unloadFont - Unloaded font '" << id << "' successfully.\n";
			return;
		}
	}
	std::cerr << "[WARNING] FontManager::unloadFont - Font '" << id << "' not found.\n";
}

void FontManager::clearFonts() {
	for (auto& entry : fonts) {
		TTF_CloseFont(entry.font);
	}
	fonts.clear();
	std::cout << "[INFO] FontManager::clearFonts - Cleared all fonts successfully.\n";
}

FontManager::~FontManager() {
	clearFonts();
	std::cerr << "[INFO] FontManager destroyed and all fonts cleared.\n";
}