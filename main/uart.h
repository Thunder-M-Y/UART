#pragma once //防止头文件重复添加
#include "driver/uart.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "esp_err.h"



//串口初始化
esp_err_t u_uart_init(void);
//发送数据
void u_send(const void *data,size_t length);
//接收数据
size_t u_recv( void *data,size_t length);



//测试同步--------------------------------------------------------------------------测试同步