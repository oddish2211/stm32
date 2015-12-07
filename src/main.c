#include <stdint.h>

#include "toggle.h"

int main(void) {
	uint32_t i = 0;

	while(1) {
		toggle();
		i++;
	}
}

void SystemInit(void) {
	return;
}

void _exit(int i) {
	while(1);
}
