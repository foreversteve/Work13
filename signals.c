#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <fcntl.h>

static void sighandler(int signo){
	if (signo == SIGINT){
		int filedesc = open("out.txt", O_WRONLY | O_TRUNC | O_CREAT, 0644);

		char temp[] = "Program exited due to SIGINT";
		write(filedesc,temp,28);
		close(filedesc);

		exit(0);
	}
	if (signo == SIGUSR1){
		printf("Parent PID is: %d\n",getppid());
	}
}

int main(){

	signal(SIGINT,sighandler);
	signal(SIGUSR1,sighandler);

	while (1){
		printf("%d\n",getpid());
		sleep(1);
	}

	return 0;

}