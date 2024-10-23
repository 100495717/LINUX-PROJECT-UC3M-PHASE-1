//P1-SSOO-23/24

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#define TAM_BUFFER 1 //Aquí marcamos que el tamaño del buffer es 1
int main(int argc, char *argv[]){
	/*If less than two arguments (argv[0] -> program, argv[1] -> file to process) print an error y return -1*/
	if(argc < 2)
	{
		printf("Too few arguments\n");
		return -1;
	}
	else
	{
	// Inicializamos las variables del buffer, del archivo y del resultado 

	char buffer[TAM_BUFFER];
	int archivo, resultado;
	
	if ((archivo = open(argv[1], O_RDONLY))<0)
	{
	//El archivo no se puede abrir
	return -1;
	}
	else
	{
	//Se ha podido abrir el archivo, inicializo variables para contar líneas, palabras y bytes. Además, inicializo una variable que comprueba si está en una palabra
	int lineas=0,words=0,bytes=0;
	int en_palabra = 0; //Comienzo sin estar en una palabra
	while ((resultado = read(archivo,buffer,TAM_BUFFER))>0)
	{ //Esto significa que estoy en un palabra, es decir, que no es ninguna tabulación, ni espacio ni salto de línea
	if(buffer[0] != ' '  && buffer[0] != '\t' && buffer[0] != '\n')
	{ en_palabra =1;
	}
	else {
		if (en_palabra == 1)
		{	en_palabra = 0;
			words++; //esto significa que ha leído un tb, un salto de línea o un espacio, por lo que la palabra ya ha terminado y se suma
		}
		if (buffer[0] == '\n'){
			lineas++; //Ha habido un salto de línea
			}
		}
	bytes++; //Ya he comprobado todas las opciones, sumo un byte
	}

	if (resultado == -1) {
	return -1; //Ha habido un error leyendo
	}
	//hay que controlar si acaba en una palabra para poder sumarla
	if (en_palabra){
	words++;
	}
	//ya he terminado de leer el archivo, lo cierro
	close(archivo);
	//Imprimo los resultados
	printf("%d %d %d %s\n",lineas,words,bytes,argv[1]);
	}
}
	return 0;
}

	
