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
	int exit = 0, i, xleft1 = 0, xright1 = 0, yup1 = 0, ydown1 = 0, countout=0, ydown = 0, yup = 0, xright = 0, xleft = 0, bosscreate=0, examcollision[16] = { 0 }, chanclacollision[16] = { 0 }, createbullet = 0, spaceup = 0, createbullet2 =  0, pup = 0, buttona = 0, randtear, randdorayaki, createenemy[16] = { 0 }, createenemy2[16] = { 0 }, randx[16], randy[16], enough = 0, futureenough = 1, enough2 = 0, futureenough2 = 1, life = 40, lifeboss = 820, GameOver, enemies=0, enemies2=0, xchange = 0, ychange = 0, firsttime = 0, bossmovey=0,bossround = 1, createchancla[5] = { 0 }, randx2[5] = { 0 }, randy2[5] = { 0 };
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_AUDIO);
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Rect chanclarect[8], explication01rect, explication02rect, doraemonrect, lifeoutbossrect, lifeinbossrect, victoryrect, dorayakirect, nobitarect,  nobitatearrect, examrect[16], srcrectinit, liferect, lifeoutrect, gameoverrect, bossrect;
	SDL_Event event;
	SDL_Surface *surbackground, *surexplication01, *surexplication02, *surchancla, *surdoraemon, *surlifeoutboss, *survictory, *surlifeinboss, *surdorayaki, *surnobita, *surnobitatearrect, *surexam, *surlife, *surtitle01, *surlifein, *surboss, *surgameover;
	SDL_Texture *texbackground, *texexplication01, *texexplication02, *texchancla, *texdoraemon, *texdorayaki, *texlifeoutboss, *texvictory, *texlifeinboss, *texnobita, *texnobitatearrect, *texexam, *texlife, *title01, *texlifein, *texboss, *texgameover;
	IMG_Init(IMG_INIT_PNG);
	Mix_Init(MIX_INIT_OGG);
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_CHANNELS, 4096) == -1);
	//	exit = 1;
	Mix_Chunk *spaceeffect, *hitlife, *gameov, *victory;
	spaceeffect = Mix_LoadWAV("Assets/SpaceEffect.wav");
	hitlife = Mix_LoadWAV("Assets/HitLifeEffect.wav");
	victory = Mix_LoadWAV("Assets/victorysong.wav");
	gameov = Mix_LoadWAV("Assets/defeatsound.wav");
	Mix_Music *music;
	Mix_Music *bossmusic;
	music = Mix_LoadMUS("Assets/DoraemonBackground.ogg");
	bossmusic= Mix_LoadMUS("Assets/bosssong.ogg");
	Mix_PlayMusic(music, -1);

	surbackground = IMG_Load("Assets/Background.png");
	surlife = IMG_Load("Assets/LifeOut.png");
	surchancla = IMG_Load("Assets/Slipper.png");
	surlifein = IMG_Load("Assets/LifeIn.png");
	surboss = IMG_Load("Assets/boss1.png");
	surexplication01 = IMG_Load("Assets/explanation1.png");
	surexplication02 = IMG_Load("Assets/explanation2.png");
	surgameover = IMG_Load("Assets/GameOver.png");
	surlifeoutboss = IMG_Load("Assets/LifeOutBoss.png");
	surlifeinboss = IMG_Load("Assets/LifeInBoss.png");
	survictory = IMG_Load("Assets/VICTORYBO.png");
	surdoraemon = IMG_Load("Assets/Doraemon.png");
	surdorayaki = IMG_Load("Assets/Dorayaki.png");

	surnobita = IMG_Load("Assets/Nobita.png");
	surnobitatearrect = IMG_Load("Assets/NobitaTear.png");

	surexam = IMG_Load("Assets/Exam.png");
	surtitle01 = IMG_Load("Assets/Title01.png");


	window = SDL_CreateWindow("Doraemon. The Real Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, 0);
	
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	texbackground = SDL_CreateTextureFromSurface(renderer, surbackground);
	texdoraemon = SDL_CreateTextureFromSurface(renderer, surdoraemon);
	texdorayaki = SDL_CreateTextureFromSurface(renderer, surdorayaki);
	texnobita = SDL_CreateTextureFromSurface(renderer, surnobita);
	texnobitatearrect = SDL_CreateTextureFromSurface(renderer, surnobitatearrect);
	texlife = SDL_CreateTextureFromSurface(renderer, surlife);
	texlifein = SDL_CreateTextureFromSurface(renderer, surlifein);
	texgameover = SDL_CreateTextureFromSurface(renderer, surgameover);
	texboss = SDL_CreateTextureFromSurface(renderer, surboss);
	texexam = SDL_CreateTextureFromSurface(renderer, surexam);
	texchancla = SDL_CreateTextureFromSurface(renderer, surchancla);
	texexplication01 = SDL_CreateTextureFromSurface(renderer, surexplication01);
	texexplication02 = SDL_CreateTextureFromSurface(renderer, surexplication02);
	texvictory = SDL_CreateTextureFromSurface(renderer, survictory);
	texlifeoutboss = SDL_CreateTextureFromSurface(renderer, surlifeoutboss);
	texlifeinboss = SDL_CreateTextureFromSurface(renderer, surlifeinboss);
	title01 = SDL_CreateTextureFromSurface(renderer, surtitle01);


	SDL_FreeSurface(surbackground,surdoraemon,surdorayaki, surnobita, surnobitatearrect, surexplication01, surexplication02, surchancla, survictory, surlifeoutboss, surlifeinboss, surexam, surtitle01, surgameover, surlifein, surlife, surboss);
	while (exit == 0) {
		if (buttona == 0) {
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

			lifeinbossrect.x = 230;
			lifeinbossrect.y = 680;
			lifeinbossrect.w = 820;
			lifeinbossrect.h = 40;

			lifeoutbossrect.x = 0;
			lifeoutbossrect.y = 0;
			lifeoutbossrect.w = 1280;
			lifeoutbossrect.h = 720;

			gameoverrect.x = 0;
			gameoverrect.y = 0;
			gameoverrect.w = 1280;
			gameoverrect.h = 720;

			explication01rect.x = 0;
			explication01rect.y = 0;
			explication01rect.w = 1280;
			explication01rect.h = 720;

			explication02rect.x = 0;
			explication02rect.y = 0;
			explication02rect.w = 1280;
			explication02rect.h = 720;

			lifeoutrect.x = 0;
			lifeoutrect.y = 0;
			lifeoutrect.w = 1280;
			lifeoutrect.h = 720;

			bossrect.x = 1500;
			bossrect.y = 260;
			bossrect.w = 200;
			bossrect.h = 200;

			dorayakirect.w = 50;
			dorayakirect.h = 50;

			nobitatearrect.w = 40;
			nobitatearrect.h = 30;

			for (i = 0; i < 16; i++) {
				examrect[i].w = 100;
				examrect[i].h = 100;
			}
			xleft1 = 0, xright1 = 0, yup1 = 0, ydown1 = 0, ydown = 0, yup = 0, life = 40, xright = 0, xleft = 0, createbullet = 0, spaceup = 0, createbullet2 = 0, pup = 0, buttona = 0, enough = 0, futureenough = 1, enemies = 0, xchange = 0, ychange = 0, lifeboss = 820;
			for (i = 0; i < 16; i++) {
				examcollision[i] = 0;
				createenemy[i] = 0;
			}
			for (i = 0; i < 5; i++) {
				chanclacollision[i] = 0;
				createenemy2[i] = 0;
				chanclarect[i].w = 100;
				chanclarect[i].h = 100;
			}

		//	if (countout == 0) {
			if (firsttime == 0) {
				SDL_RenderCopy(renderer, texbackground, NULL, NULL);
				SDL_RenderCopy(renderer, title01, NULL, &srcrectinit);
				SDL_RenderPresent(renderer);
			}
			//}
		}
		else if (buttona == 2) {
			SDL_RenderCopy(renderer, texbackground, NULL, NULL);
			SDL_RenderCopy(renderer, texexplication01, NULL, &srcrectinit);
			SDL_RenderPresent(renderer);
		}
		else if (buttona == 3) {
			SDL_RenderCopy(renderer, texbackground, NULL, NULL);
			SDL_RenderCopy(renderer, texexplication02, NULL, &srcrectinit);
			SDL_RenderPresent(renderer);
		}
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
				if (event.key.keysym.scancode == SDL_SCANCODE_A) {
					if (buttona == 0) {
						if (firsttime != 0) {
							Mix_HaltChannel(-1);
							Mix_PlayMusic(music, -1);
							buttona = 1;
						}
						else
							buttona = 2;
						firsttime = 1;
					}
					else if (buttona == 2)
						buttona = 3;
					else if (buttona == 3)
						buttona = 1;
					else {
						xleft1 = 1;
					}
				}

				for (i = 0; i < 20; i++) {
					if (event.key.keysym.scancode == SDL_SCANCODE_P && createbullet == 0 && spaceup == 0) {
						if (buttona == 1) {
							if ((lifeboss > 0) && (life > 0)) {
							Mix_PlayChannel(-1, spaceeffect, 0);
							}
							createbullet = 1;
						}
						spaceup = 1;
					}
				}
				for (i = 0; i < 20; i++) {
					if (event.key.keysym.scancode == SDL_SCANCODE_SPACE && createbullet2 == 0 && pup == 0) {
						if (buttona == 1) {
							if ((lifeboss > 0) && (life > 0)) {
								Mix_PlayChannel(-1, spaceeffect, 0);
							}
							createbullet2 = 1;
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
		if (buttona == 1) {
			//Doraemon moveset
			if (yup == 1 && ydown == 1)
				doraemonrect.y = doraemonrect.y;
			else if ((yup == 1) && (doraemonrect.y > 0))
				doraemonrect.y = doraemonrect.y - 5;
			else if ((ydown == 1) && (doraemonrect.y < 620))
				doraemonrect.y = doraemonrect.y + 5;
			if (xright == 1 && xleft == 1)
				doraemonrect.x = doraemonrect.x;
			else if ((xright == 1) && (doraemonrect.x < 1180))
				doraemonrect.x = doraemonrect.x + 5;
			else if ((xleft == 1) && (doraemonrect.x > 0))
				doraemonrect.x = doraemonrect.x - 5;

			//Nobita moveset
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

			//Creation and collider of Dorayakis
			if (createbullet == 1) {
				dorayakirect.x = doraemonrect.x + 80;
				dorayakirect.y = doraemonrect.y + 45;
				createbullet = 2;
			}
			else if (createbullet == 2) {
				dorayakirect.x += 10;
				dorayakirect.y += 1;
				if (((dorayakirect.x + 50) >= nobitarect.x && dorayakirect.x <= nobitarect.x + 100) && ((dorayakirect.y + 50) >= nobitarect.y && dorayakirect.y <= nobitarect.y + 100)) {
					life = life - 10;
					liferect.w -= 100;
					createbullet = 0;
					Mix_PlayChannel(-1, hitlife, 0);
				}
				for (int j = 0; j < enemies; j++) {
					if (((((((dorayakirect.x + 50) >= examrect[j].x && dorayakirect.x <= examrect[j].x + 100) && ((dorayakirect.y + 50) >= examrect[j].y && dorayakirect.y <= examrect[j].y + 100))))) && enough > 0) {
						examrect[j].x = 3000;
						examrect[j].y = 3000;
						createenemy[j] = 0;
						dorayakirect.x = 3000;
						dorayakirect.y = 3000;
						//enough--;
					}
				}
				for (int k = 0; k < futureenough2; k++) {
					if (((((((dorayakirect.x + 50) >= chanclarect[k].x && dorayakirect.x <= chanclarect[k].x + 100) && ((dorayakirect.y + 50) >= chanclarect[k].y && dorayakirect.y <= chanclarect[k].y + 100))))) && createchancla[k] > 0) {
						chanclarect[k].x = 3000;
						chanclarect[k].y = 3000;
						createenemy2[k] = createchancla[k] = 0;
						dorayakirect.x = 3000;
						dorayakirect.y = 3000;
					}
				}
				if (dorayakirect.x >= 1300) {
					dorayakirect.x = 3000;
					createbullet = 0;
				}
			}

			//Creation and collider of Nobita's Tears
			if (createbullet2 == 1) {
				nobitatearrect.x = nobitarect.x + 90;
				nobitatearrect.y = nobitarect.y + 35;
				createbullet2 = 2;
			}
			else if (createbullet2 == 2) {
				nobitatearrect.y += -1;
				nobitatearrect.x += 10;
				if (((nobitatearrect.x) + 40 >= doraemonrect.x && nobitatearrect.x <= doraemonrect.x + 100) && ((nobitatearrect.y) + 30 >= doraemonrect.y && nobitatearrect.y <= doraemonrect.y + 100)) {
					life = life - 10;
					liferect.w -= 100;
					createbullet2 = 0;
					Mix_PlayChannel(-1, hitlife, 0);
				}
				for (int j = 0; j < enemies; j++) {
					if ((((((nobitatearrect.x + 40) >= examrect[j].x && nobitatearrect.x <= examrect[j].x + 100) && ((nobitatearrect.y + 30) >= examrect[j].y && nobitatearrect.y <= examrect[j].y + 100))))) {
						nobitatearrect.x = 3000;
						nobitatearrect.y = 3000;
					}
				}
				for (int k = 0; k < futureenough2; k++) {
					if (((((((nobitatearrect.x + 40) >= chanclarect[k].x && nobitatearrect.x <= chanclarect[k].x + 100) && ((nobitatearrect.y + 40) >= chanclarect[k].y && nobitatearrect.y <= chanclarect[k].y + 100))))) && createchancla[k] > 0) {
						nobitatearrect.x = 3000;
						nobitatearrect.y = 3000;
					}
				}
				if (bosscreate >= 5) {
					if (((nobitatearrect.x) + 40 >= bossrect.x && nobitatearrect.x <= bossrect.x + 150) && ((nobitatearrect.y) + 40 >= bossrect.y && nobitatearrect.y <= bossrect.y + 150)) {
						lifeboss = lifeboss - 50;
						lifeinbossrect.w -= 50;
						createbullet2 = 0;
						if (bossround < 5)
							bossround++;
					}
				}
				if (nobitatearrect.x >= 1300) {
					createbullet2 = 0;
				}
			}


			//Creation of enemies (exams) and their velocities
			for (int i = 0; i < enemies; i++) {
				if (createenemy[i] == 0)
					enough--;
			}
			if (enough == 0) {
				for (int j = 0; j < futureenough; j++) {
					examrect[j].x = 1180;
					examrect[j].y = rand() % 653;
					createenemy[j] = 1;
					randx[j] = (rand() % 5) + 1;
					randy[j] = (rand() % 10) + 1;
					if (randy[j] > 5) {
						randy[j] -= 5;
						randy[j] = 0 - randy[j];
					}
				}
				enemies = enough = futureenough;

				if (futureenough < 16) {
					bosscreate++;
					futureenough *= 2;
				}
				else
					futureenough = 0;
			}
			else enough = enemies;

			if (enough != 0) {
				for (i = 0; i < enemies; i++) {
					if (createenemy[i] == 1) {
						examrect[i].x -= randx[i];
						examrect[i].y += randy[i];

						//Rebounce doraemon (later)
						if ((((((examrect[i].x + 100) >= doraemonrect.x && examrect[i].x <= doraemonrect.x + 100) && ((examrect[i].y + 100) >= doraemonrect.y && examrect[i].y <= doraemonrect.y + 100))))) {
							examrect[i].x = (rand() % 1180);
							examrect[i].y = (rand() % 620);

						}

						if (examrect[i].x <= 0) {
							examrect[i].x = 0;
							randx[i] = 0 - randx[i];
						}
						else if (examrect[i].x >= 1280) {
							examrect[i].x = 1280;
							randx[i] = 0 - randx[i];
						}
						if (examrect[i].y <= 0) {
							examrect[i].y = 0;
							randy[i] = 0 - randy[i];
						}
						else if (examrect[i].y >= 653) {
							examrect[i].y = 653;
							randy[i] = 0 - randy[i];
						}
					}
					else if (createenemy == 0) {
						examrect[i].x = 2000;
						examrect[i].y = 2000;
					}


					//Collision exam with Nobita
					if ((((((examrect[i].x + 100) >= nobitarect.x && examrect[i].x <= nobitarect.x + 100) && ((examrect[i].y + 100) >= nobitarect.y && examrect[i].y <= nobitarect.y + 100))))) {
						if (examcollision[i] == 0) {
							life = life - 5;
							liferect.w -= 50;
							examcollision[i] = 1;
							Mix_PlayChannel(-1, hitlife, 0);
						}
					}
					else examcollision[i] = 0;
				}
			}


			//BOSS Apearing (the variable bosscreate show when the exams ended and when the boss has to appear)
			if ((bosscreate >= 5) && (bossrect.x > 1050)) {
				Mix_HaltMusic(music);
				Mix_PlayMusic(bossmusic, -1);
				bossrect.x = bossrect.x - 10;
				bossmovey = 15;
			}
			if ((bosscreate >= 5) && (bossrect.x <= 1050)) {
				bossrect.x = 1050;
				bossrect.y = bossrect.y + bossmovey;
				if (bossrect.y <= 0) {
					bossmovey += 15;
				}
				if (bossrect.y >= 550) {
					bossmovey -= 15;
				}
				futureenough2 = bossround;
				for (int i = 0; i < futureenough2; i++) {
					if (createchancla[i] == 0) {
						chanclarect[i].x = bossrect.x + 1;
						chanclarect[i].y = bossrect.y + 100;
						createenemy2[i] = createchancla[i] = 1;
						randx2[i] = (rand() % 10) + 5;
						randx2[i] = 0 - randx2[i];
						randy2[i] = (rand() % 3);
						if (randy2[i] > 1) {
							randy2[i] -= 2;
							randy2[i] = 0 - randy2[i];
						}
					}
					else {
						chanclarect[i].x += randx2[i];
						chanclarect[i].y += randy2[i];
						if (chanclarect[i].x <= -100) {
							createenemy2[i] = createchancla[i] = 0;
						}
						else if (chanclarect[i].y < -100 || chanclarect[i].y>720) {
							createenemy2[i] = createchancla[i] = 0;
						}
					}
					if ((((((chanclarect[i].x + 100) >= doraemonrect.x && chanclarect[i].x <= doraemonrect.x + 100) && ((chanclarect[i].y + 100) >= doraemonrect.y && chanclarect[i].y <= doraemonrect.y + 100))))) {
						life = life - 5;
						liferect.w -= 50;
						Mix_PlayChannel(-1, hitlife, 0);
						createenemy2[i] = createchancla[i] = 0;
						chanclarect[i].x = 2000;
						chanclarect[i].y = 2000;
					}
					if ((((((chanclarect[i].x + 100) >= nobitarect.x && chanclarect[i].x <= nobitarect.x + 100) && ((chanclarect[i].y + 100) >= nobitarect.y && chanclarect[i].y <= nobitarect.y + 100))))) {
						life = life - 5;
						liferect.w -= 50;
						Mix_PlayChannel(-1, hitlife, 0);
						createenemy2[i] = createchancla[i] = 0;
						chanclarect[i].x = 2000;
						chanclarect[i].y = 2000;
					}
				}

			}



			if (life <= 0) {
				SDL_RenderCopy(renderer, texbackground, NULL, NULL);
				SDL_RenderCopy(renderer, texgameover, NULL, &gameoverrect);
				Mix_PlayChannel(-1, gameov, 0);
				Mix_HaltMusic();
				buttona = 0;
				//countout++;
				bosscreate = 0;
			}


			if (lifeboss <= 0) {
				SDL_RenderCopy(renderer, texbackground, NULL, NULL);
				SDL_RenderCopy(renderer, texvictory, NULL, &victoryrect);
				Mix_HaltMusic();
				Mix_PlayChannel(-1, victory, 0);
				buttona = 0;
				//countout++;
				bosscreate = 0;
			}

			if ((liferect.w >= 1) && (lifeinbossrect.w >= 1)) {
				SDL_RenderCopy(renderer, texbackground, NULL, NULL);
				SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
				SDL_RenderFillRect(renderer, &doraemonrect);
				SDL_RenderCopy(renderer, texdoraemon, NULL, &doraemonrect);
				SDL_RenderFillRect(renderer, &nobitarect);
				SDL_RenderCopy(renderer, texnobita, NULL, &nobitarect);
				for (i = 0; i < enemies; i++) {
					if (createenemy != 0) {
						SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
						SDL_RenderFillRect(renderer, &examrect[i]);
						SDL_RenderCopy(renderer, texexam, NULL, &examrect[i]);
					}
				}
				if (bosscreate >= 5) {
					SDL_RenderCopy(renderer, texboss, NULL, &bossrect);
					SDL_RenderCopy(renderer, texlifeinboss, NULL, &lifeinbossrect);
					SDL_RenderCopy(renderer, texlifeoutboss, NULL, &lifeoutbossrect);
					for (i = 0; i < futureenough2; i++) {
						if (createenemy2[i] != 0) {
							SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
							SDL_RenderFillRect(renderer, &chanclarect[i]);
							SDL_RenderCopy(renderer, texchancla, NULL, &chanclarect[i]);
						}
					}
				}

				if ((lifeboss > 0) && (life > 0)) {
					if (createbullet > 0) {
						SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
						SDL_RenderFillRect(renderer, &dorayakirect);
						SDL_RenderCopy(renderer, texdorayaki, NULL, &dorayakirect);
					}

					if (createbullet2 > 0) {
						SDL_RenderCopy(renderer, texnobitatearrect, NULL, &nobitatearrect);
					}
				}

				SDL_RenderCopy(renderer, texlifein, NULL, &liferect);
				SDL_RenderCopy(renderer, texlife, NULL, &lifeoutrect);
			}
			SDL_RenderPresent(renderer);
		}
	}

	SDL_DestroyTexture(texbackground, texdoraemon, texdorayaki, texnobita, title01, texexam, texgameover, texlife, texlifein, texnobitatearrect, texboss, texchancla, texlifeinboss, texlifeoutboss, texvictory);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	Mix_FreeMusic(bossmusic);
	Mix_FreeMusic(music);
	Mix_FreeChunk(hitlife);
	Mix_FreeChunk(gameov);
	Mix_FreeChunk(victory);
	Mix_FreeChunk(spaceeffect);
	Mix_CloseAudio();
	while (Mix_Init(0)) {
		Mix_Quit();
	}
	IMG_Quit();
	SDL_Quit();
	return 0;
}
