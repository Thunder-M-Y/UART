#include "uart.h"
#define UART_PORT_NUM UART_NUM_1
#define UART_PORT_TX_PIN GPIO_NUM_1
#define UART_PORT_RX_PIN GPIO_NUM_2
#define UART_BUF_SIZE (1024)

const char *TAG = "UART";
/**
 * @brief 串口初始化
 *
 */

esp_err_t u_uart_init(void)
{
    uart_config_t uart_config = {
        .baud_rate = 115200,                   // 波特率
        .data_bits = UART_DATA_8_BITS,         // 数据位长度
        .parity = UART_PARITY_DISABLE,         // 不使用校验位l
        .stop_bits = UART_STOP_BITS_1,         // 停止位长度
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE, // 不使用流控
    };
    // 安裝串口驱动程序（串口号，发送缓冲区大小，接收缓冲区大小，消息队列大小，消息队列句柄，中断类型）
    ESP_ERROR_CHECK(uart_driver_install(UART_PORT_NUM, UART_BUF_SIZE, UART_BUF_SIZE, 0, NULL, 0));

    // 串口初始化
    ESP_LOGI(TAG, "驱动安装成功");
    ESP_ERROR_CHECK( uart_param_config(UART_PORT_NUM, &uart_config));
    ESP_LOGI(TAG, "串口初始化成功");
    // 设置串口引脚
    esp_err_t err= uart_set_pin(UART_PORT_NUM, UART_PORT_TX_PIN, UART_PORT_RX_PIN, GPIO_NUM_NC, GPIO_NUM_NC);
    if (ESP_OK == err)
    {
        ESP_LOGI(TAG, "引脚设置成功");
    }
    else
    {
        ESP_LOGE(TAG, "串口引脚设置失败");
        return ESP_FAIL;
    }
    return ESP_OK;
}
/**
 * @brief  发送数据
 * @param [IN]data 要发送的数据指针
 * @param [IN]length 要发送的数据长度
 */

void u_send(const void *data, size_t length)
{
    uart_write_bytes(UART_PORT_NUM, data, length);
    ESP_LOGI(TAG, "数据发送成功");
}

size_t u_recv(void *data, size_t length)
{
    int len = uart_read_bytes(UART_PORT_NUM, data, length, portMAX_DELAY);
    return len;
}