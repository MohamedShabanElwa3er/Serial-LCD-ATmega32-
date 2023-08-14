
#include "Projects_Interface.h"


int main()
{

	M_SPI_VoidMasterInit();
	H_Lcd_Void_LCDInit();       // LCD INTIALIZING
	_delay_ms(10);
	H_Lcd_Void_LCDGoTo(1, 5);
	H_Lcd_Void_LCDWriteString("VALEO");

	while(1){
	}


	return 0;
}



