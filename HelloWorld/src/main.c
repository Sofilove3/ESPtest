#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "esp_vfs_dev.h"
#include "driver/uart.h"


void app_main() {
    // set up communication
    uart_driver_install(UART_NUM_0, 256, 0, 0, NULL, 0);
    esp_vfs_dev_uart_use_driver(UART_NUM_0);
    setvbuf(stdin, NULL, _IONBF, 0);

    char name[20];

    while(1)
    {
        // print "Hello World" and asks for name
        printf("Hello World\n");
        printf("What is your name \n");
        scanf("%s", name);

        // prints "Hello 'name'"
        printf("Hello %s\n", name);
    }

}