#include <stdio.h>
#include <stdlib.h>

#include "hardware.h"

int main(void)
{
	init_hardware("hardware.ini");
	exit(EXIT_SUCCESS);
}
