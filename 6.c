#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MIN(X, Y)   ((X < Y)?(X) : (Y))  
#define MAX(X, Y)   ((X > Y)?(X) : (Y))   

int main(void){
    long double distances[4];
    long double times[4];
    long double  min, min2, result;
    long double result2 = 1;
    char buffer[20];

    scanf(" Time: %Lf %Lf %Lf %Lf\n", &times[0], &times[1], &times[2],&times[3]);
    scanf(" Distance: %Lf %Lf %Lf %Lf", &distances[0], &distances[1], &distances[2], &distances[3]);

    for (int i = 0; i < 4; i++){
        min  = ( (times[i] + sqrtl((long double)times[i]*times[i] - (4.0 * distances[i]))) / 2.0);
        min2  = ((times[i] - sqrtl((long double)times[i]*times[i] - (4.0 * (long double)distances[i]))) / 2.0);
        result = ceill(MAX( MIN( min, min2),(times[i] - MIN( min, min2)))) - floorl(MIN( MIN( min, min2),(times[i] - MIN( min, min2)))) - 1;
        result2 *= result;
    }
    printf("Part 1: %.0Lf\n", times[0]);

    sprintf(buffer,"%.0Lf%.0Lf%.0Lf%.0Lf",times[0], times[1], times[2],times[3]);
    times[0] = strtold(buffer,NULL);
    sprintf(buffer,"%.0Lf%.0Lf%.0Lf%.0Lf",distances[0], distances[1], distances[2],distances[3]);
    distances[0] = strtold(buffer,NULL);

    min  = ( (times[0] + sqrtl((long double)times[0]*times[0] - (4.0 * distances[0]))) / 2.0);
    min2  = ((times[0] - sqrtl((long double)times[0]*times[0] - (4.0 * (long double)distances[0]))) / 2.0);
    result = ceill(MAX( MIN( min, min2),(times[0] - MIN( min, min2)))) - floorl(MIN( MIN( min, min2),(times[0] - MIN( min, min2)))) - 1;
    printf("Part 2: %.0Lf\n",result);

}