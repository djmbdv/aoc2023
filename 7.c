#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



struct Card {
    long bid;
    char card[6];
};



int rep( char a, char * str){
    int r = 0;
    for(;*str; str++)if(*str == a)r++;
    return r;
}


int repOfCars(char *c){
    int r, maxRep = 0, rest = 0;
    char last = 0;
    for(int i=0;c[i];i++){
        if(c[i] == 'A' )continue;
        r = rep(c[i],c);
        if(r > maxRep){
            maxRep = r;
            last = c[i];
        }
    }
    rest = (maxRep + rep('A',c)) *10;
    maxRep = 0;
    for(int j=0;c[j];j++){
        if(c[j] == 'A' )continue;
        if(c[j] == last)continue;
        r = rep(c[j],c);

        if(r > maxRep)
            maxRep = r;
    }
    return (rest + maxRep) ;
}

int comparatorCars(const void *a,const void *b ){
    int c;
    char *cardA, *cardB;
    cardA = ((struct Card *)a)->card;
    cardB = ((struct Card *)b)->card;
    if((repOfCars(cardA) - repOfCars(cardB))!= 0)return (repOfCars(cardA) - repOfCars(cardB));
        
    return strcmp(cardA, cardB);
}




int main(void){
    struct Card cards[1001];
    long long sum = 0;
    char map[1000];
    map['T'] = 'B' + 10;
    map['J'] = 'B' + 11;
    map['Q'] = 'B' + 12;
    map['K'] = 'B' + 13;
    map['A'] = 'B' + 14;

    int bid;
    char *c;
    int i = 0;

    while(scanf("%s %ld\n", cards[i].card, &cards[i].bid) > 0){
        for(c = cards[i].card;*c;c++)*c = isdigit(*c) ? *c - '1' + 'A': map[*c];
   i++;
    }
    printf("\n-------------------\n");
    qsort(cards,i,sizeof(struct Card), comparatorCars);
    for(long j = 0; j < i; j++){
        printf("%s %ld %d\n", cards[j].card,cards[j].bid ,repOfCars(cards[j].card));
         sum += (j + 1) * cards[j].bid;
    }

    printf("Part 1: %lld\n", sum);
    for(long j = 0; j < i; j++)
        for(c = cards[j].card;*c;c++)if(*c == 'B' + 11) *c = 'A';

    qsort(cards,i,sizeof(struct Card), comparatorCars);
    sum = 0;
    for(long j = 0; j < i; j++){
         sum += (j + 1) * cards[j].bid;
    }

    printf("Part 2: %lld\n", sum);



}