#include <stdio.h>
#include "tomcrypt_hash.h"
int number = 0;
//abc
//a9 99 3e 36 47 6 81 6a ba 3e 25 71 78 50 c2 6c 9c d0 d8 9d
//0  0  0 54 9f c4 c5 73 39 6b 88 c9 5d 88 5a 53 6b 22 a6 75
int verdade(char *str, int i)
{
    if(i == number - 1){
        return 0;
    }   else{
        if( 0 == str[i]){
            return 1 + verdade (str, i+1);
        }   else{
            return 0 + verdade (str, i+1);
        }
    }
}


int main(int argv, char **argc){
    unsigned char tmp[20];
    hash_state md;
    char *msg;
    char arg1[100], arg2[100];
    char *buf, *p;
    number = atoi(argc[1]);
    msg = argc[2];
    {
        //simple example
        sha1_init(&md);
        sha1_process(&md, (unsigned char *)msg, (unsigned long)strlen(msg));
        for (int i=0;i<20;i++)
            printf("%x ", tmp[i]);
        printf("\n");
    }

    {
        //POW example
        unsigned long k=0;
        char *powMsg="abcsfsrgfresgdrsgdsgdtgdtghdthdt";
        //allocate space for a long integer (10 digits) + 1 for any terminating null character necessary
        char *powStr=(char*) malloc( strlen(powMsg) + 10 + 1);
    
        while (1) {
        
            //TENHO a certeza que alocei bem memoria para sprintf
            #pragma GCC diagnostic ignored "-Wformat-overflow"
            sprintf(powStr, "%s%lu", powMsg,k);

            sha1_init(&md);
            sha1_process(&md, (unsigned char *)powStr, (unsigned long)strlen(powStr));
            sha1_done(&md, tmp);

            if ( verdade(tmp, 0) % number == 1 )
            {
                printf("POW done : k = %lu\n",k);
                for (int i=0;i<20;i++)
                    printf("%x ", tmp[i]);
                printf("\n");
                break;
            }
            if (k%5000000 == 0)
                printf("searching %lu\n",k);
            k++;
        }
    }
    
}