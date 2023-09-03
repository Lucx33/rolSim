all: teste main random

teste: teste.c
	gcc -Wall -o teste teste.c

main: main.c
	gcc -Wall -o main main.c

random: random.c
	gcc -Wall -o random random.c
