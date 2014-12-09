#include <stdlib.h>
#include <assert.h>

#include "mmu.h"
#include "hardware.h"

/**
 * Fonction appelée lors d'un accès illégal à la mémoire. 
 */
void hand_mmu()
{
	printf("Coucou\n");
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
	IRQVECTOR[MMU_IRQ] = hand_mmu;

	/* ========== Test fonction ppage_of_vaddr ======== */	
	assert(ppage_of_vaddr(0, 0) == 1);
	assert(ppage_of_vaddr(1, 0) == 125);
	assert(ppage_of_vaddr(0, 5000) == 2);
	
	_mask(0x1001);
	IRQVECTOR[MMU_IRQ] = hand_mmu;


	exit(EXIT_SUCCESS);
}
