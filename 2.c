#include <stdio.h>
#include <string.h>

#define MAX_RED 12
#define MAX_GREEN 13
#define MAX_BLUE 14


int main(void){
    int i,j, valid;
    size_t green, blue, red, sum_of_id = 0, sum_of_pow = 0;
    char c,buf[1024];
    
    while(scanf("Game %d: ",&i) > 0){
        valid = 1;
        green = blue = red = 0;
        do{
            scanf("%d %[^;,\n]%c",&j,buf, &c);
            if( strcmp("red",buf) == 0){
                if(j > MAX_RED)valid = 0;
                if(j >  red)red = j;
            }
            else if( strcmp("green",buf) == 0){
                if(j > MAX_GREEN)valid = 0;
                if(j > green)green = j;
            }else if(strcmp("blue",buf) == 0){
                if(j > MAX_BLUE)valid = 0;
                if(j > blue)blue = j;
            }
            
        }while(c != '\n');
        sum_of_pow += blue * green * red;
        if(valid)sum_of_id += i;
        printf("Game %d %s\n",i , (valid)?"valid":"invalid");
    }
    printf("Part 1: Sum of valid games %ld\n",sum_of_id);
    printf("Part 2: Sum of powers %ld\n",sum_of_pow);
}