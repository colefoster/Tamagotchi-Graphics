#pragma once
//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
//Screen dimension constants
const int SCREEN_WIDTH = 480;
const int SCREEN_HEIGHT = 480;

class Window {


	//The window we'll be rendering to
	SDL_Window* gWindow = NULL;
	//The image we will load and show on the screen
	SDL_Surface* gHelloWorld = NULL;
	//The window renderer
	SDL_Renderer* gRenderer = NULL;

	
	
public:
	std::ifstream closeUp;
	std::ifstream happy;
	std::ifstream general1;
	std::ifstream general2;
	std::ifstream sad;
	std::ifstream angry;
	std::ifstream sleepy;

	Window() {
		closeUp = std::ifstream ("Sprites\\closeup.txt");
		happy = std::ifstream ("Sprites\\happy.txt");
		general1 = std::ifstream("Sprites\\general1.txt");
		general2 = std::ifstream("Sprites\\general2.txt");
		sad = std::ifstream("Sprites\\sad.txt");
		angry = std::ifstream("Sprites\\angry.txt");
		sleepy = std::ifstream("Sprites\\sleepy.txt");
		//Initialize SDL
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			//Create window
			gWindow = SDL_CreateWindow("Tamagotchi", 500, 200, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
			if (gWindow == NULL)
			{
				printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			}
			else
			{

				//Create renderer for window
				gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
				if (gRenderer == NULL)
				{
					printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				}
				else
				{
					//Initialize renderer color
					SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				}

			}
		}
	}
	SDL_Window* getWindow() {
		return this->gWindow;
	}
	SDL_Renderer* getRenderer() {
		return this->gRenderer;
	}
	void close()
	{
		//Deallocate surface
		SDL_FreeSurface(gHelloWorld);
		gHelloWorld = NULL;
		//Destroy window
		SDL_DestroyWindow(gWindow);
		gWindow = NULL;
		//Quit SDL subsystems
		SDL_Quit();
	}
	void clear() {
		SDL_RenderClear(gRenderer);
		SDL_Rect square{ 0,0, SCREEN_WIDTH  ,SCREEN_HEIGHT };
		SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
		SDL_RenderFillRect(gRenderer, &square);
	}
	void drawFromFile(std::ifstream& file) {
		std::string input;
		std::stringstream ss;
		char c;

		SDL_Rect square{ SCREEN_WIDTH / 6 ,SCREEN_HEIGHT / 6, 10,10 };

		SDL_RenderClear(gRenderer);

		while (getline(file, input)) {
			ss << input;
			for (int i = 0; i < input.length(); i++) {
				c = input.c_str()[i];
				if (c  == '1') {
					SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
					SDL_RenderFillRect(gRenderer, &square);
					//Update screen
					SDL_RenderPresent(getRenderer());
					square.x += 10;
					SDL_Delay(7);
				}
				else if (c == '0') {
					square.x += 10;
				}

				
				
			}
			square.y += 10;
			square.x = SCREEN_WIDTH / 6;
			ss.clear();
		}
	}
};


