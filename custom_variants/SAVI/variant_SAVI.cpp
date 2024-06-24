#if defined(ARDUINO_SAVI)

#include "pins_arduino.h"

// Pin number
const PinName digitalPin[] = {
    PA_6,  // PX_GPIO0
    PA_5,  // PX_GPIO1
    PA_1,  // PX_GPIO2
    PA_0,  // PX_GPIO3
    PC_3,  // PX_GPIO4
    PC_2,  // PX_GPIO5
    PC_1,  // PX_GPIO6
    PB_7,  // PX_GPIO7
    PH_0,  // PX_USR_LED
    PC_0,  // PX_LCD_BTN_1_LT
    PH_1,  // PX_LCD_BTN_2_RT
    PC_13, // PX_LCD_BTN_3_UP
    PC_12, // PX_LCD_BTN_4_DN
    PA_15, // PX_LCD_BTN_5_YES
    PC_9,  // PX_LCD_BTN_6_NO
    PA_8,  // PX_USB_DET
    PB_11, // PX_LCD_RS
    PB_12, // PX_LCD_BACKLIGHT
    PC_6,  // PX_PWM_BUZZER
    PC_7,  // PX_VBAT_MEAS_EN
    PC_8,  // PX_PWR_HOLD
    PA_9,  // PX_UART1_TX
    PA_10, // PX_UART1_RX
    PA_2,  // PX_UART2_TX
    PA_3,  // PX_UART2_RX
    PC_10, // PX_UART4_TX
    PC_11, // PX_UART4_RX
    PB_8,  // PX_I2C1_SCL
    PB_9,  // PX_I2C1_SDA
    PB_6,  // PX_SPI1_CS
    PB_3,  // PX_SPI1_SCK
    PB_5,  // PX_SPI1_MOSI
    PB_4,  // PX_SPI1_MISO
    PB_2,  // PX_SPI2_CS_SF
    PB_10, // PX_SPI2_CS_LCD
    PD_2,  // PX_SPI2_CS_SD
    PB_13, // PX_SPI2_SCK
    PB_15, // PX_SPI2_MOSI
    PB_14, // PX_SPI2_MISO
    PA_4,  // PX_DAC1

    PB_0, // ADC0
    PC_5, // ADC1
    PC_4, // ADC2
    PA_7, // ADC3
    PB_1, // ADC_VBAT
};

// Analog (Ax) pin number array
const uint32_t analogInputPin[] = {
    40, // A0
    41, // A1
    42, // A2
    43, // A3
    44  // A4
};

// ----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C"
{
#endif

  /**
   * @brief  System Clock Configuration
   * @param  None
   * @retval None
   */
  WEAK void SystemClock_Config(void)
  {
    // Variables for configuration
    RCC_OscInitTypeDef RCC_OscInitStruct = {};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {};
    RCC_PeriphCLKInitTypeDef PeriphClkInit = {};

    // Enable Power Control clock
    __HAL_RCC_PWR_CLK_ENABLE();

    // Configure the main internal voltage regulator
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    // Configure LSE Drive Capability
    HAL_PWR_EnableBkUpAccess();
    __HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_LOW);

    // Initializes the CPU, AHB, and APB busses clocks
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI | RCC_OSCILLATORTYPE_LSE | RCC_OSCILLATORTYPE_HSI48;
    RCC_OscInitStruct.LSEState = RCC_LSE_ON;
    RCC_OscInitStruct.HSIState = RCC_HSI_ON;
    RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
    RCC_OscInitStruct.HSI48State = RCC_HSI48_ON;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
    RCC_OscInitStruct.PLL.PLLMUL = RCC_PLLMUL_4;
    RCC_OscInitStruct.PLL.PLLDIV = RCC_PLLDIV_2;

    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
      Error_Handler();
    }

    // Initializes the CPU, AHB, and APB busses clocks
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
    {
      Error_Handler();
    }

    // Configure the peripheral clocks
    PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1 | RCC_PERIPHCLK_USART2 | RCC_PERIPHCLK_I2C1 | RCC_PERIPHCLK_RTC | RCC_PERIPHCLK_USB;
    PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK2;
    PeriphClkInit.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
    PeriphClkInit.I2c1ClockSelection = RCC_I2C1CLKSOURCE_PCLK1;
    PeriphClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSE;
    PeriphClkInit.UsbClockSelection = RCC_USBCLKSOURCE_HSI48;

    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
    {
      Error_Handler();
    }
  }

#ifdef __cplusplus
}
#endif

#endif /* ARDUINO_SAVI */
