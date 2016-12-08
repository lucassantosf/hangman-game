/*
Programa JogoForca.c    
Desenvolvido por Lucas Ferreira dos Santos

Desenvolva um sistema (jogo) que permita ao usuário descobrir a palavra secreta através de dicas, conforme segue:

1) Será permitido ao usuário consultar 5 dicas para cada uma das palavras a ser descoberta;

2) Cada erro ou cada dica elimina um elemento do corpo do boneco da forca (cabeça e tronco, braço 1 e 2, perna 1 e 2);

3) As palavras secretas e dicas das palavras devem estar no corpo do programa.

4) Deve ser cadastrado duas palavras para cada uma das três categorias (música, filme e livro).

5) Salve num arquivo o nome do usuário, o tempo gasto, as penalidades (0,1,2,3,4,5).

Obs.:
Entregue o código fonte em .c (c source file);
A identação correta é obrigatória. 

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void){
    system("chcp 28591");
    system("cls");
    FILE *Cadastro;
    

    char word[3][2][50],helps[30][100],name[100],palpite[1],palavrachave[7][20],getdica;
    int esccat=0,R=0,R1=0,R2=0,lifes=5,p,d=0,e,errors;
    clock_t t0, tf;
    double tempo_gasto;
    /* Todas palavras e dicas, tb tem as respostas*/

    strcpy(word[0][0],"eminem");
    strcpy(helps[0],"Famoso rapper de Detroit\0");
    strcpy(helps[1],"Mora na terra do til Sam\0");
    strcpy(helps[2],"Fez um single com Rihanna\0");
    strcpy(helps[3],"Tambem conhecido como Slim Shady\0");
    strcpy(helps[4],"Famoso rapper branco\0");

    strcpy(word[0][1],"hip hop");
    strcpy(helps[5],"Estilo musical\0");
    strcpy(helps[6],"Considerado estilo das ruas\0");
    strcpy(helps[7],"Um dos maiores cantores do genero foi Tupac\0");
    strcpy(helps[8],"A maioria dos cantores do genero são negros\0");
    strcpy(helps[9],"Origininou-se nos Estados Unidos");

    strcpy(word[1][0],"cinema");
    strcpy(helps[10],"Lugar de lazer\0");
    strcpy(helps[11],"Encontrado em shoppings\0");
    strcpy(helps[12],"Conhecido pelas telonas\0");
    strcpy(helps[13],"Muitas pessoas podem usa-lo ao mesmo tempo\0");
    strcpy(helps[14],"Seu ambiente eh escuro\0");

    strcpy(word[1][1],"aventura");
    strcpy(helps[15],"Genero do filme : Os vingadores\0");
    strcpy(helps[16],"Genero do filme : Guerra nas estrelas\0");
    strcpy(helps[17],"Reflete um mundo heróico de combates\0");
    strcpy(helps[18],"George Lucas eh um grande diretor de filmes do genero\0");
    strcpy(helps[19],"Mel Gibson eh um grande ator de filmes do genero\0");

    strcpy(word[2][0],"iracema");
    strcpy(helps[20],"Seu autor foi Jose de Alencar\0");
    strcpy(helps[21],"Retrata a vida de uma india\0");
    strcpy(helps[22],"Romance brasileiro\0");
    strcpy(helps[23],"Foi feito em 1865\0");
    strcpy(helps[24],"Cai em muitos vestibulares\0");

    strcpy(word[2][1],"dom casmurro");
    strcpy(helps[25],"Seu autor foi Machado de Assis\0");
    strcpy(helps[26],"Um famoso romance, o qual a Globo fez uma miniserie\0");
    strcpy(helps[27],"Um dos principais personagens do livro eh Capitu\0");
    strcpy(helps[28],"Foi feito em 1900\0");
    strcpy(helps[29],"Outro grande personagem que faz parte do livro, Bentinho\0");

    printf("\n\n\n\n\n\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    printf("\nXXXXXXX Jogo da Forca XXXXXXXXXXXXXXXXXX");
    printf("\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"); 
    printf("\nXXXXXXX Desenvolvido XXXXXXXXXXXXXXXXXXX");
    printf("\nXXXXXXX por XXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    printf("\nXXXXXXX Lucas Ferreira Dos Santos XXXXXX");
    printf("\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n\n\n\n\n\n\n");
    system("pause");
    system("cls");

    strcpy(palavrachave[1],"------");
    strcpy(palavrachave[2],"--- ---");
    strcpy(palavrachave[3],"------");
    strcpy(palavrachave[4],"--------");
    strcpy(palavrachave[5],"-------");
    strcpy(palavrachave[6],"--- --------");
    /* Entrada do nome  Salvando no arquivo texto */

    Cadastro = fopen ("Nome.txt","a");
    fclose(Cadastro);
    Cadastro = fopen ("Nome.txt","w");
    printf("\n\n\n\n\n\n\tDigite seu nome para jogar :: ");
    printf("\n\n\n\n\n\n\t--------------------------->  ");
    fflush(stdin);
    fgets(name,100,stdin);
    fprintf(Cadastro,"%s",name);
    fclose(Cadastro);
    printf("\n\n\n\n\n\n");        
    system("pause") ;
    system("cls")   ;
    printf("\n\n\n\n\n\n\tNome cadastrado com sucesso!\n\n\n\n\n\n\n\n\n\n");
    system("pause") ;
    system("cls")   ;

    /* Entrada da categoria */

    printf("\n\n\n\n\n\n\t Escolha uma categoria  :");
    printf("\n\t1.Musica");
    printf("\n\t2.Filme");
    printf("\n\t3.Livro\n\t");
    scanf("%i",&esccat);
    
    while (esccat>=4 || esccat<=0){
          system("cls");
          printf("\n\n\n\n\n\n\tCodigo incorreto para categoria digite corretamente ,");
          printf("\n\t1.Musica");
          printf("\n\t2.Filme");
          printf("\n\t3.Livro\n\t");
          scanf("%i",&esccat);
    }
    system("cls");
    /*  Para randomica */
    srand(time(NULL));
    R = rand() % 2 ;
    if (esccat==1 && R==0){
                  d=0;              
    }
    if (esccat==1 && R==1){
                  d=5;              
    }
    if (esccat==2 && R==0){
                  d=10;              
    }
    if (esccat==2 && R==1){
                  d=15;              
    }
    if (esccat==3 && R==0){
                  d=20;
    }
    if (esccat==3 && R==1){
                  d=25;              
    }
    t0 = clock ();               
    while (lifes>0){ /*Começo do while principal*/
          if (lifes==5){
                        printf("\n\n------------                        \n");
                        printf("| |        |                        \n");
                        printf("| |                                 \n");
                        printf("| |                                 \n");
                        printf("| |                                 \n");
                        printf("| |                                 \n");
                        printf("| |                                 \n");
                        printf("| |                                 \n");
          }
          if (lifes==4){
                        printf("\n\n------------                        \n");
                        printf("| |        |                        \n");
                        printf("| |        O                        \n");
                        printf("| |        |                        \n");
                        printf("| |        |                        \n");
                        printf("| |                                 \n");
                        printf("| |                                 \n");
                        printf("| |                                 \n");
          }
          if (lifes==3){
                        printf("\n\n------------                        \n");
                        printf("| |        |                        \n");
                        printf("| |        O                        \n");
                        printf("| |      _ |                        \n");
                        printf("| |        |                        \n");
                        printf("| |                                 \n");
                        printf("| |                                 \n");
                        printf("| |                                 \n");
          }
          if (lifes==2){
                        printf("\n\n------------                        \n");
                        printf("| |        |                        \n");
                        printf("| |        O                        \n");
                        printf("| |      _ | _                      \n");
                        printf("| |        |                        \n");
                        printf("| |                                 \n");
                        printf("| |                                 \n");
                        printf("| |                                 \n");
          }
          if (lifes==1){
                        printf("\n\n------------                        \n");
                        printf("| |        |                        \n");
                        printf("| |        O                        \n");
                        printf("| |      _ | _                      \n");
                        printf("| |        |                        \n");
                        printf("| |       /                         \n");
                        printf("| |                                 \n");
                        printf("| |                                 \n");
          }
          printf("Dicas (S)  (N)  :");
          scanf("%s",&getdica);
          if (getdica=='s'){
                            printf("%s",helps[d]);
                            d=d+1;
                            lifes=lifes-1;
          }
          printf("\nDigite uma letra :");
          scanf("%s",&palpite[0]);
          system("cls");
          
          if (esccat == 1) {
                     if(R == 0){
                          p=1;
                          if (  (palpite[0] != word[0][0][0]) && (palpite[0] != word[0][0][1]) && (palpite[0] != word[0][0][2]) && (palpite[0] != word[0][0][4])  && (palpite[0] != word[0][0][5])    ){
                                lifes = lifes - 1;
                          }
                          if (palpite[0]==word[0][0][0]){
                                                         palavrachave[1][0]=word[0][0][0];
                          }
                          if (palpite[0]==word[0][0][1]){
                                                         palavrachave[1][1]=word[0][0][1];                                              
                          }
                          if (palpite[0]==word[0][0][2]){
                                                         palavrachave[1][2]=word[0][0][2];                                              
                          }
                          if (palpite[0]==word[0][0][3]){
                                                         palavrachave[1][3]=word[0][0][3];                                              
                          }
                          if (palpite[0]==word[0][0][4]){
                                                         palavrachave[1][4]=word[0][0][4];                                              
                          }
                          if (palpite[0]==word[0][0][5]){
                                                         palavrachave[1][5]=word[0][0][5];                                              
                          }
                     }
                     if (R == 1){
                           p=2;
                           palavrachave[2][3]=word[0][1][3];
                           if (  (palpite[0] != word[0][1][0]) && (palpite[0] != word[0][1][1]) && (palpite[0] != word[0][1][2]) && (palpite[0] != word[0][1][4])  && (palpite[0] != word[0][1][5])  && (palpite[0] != word[0][1][6])  ){
                                 lifes = lifes - 1;
                           }
                           if (palpite[0]==word[0][1][0]){
                                                          palavrachave[2][0]=word[0][1][0];                                              
                           }
                           if (palpite[0]==word[0][1][1]){
                                                          palavrachave[2][1]=word[0][1][1];                                              
                           }
                           if (palpite[0]==word[0][1][2]){
                                                          palavrachave[2][2]=word[0][1][2];                                              
                           }
                           if (palpite[0]==word[0][1][4]){
                                                          palavrachave[2][4]=word[0][1][4];                                              
                           }
                           if (palpite[0]==word[0][1][5]){
                                                          palavrachave[2][5]=word[0][1][5];                                              
                           }
                           if (palpite[0]==word[0][1][6]){
                                                          palavrachave[2][6]=word[0][1][6];                                              
                           }
                     }
          }
          if (esccat == 2){
                     if (R == 0 ){
                           p=3;
                           if (  (palpite[0] != word[1][0][0]) && (palpite[0] != word[1][0][1]) && (palpite[0] != word[1][0][2]) && (palpite[0] != word[1][0][3]) && (palpite[0] != word[1][0][4])  && (palpite[0] != word[1][0][5]) ){
                                 lifes = lifes - 1;
                           }
                           if (palpite[0]==word[1][0][0]){
                                                          palavrachave[3][0]=word[1][0][0];                                              
                           }
                           if (palpite[0]==word[1][0][1]){
                                                          palavrachave[3][1]=word[1][0][1];                                              
                           }
                           if (palpite[0]==word[1][0][2]){
                                                          palavrachave[3][2]=word[1][0][2];                                              
                           }
                           if (palpite[0]==word[1][0][3]){
                                                          palavrachave[3][3]=word[1][0][3];                                              
                           }
                           if (palpite[0]==word[1][0][4]){
                                                          palavrachave[3][4]=word[1][0][4];                                              
                           }
                           if (palpite[0]==word[1][0][5]){
                                                          palavrachave[3][5]=word[1][0][5];                                              
                           }
                     }
                     else if (R == 1){
                          p=4;
                          if (  (palpite[0] != word[1][1][0]) && (palpite[0] != word[1][1][1]) && (palpite[0] != word[1][1][2]) && (palpite[0] != word[1][1][3]) && (palpite[0] != word[1][1][4])  && (palpite[0] != word[1][1][5])  && (palpite[0] != word[1][1][6])  && (palpite[0] != word[1][1][7])){
                                lifes = lifes - 1;
                          }
                          if (palpite[0]==word[1][1][0]){
                                                         palavrachave[4][0]=word[1][1][0];                                              
                          }
                          if (palpite[0]==word[1][1][1]){
                                                         palavrachave[4][1]=word[1][1][1];                                              
                          }
                          if (palpite[0]==word[1][1][2]){
                                                         palavrachave[4][2]=word[1][1][2];                                              
                          }
                          if (palpite[0]==word[1][1][3]){
                                                         palavrachave[4][3]=word[1][1][3];                                              
                          }
                          if (palpite[0]==word[1][1][4]){
                                                         palavrachave[4][4]=word[1][1][4];                                              
                          }
                          if (palpite[0]==word[1][1][5]){
                                                         palavrachave[4][5]=word[1][1][5];                                              
                          }
                          if (palpite[0]==word[1][1][6]){
                                                         palavrachave[4][6]=word[1][1][6];                                              
                          }
                          if (palpite[0]==word[1][1][7]){
                                                         palavrachave[4][7]=word[1][1][7];                                              
                          }
                     }
          }
          if (esccat==3){
                         if (R == 0){
                               p=5;
                               if (  (palpite[0] != word[2][0][0]) && (palpite[0] != word[2][0][1]) && (palpite[0] != word[2][0][2]) && (palpite[0] != word[2][0][3]) && (palpite[0] != word[2][0][4])  && (palpite[0] != word[2][0][5]) && (palpite[0] != word[2][0][6]) ){
                                     lifes = lifes - 1;
                               }
                               if (palpite[0]==word[2][0][0]){
                                                              palavrachave[5][0]=word[2][0][0];                                              
                               }
                               if (palpite[0]==word[2][0][1]){
                                                              palavrachave[5][1]=word[2][0][1];                                              
                               }
                               if (palpite[0]==word[2][0][2]){
                                                              palavrachave[5][2]=word[2][0][2];                                              
                               } 
                               if (palpite[0]==word[2][0][3]){
                                                              palavrachave[5][3]=word[2][0][3];                                              
                               }
                               if (palpite[0]==word[2][0][4]){
                                                              palavrachave[5][4]=word[2][0][4];                                              
                               }
                               if (palpite[0]==word[2][0][5]){
                                                              palavrachave[5][5]=word[2][0][5];                                              
                               }
                               if (palpite[0]==word[2][0][6]){
                                                              palavrachave[5][6]=word[2][0][6];                                              
                               }
                     
                     }
                     else if (R == 1){
                          p=6;
                          palavrachave[6][3]=word[2][1][3];
                          if (  (palpite[0] != word[2][1][0]) && (palpite[0] != word[2][1][1]) && (palpite[0] != word[2][1][2]) && (palpite[0] != word[2][1][4])  && (palpite[0] != word[2][1][5]) && (palpite[0] != word[2][1][6])  && (palpite[0] != word[2][1][7]) && (palpite[0] != word[2][1][8]) && (palpite[0] != word[2][1][9])  && (palpite[0] != word[2][1][10]) && (palpite[0] != word[2][1][11]) && (palpite[0] != word[2][1][12])              ){
                                lifes = lifes - 1;
                          }
                          if (palpite[0]==word[2][1][0]){
                                                         palavrachave[6][0]=word[2][1][0];                                              
                          }
                          if (palpite[0]==word[2][1][1]){
                                                         palavrachave[6][1]=word[2][1][1];                                              
                          }
                          if (palpite[0]==word[2][1][2]){
                                                         palavrachave[6][2]=word[2][1][2];                                              
                          }
                          if (palpite[0]==word[2][1][4]){
                                                         palavrachave[6][4]=word[2][1][4];                                              
                          }
                          if (palpite[0]==word[2][1][5]){
                                                         palavrachave[6][5]=word[2][1][5];                                              
                          }
                          if (palpite[0]==word[2][1][6]){
                                                         palavrachave[6][6]=word[2][1][6];                                              
                          }
                          if (palpite[0]==word[2][1][7]){
                                                         palavrachave[6][7]=word[2][1][7];                                              
                          }
                          if (palpite[0]==word[2][1][8]){
                                                         palavrachave[6][8]=word[2][1][8];                                              
                          }
                          if (palpite[0]==word[2][1][9]){
                                                         palavrachave[6][9]=word[2][1][9];                                              
                          }
                          if (palpite[0]==word[2][1][10]){
                                                         palavrachave[6][10]=word[2][1][10];                                              
                          }
                          if (palpite[0]==word[2][1][11]){
                                                         palavrachave[6][11]=word[2][1][11];                                              
                          }
                     }
                            
                     /* Final das comparaçoes das letras */
          }
          e=esccat-1;
          printf("\n\n\nPalavra : %s                                    Vidas:%i\n\n\n\n\n\n",palavrachave[p],lifes);
          if (strcmp (palavrachave[p],word[e][R]) == 0 ){
                     tf = clock();
                     tempo_gasto = ( (double) (tf-t0) )/ CLOCKS_PER_SEC;
                     printf("\n\n\n\n\n\n\n\t Voce ganhou o jogo . ");
                     printf("\n\n\t Tempo Gasto : %.2f s\n", tempo_gasto);
                     system("pause");
                     break;
          }
          if (lifes==0){
                        tf = clock();
                        tempo_gasto = ( (double) (tf-t0) )/ CLOCKS_PER_SEC;
                        system("cls");
                        printf("\n\n------------                        \n");
                        printf("| |        |                        \n");
                        printf("| |        O                        \n");
                        printf("| |      _ | _                      \n");
                        printf("| |        |                        \n");
                        printf("| |       / \\                      \n");
                        printf("| |                                 \n");
                        printf("| |                                 \n\n\n\n\n");
                        printf("\tFim de jogo\n\n\n\n\n");
                        printf("\n\n\tTempo Gasto : %.2f s\n", tempo_gasto);
                        system("pause");
                        break;
          }
    }/*fim do while*/
    errors = 5 - lifes;
    Cadastro = fopen ("nome.txt","a");
    fprintf(Cadastro,"Vc cometeu  %i penalidades\n",errors);
    fprintf(Cadastro,"Vc gastou um tempo de  %.2f  s",tempo_gasto);              
    fclose(Cadastro);

}/*fim programa*/
