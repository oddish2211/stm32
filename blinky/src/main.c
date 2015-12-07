#include <stdint.h>

#include "stm32f7xx.h"

#include "stm32f7xx_hal_rcc.h"
#include "stm32f7xx_hal_gpio.h"

int main(void) {
	uint32_t i = 0;

	while(1) {
		i++;
	}
}

void _exit(int i) {
	while(1);
}
