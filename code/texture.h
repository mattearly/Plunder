#pragma once

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include "graphics.h"

class SDL_graphics;

class Texture {
public:
	Texture(void);
	~Texture(void);

	bool is_null(void) { return (SDLtex == nullptr); }
	bool load(const std::string &path);  //loading up pictures
	bool load(TTF_Font *font, std::string text, SDL_Color text_color);  //loading up text
	void setColor(Uint8 red, Uint8 green, Uint8 blue) { SDL_SetTextureColorMod(SDLtex, red, green, blue); }
	void setBlendMode(SDL_BlendMode blend_mode) { SDL_SetTextureBlendMode(SDLtex, blend_mode); }
	void setAlpha(Uint8 alpha) { SDL_SetTextureAlphaMod(SDLtex, alpha); }

	int getWidth(void) { return width; }
	int getHeight(void) { return height; }

	void drawWithWidthClamp(const int &clamp_width, int x = 0, int y = 0);

	void draw(int x = 0, int y = 0, SDL_Rect *src_clip = NULL, SDL_Rect *dst_rect = NULL, double angle = 0.0, SDL_Point *center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void draw(SDL_Rect *destination);

	void free();

private:
	int width;
	int height;
	SDL_Texture *SDLtex;
};
