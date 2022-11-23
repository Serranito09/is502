#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>


int contarlineas(char *nf){
    FILE* fich=fopen(nf,"r");
    if(fich==NULL){
        printf("error al abrir el fichero");
        exit(EXIT_FAILURE);
    }
    int cont=0;
    char cadena[200];
    while(fgets(cadena,200,fich)){
        cont++;
    }
    fclose(fich);
    return cont;
}

int main(int argc,char **argv){
    if(argc==1){
        printf("Error en linea de argumentos");
        exit(EXIT_FAILURE);
    }
    pid_t pid,flag;
    int status;
    int dato=0;

    for(int i=0;i<(argc-1);i++){
         pid=fork();
        if(pid == -1) //ERROR
        {
            printf("Error en el fork()\n");
            exit(EXIT_FAILURE);
        }
        else if(pid == 0) //HIJO
        {
            printf("[HIJO]: Soy el proceso %ld y mi padre es %ld\n",(long int)getpid(),(long int)getppid());
             dato=contarlineas(argv[i+1]);
             printf("el dato es:%i\n",dato);
            exit(dato);
        }
    }

    
    while((flag=wait(&status))>0){
        dato+=WEXITSTATUS(status);
		    if(WIFEXITED(status)){
		        printf("hijo %ld finalizado con status %d\n",(long int)pid,WEXITSTATUS(status));
		    }
		    else if(WIFSIGNALED(status)){
		        printf("hijo %ld finalizado tras recibir una senal con status %d\n",(long int)flag,WTERMSIG(status));
		    }
		    else if(WIFSTOPPED(status)){
		        printf("hijo %ld parado con status %d\n",(long int)flag,WSTOPSIG(status));
		    }
		    else if(WIFCONTINUED(status)){
		        printf("hijo %ld reanudado\n",(long int)flag);
		    }

		}
		if(flag==(pid_t)-1 && errno==ECHILD){ 
		    printf("Valor del errno= %d, definido como %s\n",errno,strerror(errno));
		}
		else{
		    printf("Error en la invocacion de wait o la llamada ha sido interrumpida por una señal\n");
		    exit(EXIT_FAILURE);
		} 
        printf("la suma es:%i\n",dato);

		exit(EXIT_SUCCESS);

    }
