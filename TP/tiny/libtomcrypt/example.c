#include <stdio.h>
#include "tomcrypt_hash.h"
#include "csapp.h"

int main(){
    unsigned char tmp[20];
    char *buf, *p, n2;
    hash_state md;
    unsigned long k=0;
    char arg1[MAXLINE], arg2[MAXLINE], content[MAXLINE];
    int n1 = 0;

    if ((buf = getenv("QUERY_STRING")) != NULL) {
	p = strchr(buf, '&');
	*p = '\0';
	strcpy(arg1, buf);
	strcpy(arg2, p+1);
	n1 = atoi(arg1);
	n2 = arg2;
    }

    char *powMsg= n2;
    int dif = n1;
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

        if(dif == 1){
            if(0 == tmp[0]){
                printf("HASH = %lu\n",k);
                for (int i = 0;i < 20; i++)
                    printf("%x ", tmp[i]);
                printf("\n");
                break;
            }
        } else if(dif == 2){
            if(0 == tmp[0] && 0 == tmp[1]){
                printf("HASH = %lu\n",k);
                for (int i = 0;i < 20; i++)
                    printf("%x ", tmp[i]);
                printf("\n");
                break;
            }
        } else if(dif == 3){
            if(0 == tmp[0] && 0 == tmp[1] && 0 == tmp[2]){
                printf("HASH = %lu\n",k);
                for (int i = 0;i < 20; i++)
                    printf("%x ", tmp[i]);
                printf("\n");
                break;
            }
        } else if(dif == 4){
            if(0 == tmp[0] && 0 == tmp[1] && 0 == tmp[2] && 0 == tmp[3]){
                printf("HASH = %lu\n",k);
                for (int i = 0;i < 20; i++)
                    printf("%x ", tmp[i]);
                printf("\n");
                break;
            }
        } else if(dif == 5){
            if(0 == tmp[0] && 0 == tmp[1] && 0 == tmp[2] && 0 == tmp[3] && 0 == tmp[4]){
                printf("HASH = %lu\n",k);
                for (int i = 0;i < 20; i++)
                    printf("%x ", tmp[i]);
                printf("\n");
                break;
            }
        } else if(dif == 6){
            if(0 == tmp[0] && 0 == tmp[1] && 0 == tmp[2] && 0 == tmp[3] && 0 == tmp[4] && 0 == tmp[5]){
                printf("HASH = %lu\n",k);
                for (int i = 0;i < 20; i++)
                    printf("%x ", tmp[i]);
                printf("\n");
                break;
            }
        } else if(dif == 7){
            if(0 == tmp[0] && 0 == tmp[1] && 0 == tmp[2] && 0 == tmp[3] && 0 == tmp[4] && 0 == tmp[5] && 0 == tmp[6]){
                printf("HASH = %lu\n",k);
                for (int i = 0;i < 20; i++)
                    printf("%x ", tmp[i]);
                printf("\n");
                break;
            }
        } else if(dif == 8){
            if(0 == tmp[0] && 0 == tmp[1] && 0 == tmp[2] && 0 == tmp[3] && 0 == tmp[4] && 0 == tmp[5] && 0 == tmp[6] && 0 == tmp[7]){
                printf("HASH = %lu\n",k);
                for (int i = 0;i < 20; i++)
                    printf("%x ", tmp[i]);
                printf("\n");
                break;
            }
        } else if(dif == 9){
            if(0 == tmp[0] && 0 == tmp[1] && 0 == tmp[2] && 0 == tmp[3] && 0 == tmp[4] && 0 == tmp[5] && 0 == tmp[6] && 0 == tmp[7] && 0 == tmp[8]){
                printf("HASH = %lu\n",k);
                for (int i = 0;i < 20; i++)
                    printf("%x ", tmp[i]);
                printf("\n");
                break;
            }
        } else{
            printf("HASH = %lu\n",k);
            for (int i = 0;i < 20; i++)
                printf("%x ", tmp[i]);
            printf("\n");
            break;
        }
        k++;
    }
    
    
    
}

