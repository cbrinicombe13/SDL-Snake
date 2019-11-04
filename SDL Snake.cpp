#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Screen.h"
#include "Dot.h"

using namespace std;
using namespace Snake;

int main() {

	srand(time(NULL));

	// Create screen:

	Screen screen;

	if(!screen.init()) {
		cout << " Could not initialise screen .." << endl;
	}

	// Create head and body:

	//Dot head(Screen::SCREEN_WIDTH/2, Screen::SCREEN_HEIGHT/2, Dot::DOT_SPEED);

	vector<Dot> snake;
	snake.push_back(Dot(Screen::SCREEN_WIDTH/2, Screen::SCREEN_HEIGHT/2, Dot::DOT_SPEED));

	// Set initial fruit position:

	int fruitX = rand() % Screen::SCREEN_WIDTH;
	int fruitY = rand() % Screen::SCREEN_HEIGHT;

	// Initialise score:

	int score = 0;

	bool notQuit = true;

/////// END OF SETUP ///////

	while(notQuit) {

		screen.clear();

	// Draw snake:

		for(vector<Dot>::iterator it = snake.begin(); it != snake.end(); it++) {

			for(int r = 0; r < Dot::DOT_RADIUS; r++) {
				for (int theta = 0; theta < 360; theta++) {

					double x = it->getX() + (r * cos(theta));
					double y = it->getY() + (r * sin(theta));

					screen.setPixel(x, y, 255, 255, 255);
				}
			}
		}

	// Create and draw fruit:

		Dot fruit(fruitX, fruitY);

		for (int r = 0; r < Dot::DOT_RADIUS; r++) {
			for (int theta = 0; theta < 360; theta++) {

				double x = fruit.getX() + (r * cos(theta));
				double y = fruit.getY() + (r * sin(theta));

				screen.setPixel(x, y, 255, 0, 0);
			}
		}

	// Process snake movements:

		for(vector<Dot>::iterator it = snake.begin(); it != snake.end(); it++) {
			it->move();
		}

	// Process head collisions:

		if(!snake[0].processQuitCollisons()) {

			cout << "!!! Game Over !!!" << endl;
			cout << "Final score: " << score << endl;
			notQuit = false;

		}

		if(!snake[0].processFruitCollisions(fruit)) {

		// Increment score:

			score += 10;
			cout << "Score: " << score << endl;

		// Re-initialise fruit:

			fruitX = rand() % Screen::SCREEN_WIDTH;
			fruitY = rand() % Screen::SCREEN_HEIGHT;

		// Extend snake:

			// Get old position of head as new dot position:

			int newX = snake[0].getX();
			int newY = snake[0].getY();
			int spacer = 2 * Dot::DOT_RADIUS;

			snake.push_back(Dot(newX - spacer, newY - spacer, Dot::DOT_SPEED, snake[0].getDirection()));
			cout << "Snake size: " << snake.size() << endl;
		}

	// Update screen:

		screen.update();

	// Process game events:

		SDL_Event event;

		while(SDL_PollEvent(&event)) {
			if( event.type == SDL_QUIT) {
				cout << "!!! Game Over !!!" << endl;
				cout << "Final score: " << score << endl;
				notQuit = false;
				break;
			}
			else if( event.type == SDL_KEYDOWN ) {
				for(vector<Dot>::iterator it = snake.begin(); it != snake.end(); it++) {
					switch( event.key.keysym.sym ) {
						case SDLK_w:
							it->changeDirectionUp();
							break;
						case SDLK_a:
							it->changeDirectionLeft();
							break;
						case SDLK_s:
							it->changeDirectionDown();
							break;
						case SDLK_d:
							it->changeDirectionRight();
							break;
						case SDLK_p:
							it->pause();
							break;
					}
				}
			}
		}

	} /* GAME LOOP */

	screen.close();

	return 0;
}
