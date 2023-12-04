#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define NotDigitAndNotDot(X) (X != '.' && !isdigit(X))

int main(void){ 
    char *buf1,*buf2;
    void *aux;
    int j,n, iterations = 0;
    long sum_gears = 0;
    long *bValue1 = NULL,*bValue2 = NULL;

    size_t sum = 0, len;
    buf1 = malloc(1024);
    buf2 =  malloc(1024);
    bValue1  =  (size_t *)malloc(1024 *sizeof(size_t));
    bValue2  =  (size_t *)malloc(1024 *sizeof(size_t));
    
    memset( buf2,'.', 1023);

    while(scanf("%[^\n] " , buf1) > -1){
            len = strlen(buf1);
            memset(bValue1, 0,1024 * sizeof(size_t));
            for(size_t  i = 0;  buf1[i]; i++){
                if(NotDigitAndNotDot(buf1[i]) && buf1[i] != '*') buf1[i] ='%';
                if(iterations >  0){
                    if(NotDigitAndNotDot(buf1[i])  && (i > 0 && isdigit(buf2[i-1])) ){
                        for(j = i-1; j > 0 && isdigit(buf2[j-1]); --j);
                        sscanf(&buf2[j], "%u", &n);
                        memset(buf2 + j ,'.', (int)log10(n)+1);
                        sum+=n;
                        if(buf1[i] == '*'){
                            buf1[i]++;
                            bValue1[i] = -n;
                        }else if(buf1[i] == '+'){
                            buf1[i]++;
                            bValue1[i]=-bValue1[i]*n;
                        }
                        else bValue1[i]  = 0;
                    }
                    if(NotDigitAndNotDot(buf1[i]) &&  (isdigit(buf2[i])) ){
                        for(j = i; j > 0 && isdigit(buf2[j-1]); --j);
                        sscanf(&buf2[j], "%u", &n);
                        memset(buf2 + j ,'.', (int)log10(n)+1);
                        sum+=n;
                        if(buf1[i] == '*'){
                            buf1[i]++;
                            bValue1[i] =-n;
                        }else if(buf1[i] == '+'){
                            buf1[i]++;
                            bValue1[i]=-bValue1[i]*n;;
                        }
                        else bValue1[i]  = 0;
                    }
                    if(NotDigitAndNotDot(buf1[i])  &&  i+1 < len && (isdigit(buf2[i+1])) ){
                        for(j = i+1; j > 0 && isdigit(buf2[j-1]); --j);
                        sscanf(&buf2[j ], "%u", &n);
                        memset( buf2 + j ,'.', (int)log10(n)+1);
                        sum+=n;
                        if(buf1[i] == '*'){
                            buf1[i]++;
                            bValue1[i] = -n;
                        }else if(buf1[i] == '+'){
                            buf1[i]++;
                            bValue1[i]=-bValue1[i]*n;
                        }
                        else bValue1[i]  = 0;
                    }
                    

                    if(isdigit(buf1[i]) && i > 0 && NotDigitAndNotDot(buf2[i-1]) ){
                        for(j = i; j > 0 && isdigit(buf1[j-1]); --j);
                        sscanf(&buf1[j], "%u", &n);
                        memset( buf1 + j ,'.', (int)log10(n)+ 1);
                        sum+=n;
                        if(buf2[i-1] == '*')buf2[i-1];

                        if(buf2[i-1] == '*'){
                            buf2[i-1]++;
                            bValue2[i-1] = -n;
                        }else if(buf2[i-1] == '+'){
                            buf2[i]++;
                            bValue2[i-1]= -bValue2[i-1]*n;
                        }
                        else bValue2[i]  = 0;
                    }
                    if(isdigit(buf1[i])  && NotDigitAndNotDot(buf2[i]) ){
                        for(j = i; j > 0 && isdigit(buf1[j-1]); --j);
                        sscanf(&buf1[j], "%u", &n);
                        memset( buf1 + j,'.', (int)log10(n)+1);
                        sum+=n;
                        if(buf2[i] == '*'){
                            buf2[i]++;
                            bValue2[i] = -n;
                        }else if(buf2[i] == '+'){
                            buf2[i]++;
                            bValue2[i] = -bValue2[i]*n;
                        }
                        else bValue2[i]  = 0;
                    }
                    if(isdigit(buf1[i]) &&  i+1 < len && NotDigitAndNotDot(buf2[i+1]) ){
                        for(j = i; j > 0 && isdigit(buf1[j-1]); --j);
                        sscanf(buf1 + j , "%u", &n);
                        memset( buf1 + j ,'.', (int)log10(n) + 1);
                        sum+=n;
                        if(buf2[i+1] == '*'){
                            buf2[i+1]++;
                            bValue2[i+1] = -n;
                        }else if(buf2[i+1] == '+'){
                            buf2[i+1]++;
                            bValue2[i+1] = -bValue2[i+1]*n;
                        }
                        else bValue2[i+1]  = 0;
                    }
                }


                if(NotDigitAndNotDot(buf1[i]) && i > 0 && isdigit(buf1[i-1])){
                    for(j = i-1; j > 0 && isdigit(buf1[j-1]); --j);
                    sscanf(&buf1[j], "%u", &n);
                    memset( buf1 + j ,'.', (int)log10(n) + 1);
                    sum+=n;
                    if(buf1[i] == '*'){
                            buf1[i]++;
                            bValue1[i] = -n;
                    }else if(buf1[i] == '+'){
                            buf1[i]++;
                            bValue1[i] = -bValue1[i]*n;
                    }else bValue1[i]  = 0;
                }

                if(NotDigitAndNotDot(buf1[i])  && i+1 < len && isdigit(buf1[i+1])){
                    sscanf(&buf1[i+1], "%u", &n);
                    memset( buf1 + i + 1,'.', (int)log10(n) + 1);
                    sum+=n;
                        if(buf1[i] == '*'){
                            buf1[i]++;
                            bValue1[i] = -n;
                        }else if(buf1[i] == '+'){
                            buf1[i]++;
                            bValue1[i] = -bValue1[i]*n;
                        }
                        else bValue1[i]  = 0;
                }
            }
          

        if(iterations)for(int k = 0;k < len; k++){
            sum_gears += (bValue2[k] > 0) ? bValue2[k]: 0 ;
        }
         ++iterations;
        aux = bValue2;
        bValue2 = bValue1;
        bValue1 = aux;

        aux = buf1;
        buf1 = buf2;
        buf2 = aux;
    }
    printf("Part 1: sum of pieces %ld\n", sum);
    printf("Part 2: sum of gears %ld\n", sum_gears);
}