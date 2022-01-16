#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int main()
  {
        int pid;
        /*printf("1");
        pid = fork();
        if (pid == 0) {
            execl("long","long","1","100","100","10",NULL); //expected time set to 10        }
        printf("2");
        pid = fork();
        if (pid == 0) {
            execl("long","long","2","100","100","15",NULL); //expected time set to 15
        }
        printf("3");
        pid = fork();
        if (pid == 0) {
            execl("long","long","3","100","100","5",NULL); //expected time set to 5
        }
	printf("4");
        pid = fork();
        if (pid == 0) {
            execl("long","long","4","100","1000","7",NULL); //expected time set to 7
        }
	printf("5");
        pid = fork();
        if (pid == 0) {
            execl("long","long","4","100","1000","3",NULL); //expected time set to 3
        }
	printf("5");
        pid = fork();
        if (pid == 0) {
            execl("long","long","4","100","1000","20",NULL); //expected time set to 20
        }*/

	for(int i=1;i<=10;i++){
		//printf("%d",i);

		 pid = fork();
       		 if (pid == 0) {
           	 	execl("long","long",itoa(i),"100","1000",itoa(i*500%17+1),NULL); //expected times 8 15 5 12 2 9 16 6 13 3
        	}
	}



  }
