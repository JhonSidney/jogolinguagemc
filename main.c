#include <stdio.h>
#include <stdlib.h>



struct Lutador{
    int id;
    int time;
    int valorDano;
    int pontosVida;
    int iniciativa;
};

struct Iniciativa{
    struct Lutador *l;
    struct Iniciativa *next;

};



struct Iniciativa* removerLutador(struct Iniciativa *head, int id);


int main(){
    srand(time(NULL));
    int opcao = menuPrincipal();
    while(opcao!=0){
        switch(opcao){
            case 1:
                system("cls");
                iniciarJogo();
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




void iniciarJogo(){
    struct Iniciativa *iniciativa = malloc(sizeof (struct Iniciativa));
    struct Iniciativa *time1 = malloc(sizeof(struct Iniciativa));
    struct Iniciativa *time2 = malloc(sizeof(struct Iniciativa));


    iniciativa->next = NULL;
    iniciativa->l = NULL;
    organizacaoTime(iniciativa);
    insertion_sort(iniciativa);
    statusLutadores(iniciativa);

     /*
     separar times de iniciativa - separação de times
    */
     /*
     iniciar combate
    */
}

void organizacaoTime(struct Iniciativa *iniciativa){

    int opcao;
    int id;
    struct Iniciativa *last = iniciativa;

    while(1){
        system("cls");
        int opcao = menuPrincipal2();
        switch(opcao){
            case 1:
                insercaoLutador(last);
                if(last->next != NULL){
                    last = last-> next;
                 }

                printf("\n -> JOGADOR ADICIONADO COM SUCESSO!! \n\n");
                system("pause");
                break;
            case 2:

                statusLutadores(iniciativa);
                system("pause");
                break;
            case 3:
                if(iniciativa->l == NULL){
                    printf("\n|====================================|\n");
                    printf("| -> POR FAVOR INSIRA LUTADORES      |\n");
                    printf("|====================================|\n");
                    system("pause");
                    break;

                }
                printf("|INFORME O ID DO LUTADOR: ");
                scanf("%d",&id);

                struct Iniciativa *aux = removerLutador(iniciativa,id);

                if(aux != NULL){
                    last = aux;
                 }

                system("pause");
                break;
            case 4:
                break;
            default:
                printf("opcao invalida \n");
                system("pause");
        }

        if(opcao == 4){
            break;                                 //mexi aqui
        }

    }
}







void insertion_sort(struct Iniciativa *head){
    struct Iniciativa *proximo = head->next;
    struct Iniciativa *anterior = NULL;

    while(proximo != NULL){
        struct Iniciativa *aux = head;

        if(proximo != NULL && proximo->l->iniciativa > aux->l->iniciativa ){
            struct Lutador *lut = proximo->l;
            proximo->l = aux->l;
            aux->l = lut;
            continue;
        }

        while(aux->next !=NULL && proximo->l->iniciativa < aux->next->l->iniciativa && aux->next != proximo){
            aux = aux->next;
        }

        if(anterior != NULL) {
            struct Iniciativa *init = proximo;
            anterior->next = proximo->next;
            init->next = aux->next;
            aux->next = init;
        }

        anterior = proximo;
        proximo = proximo->next;
    }
}

void insercaoLutador(struct Iniciativa *iniciativa){
    static int k=1;
    int timeLutador;                                                            //MEXI AQUI
    struct Iniciativa *novoLutador = malloc(sizeof(struct Iniciativa));

    novoLutador->l = malloc (sizeof(struct Lutador));
    novoLutador->next = NULL;

    novoLutador->l->id = k++;
    printf("\nTime 1 ou 2:");                                                   //MEXI AQUI
    scanf("%d",&timeLutador);
    novoLutador->l->time = timeLutador;
    novoLutador->l->valorDano = 20;
    novoLutador->l->pontosVida = 20;
    novoLutador->l->iniciativa = 1 + (rand() % 100);

    if(iniciativa->l != NULL){
        iniciativa->next = novoLutador;

    }else{
        iniciativa->l = novoLutador->l;
        free(novoLutador); //liberando espaço
    }
}


void statusLutadores(struct Iniciativa *head){
    int opcao;
    int i =1;
    printf("\n|====================================|\n");                                 //eu mexi aqui
    if(i == 1 && head->l == NULL){
        printf("| -> POR FAVOR INSIRA LUTADORES      |\n");
        printf("|====================================|\n");
    }else{

        printf("\n Listar time:");
        scanf("%d",&opcao);

        while(head != NULL){

            if(opcao == head->l->time){
                 printf("|                  %d                 |\n",i);
                 printf("|ID:             | %d                 |\n",head->l->id);
                 printf("|Time:           | %d                 |\n",head->l->time);
                 printf("|Iniciativa:     | %d                |\n",head->l->iniciativa);
                 printf("|Valor Dano:     | %d                |\n",head->l->valorDano);
                 printf("|Pontos de vida: | %d                |\n",head->l->pontosVida);
                 printf("|====================================|\n");
            }

            head = head->next;
            i++;
        }
    }
}


struct Iniciativa* removerLutador(struct Iniciativa *head, int id){
    struct Iniciativa *proximo;

    if(head->next == NULL){
        free(head->l);
        head->l = NULL;
        return NULL;

    }

    if(head != NULL && head->l->id == id){
        free(head->l);
        proximo = head->next;
        head->l = proximo->l;
        head->next = proximo->next;
        free(proximo);
        return NULL;
    }


    while(head != NULL){
            proximo = head->next;
            if(proximo != NULL && proximo->l->id == id){
                head->next = proximo->next;
                free(proximo);
                break;
            }

            head = head->next;
        }


    if (head->next != NULL){
        return NULL;
    }


    return head;
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


int  menuPrincipal2(){
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
    printf("|                              1 - INSERIR JOGADOR                                |\n");
    printf("|                              2 - STATUS DOS TIMES                               |\n");
    printf("|                              3 - FUGA DE LUTADOR                                |\n");
    printf("|                              4 - VOLTAR                                         |\n");
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

