#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <openssl/aes.h>
#define KEYSIZE 16

void task1();
void task2();



int main()
{
//task1();
task2();

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

void task2(){
    // char p[] = "255044462d312e350a25d0d4c5d80a34";
    // char c_unknown[KEYSIZE];
     char generated_key[KEYSIZE];
    // char c_known[] = "d06bf9d0dab8e8ef880660d2af65aa82";
    // char iv[] = "09080706050403020100A2B2C2D2E2F2";

    time_t time = 1524013729;
    time_t time_end = 1524020929;
    int j;
    for(time; time <= time_end; time++){
        //fprintf(f,"%lld\n", (long long) time);
        srand (time);
        //printf("%lld\n", (long long) time);
        for (j = 0; j< KEYSIZE; j++){
            generated_key[j] = rand()%256;
            printf("%.2x", (unsigned char)generated_key[j]);
           // AES_set_encrypt_key(*generated_key,128,AesKey);

    }
    printf("\n");

    }


}

