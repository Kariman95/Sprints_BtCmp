/***************************************************************
* Task		 : Traffic Light system
* File Name	 : main.c
* Description: main
* Author	 : Kariman
* Date		 : 13/7/2021
***************************************************************/


/*- INCLUDES--------------------------------------------------*/
#include "Traffic_Light_System/TrafficLight.h"


/*- MAIN FUNCTION---------------------------------------------*/
int main(void)
{
	TrafficLight_Init();

	while(1)
	{
		TrafficLight_Update();
	}//end while
	return 0;
}//end main
