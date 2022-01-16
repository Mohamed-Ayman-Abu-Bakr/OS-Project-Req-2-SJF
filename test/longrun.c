#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <sys/resource.h>


#define LOOP_COUNT_MIN 100
#define LOOP_COUNT_MAX 100000000

long long subtime(struct timeval start, struct timeval end) {
    return 1e6 * (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);
}

int main (int argc, char *argv[])
{
  char *idStr;
  unsigned int	v;
  int	i = 0;
  int	iteration = 1;
  int	loopCount;
  int	maxloops;
  int which = PRIO_PROCESS;
  id_t pid;
    //clock_t start,end;
    struct timeval start, end, wait, curr;
    double waiting_time= 0;
    double time_taken;
    int no;

    FILE *fp;
  //start = clock();
    int expected_time = atoi(argv[4]);
    setsjf(expected_time);
  gettimeofday(&start, NULL);

    no = atoi(argv[1]);
    pid = getpid();
    int ret = 0;
  if (argc < 4 || argc > 5) {
    printf ("Usage: %s <id> <loop count> [max loops]\n", argv[0]);
    exit (-1);
  }
  /* Start with PID so result is unpredictable */
  v = getpid ();
  /* ID string is first argument */
  idStr = argv[1];
  /* loop count is second argument */
  loopCount = atoi (argv[2]);
  if ((loopCount < LOOP_COUNT_MIN) || (loopCount > LOOP_COUNT_MAX)) {
    printf ("%s: loop count must be between %d and %d (passed %d)\n",
argv[0], LOOP_COUNT_MIN, LOOP_COUNT_MAX, argv[2]);
    exit (-1);
  }
  /* max loops is third argument (if present) */
  if (argc == 5) {
    maxloops = atoi (argv[3]);
  } else {
    maxloops = 0;
  }
  
  /* Loop forever - use CTRL-C to exit the program */
  while (1) {
    /* This calculation is done to keep the value of v unpredictable. Since
the compiler can't calculate it in advance (even from the original
value of v and the loop count), it has to do the loop. */
    v = (v << 4) - v;
    if (++i == loopCount) {
      /* Exit if we've reached the maximum number of loops. If maxloops is
0 (or negative), this'll never happen... */
      if (iteration == maxloops) {
break;
      }
      //printf ("%s:%06d\n", idStr, iteration);
      gettimeofday(&wait, NULL);
      fflush(stdout);
      gettimeofday(&curr, NULL);
      waiting_time = waiting_time + subtime(wait, curr);
      iteration += 1;
      i = 0;
    }
  }
  /* Print a value for v that's unpredictable so the compiler can't
optimize the loop away. Note that this works because the compiler
can't tell in advance that it's not an infinite loop. */
  printf ("The final value of v is 0x%08x\n", v);
  //end = clock();
  gettimeofday(&end, NULL);
  //time_taken = (double)((end-start)/CLOCKS_PER_SEC);
  fp = fopen("test.txt","a");
   printf("Process with expected time: %d finished\n",expected_time);

  fclose(fp);
  return 0;
}

