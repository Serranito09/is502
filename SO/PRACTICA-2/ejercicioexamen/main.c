#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>

   struct numero{
        int num1;
        int num2;
    };

void *suma(struct numero *a){
    int suma=0;
    suma=(a->num1)+(a->num2);
       printf("[HILO]: Soy el hilo sumador %lu y la suma de %d y %d es %d.\n",pthread_self(),a->num1,a->num2,suma);
    int *retorno=(int*)malloc(sizeof(int));
    (*retorno)=suma;
    pthread_exit((void*)retorno);
}

void *resta(struct numero *a){
 int resta=0;
    resta=(a->num1)+(a->num2);
     printf("[HILO]: Soy el hilo restador %lu y la resta de %d y %d es %d.\n",pthread_self(),a->num1,a->num2,resta);
    int *retorno=(int*)malloc(sizeof(int));
    (*retorno)=resta;
    pthread_exit((void*)retorno);
}


int main(int argc,char **argv){
    srand(time(NULL));
    if(argc!=3){
        printf("error en linea de argumentos\n");
        exit(EXIT_FAILURE);
    }
    int n1=atoi(argv[1]);
    int n2=atoi(argv[2]);
    pthread_t hilos_sum[atoi(argv[1])],hilos_rest[atoi(argv[2])];
    struct numero v_sum[n1];
    struct numero v_rest[n2];
        for(int i=0;i<n1;i++){
        v_sum[i].num1=rand()%10;
        v_sum[i].num2=rand()%10;
            if(pthread_create(&hilos_sum[i],NULL,(void*)suma,&v_sum[i])!=0){
                printf("error al crear un hilo\n");
                exit(EXIT_FAILURE);
            }
        }
          
          for(int i=0;i<n2;i++){
        v_rest[i].num1=rand()%10;
        v_rest[i].num2=rand()%10;
            if(pthread_create(&hilos_rest[i],NULL,(void*)resta,&v_rest[i])!=0){
                printf("error al crear un hilo\n");
                exit(EXIT_FAILURE);
            }
        }int *valorRecogido;
        for(int j=0;j<n1;j++){
           if(pthread_join(hilos_sum[j],(void**)&valorRecogido)!=0)
           {
            printf("error\n");
            exit(EXIT_FAILURE);
           }
           printf("Main()...El hilo sumador %lu ha devuelto un %d.\n",hilos_sum[j],(*valorRecogido));
        }

         for(int j=0;j<n2;j++){
           if(pthread_join(hilos_rest[j],(void**)&valorRecogido)!=0)
           {
            printf("error\n");
            exit(EXIT_FAILURE);
           }
           printf("Main()...El hilo restador %lu ha devuelto un %d.\n",hilos_rest[j],(*valorRecogido));
    
        }
        
           exit(EXIT_SUCCESS);




}