//
//  random_number_gen.c
//  Particle Filter
//
//  Created by Steven S. L. Xie on 9/10/14.
//  Copyright (c) 2014 XIE Shuanglong. All rights reserved.
//

#include <math.h>
#include <stdlib.h>
#include <time.h>


void init(){
    static int flag;
    if(0 == flag){
        srand((unsigned)time(NULL));
        flag = 1;
    }
    return;
}

// generate a random number following normal distribution

double randn (double mu, double sigma)
{
    double U1, U2, W, mult;
    static double X1, X2;
    static int call = 0;
    
    //static int seed = 0;
    //srand((unsigned)time(NULL));
    init();
    
    if (call == 1)
    {
        call = !call;
        return (mu + sigma * (double) X2);
    }
    
    do
    {
        U1 = -1 + ((double) rand () / RAND_MAX) * 2;
        U2 = -1 + ((double) rand () / RAND_MAX) * 2;
        W = pow (U1, 2) + pow (U2, 2);
    }
    while (W >= 1 || W == 0);
    
    mult = sqrt ((-2 * log (W)) / W);
    X1 = U1 * mult;
    X2 = U2 * mult;
    
    call = !call;
    
    return (mu + sigma * (double) X1);
}

// generate a random number following uniform distribution from [a,b]
double randu(double a, double b)
{
    init();
    //srand((unsigned)time(NULL));
    //static int seed = 0;
    //srand(seed++);
    
    double u = (double) rand() / RAND_MAX;
    return a + (b - a) * u;
}

