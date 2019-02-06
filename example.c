/* Example POSIX thread program
 * Dr Alun Moon
 * Feb 2018
 */

#include <pthread.h>
#include <signal.h>

#include <stdlib.h>
#include <stdio.h>

#include "libcounter.h"

pthread_t a,b;

void endprog(int sig)
{
	pthread_kill(a, SIGTERM);
	pthread_kill(b, SIGTERM);
	exit(EXIT_SUCCESS);
}


int main ( int argc , char *argv[] )
{
	/* latest C versions allow neat struct initialisers */
	struct count_t up = {.incr=1, .delay=1000 };
	struct count_t down = {.incr=-1, .delay=1000};

	signal(SIGTERM, endprog); /* signal handler for TERMinate - quit signals */
	signal(SIGINT, endprog);  /* signal handler for INTerupt Ctrl-C */

	puts("creating threads");

	pthread_create( &a, NULL, counter, &up );
	pthread_create( &b, NULL, counter, &down );

	pthread_join(a, NULL);
}

