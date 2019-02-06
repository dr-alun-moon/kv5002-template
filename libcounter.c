/* Counter */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

struct count_t {
	int incr;
	int delay; /* in ms */
	int rand;  /* flag to select random delay in range */
};

static int count;

void *counter(void *param)
{
	int delay;
	struct count_t *spec = (struct count_t *)param;

	while(1){
		count += spec->incr;
		printf("count is %8d\n", count);
	
		delay = spec->delay;
		if(spec->rand) delay = rand()%delay;
		usleep(delay);
	}
}

