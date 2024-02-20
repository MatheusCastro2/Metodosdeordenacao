# Metodosdeordenacao
Trabalho de Estrutura de Dados
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool sair = false;
FILE *arquivo;
FILE *aux; // vamos usar para sobrepor o arquivo original

struct banco{
    char nome_completo[100];
    int numero[99999];
    float salario;
}conta;


// funcao para abrir o aquivo 
void abrir_arq(){
    arquivo = fopen("banco.txt","a+b");
    aux = fopen("auxiliar.txt","wb");
    if(arquivo == NULL || aux == NULL){
        printf("Erro na abertura do arquivo\n");
        system("pause");
        exit(1);
    }
}

void cadastro(){
    // vamos usar o FFLUSH e o STDIN
    // funcao para cadastro
    
    system("cls");
    abrir_arq();
    printf("Informe seu nome: ");
    scanf("%s", &conta.nome_completo);
    printf("Informe o seu numero(no maximo 5 caracteres)");
    fflush(stdin);
    gets(conta.numero);
    printf("Informe seu salario:  ");
    fflush(stdin);
    scanf("%f", &conta.salario);
    fseek(arquivo,SEEK_END,1);
    fwrite(&conta,sizeof(conta),1,arquivo);
    fclose(arquivo);
    fclose(aux);
    system("pause");
}
// funcao para realizar a ordenacao por Selection Sort
void selectionSort(struct banco arr[], int n){
    system("cls");
    abrir_arq();
    int i, j, termo_min;
    struct banco temp;

    for (i = 0; i < n - 1; i++){
        termo_min = i;
        for (j = i + 1; j < n; j++){
            //vamos comparar os salarios
            if (arr[j].salario < arr[termo_min].salario){
                termo_min = j;
            }
        }
        if (termo_min != i){
            temp = arr[i];
            arr[i] = arr[termo_min];
            arr[termo_min] = temp;
        }
    }

    system("pause");
}
// Cricao da funcao do menu ultilizando switch
void menu(){
    system("cls");
    int op;
    printf("1 -- Cadastro\n");
    printf("3 -- Lista por Selection sort\n");
    printf("3 -- Sair\n");
    printf("Escolha uma opcao:");
    scanf("%d", &op);

    switch(op){
        case 1: cadastro();break;
        case 2: selectionSort(banco,n);break;
        case 3: sair = true;break;
        default: printf("Invalido");break;
    }
}

int main(){
    arquivo = fopen("banco.txt","w+b");
    if(arquivo == NULL){
        printf("Erro na abertura do arquivo\n");
        system("pause");
        exit(1);
    }
    fclose(arquivo);
    while(!sair)
    menu();    

    return 0;
}

