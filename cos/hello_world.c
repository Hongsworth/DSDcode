#include <stdlib.h>
#include <sys/alt_stdio.h>
#include <sys/alt_alarm.h>
#include <sys/times.h>
#include <alt_types.h>
#include <system.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>

// Test case 1
//#define step 5
//#define N 52

// Test case 2
//#define step 1/8.0
//#define N 2041

//Test case 3
#define step 1/1024.0
#define N 261121


// Generates the vector x and stores it in the memory
void generateVector(float x[N], float l1[N], float l2[N])
{
	int i;
	x[0] = 0;
	l1[0] = 0;
	l2[0] = 0;
	for (i=1; i<N; i++){
		x[i] = x[i-1] + step;
		l1[i] = cos(x[i]/128.0);
		l2[i] = sin(x[i]/128.0);
	}
}

float sumVector(float x[], float l1[], float l2[], int M)
{
	// YOUR CODE GOES HERE
	float sum = 0.0;
	for(int i=0; i < M; i++) {
		sum += 0.5 * x[i] + x[i]*x[i]*(0.540302*l1[i] + 0.841471*(l2[i]));
	}
	return sum;
}

//float sumVector(float x[], float l1[], float l2[], int M)
//{
//	// YOUR CODE GOES HERE
//	float sum = 0.0;
//	for(int i=0; i < M; i++) {
//		sum += 0.5 * x[i] + x[i]*x[i]*cos((x[i]-128.0)/128.0);
//	}
//	return sum;
//}

//void storelookuptable(float lookuptable1[],float lookuptable2[], float x[], int M){
//	lookuptable1[0] = 0;
//	lookuptable2[0] = 0;
//	for (int i = 1; i< M; i++){
//		lookuptable1[i] = cos(x[i]/128.0);
//		lookuptable2[i] = sin(x[i]/128.0);
//	}
//}

int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main()
{

  alt_putstr("Task 2!\n");

  // Define input vector
  float x[N], l1[N], l2[N];

  // Returned result
  float y;

  generateVector(x, l1, l2);
  printf("x[50] %f \n", x[2]);
  printf("generate complete");

//  storelookuptable(x,l1,l2,N);
//  printf("store complete");

  // The following is used for timing
  char buf[50];
  clock_t exec_t1, exec_t2;

  exec_t1 = times(NULL); // get system time before starting the process

  // The code that you want to time goes here
  y = sumVector(x,l1,l2, N);

  // till here
  exec_t2 = times(NULL); // get system time after finishing the process

  printf(" proc time = %d ticks \n", (unsigned int) (exec_t2-exec_t1));
  printf("Result = %d \n", (int) y);
  int i;
  for (i=0; i<10; i++)
  	y = y/2.0;

  printf(" Result (divided by 1024) = %d \n", (int) y);

  return 0;
}
