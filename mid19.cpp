//Modified By: Juan Trigueros
//Date: April 11, 2019
//
//
//Author: Gordon Griesel
//Date: April 7, 2019
//Purpose: Framework for a coding exam
//
//See instructions on assignment web page to produce a unit-test
//for the vec_length function.
//
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//type defines
typedef double Flt;
typedef Flt Vec[3];

//prototype
Flt vec_length(Vec v);


//Array of vector values
const Flt arr[] = {

#ifndef UNIT_TEST
    1.0,   0.0,
    1.0,   1.0,
    -1.2,   2.5,
    99.9,  99.9,
    2.2,  -1.2,
#endif

#ifdef UNIT_TEST
    -3.77983  ,  -8.11711   ,
    -6.19391  ,  -7.48675   ,
    0.46671   ,  7.98604    ,
    -3.78165  ,  9.45696    ,
    -1.08659  ,  -4.13340   ,
    -1.09663  ,  -4.13138  ,
    -0.42783  ,  -3.57757 ,
    9.33954   ,  -1.55691  , 
    0.07000   ,  3.31899   ,
    4.83957   ,  -5.88670  ,
    2.63395   ,  -8.08769  ,
    -2.86933  ,  7.61333   ,
    -6.52007  ,  -4.95898  ,
    -0.09036  ,  -3.03667  ,
#endif

    0.000, 0.000
};

#ifdef UNIT_TEST
const Flt arr_act[] {
    8.945631 , 9.715759 , 8.014661, 10.200031,
        4.269271 , 4.273677, 3.609497, 9.477810 ,
        3.319133, 7.610853, 8.508348, 8.140864, 
        8.192558, 3.046420, 0.00, 0.00
};

bool goodval = true;
#endif

#ifndef UNIT_TEST
int main()
#endif
#ifdef UNIT_TEST
int main(int argc, char *argv[])
#endif
{
#ifdef UNIT_TEST
    double toler = .01;
    if (argc > 1) {
        toler = atof(argv[1]);
    }
#endif

    //Program to calculate vector normalization and length.
    //
    printf("                                    \n");
    printf("3350 software engineering           \n");
    printf("                                    \n");
    printf("Calculation of vector lengths:      \n");
    printf("                                    \n");
#ifndef UNIT_TEST
        printf("     x         y         length     \n");
        printf("     --------  --------  ---------- \n");
#endif
#ifdef UNIT_TEST
        printf("     x         y         length      Actual\n");
        printf("     --------  --------  ----------  ---------\n");
#endif

    //read until sentinel found.
    int i=0;
    Vec v = { arr[i*2+0], arr[i*2+1] };
    do {
        Flt ret = vec_length(v);
#ifdef UNIT_TEST
        if ((ret < arr_act[i]-toler) || (ret > arr_act[i]+toler))
            goodval = false;
        else 
            goodval = true;
#endif
#ifndef UNIT_TEST
            printf("%3i  %8.5lf  %8.5lf  %10.5lf\n", i+1, v[0], v[1], ret);
#endif
#ifdef UNIT_TEST
        if (goodval == true)
            printf("%3i  %8.5lf  %8.5lf  %10.5lf %10.5lf\n", i+1, v[0], v[1], ret, arr_act[i]);
        else if (goodval == false)
            printf("%3i  %8.5lf  %8.5lf  %10.5lf %10.5lf <-- error\n", i+1, v[0], v[1], ret, arr_act[i]);
#endif
        ++i;
        v[0] = arr[i*2+0];
        v[1] = arr[i*2+1];
    } while (!(v[0]==0.0 && v[1]==0.0));
    //
    printf("\nProgram complete.\n\n");
    return 0;
}

Flt vec_length(Vec v)
{
    //Normalize a vector.
    //Return the original length of the vector.
    //
    //input: the 2 components of a vector
    //output: the pre-normalized vector length is returned
    //        the vector argument is scaled to a length of 1.0
    //
    //A degenerate vector causes an error condition.
    //It will return a length of 0.0
    //and an arbitrary vector with length 1.0.
    //
    //calculate the vector dot product with itself...
    Flt dot = v[0]*v[0] + v[1]*v[1];
    //check for degenerate vector...
    if (dot == 0.0) {
        //set an arbitrary vector of length 1.0
        //printf("ERROR vector magnitude is zero.\n");
        v[0] = 1.0;
        v[1] = 0.0;
        return 0.0;
    }
    //vector has a magnitude so continue.
    Flt len = sqrt(dot);
    Flt oolen = 1.0 / len;
    v[0] *= oolen;
    v[1] *= oolen;
    return len;
}

