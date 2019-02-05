/* Example POSIX thread program
 * Dr Alun Moon
 * Feb 2018
 */

#include <pthread.h>
#include <signal.h>

pthread_t a,b;

void *incrementer(void *param)
{
	int delta = *(int*)param;

}

void endprog(int sig)
{
	pthread_kill(a, SIGTERM);
	pthread_kill(b, SIGTERM);
}


struct foreach {
	int init;
	int incr;
};

int main ( int argc , char *argv[] )
{
	/*
	int up   =  1 ;
	int down = -1 ;
	*/
	struct foreach up = {.init=5, .incr=1};
	struct foreach down = {.init=5, .incr=1};

	signal(SIGTERM, endprog); /* signal handler for TERMinate - quit signals */
	signal(SIGINT, endprog);  /* signal handler for INTerupt Ctrl-C */

	pthread_create( &a, NULL, incrementer, &up );
	pthread_create( &b, NULL, incrementer, &down );

	pthread_join(a, NULL);
}

