#ifndef H_MMU
#define H_MMU

#include <stdio.h>

#define MMU_IRQ 13
#define TLB_ENTRIES 32
#define MEM_SIZE 1024*1000
#define PAGE_SIZE 4096 /* une page fait 4ko */
#define NB_PAGE ((MEM_SIZE / PAGE_SIZE)-1)/2 /* Nombre de page / process */

struct tlb_entry_s
{
	char rfu;
	int v_page;
	char p_page;
	char access_x;
	char access_w;
       	char access_r;
	char used;
};

/**
 * Handler pour MMU_IRQ
 */
extern void hand_mmu();

#endif
