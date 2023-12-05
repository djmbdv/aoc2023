#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
    char line[1024];
    int cards[1024], sumcard = 0;
    
    size_t split;
    size_t init;
    char buf2[100];
    char *n = buf2 +1 ;
    buf2[0] = ' ';
    char *location = NULL;
    int game, sum = 0,k;
    int len;
    size_t x = 0, y = 0;
    for(int i = 0; i < 1024 ; i++)cards[i] = 1;
    while(scanf(" %[^\n]", line) > 0){
        len= strlen(line);
        line[len] = ' ';
        line[len + 1] = 0;
        game = 0;
    
        
        for (size_t i = 0; line[i]; i++)
        {
            if(line[i]  == ':'){
                init = i + 2;
            }
            if (line[i] == '|')
            {
                line[i] = 0;
                split = i+1;
            }
            
        }
        y= 1;
        while( (k = sscanf(&line[init]," %s ",n)) > 0){
            init+=(line[init + strlen(n)+1] == ' ')  ? strlen(n) + 2: strlen(n)+1;
            len  = strlen(buf2);
            buf2[len] = ' ';
            buf2[len+1] = 0;
            if((location = strstr(&line[split],buf2))  ){
                cards[x + y++] +=  cards[x];
                game = game?  game << 1: 1;
            }
            
        }
       
        x++;
        sum+=game;
    }
    for(int i = 0; i < x; i++)sumcard += cards[i];

    printf("Part 1: %d\n",sum);
    printf ("Part 2: %d\n",sumcard);
}