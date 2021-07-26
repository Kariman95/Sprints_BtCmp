/***************************************************************
* Task		 : EEPROM
* File Name	 : main.c
* Description: main
* Author	 : Kariman Karam
* Date		 : 26/7/2021
***************************************************************/


/*- INCLUDES--------------------------------------------------*/

#include "EEPROM_task/EEPROM_task.h"


/*- MAIN FUNCTION---------------------------------------------*/
int main(void)
{
	App_Init();
	while(1)
	{
		App_Update();
	}
	return 0;
}//end main
