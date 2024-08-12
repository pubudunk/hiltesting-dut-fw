/*
 * task_handlers.c
 *
 *  Created on: Aug 8, 2024
 *      Author: pubudk
 */

#include "main.h"
#include "task_handlers.h"

extern CAN_HandleTypeDef hcan1;

void CAN1_TX(void)
{
	CAN_TxHeaderTypeDef sTxHdr = {0};
	uint32_t ulTxMailBox = 0;
	HAL_StatusTypeDef status = HAL_ERROR;

	const uint8_t ucMsg[] = {0x01, 0x12};	// assume sensor data byte 0 - sensor type, byte 1 - sensor value

	sTxHdr.IDE = CAN_ID_STD;	/* Standard CAN frame */
	sTxHdr.DLC = 2;				/* 2 byte to tx */
	sTxHdr.StdId = 0x65;
	sTxHdr.RTR = CAN_RTR_DATA;	/* data frame */

	status = HAL_CAN_AddTxMessage( &hcan1, &sTxHdr, ucMsg, &ulTxMailBox );
	configASSERT(HAL_OK == status);
}


void vCANComm_Handler( void *pvParam )
{
	while(1) {
		CAN1_TX();
		vTaskDelay(pdMS_TO_TICKS(2000));	/* Sends a data frame every 3 seconds */
	}
}

void vI2CComm_Handler( void *pvParam )
{

	while(1) {
		Add_To_Log("%s\n", (char *)pvParam);
	}
}
