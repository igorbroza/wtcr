#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>

#define AZUL 		printf("\033[1;34m");
#define PRETO printf ("\033[1;40m");
#define RESET printf("\033[0;0m");
#define VERDE printf("\033[1;42m");
#define PRET  printf("\033[1;30m");
#define VERD  printf("\033[1;32m");
#define AMARELO printf("\033[1;43m");
#define BRANCO printf("\033[1;107m");
#define LARANJA printf("\033[1;91m");
#define RESET		printf("\033[0;0m");

#define LAR 		55
#define ALT 		18
#define CAMINHO 		0
#define PAREDE 		1
#define ESTRADA 		2
#define SAIDA 		3
#define OBJETO		4

int getch(void);

int main() {
	srand(time(NULL));

	int mapa[ALT][LAR]= { {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,3,3,3,3,3,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,3,3,3,3,3,3},
						  {1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,3,3,3,3,3,3,3,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,3,3,3,3,3,3,3},
						  {1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,3,3,3,3,3,3,3,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,3,3,3,3,3,3,3},
						  {1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,3,3,3,3,3,3,3,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,3,3,3,3,3,3,3},
						  {1,2,2,2,2,1,1,1,1,1,1,2,2,2,2,1,3,3,3,3,3,3,3,1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1},
						  {1,2,2,2,2,1,3,3,3,3,1,2,2,2,2,1,3,3,3,3,3,3,3,1,2,2,2,2,1,3,3,3,3,3,3,3,3,3,3,3,3,3,1,2,2,2,2,2,2,2,2,2,2,2,1},
						  {1,2,2,2,2,1,3,3,3,3,1,2,2,2,2,1,3,3,3,3,3,3,3,1,2,2,2,2,1,3,3,3,3,3,3,3,3,3,3,3,3,3,1,2,2,2,2,2,2,2,2,2,2,2,1},
						  {1,2,2,2,2,1,3,3,3,3,1,2,2,2,2,1,1,1,1,1,1,1,1,1,2,2,2,2,1,3,3,3,3,3,3,3,3,3,3,3,3,3,1,2,2,2,2,2,2,2,2,2,2,2,1},
						  {1,2,2,2,2,1,3,3,3,3,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1,1,1,1,1,2,2,2,2,1},
						  {1,2,2,2,2,1,3,3,3,3,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,3,3,3,3,3,3,3,3,3,3,3,3,3,1,1,1,1,1,1,1,1,2,2,2,2,1},
						  {1,2,2,2,2,1,3,3,3,3,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,3,3,3,3,3,3,3,3,3,3,3,3,3,1,2,2,2,2,2,2,2,2,2,2,2,1},
						  {1,2,2,2,2,1,3,3,3,3,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,3,3,3,3,3,3,3,3,3,3,3,3,3,1,2,2,2,2,2,2,2,2,2,2,2,1},
						  {1,2,2,2,2,1,3,3,3,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,3,3,3,3,3,3,3,3,3,3,3,3,1,2,2,2,2,2,2,2,2,2,2,2,1},
						  {1,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,1,1,1,1,1,1,1,1},
						  {1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,3,3,3,3,3,3,3},
						  {1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,3,3,3,3,3,3,3},
						  {1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,3,3,3,3,3,3,3},
						  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,3,3,3,3,3,3},
						};

	int lin, col, menu, final, fim, px, py,i, dificuldade = 1, dif = 0, volta = 0, jogador , fimjogo=0 , tempojogador1 , tempojogador2,jog=0,penalidade=0;
	time_t t_ini, t_fin;
	char jogada;
	float t_tot;

	jogador = 1;

	final = 0;

	while(fim == 0) {
	
	system("clear");
	printf("\n     ███       ███   █████████     ███████     ████████     ");
	printf("\n     ███       ███      ███        ██          ██    ██     ");
	printf("\n     ███  ███  ███      ███        ██          ██    ██     ");
	printf("\n     ███  ███  ███      ███        ██          ████████     ");
	printf("\n     ███  ███  ███      ███        ██          ██  ██       ");
	printf("\n     █████████████      ███        ██████      ██    ██     ");
	printf("\n************************************************************");
	printf("\n************************************************************");
	printf("\n************************************************************");
	printf("\n********                 1 = Jogar                  ********");
	printf("\n********              2 = Dificuldade               ********");
	printf("\n********                 3 = Sair                   ********");
	printf("\n************************************************************");
	printf("\n************************************************************");
	printf("\n************************************************************\n\n");
	fimjogo = 0;
	scanf("%i", &menu);

	switch(menu) {

		case 1:
			if(dificuldade == 2) {
				for(i = 0; i< 20;){
					lin = rand()%ALT;
					col = rand()%LAR;
					if(mapa[lin][col] == 2){
						mapa[lin][col] = 4;
						i++;
					}
				}
			}
			if(dificuldade == 3) {
				for(i = 0; i< 30;){
					lin = rand()%ALT;
					col = rand()%LAR;
					if(mapa[lin][col] = 2){
						mapa[lin][col] = 4;
						i++;
					}
				}
			}
			final = 0;
			fimjogo = 0;
			jogador = 1;
			penalidade = 0;
			px = 15;
			py = 25;


		while(fimjogo != 1){

			while(final == 0 ) {
				printf(" \t\tNumero de voltas: %i/3",volta);
				t_ini = time(NULL);
				system("clear");
				printf("\t\t\t  WTCR Time run\n");
				for(lin=0; lin<ALT; lin++) {
					printf("\t\t");
					for(col=0; col<LAR; col++) {
						if(lin == px && col == py) {
							if(jogador == 1){
                            PRETO;
                            VERD;
							printf("🚘");
							RESET;
							}
							if(jogador == 2){
                            PRETO;
                            AZUL;
							printf("🚘");
							RESET;
							}
						}else if(mapa[lin][col] == 2) {
							PRETO;
							printf(" ");
							RESET;
						}else if(mapa[lin][col] == 3) {
							VERDE;
							printf(" ");
							RESET;
						}
						else if(mapa[lin][col] == 0) {
							BRANCO;
							printf(" ");
							RESET;
						}
						else if(mapa[lin][col] == 1) {
							AMARELO;
							printf(" ");
							RESET;
						}
						else if(mapa[lin][col] == 4){
							PRETO;
							LARANJA;
							printf("🛢️");
							RESET;
						}
					}
					printf("\n");
				}

				// CAPTURA TECLA
				jogada = getch();

				// TECLA ESPECIAL
				if(jogada == 27) {
					jogada = getch();
					if(jogada == 91) {
						jogada = getch();

						if(jogada == 65) {// CIMA
							px--;
								if(mapa[px][py] == 1){
									
									px = 15;
									py = 23;
								}
							if(dificuldade == 2 || dificuldade == 3){
                                if(mapa[px][py] == 4){
                                    px = 15;
                                    py = 23;
                                        if(dificuldade == 3){
                                           penalidade++;
                                        }
                                    }
                            }

						}else if(jogada == 66) {// BAIXO
							px++;
								if(mapa[px][py] == 1){
								 	
								 	px = 15;
								  py = 23;
								}
							if(dificuldade == 2 || dificuldade == 3){
                                if(mapa[px][py] == 4){
                                    px = 15;
                                    py = 23;
                                        if(dificuldade == 3){
                                           penalidade++;
                                        }
                                    }
                            }

					}else if(jogada == 67) {// DIREITA
						py++;
							if(mapa[px][py] == 1){
								
								 px = 15;
								 py = 23;
							}
							if(dificuldade == 2 || dificuldade == 3){
                                if(mapa[px][py] == 4){
                                    px = 15;
                                    py = 23;
                                        if(dificuldade == 3){
                                           penalidade++;
                                        }
                                    }
                            }

					}else if(jogada == 68){// ESQUERDA
						py--;
							if (mapa[px][py] == 0) {
								volta++;
							}
							if(mapa[px][py] == 1){
								px = 15;
								py = 25;

							}
                             if(dificuldade == 2 || dificuldade == 3){
                                if(mapa[px][py] == 4){
                                    px = 15;
                                    py = 25;
                                        if(dificuldade == 3){
                                           penalidade++;
                                        }
                                    }
                            }
					}
				}
				}
				if(volta >= 3){

					final=1;
				}
			}

			if(jogador == 2){
						t_fin = time(NULL);
						t_tot = t_fin - t_ini;
						if(dificuldade == 1){
							tempojogador2 = t_tot;
						}
						if(dificuldade == 2 || dificuldade == 3){
							tempojogador2=t_tot + penalidade;
						}
						if(tempojogador1 > tempojogador2){
                          system("clear");
                          printf("\n\n\n\n\n\n\t\t\t\tJOGADOR 2 VENCEU!! :)");
						  printf("                                      \n");
                          printf("\t\t\t              🏆🏆🏆🏆🏆🏆🏆🏆🏆🏆🏆🏆🏆           \n");
                          printf("\t\t\t              🏆🏆🏆🏆🏆🏆🏆🏆🏆🏆🏆🏆🏆           \n");
                          printf("\t\t\t               🏆🏆🏆🏆🏆🏆🏆🏆🏆🏆🏆            \n");
                          printf("\t\t\t                🏆🏆🏆🏆🏆🏆🏆🏆🏆             \n");
                          printf("\t\t\t                  🏆🏆🏆🏆🏆               \n");
                          printf("\t\t\t                  🏆🏆🏆🏆🏆               \n");
                          printf("\t\t\t                   🏆🏆🏆                \n");
                          printf("\t\t\t                   🏆🏆🏆                \n");
                          printf("\t\t\t                   🏆🏆🏆                \n");
                          printf("\t\t\t                   🏆🏆🏆                \n");
                          printf("\t\t\t                  🏆🏆🏆🏆🏆               \n");
                          printf("\t\t\t                 🏆🏆🏆🏆🏆🏆🏆              \n");
                          printf("\nTempo Do Vencedor:%i",tempojogador2);
                          printf("\nTempo Do Ruim:%i",tempojogador1);
                          __fpurge(stdin);
                          getchar();

						}
						else{
                          system("clear");
                          printf("\n\n\n\n\n\n\t\t\t\tJOGADOR 1 VENCEU!! :)");
     				      printf("                                      \n");
                          printf("\t\t\t              🏆🏆🏆🏆🏆🏆🏆🏆🏆🏆🏆🏆🏆           \n");
                          printf("\t\t\t              🏆🏆🏆🏆🏆🏆🏆🏆🏆🏆🏆🏆🏆           \n");
                          printf("\t\t\t               🏆🏆🏆🏆🏆🏆🏆🏆🏆🏆🏆            \n");
                          printf("\t\t\t                🏆🏆🏆🏆🏆🏆🏆🏆🏆             \n");
                          printf("\t\t\t                  🏆🏆🏆🏆🏆               \n");
                          printf("\t\t\t                  🏆🏆🏆🏆🏆               \n");
                          printf("\t\t\t                   🏆🏆🏆                \n");
                          printf("\t\t\t                   🏆🏆🏆                \n");
                          printf("\t\t\t                   🏆🏆🏆                \n");
                          printf("\t\t\t                   🏆🏆🏆                \n");
                          printf("\t\t\t                  🏆🏆🏆🏆🏆               \n");
                          printf("\t\t\t                 🏆🏆🏆🏆🏆🏆🏆              \n");
                          printf("\nTempo Do Vencedor:%i",tempojogador1);
                          printf("\nTempo Do Ruim:%i",tempojogador2);

                          __fpurge(stdin);
                          getchar();
						}
						volta = 0;

						fimjogo=1;
						final=1;
					}

			if(jogador == 1){
					final = 0;
					jogador = 2;
					t_fin = time(NULL);
					t_tot = t_fin - t_ini;
					if(dificuldade == 1){
							tempojogador1 = t_tot;
						}
						if(dificuldade == 2 || dificuldade == 3){
							tempojogador1=t_tot + penalidade;
						}
					volta=0;
					penalidade = 0;
					printf("\n VEZ DO JOGADOR 2!!");
					jogada=getchar();
					}




		}


    break;
    case 2:
      printf("Nivel Facil: 1");
      printf("\nNivel Medio: 2");
      printf("\nNivel Dificil: 3\n\n");
      scanf("%i", &dificuldade);
      switch(dificuldade) {
        case 1:
          dificuldade = 1;
          fimjogo=0;
        break;
        case 2:
          dificuldade = 2;
          fimjogo=0;
        break;
        case 3:
          dificuldade = 3;
          fimjogo=0;
        break;
      }
    break;
    case 3:
      fim =1;
    break;
			}
		}


	printf("\n");
	return 0;
}

int getch(void) {

    struct termios oldattr, newattr;
    int ch;

    tcgetattr( STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO);
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr);
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr);

    return ch;
}
