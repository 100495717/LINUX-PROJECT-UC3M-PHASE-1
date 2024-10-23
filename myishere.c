//P1-SSOO-23/24
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>


int main(int argc, char *argv[])
{
	/* If less than three arguments (argv[0] -> program, argv[1] -> directory to search, argv[2] -> file to find) print an error y return -1 */
	if(argc < 3)
	{
		printf("Too few arguments\n");
		return -1;
	}

	

// Abrimos el directorio
DIR *dir = opendir(argv[1]);

if (dir == NULL) {
printf("no se puede abrir el directorio");
//imprimo un error si no puede abrir el directorio

return -1;
}
//Busco el archivo en el directorio

struct dirent *entry;

int found = 0; //Variable para indicar si hemos encontrado el archivo
//Si llega a NULL, ha leído todos los archivos y no coincide, siempre y cuando no lo haya encontrado (found =0)
while(((entry = readdir(dir)) != NULL) && (found ==0)) {
	if (strcmp(entry->d_name, argv[2]) == 0) {
		found = 1;
	}
}

//Cerramos el directorio
closedir(dir);
//Si hemos encontrado o no
if (found == 1){
printf("File %s is in directory %s\n", argv[2],argv[1]);
} else{
printf("File %s is not in directory %s\n", argv[2],argv[1]);
}

return 0;
}
