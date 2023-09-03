#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void type_prompt(void){
    //Função para imprimir o prompt
    printf("Rolador> ");
}

void read_command(char* input, char **command, char *parameters[]){
    //Função para ler o comando e os parâmetros de uma string input
    //strtok para separar o input em tokens
    char *token = strtok(input, " ");
    
    //O primeiro token é o comando
    int i = 1;
    *command = token;
    
    //O primeiro parâmetro é o comando
    parameters[0] = token;

    //Os próximos tokens são os parâmetros
    while(token != NULL){
        //NULL para indicar que strtok deve continuar a procurar
        token = strtok(NULL, " \n");
        parameters[i] = token;
        i++;
    }
    if(i == 2)
    //O último parâmetro é NULL
    parameters[i] = NULL;
}

void troca_command(char** command, char* parameters[]){
    //Função para trocar o comando lido na shell para o executável correto
    if(strcmp(*command, "roll") == 0 || strcmp(*command, "r") == 0){
        *command = "./random";
        parameters[0] = "./random";
    }
}

int main(void){
    //Variáveis para ler o comando e os parâmetros
    char* command, *parameters[20], input[1000];
    //Variável para o status do processo
    int status = 0;
    while(1){
        //Loop para executar o shell
        type_prompt();

        //Lê o comando e os parâmetros
		fgets(input, sizeof(input), stdin);

        //Passa o comando e os parâmetros para a função read_command
		read_command(input, &command, parameters);

        //Cria um processo filho
		if (fork() != 0){
            //Processo pai espera o filho terminar
			waitpid(-1, &status, 0);
		} else {
            //Processo filho
            //Troca os comandos para os executáveis corretos
            troca_command(&command, parameters);

            //Executa o comando
			execvp(command, parameters);

            //Se o comando não existir, imprime o erro
			perror("Exec falhou");
			exit(1);
		}
    }

    return 0;
}