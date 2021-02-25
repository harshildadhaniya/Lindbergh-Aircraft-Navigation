/* AIRCRAFT NAVIGATION */

#include <stdio.h>
#include <math.h>

void fly(double latA, double longA, double latB, double longB){
    
    if (latA < -90 | latB < -90 | latA > 90 | latB > 90){
        printf("Invalid Latitude!!");
        return;
    }
    else if(longA <= -180 | longB <= -180 | longA > 180 | longB > 180){
        printf("Invalid Longitude!!");
        return;
    }
    else if(latA == latB && longA == longB){
        printf("You are already at your destination. :)\n");
        return;
    }
    else{
        int radius = 3440; //Radius of Earth in nautical miles
        float deg2rad = M_PI/180;
        double temp1 = sin(((latB - latA)/2) * deg2rad);
        double temp2 = sin(((longB - longA)/2) * deg2rad);

        double a = pow(temp1, 2) + (cos(latA * deg2rad) * cos(latB * deg2rad) * pow(temp2, 2));

        double d = 2*radius*atan2(sqrt(a), sqrt(1 - a));
    
        double temp3 = sin((longB - longA) * deg2rad) * cos(latB * deg2rad);
        double temp4 = cos(latA * deg2rad) * sin(latB * deg2rad) - (sin(latA * deg2rad) * cos(latB * deg2rad) * cos((longA - longB) * deg2rad));
    
        double theta = atan2(temp3, temp4) * (1/deg2rad);

        if (theta > 360){
            theta = theta - 360;
        }
        else if(theta < 0){
            theta = theta + 360;
        }

        printf("Fly heading %lf degrees for %lf nautical miles.\n", theta, d);
        return;
    }
}

int main(){

    double A, B, C, D;

    printf("Enter the latitude of origin: ");
    scanf("%lf", &A);
    printf("Enter the longitude of origin: ");
    scanf("%lf", &B);
    printf("Enter the latitude of destination: ");
    scanf("%lf", &C);
    printf("Enter the longitude of destination: ");
    scanf("%lf", &D);

    fly(A, B, C, D);

    return 0;
}