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
	int exit = 0, i, xleft1 = 0, xright1 = 0, yup1 = 0, ydown1 = 0, ydown = 0, yup = 0, xright = 0, xleft = 0, createbullet[20] = { 0 }, spaceup = 0, createbullet2[20] = { 0 }, pup = 0, buttona = 0, randtear, randdorayaki, createenemy[31] = { 0 }, randx[31], randy[31], enough = 0, futureenough = 1, enemycount = 0, life = 50, GameOver, examcollision[16] = { 0 };
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_AUDIO);
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Rect doraemonrect, dorayakirect[20], nobitarect,  nobitatearrect[20], examrect[31], srcrectinit, liferect, lifeoutrect, gameoverrect;
	SDL_Event event;
	SDL_Surface *surbackground, *surdoraemon, *surdorayaki, *surnobita, *surnobitatearrect, *surexam, *surlife, *surtitle01, *surlifein, *surgameover;
	SDL_Texture *texbackground, *texdoraemon, *texdorayaki, *texnobita, *texnobitatearrect, *texexam, *texlife, *title01, *texlifein, *texgameover;
	IMG_Init(IMG_INIT_PNG);
	Mix_Init(MIX_INIT_OGG);
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_CHANNELS, 4096) == -1);
	//	exit = 1;
	Mix_Chunk *spaceeffect;
	spaceeffect = Mix_LoadWAV("Assets/SpaceEffect.wav");
	Mix_Music *music;
	music = Mix_LoadMUS("Assets/DoraemonBackground.ogg");
	Mix_PlayMusic(music, -1);

	surbackground = IMG_Load("Assets/Background.png");
	surlife = IMG_Load("Assets/LifeOut.png");
	surlifein = IMG_Load("Assets/LifeIn.png");
	surgameover = IMG_Load("Assets/GameOver.png");

	surdoraemon = IMG_Load("Assets/Doraemon.png");
	surdorayaki = IMG_Load("Assets/Dorayaki.png");

	surnobita = IMG_Load("Assets/Nobita.png");
	surnobitatearrect = IMG_Load("Assets/NobitaTear.png");

	surexam = IMG_Load("Assets/Exam.png");
	surtitle01 = IMG_Load("Assets/Title01.png");


	window = SDL_CreateWindow("Doraemon. The Real Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, 0);
	doraemonrect.x = 100;
	doraemonrect.y = 100;
	doraemonrect.w = 100;
	doraemonrect.h = 100;

	nobitarect.x = 100;
	nobitarect.y = 520;
	nobitarect.w = 100;
	nobitarect.h = 100;

	srcrectinit.w = 1280;
	srcrectinit.h = 720;
	srcrectinit.x = 0;
	srcrectinit.y = 0;

	liferect.x = 420;
	liferect.y = 12;
	liferect.w = 400;
	liferect.h = 40;

	gameoverrect.x = 0;
	gameoverrect.y = 0;
	gameoverrect.w = 1280;
	gameoverrect.h = 720;

	lifeoutrect.x = 0;
	lifeoutrect.y = 0;
	lifeoutrect.w = 1280;
	lifeoutrect.h = 720;

	for (i = 0; i < 20; i++) {
		dorayakirect[i].w = 50;
		dorayakirect[i].h = 50;
	}
	for (i = 0; i < 20; i++) {
		nobitatearrect[i].w = 40;
		nobitatearrect[i].h = 30;
	}
	for (i = 0; i < 31; i++) {
		examrect[i].w = 100;
		examrect[i].h = 70;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	texbackground = SDL_CreateTextureFromSurface(renderer, surbackground);
	texdoraemon = SDL_CreateTextureFromSurface(renderer, surdoraemon);
	texdorayaki = SDL_CreateTextureFromSurface(renderer, surdorayaki);
	texnobita = SDL_CreateTextureFromSurface(renderer, surnobita);
	texnobitatearrect = SDL_CreateTextureFromSurface(renderer, surnobitatearrect);
	texlife = SDL_CreateTextureFromSurface(renderer, surlife);
	texlifein = SDL_CreateTextureFromSurface(renderer, surlifein);
	texgameover = SDL_CreateTextureFromSurface(renderer, surgameover);
	texexam = SDL_CreateTextureFromSurface(renderer, surexam);
	title01 = SDL_CreateTextureFromSurface(renderer, surtitle01);


	SDL_FreeSurface(surbackground,surdoraemon,surdorayaki, surnobita, surnobitatearrect, surexam, surtitle01, surgameover, surlifein, surlife);

	SDL_RenderCopy(renderer, texbackground, NULL, NULL);
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
							createbullet[i] = 1;
						}
						spaceup = 1;
					}
				}
				for (i = 0; i < 20; i++) {
					if (event.key.keysym.scancode == SDL_SCANCODE_SPACE && createbullet2[i] == 0 && pup == 0) {
						if (buttona == 1) {
							Mix_PlayChannel(-1, spaceeffect, 0);
							createbullet2[i] = 1;
						}
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

		///////////  If the player play A    ////////////

		if(buttona == 1){  
			//Doraemon moveset
			if (yup == 1 && ydown == 1)
				doraemonrect.y = doraemonrect.y;
			else if ((yup == 1) && (doraemonrect.y>0))
				doraemonrect.y = doraemonrect.y - 5;
			else if ((ydown == 1) && (doraemonrect.y <620))
				doraemonrect.y = doraemonrect.y + 5;
			if (xright == 1 && xleft == 1)
				doraemonrect.x = doraemonrect.x;
			else if ((xright == 1) && (doraemonrect.x < 1180))
				doraemonrect.x = doraemonrect.x + 5;
			else if ((xleft == 1) && (doraemonrect.x > 0))
				doraemonrect.x = doraemonrect.x - 5;

			//Novita moveset
			if (yup1 == 1 && ydown1 == 1)
				nobitarect.y = nobitarect.y;
			else if ((yup1 == 1) && (nobitarect.y > 0))
				nobitarect.y = nobitarect.y - 5;
			else if ((ydown1 == 1) && (nobitarect.y < 620))
				nobitarect.y = nobitarect.y + 5;
			if (xright1 == 1 && xleft1 == 1)
				nobitarect.x = nobitarect.x;
			else if ((xright1 == 1) && (nobitarect.x < 1180))
				nobitarect.x = nobitarect.x + 5;
			else if ((xleft1 == 1) && (nobitarect.x > 0))
				nobitarect.x = nobitarect.x - 5;

			for (i = 0; i < 20; i++) {
				if (createbullet[i] == 1) {
					dorayakirect[i].x = doraemonrect.x + 80;
					dorayakirect[i].y = doraemonrect.y + 45;
					createbullet[i] = 2;
				}
				else if (createbullet[i] == 2) {
					dorayakirect[i].x += 10;
					dorayakirect[i].y += 1;
					if ((dorayakirect[i].x >= nobitarect.x && dorayakirect[i].x <= nobitarect.x + 100) && (dorayakirect[i].y >= nobitarect.y && dorayakirect[i].y <= nobitarect.y + 100)) {
						life = life - 10;
						liferect.w -= 100;
						createbullet[i] = 0;
					}
					if (dorayakirect[i].x >= 1300) {
						createbullet[i] = 0;
					}
				}
			}

			for (i = 0; i < 20; i++) {
				if (createbullet2[i] == 1) {
					nobitatearrect[i].x = nobitarect.x + 90;
					nobitatearrect[i].y = nobitarect.y + 35;
					createbullet2[i] = 2;
				}
				else if (createbullet2[i] == 2) {
					nobitatearrect[i].y += -1;
					nobitatearrect[i].x += 10;
					if ((nobitatearrect[i].x >= doraemonrect.x && nobitatearrect[i].x <= doraemonrect.x + 100) && (nobitatearrect[i].y >= doraemonrect.y && nobitatearrect[i].y <= doraemonrect.y + 100)) {
						life = life - 10;
						liferect.w -= 100;
						createbullet2[i] = 0;
					}

					if (nobitatearrect[i].x >= 1300) {
						createbullet2[i] = 0;
					}
				}
			}


			if (enough == 0) {
				for (enough = 0; enough < futureenough; enough++) {
					examrect[enemycount].x = 1300;
					examrect[enemycount].y = rand() % 653;
					createenemy[enemycount] = 1;
					randx[enemycount] = (rand() % 5) + 1;
					randy[enemycount] = (rand() % 10) + 1;
					if (randy[enemycount] > 5) {
						randy[enemycount] -= 5;
						randy[enemycount] = 0 - randy[enemycount];
					}
					enemycount++;
				}
				if (futureenough < 16 && futureenough > 0)
					futureenough *= 2;
				else
					futureenough = 0;
			}

			if(enough!=0){
				for (i = 0; i < enough; i++) {
					if (createenemy[i] == 1) {
						examrect[i].x -= randx[i];
						examrect[i].y += randy[i];
						if (examrect[i].x <= -60) {
							examrect[i].x = -60;
							randx[i] = 0 - randx[i];
						}
						else if (examrect[i].x >= 1300) {
							examrect[i].x = 1300;
							randx[i] = 0 - randx[i];
						}
						if (examrect[i].y <= 0) {
							examrect[i].y = 0;
							randy[i] = 0 - randy[i];
						}
						else if (examrect[i].y >= 653) {
							examrect[i].y =653;
							randy[i] = 0 - randy[i];
						}
					}
					for (int j = 0; j < 16; j++) {
						if (examcollision[i] == 0) {
							if (((examrect[i].x >= doraemonrect.x && examrect[i].x <= doraemonrect.x + 100) && (examrect[i].y >= doraemonrect.y && examrect[i].y <= doraemonrect.y + 100)) || ((examrect[i].x >= nobitarect.x && examrect[i].x <= nobitarect.x + 100) && (examrect[i].y >= nobitarect.y && examrect[i].y <= nobitarect.y + 100))) {
								life = life - 10;
								liferect.w -= 50;
								examcollision[i] = 1;
							}
						}
						else if (examcollision[i] == 1){
							if (((examrect[i].x < doraemonrect.x && examrect[i].x > doraemonrect.x + 100) && (examrect[i].y < doraemonrect.y && examrect[i].y > doraemonrect.y + 100)) || ((examrect[i].x < nobitarect.x && examrect[i].x > nobitarect.x + 100) && (examrect[i].y < nobitarect.y && examrect[i].y > nobitarect.y + 100))) {
								life = life - 10;
								liferect.w -= 50;
								examcollision[i] = 0;
							}
						}
					}
				}
			}

			if (liferect.w == 0) {
				SDL_RenderCopy(renderer, texbackground, NULL, NULL);
				SDL_RenderCopy(renderer, texgameover, NULL, &gameoverrect);
			}

			if (liferect.w >= 1) {
				SDL_RenderCopy(renderer, texbackground, NULL, NULL);
				SDL_RenderCopy(renderer, texdoraemon, NULL, &doraemonrect);
				SDL_RenderCopy(renderer, texnobita, NULL, &nobitarect);
				SDL_RenderCopy(renderer, texexam, NULL, &examrect);
				SDL_RenderCopy(renderer, texlifein, NULL, &liferect);
				SDL_RenderCopy(renderer, texlife, NULL, &lifeoutrect);
			}

			for (i = 0; i < 20; i++) {
				if (createbullet[i] > 0) {
					SDL_RenderCopy(renderer, texdorayaki, NULL, &dorayakirect[i]);
				}
			}

			for (i = 0; i < 20; i++) {
				if (createbullet2[i] > 0) {
					SDL_RenderCopy(renderer, texnobitatearrect, NULL, &nobitatearrect[i]);
				}
			}


			SDL_RenderPresent(renderer);
		}
	}
	SDL_DestroyTexture(texbackground, texdoraemon, texdorayaki, texnobita, title01);
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
