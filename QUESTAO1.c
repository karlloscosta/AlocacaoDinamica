#include <stdio.h>
#include <stdlib.h>

int main(void){

    char *vtrsexo, *vtropiniao;
    float porcentof, porcentoM, clientes, Mulher, Homem;

    clientes = 0; Mulher = 0; Homem = 0;    
    printf("Quantos clientes realizaram a entrevista:\n");
    scanf("%d", &clientes);

    vtrsexo = (char*) malloc(clientes *sizeof(char));
    if (vtrsexo == NULL){
        printf("Erro de alocacao de memoria!");
        exit(1);
    }
    vtropiniao = (char*) malloc(clientes *sizeof(char));
    if (vtropiniao == NULL){
        printf("Erro na alocacao de memoria!");
        exit(1);
    }

    int contador;
    for(contador=0; contador < clientes; contador++){
        printf("Digite 'F' se for mulher ou 'M' se for homem:\n");
        scanf("%s", &vtrsexo[contador]);
        if(vtrsexo[contador] == 'F'){
            Mulher++;
        }else{
            Homem++;
        }
        printf("Digite 'SIM' caso tenha gostado do produto ou 'NAO' caso contrario.\n");
        scanf("%s", &vtropiniao[contador]);
    }
   
    porcentof = porcentoM = 0.0;
    for(contador=0; contador < clientes; contador++){
        if((vtrsexo[contador] == 'F') && (vtropiniao[contador] == 'S')){
            porcentof++;
        }
        if ((vtrsexo[contador] == 'M') && (vtropiniao[contador] == 'N')){
            porcentoM++;
        }
    }
   
    porcentof=(porcentof/Mulher)*100;
    porcentoM=(porcentoM/Homem)*100;

    printf("O total de mulheres que gostaram do produto foi de %.2f \n", porcentof);
    printf("O total de homens que nao gostaram do produto foi de %.2f \n", porcentoM);

    free(vtrsexo);
    free(vtropiniao);

    return 0;
}