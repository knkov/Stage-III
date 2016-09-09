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

/* for task 1 only */
void usage(void)
{
	fprintf(stderr, "bandwith [--no_iterations iterations] [--array_size size]\n");
	exit(1);
}

int main (int argc, char *argv[])
{
  double t1, t2; 
  
  /* variables for task 1 */
  unsigned int size=1024; //elements in array
  unsigned int N = 100; //iterations
  
  unsigned int i;
   

  /* declare variables; examples, adjust for task */
  int *A; // source array
  int *B; // array to be copied to
 
  
  /* parameter parsing task 1 */
 
  for(i=1; i<(unsigned)argc; i++) {
	
	

	  if (strcmp(argv[i], "--no_iterations") == 0) {
		  i++;
		  if (i < argc){
			  sscanf(argv[i], "%u", &N);
		  }else{
			
			  usage();
	}
	  } else if (strcmp(argv[i], "--array_size") == 0) {
		  i++;
		  if (i < argc){
			  sscanf(argv[i], "%u", &size);
		  }else{
			  usage();
		}
	  } else {
	usage();
	}
  }//end for



  /* size in bytes / sizeof(int) will give number of elements in array
  /* allocate memory for arrays; examples, adjust for task */
   A = malloc (size * sizeof (int));
   B = malloc (size * sizeof (int));
   
	  
  
   /* initialise arrray elements */
   for(i=0;i<size;i++){
	   A[i]= rand();
	   B[i]=rand(); // initialising both arrays to random ints
	
   }
   

  

   t1 = getTime();

  /* code to be measured goes here */
 for(i=0;i<N;i++){

   //repeat copy N times 
    
    memcpy(B, A,sizeof(int)*size);


 
}

  t2 = getTime();


double MB = 1024*1024; // 1MB in bytes 
double totalSize = size*sizeof(int); //byte size of Array
double throughput= totalSize*N/(t2-t1); //given in BYTES
double answ = throughput / MB; //converts throughput to MBytes
printf("Throughput: %6.2f MB/secs\n",answ);




  /* free memory; examples, adjust for task */
  free(B);
  free(A);

  return 0;  
}
