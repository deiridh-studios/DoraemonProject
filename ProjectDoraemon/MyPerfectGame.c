#include "SDL/include/SDL.h"
#include "SDL_Image/include/SDL_image.h"
#include "SDL_Mixer/include/SDL_mixer.h"
#include <time.h>

#pragma comment(lib, "SDL_Image/libx86/SDL2_image.lib")
#pragma comment(lib, "SDL/libx86/SDL2.lib")
#pragma comment(lib, "SDL/libx86/SDL2main.lib")
#pragma comment(lib, "SDL_Mixer/libx86/SDL2_mixer.lib")


int main(int argc, char* argv[]) {
	srand(time(NULL));
	int exit = 0, i, xleft1 = 0, xright1 = 0, yup1 = 0, ydown1=0, ydown = 0, yup = 0, xright = 0, xleft = 0, createbullet[20] = { 0 }, spaceup = 0, createbullet2[20] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, pup = 0, buttona = 0, randtear, randdorayaki;
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_AUDIO);
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Rect srcrect, srcrect3, srcrect2[20], srcrect4[20], srcrectinit;
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
	SDL_Event event;
	SDL_Surface *surface, *surface2, *surface3, *surface4, *surface5, *surtitle01;
	SDL_Texture *texture, *texture2, *texture3, *texture4, *texture5, *title01;
	IMG_Init(IMG_INIT_PNG);
	Mix_Init(MIX_INIT_OGG);
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_CHANNELS, 4096) == -1)
		exit = 1;
	Mix_Chunk *spaceeffect;
	spaceeffect = Mix_LoadWAV("Assets/SpaceEffect.wav");
	Mix_Music *music;
	music = Mix_LoadMUS("Assets/DoraemonBackground.ogg");
	Mix_PlayMusic(music, -1);
	surface = IMG_Load("Assets/Background.png");
	surface2 = IMG_Load("Assets/Doraemon.png");
	surface3 = IMG_Load("Assets/Dorayaki.png");
	surface4 = IMG_Load("Assets/Nobita.png");
	surface5 = IMG_Load("Assets/NobitaTear.png");
	surtitle01 = IMG_Load("Assets/Title01.png");
	window = SDL_CreateWindow("Doraemon loving his Dorayakis", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, 0);
	srcrect.x = 100;
	srcrect.y = 100;
	srcrect.w = 100;
	srcrect.h = 100;
	srcrect3.x = 100;
	srcrect3.y = 520;
	srcrect3.w = 100;
	srcrect3.h = 100;
	srcrectinit.w = 1280;
	srcrectinit.h = 720;
	srcrectinit.x = 0;
	srcrectinit.y = 0;
	for (i = 0; i < 20; i++) {
		srcrect2[i].w = 50;
		srcrect2[i].h = 50;
	}
	for (i = 0; i < 20; i++) {
		srcrect4[i].w = 50;
		srcrect4[i].h = 30;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	texture2 = SDL_CreateTextureFromSurface(renderer, surface2);
	texture3 = SDL_CreateTextureFromSurface(renderer, surface3);
	texture4 = SDL_CreateTextureFromSurface(renderer, surface4);
	texture5 = SDL_CreateTextureFromSurface(renderer, surface5);
	title01 = SDL_CreateTextureFromSurface(renderer, surtitle01);


	//Title
	SDL_FreeSurface(surface,surface2,surface3, surface4, surface5, surtitle01);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderCopy(renderer, title01, NULL, &srcrectinit);
	SDL_RenderPresent(renderer);

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
					if (event.key.keysym.scancode == SDL_SCANCODE_W)
						yup1 = 1;
					if (event.key.keysym.scancode == SDL_SCANCODE_S)
						ydown1 = 1;
					if (event.key.keysym.scancode == SDL_SCANCODE_D)
						xright1 = 1;


				if (event.key.keysym.scancode == SDL_SCANCODE_A)
					if (buttona == 0)
						buttona = 1;
					else
						xleft1 = 1;

				for (i = 0; i < 20; i++) {
					if (event.key.keysym.scancode == SDL_SCANCODE_P && createbullet[i] == 0 && spaceup == 0) {
						if (buttona == 1) {
							Mix_PlayChannel(-1, spaceeffect, 0);
						}
						createbullet[i] = 1;
						spaceup = 1;
					}
				}
				for (i = 0; i < 20; i++) {
					if (event.key.keysym.scancode == SDL_SCANCODE_SPACE && createbullet2[i] == 0 && pup == 0) {
						if (buttona == 1) {
							Mix_PlayChannel(-1, spaceeffect, 0);
						}
						createbullet2[i] = 1;
						pup = 1;
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
				if (event.key.keysym.scancode == SDL_SCANCODE_W)
					yup1 = 0;
				if (event.key.keysym.scancode == SDL_SCANCODE_S)
					ydown1 = 0;
				if (event.key.keysym.scancode == SDL_SCANCODE_D)
					xright1 = 0;
				if (event.key.keysym.scancode == SDL_SCANCODE_A)
					xleft1 = 0;
				if (event.key.keysym.scancode == SDL_SCANCODE_P)
					spaceup = 0;
				if (event.key.keysym.scancode == SDL_SCANCODE_SPACE)
					pup = 0;
				break;
			}
		}

		if(buttona==1){
			if (yup == 1 && ydown == 1)
				srcrect.y = srcrect.y;
			else if ((yup == 1) && (srcrect.y>0))
				srcrect.y = srcrect.y - 5;
			else if ((ydown == 1) && (srcrect.y <620))
				srcrect.y = srcrect.y + 5;
			if (xright == 1 && xleft == 1)
				srcrect.x = srcrect.x;
			else if ((xright == 1) && (srcrect.x < 1180))
				srcrect.x = srcrect.x + 5;
			else if ((xleft == 1) && (srcrect.x > 0))
				srcrect.x = srcrect.x - 5;
			if (yup1 == 1 && ydown1 == 1)
				srcrect3.y = srcrect3.y;
			else if ((yup1 == 1) && (srcrect3.y > 0))
				srcrect3.y = srcrect3.y - 5;
			else if ((ydown1 == 1) && (srcrect3.y < 620))
				srcrect3.y = srcrect3.y + 5;
			if (xright1 == 1 && xleft1 == 1)
				srcrect3.x = srcrect3.x;
			else if ((xright1 == 1) && (srcrect3.x < 1180))
				srcrect3.x = srcrect3.x + 5;
			else if ((xleft1 == 1) && (srcrect3.x > 0))
				srcrect3.x = srcrect3.x - 5;

			for (i = 0; i < 20; i++) {
				if (createbullet[i] == 1) {
					srcrect2[i].x = srcrect.x + 80;
					srcrect2[i].y = srcrect.y + 45;
					createbullet[i] = 2;
				}
				else if (createbullet[i] == 2) {
					srcrect2[i].x += 8;
					srcrect2[i].y += 1;
					if (srcrect2[i].x >= 1300) {
						createbullet[i] = 0;
					}
				}
			}

			for (i = 0; i < 20; i++) {
				if (createbullet2[i] == 1) {
					srcrect4[i].x = srcrect3.x + 90;
					srcrect4[i].y = srcrect3.y + 35;
					createbullet2[i] = 2;
				}
				else if (createbullet2[i] == 2) {
					randtear = rand() % 3;
					srcrect4[i].y += -1;
					srcrect4[i].x += 7;
					if (srcrect4[i].x >= 1300) {
						createbullet2[i] = 0;
					}
				}
			}

			SDL_RenderCopy(renderer, texture, NULL, NULL);
			SDL_RenderCopy(renderer, texture2, NULL, &srcrect);
		    SDL_RenderCopy(renderer, texture4, NULL, &srcrect3);

			for (i = 0; i < 20; i++) {
				if (createbullet[i] > 0) {
					SDL_RenderCopy(renderer, texture3, NULL, &srcrect2[i]);
				}
			}
			for (i = 0; i < 20; i++) {
				if (createbullet2[i] > 0) {
					SDL_RenderCopy(renderer, texture5, NULL, &srcrect4[i]);
				}
			}

			SDL_RenderPresent(renderer);
		}
	}
	SDL_DestroyTexture(texture,texture2,texture3, texture4, title01);
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
