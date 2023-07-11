#include <stdio.h>
#include <stdlib.h>

int main(void){

    float QTDquestoes, nota, porcent = 0.0, aprovados=0.0;
    int alunos, contador;
    char *gabarito, **respostas;

    printf("Forneca a quantidade de questoes da prova e quantidade de alunos respectivamente\n");
    scanf("%f %d", &QTDquestoes, &alunos); 


    float valorquestao = 10.0/QTDquestoes;

    printf("\n");
    gabarito = (char*) malloc(QTDquestoes * sizeof(char));
    if(gabarito == NULL){
        printf("Erro na alocacao de memoria!");
        exit(1);
    }

    for(contador=0; contador < QTDquestoes; contador++){
        printf("Qual a resposta da questao %d:\n", contador+1);
        scanf("%s", &gabarito[contador]);
    }
    printf("\n");

    respostas = (char**) malloc(alunos * QTDquestoes * sizeof(char*)); 
    if(respostas == NULL){
        printf("Erro na alocacao de memoria!\n");
        exit(1);
    }
    for(contador=0; contador < alunos; contador++){
        respostas[contador] = (char*) malloc(QTDquestoes * sizeof(char));
    }

    int i, j;
    for(i=0; i < alunos; i++){
        for(j=0; j < QTDquestoes; j++){
            printf("Qual foi a resposta  do aluno %d na questao %d:\n", i+1, j+1);
            scanf("%s", &respostas[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    
    for(i=0; i < alunos; i++){
        nota = 0.0;
        for(j=0; j < QTDquestoes; j++){
            if(respostas[i][j] == gabarito[j]){
                nota += valorquestao; 
            }     
        }
        if(nota >= 6.00){
             aprovados++;
        }
        printf("A nota do aluno %d foi: %.2f\n", i+1 , nota);
    }
    
    porcent = (aprovados/alunos)*100;

    printf("A porcetagem de alunos aprovados foi: %.2f\n", porcent);

    for(contador=0; contador < alunos; contador++){
        free(respostas[contador]);
    }
    free(respostas);
    free(gabarito);

    return 0; 
}