#include "uart.h"
#include "i2c-ths.h"
#include "cconsole/console.h"

extern "C" void initialize_filesystem(void);

extern "C" void app_main()
{
	initialize_filesystem();

	/* Setup thread-safe i2c */
	i2c_master_setup(I2C_NUM_0, GPIO_NUM_21, GPIO_NUM_22, 400000);

	console.HandleCmd(uart, "auth 123");
	// console.HandleCmd(uart, "wifi init_sta");
	// console.HandleCmd(uart, "wifi connect Faramoz 12169931");
	// console.HandleCmd(uart, "tcp 0");

	while(1)
		console.WaitForCmd(uart);

	/* Release thread-safe i2c and semaphore */
	i2c_release(I2C_NUM_0);
}
