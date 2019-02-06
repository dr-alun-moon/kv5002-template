/* Counter header file */

struct count_t {
	int incr;
	int delay; /* in ms */
	int rand;  /* flag to select random delay in range */
};


void *counter(void *param);

