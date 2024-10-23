//P1-SSOO-23/24
#include <stdlib.h>
#include <stdio.h>		// Header file for system call printf
#include <unistd.h>		// Header file for system call gtcwd
#include <sys/types.h>	// Header file for system calls opendir, readdir y closedir
#include <dirent.h>
#include <string.h>

#define PATH_MAX 4096 //Se define el tamaño máximo de la ruta del directorio

int main(int argc, char *argv[])
{
	char cwd[PATH_MAX]; //Se almacena la ruta del directorio
	DIR *dir; //Se declara el puntero al directorio
	struct dirent *entry;
//Obtenemos el directorio
if (argc>1) {
	//Usamos el directorio especificado como argumento
	dir = opendir(argv[1]);
} else { 
	//Usamos el directorio actual
	getcwd(cwd,PATH_MAX);
	dir = opendir(cwd);
	}
//Si no se puede abrir el directorio, imprimimos un fallo
if (dir == NULL) {
	printf("Error: no se puede abrir el directorio");
	return -1;
}

//Mostramos los nombres de cada archivo del directorio

while ((entry = readdir(dir)) != NULL) {
	printf("%s\n", entry->d_name);
}

//Cerramos el directorio
closedir(dir);

	return 0;
}

