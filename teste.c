#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#define MAX 20

int main(void){
    srand(time(NULL));
    int numero;
    double media;
    //double mediaTotal;
    media = 0;

    for(int i = 0; i < MAX; i++)
    numero = rand() % MAX + 1;
    media += (double)numero;
    printf("%d ", numero);
    fflush(stdout);
    usleep(1000);
    //printf("\n");
    return 0;
}

