#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h>

namespace Snake {

class Screen {
private:
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer; // Pixel memory
public:
	const static int SCREEN_WIDTH = 800; // standard: 800
	const static int SCREEN_HEIGHT = 600; // standard: 600
public:
	Screen();
	bool init();
	void update();
	void setPixel(double x, double y, Uint32 red, Uint32 green, Uint32 blue);
	void clear();
	void close();
};

} /* namespace Snake */

#endif /* SCREEN_H_ */
