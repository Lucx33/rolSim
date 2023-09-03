# rolSim
Simulador de rolagem de dados em C.

### Pré-requisitos
1. Para utilizá-lo, é necessário estar em um ambiente LINUX/UNIX ou WSL.
2. C
3. GCC
4. run> make all

### Rodando
run> ./main

O programa aceita tanto "r" quanto "roll" como comandos.

O primeiro parâmetro é o número de faces do dado, por exemplo: 6, 10, 20, 100.

O segundo parâmetro (opcional) é a quantidade de dados a serem rolados.

### Exemplos
"r 100"

O programa irá "jogar" um dado de 100 faces. d100.

"r 20 10"

O programa irá "rolar" 10 dados de 20 faces. 10d20.
