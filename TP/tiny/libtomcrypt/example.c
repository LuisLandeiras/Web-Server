//abc
//a9 99 3e 36 47 6 81 6a ba 3e 25 71 78 50 c2 6c 9c d0 d8 9d
//0  0  0 54 9f c4 c5 73 39 6b 88 c9 5d 88 5a 53 6b 22 a6 75 
#include <stdio.h>
#include "tomcrypt_hash.h"

int main(int argc, char **argv){
    unsigned char tmp[20];
    hash_state md;
    unsigned long k=0;
    
    char *powMsg= argv[2];
    int dif = atoi(argv[1]);
    printf("%d\n", dif);

    //allocate space for a long integer (10 digits) + 1 for any terminating null character necessary
    char *powStr=(char*) malloc( strlen(powMsg) + 10 + 1);

    while (1) {
        //TENHO a certeza que alocei bem memoria para sprintf
        #pragma GCC diagnostic ignored "-Wformat-overflow"
        sprintf(powStr, "%s%lu", powMsg,k);
        sha1_init(&md);
        sha1_process(&md, (unsigned char *)powStr, (unsigned long)strlen(powStr));
        sha1_done(&md, tmp);

        if (0==tmp[0] && 0==tmp[1] && 0==tmp[2])
        {
            printf("Hash = %lu\n",k);
            for (int i = 0;i < 20; i++)
                printf("%x ", tmp[i]);
            printf("\n");
            break;
        }
        k++;
    }
}