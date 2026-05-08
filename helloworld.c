#include "xparameters.h"
#include "xiic_l.h"
#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include <stdlib.h>

#define IIC_BASE_ADDRESS    XPAR_AXI_IIC_0_BASEADDR
#define SI570_I2C_ADDR      0x5D 
#define mux_addy 			0x74


int main(void)

{
	  init_platform();
    u8 tx[8];
	  u8 rx[6]={0};
	  u8 reg_addr = 7;
    u8 open_chn = 0b00000001;

	//unsigned sentt;
	//unsigned readd;

  //open channel 0 on mux
    XIic_Send(IIC_BASE_ADDRESS, mux_addy, &open_chn, 1, XIIC_STOP);

  //Un-comment to use for debugging
  /*  
    XIic_Send(IIC_BASE_ADDRESS, SI570_I2C_ADDR, &reg_addr, 1, XIIC_REPEATED_START);
	  readd = XIic_Recv(IIC_BASE_ADDRESS, SI570_I2C_ADDR, rx, 6, XIIC_STOP);
  	xil_printf("Code read %d registers, expected value is 6\n\r",readd);
	  xil_printf("Recieved register values are - %x, %x, %x, %x, %x, %x \n\r",rx[0],rx[1],rx[2],rx[3],rx[4],rx[5]); //expect 0,0,0,0,0,0 since no data is loaded yet  
  */

  //Freeze DCO
    tx[0] = 137;
    tx[1] = 0x10;
    XIic_Send(IIC_BASE_ADDRESS, SI570_I2C_ADDR, tx, 2, XIIC_STOP); //2 bytes since address and data

	  tx[0] = 7; //Leave this as it is, it points to which register the data should start filling from 
  //the following registers are for 800MHz, change these values according to whatever the SkyWorks application tells you to.
    tx[1] = 0x60;   // reg 7
    tx[2] = 0x31;   // reg 8
    tx[3] = 0x51;   // reg 9
    tx[4] = 0xA5;   // reg 10
    tx[5] = 0x4E;   // reg 11
    tx[6] = 0xB0;   // reg 12

  //send all data, it auto-increments so it autofills register 7,8,9,10,11 and 12
    XIic_Send(IIC_BASE_ADDRESS, SI570_I2C_ADDR, tx, 7, XIIC_STOP);
  
  //Un-comment to use for debugging
  /*
    XIic_Send(IIC_BASE_ADDRESS, SI570_I2C_ADDR, &reg_addr, 1, XIIC_REPEATED_START);
	  readd = XIic_Recv(IIC_BASE_ADDRESS, SI570_I2C_ADDR, rx, 6, XIIC_STOP);
  	xil_printf("Code read %d registers, expected value is 6\n\r",readd);
	  xil_printf("Recieved register values are - %x, %x, %x, %x, %x, %x \n\r",rx[0],rx[1],rx[2],rx[3],rx[4],rx[5]); //expect values that you loaded in the tx[] array here, if data is different, its a problem
  */
  
    //release unfreeze dco same way
    tx[0] = 137;
    tx[1] = 0x00;
    XIic_Send(IIC_BASE_ADDRESS, SI570_I2C_ADDR, tx, 2, XIIC_STOP);

    // write reg 135
    tx[0] = 135;
    tx[1] = 0x40;
    XIic_Send(IIC_BASE_ADDRESS, SI570_I2C_ADDR, tx, 2, XIIC_STOP);


	  //Close mux again
	  open_chn = 0x00;
	  XIic_Send(IIC_BASE_ADDRESS, mux_addy, &open_chn, 1, XIIC_STOP);

    cleanup_platform();
    return 0;
}

