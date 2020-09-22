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
    iniciativa->next = NULL;
    iniciativa->l = NULL;
    organizacaoTime(iniciativa);


}

void organizacaoTime(struct Iniciativa *iniciativa){
    int opcao;
    int id;
    struct Iniciativa *last = iniciativa;

    while(1){
        system("cls");
        printf("1. insercao\n");
        printf("2. status \n");
        printf("3. fuga\n");
        printf("4. voltar\n");

        scanf("%d",&opcao);

        switch(opcao){
        case 1:

             insercaoLutador(last);
             if(last->next != NULL){
                last = last-> next;
             }
             printf("Adicionado !\n");
             system("pause");
             break;
        case 2:
             printf("status");
             statusLutadores(iniciativa);
             system("pause");
             break;
        case 3:

             printf("informe o id:");
             scanf("%d",&id);

             struct Iniciativa *aux = removerLutador(iniciativa,id);
             if(aux != NULL){
                    last = aux;

             }
             system("pause");
             break;
        case 4:
            printf("voce saiu\n");
            break;
            break;
        default:
            printf("opcao invalida \n");

        }

    }







}



void insercaoLutador(struct Iniciativa *iniciativa){
    static int k=0;
    struct Iniciativa *novoLutador = malloc(sizeof(struct Iniciativa));

    novoLutador->l = malloc (sizeof(struct Lutador));
    novoLutador->next = NULL;

    novoLutador->l->id = k++;
    novoLutador->l->time = 1;
    novoLutador->l->valorDano = 20;
    novoLutador->l->pontosVida = 20;
    novoLutador->l->iniciativa = 20;

    if(iniciativa->l != NULL){
        iniciativa->next = novoLutador;

    }else{
        iniciativa->l = novoLutador->l;
        free(novoLutador); //liberando espaço
    }
}




void statusLutadores(struct Iniciativa *head){
    int i =1;
    printf("========================\n");
    while(head != NULL){
        printf("%d\n",i);
        printf("iniciativa: %d\n",head->l->iniciativa);
        printf("id: %d\n",head->l->id);
        printf("pontos de vida: %d\n",head->l->pontosVida);
        printf("Time: %d\n",head->l->time);
        printf("valor Dano: %d\n",head->l->valorDano);
        printf("========================\n");

        head = head->next;
        i++;
    }




}





struct Iniciativa* removerLutador(struct Iniciativa *head, int id){
    struct Iniciativa *proximo;

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


int menuVoltar(){

    printf("|=================================================================================|\n");
    printf("|  1 - VOLTAR                                                                     |\n");
    printf("|=================================================================================|\n");

    printf(" DIGITE A OPCAO DESEJADA:");
    int opcao;
    scanf("%i",&opcao);
    return opcao;
}

