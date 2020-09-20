#include <stdio.h>
#include <stdlib.h>



struct Lutador{
    int id;
    int time;
    int valorDano;
    int pontos;
    int iniciativa;
};

struct Iniciativa{
    struct Lutador *l;
    struct Iniciativa *next;

};


int main(){
    int quantidadeTime1, quantidadeTime2;
    int opcao = menuPrincipal();
    while(opcao!=0){
        switch(opcao){
            case 1:
                system("cls");
                printf("informe o numero de lutadores da equipe 1: ");
                scanf("%d",&quantidadeTime1);
                printf("informe o numero de lutadores da equipe 2: ");
                scanf("%d",&quantidadeTime2);

                iniciarJogo(quantidadeTime1, quantidadeTime2);

                break;
            case 2:
                exit(0);
                break;
            default:
                printf("Error : Opcao Invalida!!!!\n\n");
                system("pause");
                break;
        }

        opcao = menuPrincipal();

    }

    return 0;
}




void iniciarJogo(int qtdLutadoresTime, int qtdlutadoresTime2){
    struct Lutador time1[qtdlutadoresTime];
    struct Lutador time2[qtdLutadoresTime2];

    organizacaoTime(time1,qtdLutadoresTime,1);
    organizacaoTime(time2,qtdLutadoresTime2,2);








}

void organizacaoTime(struct Lutador *ptime, int qtdLutadores,int time){
    static int k=0;
    for(int i=0; i< qtdLutadores;i++){
            ptime[i].id = k++;
            ptime[i].time = time;
            ptime[i].valorDano=20;
            ptime[i].pontosVida= 20;
            ptime[i].iniciativa=20;
    }
}


int  menuPrincipal(){
    int opcao=0;
    system("cls");

    printf("|=================================================================================|\n");
    printf("|=================================================================================|\n");
    printf("|                        0      0  00000  0      0  00     00                     |\n");
    printf("|                        00    00  0      0 0    0  00     00                     |\n");
    printf("|                        0  00  0  0000   0   0  0  00     00                     |\n");
    printf("|                        0      0  0      0     00  00     00                     |\n");
    printf("|                        0      0  00000  0      0  000000000                     |\n");
    printf("|=================================================================================|\n");
    printf("|=================================================================================|\n");
    printf("|                              1 - INICIAR                                        |\n");
    printf("|                              2 - SAIR DO JOGO                                   |\n");
    printf("|=================================================================================|\n");
    printf("|=================================================================================|\n");
    printf("| DIGITE A OPCAO DESEJADA:");
    scanf("%i",&opcao);
    return opcao;
}


int menuVoltar(){

    printf("|=================================================================================|\n");
    printf("|  1 - VOLTAR                                                                     |\n");
    printf("|=================================================================================|\n");

    printf(" DIGITE A OPCAO DESEJADA:");
    int opcao;
    scanf("%i",&opcao);
    return opcao;
}

