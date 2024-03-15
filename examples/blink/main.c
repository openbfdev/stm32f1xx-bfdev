#include "stm32f1xx_hal.h"

int main(void)
{
    RCC_OscInitTypeDef OscInitType = {};
    RCC_ClkInitTypeDef ClkInitType = {};
    GPIO_InitTypeDef GPIOInitType = {};

    HAL_Init();

    OscInitType.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    OscInitType.HSEState = RCC_HSE_ON;
    OscInitType.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
    OscInitType.PLL.PLLState = RCC_PLL_ON;
    OscInitType.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    OscInitType.PLL.PLLMUL = 9;
    HAL_RCC_OscConfig(&OscInitType);

    ClkInitType.ClockType = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    ClkInitType.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    ClkInitType.AHBCLKDivider = RCC_SYSCLK_DIV1;
    ClkInitType.APB1CLKDivider = RCC_HCLK_DIV2;
    ClkInitType.APB2CLKDivider = RCC_HCLK_DIV1;
    HAL_RCC_ClockConfig(&ClkInitType, FLASH_LATENCY_2);

    GPIOInitType.Pin = GPIO_PIN_8;
    GPIOInitType.Mode = GPIO_MODE_OUTPUT_PP;
    GPIOInitType.Speed = GPIO_SPEED_FREQ_HIGH;

    __HAL_RCC_GPIOA_CLK_ENABLE();
    HAL_GPIO_Init(GPIOA, &GPIOInitType);

    for (;;) {
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
        HAL_Delay(500);
    }

    return 0;
}
