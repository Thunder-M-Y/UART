#include <stdio.h>
#include "uart.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include <string.h>

#define BUF_SIZE (32)
/**
 * @brief 发送任务入口地址
 */
extern const char *TAG;

void task_sender_entry(void *params)
{
    static const char *msg = "hello uart1";
    while (1)
    {
        u_send(msg, strlen(msg));
        ESP_LOGI(TAG,"发送输出成功");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
void task_reader_entry(void *params)
{
    char buffer[BUF_SIZE];
    while (1)
    {   
        memset(buffer,0,BUF_SIZE);//清空缓冲区
        size_t len = u_recv(buffer, BUF_SIZE);
        buffer[len]=0;        //封装完整字符串
        ESP_LOGI(TAG,"收到数据 %s",buffer);
    }
}

void app_main(void)
{
    u_uart_init();
    xTaskCreate(task_sender_entry,"sender",1024*10,NULL,1,NULL);
    xTaskCreate(task_reader_entry,"reader",1024*10,NULL,1,NULL);
    vTaskDelete(NULL);
}
