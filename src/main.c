#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

int main()
{
    // Initialize the cyw43
    cyw43_arch_init();
    // The LED is hooked into the CYW43, so it's necessary to go through CYW43 to activate it
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
    // Initialize stdio through USB
    stdio_usb_init();

    while (true)
    {
        printf("Hello\n");
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0);
        sleep_ms(1000);

        printf("World\n");
        cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1);
        sleep_ms(1000);
    }
    return 0;
}