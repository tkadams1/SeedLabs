#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <openssl/aes.h>
#define KEYSIZE 16

void task1();


int main()
{
task1();
//task2();

return 0;
}

void task1(){
    int i;
    char key[KEYSIZE];
    printf("%lld\n", (long long) time(NULL));
    srand (time(NULL));
    for (i = 0; i< KEYSIZE; i++){
    key[i] = rand()%256;
        printf("%.2x", (unsigned char)key[i]);
    }
    printf("\n");

    
}


