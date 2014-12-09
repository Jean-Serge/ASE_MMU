#include <stdlib.h>
#include <assert.h>

#include "mmu.h"
#include "hardware.h"

static int *tlb;
static int current_process = 0;


/**
 * Fonction appelée lors d'un accès illégal à la mémoire. 
 */
void hand_mmu()
{
	int page;
	printf("MMU_IRQ déclenché\n");

	printf("On sort du handler.\n");
}

/**
 * Permet de récupérer la page correspondante à l'adresse virtuelle 
 * d'un processus.
 */
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
	tlb = (int *) malloc (TLB_ENTRIES * sizeof(int));
	IRQVECTOR[MMU_IRQ] = hand_mmu;

	/* ========== Test fonction ppage_of_vaddr ======== */	
	assert(ppage_of_vaddr(0, 0) == 1);
	assert(ppage_of_vaddr(1, 0) == 125);
	assert(ppage_of_vaddr(0, 5000) == 2);
	
	free(tlb);
	exit(EXIT_SUCCESS);
}
