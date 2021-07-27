/*****************************************************************************
* Task		 : UART Driver
* File Name	 : UART_registers.h
* Description: header file for UART memory mapped registers
* Author	 : Kariman
* Date		 : Jul 13, 2021
******************************************************************************/

#ifndef MCAL_UART_UART_REGISTERS_H_
#define MCAL_UART_UART_REGISTERS_H_


/*- DEFINES-----------------------------------------------*/

/*- UART Registers----------------------------------------*/

/*- USART I/O Data Register----------------------------------------*/
#define UDR_R  		(*(volatile unsigned char*)0x2C)

/*- USART Control and Status Register A----------------------------------------*/
#define UCSRA_R		(*(volatile unsigned char*)0x2B)
#define MPCM_B		0
#define U2X_B		1
#define PE_B		2
#define DOR_B		3
#define FE_B		4
#define UDRE_B		5
#define TXC_B		6
#define RXC_B		7

/*- USART Control and Status Register B----------------------------------------*/
#define UCSRB_R 	(*(volatile unsigned char*)0x2A)
#define TXB8_B		0
#define RXB8_B		1
#define UCSZ2_B		2
#define TXEN_B		3
#define RXEN_B		4
#define UDRIE_B		5
#define TXCIE_B		6
#define RXCIE_B		7

/*- USART Control and Status Register C----------------------------------------*/
#define UCSRC_R 	(*(volatile unsigned char*)0x40)
#define UBRRH_R    	(*(volatile unsigned char*) 0x40)
#define UCPOL_B     0
#define UCSZ0_B     1
#define UCSZ1_B     2
#define USBS_B      3
#define UPM0_B      4
#define UPM1_B      5
#define UMSEL_B     6
#define URSEL_B     7

/*- USART I/O Data Register----------------------------------------*/
#define UBRRL_R 	(*(volatile unsigned char*)0x29)

#endif /* MCAL_UART_UART_REGISTERS_H_ */
