/*
 * example: quadrature
 * Written by Dr Maryam Abo-Tabik
 */

#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include <sys/time.h>  // for wallclock timing functions

#define MAX(x,y) ( x>y ? x : y )

double func (double x);
double work(int numberQuads, double a, double width);

int main(int argc, char** argv) {
  
  const double a=0.1, b=200.0;  /* bounds */
  const int numberQuads = 50000000;
  double integrand, width, x, y, meanHeight;
  int i;              /* loop counter */

  /* for timing */
  struct timeval wallStart, wallEnd;

  /* sequential in-line way */
  width = (b-a) / (float) numberQuads;
  integrand = 0.0;

  gettimeofday(&wallStart, NULL); // save start time in to variable 'wallStart'

  integrand = work(numberQuads, a, width);

  gettimeofday(&wallEnd, NULL); // end time
  printf("SERIAL- integral = %f\n", integrand);
  double wallSecs = (wallEnd.tv_sec - wallStart.tv_sec);           // just integral number of seconds
  double WALLtimeTaken = 1.0E-06 * ((wallSecs*1000000) + (wallEnd.tv_usec - wallStart.tv_usec)); // and now with any microseconds
  printf("Wall clock time measured in program: %f seconds  \n", WALLtimeTaken);
}

double work(int numberQuads, double a, double width){
  double *x, *y;
  double meanHeight, intergrand;

  x = (double*)malloc(numberQuads * sizeof(double));
  y = (double*)malloc(numberQuads * sizeof(double));

  //Calculate area of trapeziums
  for(int i = 0; i<numberQuads; i++){
    x[i] = a + i * width;
    y[i] = x[i] + width;
    meanHeight = 0.5 * (func(x[i]) + func(y[i]));
    intergrand += meanHeight*width;
  }
  return intergrand;
}

