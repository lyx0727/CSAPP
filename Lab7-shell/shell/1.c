#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <setjmp.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <errno.h>
#include <math.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(){
    pid_t pid;

    for(int i = 0; i < 4; ++i){
        if((pid = fork()) == 0){
            printf("I'm child[%d]\n", i + 1);
            exit(100 + i);
        }
        else{
            printf("[%d]: I'm father[%d]\n", pid, i);
        }
    }

    return 0;
}
