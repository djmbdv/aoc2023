#include <stdio.h>
#include <string.h>

// PROBLEM #1 Advent of Code 2023

const char* numbers[] = { 
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine"
};

int main(void) {
    char c, lastchar = 0;
    int conditions[10] = { 0,0,0,0,0,0,0,0,0,0}, i;
    int ac = 0, b = -1, e;

    while((c = getchar()) != EOF){
        if(c == '\n'){
            memset(conditions, 0, sizeof(conditions));
            lastchar = 0;
            if(b == -1)continue;
            ac += b*10  + e ;
            printf( "%d\n", b*10  + e );
            b = -1;
            e = 0;
            continue;
        }
        if(c >= '0' && c <= '9'){
            if(b == -1)b = (c - '0');
            e = (c - '0');
        }else{
            for(i= 0; i < 10; i++){
                if(c == numbers[i][conditions[i]])
                conditions[i]++;
                else if( c == numbers[i][0])
                    conditions[i] = 1;
                else if (c == numbers[i][1]  && lastchar == numbers[i][0])
                    conditions[i] = 2;
                else conditions[i] = 0;
                if(numbers[i][conditions[i]] == 0){
                    if(b == -1)b = i;
                    e = i;
                }
            }
        }
        lastchar = c;
    }
    printf("%d\n", ac);
}