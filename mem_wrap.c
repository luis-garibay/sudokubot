/*mem_wrap.c*/

//
// wrapper funtions for malloc and free
//

#include <stdio.h>
#include <stdlib.h>

#include "mem_wrap.h"

static int g_mallocs = 0;
static int g_mallocFailures = 0;
static int g_frees = 0;
static int g_freeErrors = 0;

void *wMalloc(unsigned int size) {
	g_mallocs++;

	void *ptr = malloc(size);

	if (ptr == NULL)
		g_mallocFailures++;

	return ptr;
}

void wFree(void *ptr) {
	g_frees++;

	if (ptr == NULL)
		g_freeErrors++;

	free(ptr);
}

void wMemStats() {
	printf("** Memory stats: malloc (%d, %d), free (%d, %d)\n",
			g_mallocs, g_mallocFailures, g_frees, g_freeErrors);
}
