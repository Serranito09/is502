#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>

int v[5];
pthread_mutex_t semaforo;

void *productor(){
    for(int i=0;i<10;i++){
        int pos=rand()%5;
        int cant=rand()%10;
        printf("Hilo %lu produce 1 en la posicion %d\n",pthread_self(),pos);
        v[pos]=cant;
    }       pthread_exit(NULL);

}
void *consumidor(){
    for(int i=0;i<10;i++){
        int pos=rand()%5;
        int cant=rand()%10;
        printf("Hilo %lu consume 1 en la posicion %d\n",pthread_self(),pos);
        v[pos]=cant;
    }
           pthread_exit(NULL);
}