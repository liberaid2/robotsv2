#include "i2c2.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"

static SemaphoreHandle_t sem[I2C_NUM_MAX];

void i2c_master_setup(i2c_port_t num, gpio_num_t sda, gpio_num_t scl, uint32_t freq){
	i2c_config_t conf;
	conf.mode = I2C_MODE_MASTER;
	conf.sda_io_num = sda;
	conf.sda_pullup_en = GPIO_PULLUP_ENABLE;
	conf.scl_io_num = scl;
	conf.scl_pullup_en = GPIO_PULLUP_ENABLE;
	conf.master.clk_speed = freq;
	i2c_param_config(num, &conf);
	i2c_driver_install(num, conf.mode, 0, 0, 0);

	sem[num] = xSemaphoreCreateMutex();
}

void i2c_release(i2c_port_t num){
	vSemaphoreDelete(sem[num]);
	i2c_driver_delete(num);
}

esp_err_t i2c_master_cmd_begin_safe(i2c_port_t i2c_num, i2c_cmd_handle_t cmd_handle, TickType_t ticks_to_wait){
	xSemaphoreTake(sem[i2c_num], pdMS_TO_TICKS(100));
	esp_err_t result = i2c_master_cmd_begin(i2c_num, cmd_handle, ticks_to_wait);
	xSemaphoreGive(sem[i2c_num]);

	return result;
}
