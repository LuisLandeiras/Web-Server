#include <stdio.h>
#include "tomcrypt_hash.h"

int main(){
    unsigned char tmp[20];
    hash_state md;


    {
        //simple example
        char *msg="abc";
        sha1_init(&md);
        sha1_process(&md, (unsigned char *)msg, (unsigned long)strlen(msg));
        sha1_done(&md, tmp);
        for (int i=0;i<20;i++)
            printf("%x ", tmp[i]);
        printf("\n");
    }

    {
        //POW example
        unsigned long k=0;
        char *powMsg="O Zézinho é gay";
        //allocate space for a long integer (10 digits) + 1 for any terminating null character necessary
        char *powStr=(char*) malloc( strlen(powMsg) + 10 + 1);
    
        while (1) {
        
            //TENHO a certeza que alocei bem memoria para sprintf
            #pragma GCC diagnostic ignored "-Wformat-overflow"
            sprintf(powStr, "%s%lu", powMsg,k);

            sha1_init(&md);
            sha1_process(&md, (unsigned char *)powStr, (unsigned long)strlen(powStr));
            sha1_done(&md, tmp);

            if ( 0==tmp[0] && 0==tmp[1] && 0==tmp[2])
            {
                printf("POW done : k = %lu\n",k);
                for (int i=0;i<20;i++)
                    printf("%x ", tmp[i]);
                printf("\n");
                break;
            }
            if (k%5000000==0)
                printf("searching %lu\n",k);
            k++;
        }
    }
}