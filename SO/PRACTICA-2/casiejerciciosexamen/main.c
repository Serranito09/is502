#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>

struct param{
    int v[10];
    int pos;
};
void *funcionhilo(struct param* p){
    if(p-> pos%2 ==0){
        

    }
    else{

    }
}
int main(){

    pthread_t vhilos[10];
    struct param p[10];
     srand(time(NULL));
    for(int j=0;j<10;j++){
        int n=rand()%10;
   for(int k=0;k<10;k++)
   {
       p[j].v[k]=n;
     }
    }
    for(int i=0;i<10;i++){
        p[i].pos=i;
                pthread_create(&vhilos[i],NULL,(void*)funcionhilo,(void *)&p[i]);
    }
    for(int j=0;j<10;j++){
        pthread_join(vhilos[j],NULL);
    }
    exit(EXIT_SUCCESS);
}