/* do not add other includes */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>

double getTime(){
  struct timeval t;
  double sec, msec;
  
  while (gettimeofday(&t, NULL) != 0);
  sec = t.tv_sec;
  msec = t.tv_usec;
  
  sec = sec + msec/1000000.0;
  
  return sec;
}


int main (int argc, char *argv[])
{
  double t1, t2, sum;
  
  
  
  unsigned int N = 1000; 
  unsigned int i;
  unsigned int j;
  int k;

  /* declare variables; examples, adjust for task */
  double **A;
  double **B;
  double **C; //result of multiplication

  
  /* allocate memory for arrays; examples, adjust for task */
  A =malloc (N * sizeof (double));
  for (i =0;i < N; i++){
   A[i]= malloc(N*sizeof(double));
}

  B =malloc (N * sizeof (double));
for (i =0;i < N; i++){
   B[i]= malloc(N*sizeof(double));
}
  C =malloc(N * sizeof(double));
for (i =0;i < N; i++){
   C[i]= malloc(N*sizeof(double));
}


   
	  
  
   /* initialise array elements */
   for(i=0;i<N;i++){
	   for(j=0;j<N;j++){
		   A[i][j]= rand();
		  

		   
	   }
	  
   }
  


   for(i=0;i<N;i++){
	   for(j=0;j<N;j++){
		   B[i][j]= rand();
		  
		   
	   }
	
	   
   }
  
  
 
  t1 = getTime();
  
  /* code to be measured goes here */
  for (i = 0; i < N; i++) {
      for (j = 0; j < N; j++) {
        for (k = 0; k < N; k++) {
          sum += A[i][k] * B[k][j];
        }
 
        C[i][j] = sum;
        sum = 0;
      }
    }
  
  
  
  t2 = getTime();
  
   
  

  
  /* output; examples, adjust for task */
  printf("time: %6.2f secs\n",t2 - t1);

  /* free memory; examples, adjust for task */
  free(B);
  free(A);
  free(C);

  return 0;  
}
