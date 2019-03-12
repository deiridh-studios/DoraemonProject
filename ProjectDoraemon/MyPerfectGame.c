#include "SDL/include/SDL.h"
#include "SDL_Image/include/SDL_image.h"
#include "SDL_Mixer/include/SDL_mixer.h"

#pragma comment(lib, "SDL_Image/libx86/SDL2_image.lib")
#pragma comment(lib, "SDL/libx86/SDL2.lib")
#pragma comment(lib, "SDL/libx86/SDL2main.lib")
#pragma comment(lib, "SDL_Mixer/libx86/SDL2_mixer.lib")


int main(int argc, char* argv[]) {
	int exit = 0, i, x = 50, y = 50, x1 = 0, ydown = 0, yup = 0, xright = 0, xleft = 0, createbullet[20] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, spaceup = 0;
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_AUDIO);
	IMG_Init(IMG_INIT_PNG);
	Mix_Init(MIX_INIT_OGG);
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_CHANNELS, 4096) == -1)
		exit = 1;
	Mix_Chunk *spaceeffect;
	spaceeffect = Mix_LoadWAV("Assets/SpaceEffect.wav");
	Mix_Music *music;
	music = Mix_LoadMUS("Assets/DoraemonBackground.ogg");
	Mix_PlayMusic(music, -1);
	SDL_Surface *surface, *surface2, *surface3;
	surface = IMG_Load("Assets/Background.png");
	surface2 = IMG_Load("Assets/Doraemon.png");
	surface3 = IMG_Load("Assets/Dorayaki.png");
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Event event;
	SDL_Rect srcrect, srcrect2[20];
	srcrect.x = 450;
	srcrect.y = 250;
	srcrect.w = 100;
	srcrect.h = 100;
	for (i = 0; i < 20; i++) {
		srcrect2[i].w = 40;
		srcrect2[i].h = 40;
	}
	window = SDL_CreateWindow("Doraemon loving his Dorayakis", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 500, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	SDL_Texture *texture, *texture2, *texture3;
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	texture2 = SDL_CreateTextureFromSurface(renderer, surface2);
	texture3 = SDL_CreateTextureFromSurface(renderer, surface3);
	SDL_FreeSurface(surface,surface2,surface3);
	while (exit == 0) {
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				exit = 1;
				break;
			case SDL_KEYDOWN:
				if (event.key.keysym.scancode == SDL_SCANCODE_UP)
					yup = 1;
				if (event.key.keysym.scancode == SDL_SCANCODE_DOWN)
					ydown = 1;
				if (event.key.keysym.scancode == SDL_SCANCODE_LEFT)
					xleft = 1;
				if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
					xright = 1;
				for (i = 0; i < 20; i++) {
					if (event.key.keysym.scancode == SDL_SCANCODE_SPACE && createbullet[i] == 0 && spaceup == 0) {
						Mix_PlayChannel(-1, spaceeffect, 0);
						createbullet[i] = 1;
						spaceup = 1;
					}
				}
				if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
					exit = 1;
				break;

			case SDL_KEYUP:
				if (event.key.keysym.scancode == SDL_SCANCODE_UP)
					yup = 0;
				if (event.key.keysym.scancode == SDL_SCANCODE_DOWN)
					ydown = 0;
				if (event.key.keysym.scancode == SDL_SCANCODE_LEFT)
					xleft = 0;
				if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
					xright = 0;
				if (event.key.keysym.scancode == SDL_SCANCODE_SPACE)
					spaceup = 0;
				break;
			
			}
		}
		if (yup == 1 && ydown == 1)
			srcrect.y = srcrect.y;
		else if ((yup == 1) && (srcrect.y>0))
			srcrect.y = srcrect.y - 5;
		else if ((ydown == 1) && (srcrect.y <400))
			srcrect.y = srcrect.y + 5;
		if (xright == 1 && xleft == 1)
			srcrect.x = srcrect.x;
		else if ((xright == 1) && (srcrect.x < 900))
			srcrect.x = srcrect.x + 5;
		else if ((xleft == 1) && (srcrect.x > 0))
			srcrect.x = srcrect.x - 5;
		for (i = 0; i < 20; i++) {
			if (createbullet[i] == 1) {
				srcrect2[i].x = srcrect.x + 40;
				srcrect2[i].y = srcrect.y + 45;
				createbullet[i] = 2;
			}


			else if (createbullet[i] == 2) {
				srcrect2[i].x += 8;
				if (srcrect2[i].x >= 985) {
					createbullet[i] = 0;
				}
			}
		}
		//SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		//SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		//SDL_RenderDrawRect(renderer, &srcrect);
		//SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		//SDL_RenderFillRect(renderer, &srcrect);
		SDL_RenderCopy(renderer, texture2, NULL, &srcrect);
		for (i = 0; i < 20; i++) {
			//SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

			if (createbullet[i] > 0) {
				//SDL_RenderFillRect(renderer, &srcrect2[i]);
				SDL_RenderCopy(renderer, texture3, NULL, &srcrect2[i]);

			}
		}
		SDL_RenderPresent(renderer);
	}
	SDL_DestroyTexture(texture,texture2,texture3);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	Mix_FreeMusic(music);
	Mix_FreeChunk(spaceeffect);
	Mix_CloseAudio();
	while (Mix_Init(0)) {
		Mix_Quit();
	}
	IMG_Quit();
	SDL_Quit();
	return 0;
}
