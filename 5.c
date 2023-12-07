#include <stdio.h>
#include <string.h>
#include <limits.h>

typedef struct range
{
  long long end_range;
  long long start_range;
  long long size_range;
} ;


long long process(long long input, struct range *r, int nranges ){
  for( int i=0; i<nranges/2 + 1 ; i++){
    
     if(input >= (r+i)->start_range && input <= (r+i)->start_range + (r+i)->size_range ){
      return   (r+i)->end_range  + input - (r+i)->start_range; 
     }
     if(input >= (r+nranges - i)->start_range && input <= (r+nranges - i)->start_range + (r+nranges - i)->size_range ){
      return   (r+nranges - i)->end_range  + input -(r+nranges - i)->start_range; 
     }
  }
  return input;
}



int main(void){
  enum Level {
    SOIL = 2,
    FERTILIZER,
    WATER,
    LIGHT,
    TEMPERATURE,
    HUMIDITY,
    LOCATION,
  };
  long long numbers[1000],numbers2[1000],i,j,nrsoil = 0, nrfertilizer = 0, nrwater = 0, nrlight = 0, nrtemperature = 0, nrhumidity = 0,nrlocation = 0, minorj,minori;
  struct range rsoil[1000],rfertilizer[1000],rwater[1000],rlight[1000],rtemperature[1000],rhumidity[1000], rlocation[1000];
  char flags[1000];
  int count = 0;
  long long temp, minor;
  long long end_range, start_range, size_range;
  memset(flags, 0, sizeof(flags));

  scanf("seeds:");
  while (scanf(" %lld", &temp) == 1) {
    numbers[count] = temp;
    numbers2[count++] = temp;
  }
    
   for(i = 0; i < count; i++){
      printf("%lld ",numbers[i]);
    }
    printf(">\n");
 
  scanf("seed-to-soil map:");
  while (scanf(" %lld %lld %lld", &end_range, &start_range, &size_range) > 0) {
    rsoil[nrsoil].start_range = start_range;
    rsoil[nrsoil].end_range = end_range;
    rsoil[nrsoil++].size_range = size_range;
    printf(" %lld %lld %lld\n", end_range, start_range, size_range);
    for(i = 0; i < count; i++){
      if(numbers[i] >= start_range && numbers[i] <= start_range + size_range && flags[i] != SOIL){ numbers[i] =  end_range  + numbers[i] - start_range; flags[i] = SOIL; }
    }
  }
    for(i = 0; i < count; i++){
      printf("%lld ",numbers[i]);
    }
    printf(">\n");
  scanf("soil-to-fertilizer map:");
  while (scanf(" %lld %lld %lld", &end_range, &start_range, &size_range) > 0) {
    rfertilizer[nrfertilizer].end_range = end_range;
    rfertilizer[nrfertilizer].start_range = start_range;
    rfertilizer[nrfertilizer++].size_range = size_range;
    printf(" %lld %lld %lld\n", end_range, start_range, size_range);
    for(i = 0; i < count; i++){
      if(numbers[i] >= start_range && numbers[i] <= start_range + size_range && flags[i] != FERTILIZER){ numbers[i] =  end_range  + numbers[i] - start_range; flags[i] = FERTILIZER;}
    }
  }
    for(i = 0; i < count; i++){
      printf("%lld ",numbers[i]);
    }
    printf(">\n");
  scanf("fertilizer-to-water map:");
  while (scanf(" %lld %lld %lld", &end_range, &start_range, &size_range) > 0) {
    rwater[nrwater].end_range = end_range;
    rwater[nrwater].start_range = start_range;
    rwater[nrwater++].size_range = size_range;
    printf(" %lld %lld %lld\n", end_range, start_range, size_range);
    for(i = 0; i < count; i++){
      if(numbers[i] >= start_range && numbers[i] <= start_range + size_range && flags[i]!= WATER){ numbers[i] =  end_range  + numbers[i] - start_range; flags[i]= WATER;}
    }
  }
   for(i = 0; i < count; i++){
      printf("%lld ",numbers[i]);
    }
    printf(">\n");
    scanf("water-to-light map:");
  while (scanf(" %lld %lld %lld", &end_range, &start_range, &size_range) > 0) {
    rlight[nrlight].end_range = end_range;
    rlight[nrlight].start_range = start_range;
    rlight[nrlight++].size_range = size_range;
    printf(" %lld %lld %lld\n", end_range, start_range, size_range);
    for(i = 0; i < count; i++){
      if(numbers[i] >= start_range && numbers[i] <= start_range + size_range && flags[i] != LIGHT){ numbers[i] =  end_range  + numbers[i] - start_range; flags[i] = LIGHT; }
    }
  }
   for(i = 0; i < count; i++){
      printf("%lld ",numbers[i]);
    }
    printf(">\n");
    scanf(" light-to-temperature map:");
  while (scanf(" %lld %lld %lld", &end_range, &start_range, &size_range) > 0) {
    rtemperature[nrtemperature].end_range = end_range;
    rtemperature[nrtemperature].start_range = start_range;
    rtemperature[nrtemperature++].size_range = size_range;
        printf(" %lld %lld %lld\n", end_range, start_range, size_range);
    for(i = 0; i < count; i++){
      if(numbers[i] >= start_range && numbers[i] <= start_range + size_range && flags[i] != TEMPERATURE){ numbers[i] =  end_range  + numbers[i] - start_range; flags[i] = TEMPERATURE;}
    }
  }
   for(i = 0; i < count; i++){
      printf("%lld ",numbers[i]);
    }
    printf(">\n");
    scanf("temperature-to-humidity map:");
  while (scanf("%lld %lld %lld", &end_range, &start_range, &size_range) > 0) {
    rhumidity[nrhumidity].end_range = end_range;
    rhumidity[nrhumidity].start_range = start_range;
    rhumidity[nrhumidity++].size_range = size_range;
        printf(" %lld %lld %lld\n", end_range, start_range, size_range);
    for(i = 0; i < count; i++){
      if(numbers[i] >= start_range && numbers[i] <= start_range + size_range && flags[i] != HUMIDITY){ numbers[i] =  end_range  + numbers[i] - start_range; flags[i]= HUMIDITY;}
    }
  }
   for(i = 0; i < count; i++){
      printf("%lld ",numbers[i]);
    }
    printf(">\n");
  scanf("humidity-to-location map:");
  while (scanf(" %lld %lld %lld", &end_range, &start_range, &size_range) > 0) {
    rlocation[nrlocation].end_range = end_range;
    rlocation[nrlocation].start_range = start_range;
    rlocation[nrlocation++].size_range = size_range;
        printf(" %lld %lld %lld\n", end_range, start_range, size_range);
    for(i = 0; i < count; i++){
      if(numbers[i] >= start_range && numbers[i] <= start_range + size_range && flags[i] != LOCATION){ numbers[i] =  end_range  + numbers[i] - start_range; flags[i] = LOCATION;}
    }
  }
  minor = numbers[0];
   for(i = 0; i < count; i++){
      if( numbers[i] <  minor)minor = numbers[i];
      printf("[%lld][%lld]",numbers[i], minor);
  
   }
    printf("\nPart 1: %lld \n", minor);
 /**        PART 2    */                  
  for (i = 0, minori = LLONG_MAX; i < count/2; i++){
    printf("\nrange [%lld, %lld]", numbers2[i*2], numbers2[i*2+1]);
    for(j = numbers2[i*2],minorj = LLONG_MAX; j < numbers2[i*2] + numbers2[i*2 + 1]; j++){
      temp = process(
              process(
                process(
                  process(
                    process(
                      process(
                        process( j , rsoil, nrsoil), rfertilizer, nrfertilizer),
                      rwater, nrwater),
                    rlight, nrlight ),
                  rtemperature, nrtemperature),
                rhumidity, nrhumidity),
              rlocation, nrlocation);
      
      if(temp < minorj)minorj = temp;
    }
    printf(", max j= %lld  %lld\n", j , numbers2[i*2] + numbers2[i*2 + 1]);
    if(minorj <  minori) minori = minorj;
  }

  printf("\nPart 2: %lld \n", minori);

}