#include "Graphics.h"
#include <iostream>

int main(int argc, char* args[])
{
	Window* w = new Window();

	if (w->getRenderer() == NULL || w->getWindow() == NULL) {
		std::cout << "Error initializing Window";
		//return 0;
	}
	
	
	
	w->drawFromFile(w->closeUp);
	SDL_RenderPresent(w->getRenderer());//Update screen
	SDL_Delay(1000);
	w->clear();
	
	w->drawFromFile(w->angry);
	SDL_RenderPresent(w->getRenderer());//Update screen
	SDL_Delay(1000);
	w->clear();
	w->drawFromFile(w->sad);
	SDL_RenderPresent(w->getRenderer());//Update screen
	SDL_Delay(1000);
	w->clear();
	w->drawFromFile(w->general1);
	SDL_RenderPresent(w->getRenderer());//Update screen
	SDL_Delay(1000);
	w->clear();
	w->drawFromFile(w->general2);
	SDL_RenderPresent(w->getRenderer());//Update screen
	SDL_Delay(1000);
	w->clear();
	w->drawFromFile(w->happy);
	SDL_RenderPresent(w->getRenderer());//Update screen
	SDL_Delay(1000);
	w->clear();
	w->drawFromFile(w->sleepy);
	SDL_RenderPresent(w->getRenderer());//Update screen
	SDL_Delay(1000);
	w->clear();

	std::string s;
	std::cin >> s;

	//Free resources and close SDL
	w->close();

	return 0;
	//i love you cole
}
