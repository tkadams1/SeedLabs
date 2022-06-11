#include <stdio.h>
#include <stdlib.h>
#define LEN 32  // 256 bits

int main(){

    unsigned char *key = (unsigned char *) malloc(sizeof(unsigned char)*LEN);
    FILE* random = fopen("/dev/urandom", "r");
    fread(key, sizeof(unsigned char)*LEN, 1, random);
    printf("The 256 bit key generated is: ");
    for (int i = 0; i< LEN; i++){
        printf("%.2x", (unsigned char)key[i]);
    }

    fclose(random);
    printf("\n");

}

main();