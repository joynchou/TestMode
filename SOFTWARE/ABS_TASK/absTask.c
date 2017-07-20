#include "../TASK/TASK.h"
#include <rtx51tny.h>                 /* RTX-51 tiny functions & defines      */
#include <stdio.h>
#include <stdlib.h>
#include "../TASK/setup.h"
#include "../../HARDWARE/DEVICES/BUTTON/BUTTON.H"
#include "../../HARDWARE/DEVICES/LED/LED.H"
#include "../../HARDWARE/BSP/USART1.H"
#include "../HARDWARE/DEVICES/SENSOR/ANGLE/ANGLE.h"
#include "../COMMON_SOFTWARE/DATA_SCOPE/DataScope_DP.h"
#include "../COMMON_SOFTWARE/STORAGE/STORAGE.h"

void taskStart() _task_ 0
{ 
	setup();
	blink(4);
		os_create_task (1);
	//	os_create_task (2);
	os_create_task(3);
	os_create_task(5);
	//	os_create_task (6);
	os_create_task(7);
	os_create_task(8);
	os_create_task(9);
	os_delete_task(0);
}
void task1(void) _task_ 1
{
  u8 i=0;
	for (;;)
	{

		os_wait(K_IVL, 40, 0);

	}
}
void task2(void) _task_ 2
{
	static unsigned int count = 0;
	unsigned int test[20];




}
void task3(void) _task_ 3
{
	unsigned int string[50];
	static unsigned int count = 0;
	u8 i=10;
	for (;;)
	{   i++;

     os_wait(K_IVL, 200, 0);

	}

}
void task5(void) _task_ 5
{
	unsigned long count = 0;
	for (;;)
	{

		buttonScan();
		os_wait(K_IVL, 2, 0);
	}
}

void task7(void) _task_ 7
{
	for (;;)
	{
		if (getButtonState(BUTTON1_GPIO_PIN))
		{
			open_Board_LED();
		}
	
		os_wait(K_IVL, 10, 0);
	}
}
void task8(void) _task_ 8
{
	for (;;)
	{
		if (getAngle(1) > 50)
		{
			open_Board_LED();
		}
		else
		{
			close_Board_LED();
		}
		os_wait(K_IVL, 1, 0);
	}
}
void task9(void) _task_ 9
{
	for (;;)
	{
		sendScopeData(getAngle(1), 1);
		os_wait(K_IVL, 40, 0);

	}

}

