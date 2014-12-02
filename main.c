#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "hardware.h"

#define MEM_SIZE 1024*1000
#define PAGE_SIZE 4096 /* une page fait 4ko */
#define NB_PAGE ((MEM_SIZE / PAGE_SIZE)-1)/2 /* Nombre de page / process */

static int ppage_of_vaddr(int process, unsigned int vaddr)
{
	int page = vaddr / PAGE_SIZE;
	if(page > NB_PAGE)
		return -1;
	return page + process * NB_PAGE + 1; /* +1 car la 1ère page est réservée */ 
}

int main(void)
{
	init_hardware("hardware.ini");

	/* ========== Test fonction ppage_of_vaddr ======== */	
	assert(ppage_of_vaddr(0, 0) == 1);
	assert(ppage_of_vaddr(1, 0) == 125);
	assert(ppage_of_vaddr(0, 5000) == 2);
/*	assert(ppage_of_vaddr(1, 0) == 125); */
	
	exit(EXIT_SUCCESS);
}
