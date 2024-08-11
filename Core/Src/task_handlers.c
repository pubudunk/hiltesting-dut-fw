/*
 * task_handlers.c
 *
 *  Created on: Aug 8, 2024
 *      Author: pubudk
 */

#include "main.h"
#include "task_handlers.h"



void vTask1_Handler(void *pvParam)
{
	while(1) {
		Add_To_Log("%s\n", (char *)pvParam);

		//HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}

void vTask2_Handler(void *pvParam)
{

	while(1) {
		Add_To_Log("%s\n", (char *)pvParam);
	}
}
