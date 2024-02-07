#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_thread.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <stdbool.h>

void InitSDLImage(int img_flags) {
	if ( !( IMG_Init(img_flags) & img_flags ) )
		printf("SDL_image could not be initialized! SDL_image Error:\n%s\n", IMG_GetError());
}
 
int main(int argc, char *argv[])
{
	bool is_running = true;
	SDL_Event event;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("error initializing SDL: %s\n", SDL_GetError());
	}
	SDL_Window* win = SDL_CreateWindow("GAME",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			1000, 550, 0);
	SDL_Renderer* renderer = SDL_CreateRenderer(win, -1, 0);
	if (renderer == NULL) printf("Error creating renderer\n%s\n", SDL_GetError());
	
	// Initialize SDL_image
	InitSDLImage(IMG_INIT_JPG);

	// Load image
	SDL_Surface* image = IMG_Load("assets/start_screen/bg.jpg");
	if (image == NULL) printf("Error loading image\n%s\n", IMG_GetError());

	// Create Texture
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
	if (texture == NULL) printf("Error creating texture from loaded image\n%s\n", SDL_GetError());

	// Game loop
	while (is_running)
	{
		// wait indefinitely for event
		SDL_WaitEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			is_running = false;
			break;
		}
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
	}

	// Clean up
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(image);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;
}

