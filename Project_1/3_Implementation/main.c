/**
 * @file main.c
 * @author vinay mathad (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// Button count function implemented by vinay mathad, mahesh.
//pin config by manoj , dinesh .

#include "MyStm32f407xx.h"
#define S 1  // Defining set pin to high
#define R 0  //// Defining set pin to Low

void GPIO_Config()  										
{
	GPIO_Handle_t GpioLed, GPIOBtn;

	
	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;   // Initiliaze Led at Pin number 12 as output 
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLed);

	
	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;    //// Initiliaze Led at Pin number 13 as output
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLed);

	
	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;    // Initiliaze Led at Pin number 14 as output
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLed);
	
	
	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15;   //// Initiliaze Led at Pin number 15 as output 
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLed);

	
	GPIOBtn.pGPIOx = GPIOA;
	GPIOBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;     // Initiliaze Button at Pin number 0 as button
	GPIOBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GPIOBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIOBtn.GPIO_PinConfig.GPIO_PinOPType = GPIO_NO_PUPD;
	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Init(&GPIOBtn);
}
 int main()
{
	GPIO_Config(); 
	while(1)  // Forever loop 
	{
		int res;  
		res = button_count();
		volatile int enc1 = encryption(res);	// Encryption

		if(enc1 == 5)
		{	
			GPIO_Config();
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, S);
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, S);
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14, S);
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15, S);
			delay(350);
			res = 0;
			button_count();
		}
		else if(enc1 == 11)
		{
			GPIO_Config();
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, R);
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, R);
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14, R);
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15, R);
			delay(350);
			res =0;
			button_count();
			
		}
		else if(enc1 == 26)
		{
			GPIO_Config();
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, S);
			delay(350);
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, R);
			delay(350);
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, S);
			delay(350);
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, R);
			delay(350);
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14, S);
			delay(350);
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14, R);
			delay(350);
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15, S);
			delay(350);
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15, R);
			delay(350);
			res = 0;
			button_count();

			
		}
		else if(enc1 == 35)
		{
			GPIO_Config();
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15, S);
			delay(350);
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15, R);
			delay(350);
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14, S);
			delay(350);
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14, R);
			delay(350);
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, S);
			delay(350);
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, R);
			delay(350);
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, S);
			delay(350);
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, R);
			delay(350);
			res = 0;
			button_count();

		}
	}
}

int button_count(void)    // Button count function implemented by vinay mathad
{
	GPIO_Config(); // Gpio's are configured
	int count = 0; // button count is initialized to zero
	uint32_t *pGpiodDataReg1 = (uint32_t *)0x40020010; 
	int sec = 10000000; 
	while (sec--)
	{
		if ((*pGpiodDataReg1) & (1 << GPIO_PIN_NO_0)) // Read input from pin number 0 (blue button)
		{ 
			delay(150);
			count++; // inceremnt count
		}
	}
	return count; // Returns no of key presses
}