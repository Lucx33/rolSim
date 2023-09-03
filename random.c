#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    //Inicializa o gerador de números aleatórios com o tempo atual
    srand(time(NULL));

    //Cria variáveis
    int result, MAX, NUM, /*AVG,*/ TOTAL;

    //Dorme por 1 segundo
    sleep(1);

    //Switch para verificar o número de argumentos
    switch(argc){
        //Caso para 1 argumento, "r/roll MAX"
        case 2:
            //Converte o argumento para inteiro 
            MAX = atoi(argv[1]);
            
            //Gera um número aleatório entre 1 e MAX
            result = rand() % MAX + 1;
            printf("%d\n", result);
            break;

        //Caso para 2 argumentos, "r/roll MAX NUM"  
        case 3:
            //Converte os argumentos para inteiros
            MAX = atoi(argv[1]);
            NUM = atoi(argv[2]);
            
            //Gera NUM números aleatórios entre 1 e MAX
            for(int i = 0; i < NUM; i++){
                result = rand() % MAX + 1;
                
                //Salva a soma dos números gerados
                TOTAL += result;
                printf("%d ", result);
            }
            
            //AVG /= NUM;
            printf("\nTotal: %d\n", TOTAL);
            break;
        
        //Caso default, muitos/poucos argumentos
        default:
            printf("Erro: muitos/poucos argumentos\n");
            break;
    }
    
    return 0;
}

