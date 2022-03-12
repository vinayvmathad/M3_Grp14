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
// Main function Implemented by manoj ,dinesh.
// Button count function implemented by vinay mathad,mahesh.
#include "MyStm32f407xx.h"
#define S 1  // Defining set pin to high
#define R 0  // Defining set pin to Low

void GPIO_Config()
{
	GPIO_Handle_t GpioLed, GPIOBtn;

	
	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_12;			// Initialize Led at Pin number 12 as output 
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLed);


	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;				// Initialize Led at Pin number 13 as output 
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLed);

	
	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_14;			// Initialize Led at Pin number 14 as output 
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLed);
	
	
	GpioLed.pGPIOx = GPIOD;
	GpioLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_15;				// Initialize Led at Pin number 15 as output 
	GpioLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GpioLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GpioLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIO_PeriClockControl(GPIOD, ENABLE);
	GPIO_Init(&GpioLed);

	
	GPIOBtn.pGPIOx = GPIOA;
	GPIOBtn.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_0;			// Initialize Button at Pin number 0 as  button
	GPIOBtn.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GPIOBtn.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIOBtn.GPIO_PinConfig.GPIO_PinOPType = GPIO_NO_PUPD;
	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Init(&GPIOBtn);
}
 int main()  
{
	GPIO_Config(); // Function call to initialize led and button pins 
	while(1)  // Forever loop 
	{
		int res;  
		res = button_count();

		if(res == 1) // Turn On all LED's
		{	
			GPIO_Config();
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, S);  // Pin Number 12 set to HIGH
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, S);  // Pin Number 13 set to HIGH
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14, S);  // Pin Number 14 set to HIGH
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15, S);  // Pin Number 15 set to HIGH
			delay(350);
			res = 0;
			button_count();
		}
		else if(res == 2) // Turn off all LED's
		{
			GPIO_Config();
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, R); // Pin Number 12 set to LOW
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, R); // Pin Number 13 set to LOW
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14, R); // Pin Number 14 set to LOW
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15, R); // Pin Number 15 set to LOW
			delay(350);
			res =0;
			button_count();
			
		}
		else if(res == 3)  // led operation in clockwise direction
		{
			GPIO_Config();
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, S); // Pin Number 12 set to HIGH
			delay(350); 									 
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, R); // Pin Number 12 set to LOW
			delay(350);
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, S); // Pin Number 13 set to HIGH
			delay(350);
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, R); // Pin Number 13 set to LOW
			delay(350);
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14, S); // Pin Number 14 set to HIGH
			delay(350);
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14, R); // Pin Number 14 set to LOW
			delay(350);
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15, S); // Pin Number 15 set to HIGH
			delay(350);
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15, R); // Pin Number 15 set to LOW
			delay(350);
			res = 0;
			button_count();
		}
		else if(res == 4) // led operation in Anticlockwise direction
		{
			GPIO_Config();
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, S); // Pin Number 12 set to HIGH
			delay(350);
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_12, R); // Pin Number 12 set to LOW
			delay(350);
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15, S); // Pin Number 15 set to HIGH
			delay(350);
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_15, R); // Pin Number 15 set to LOW
			delay(350);
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14, S); // Pin Number 14 set to HIGH
			delay(350);
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_14, R); // Pin Number 14 set to LOW
			delay(350);
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, S); // Pin Number 13 set to HIGH
			delay(350);
			GPIO_WriteToOutputPin(GPIOD, GPIO_PIN_NO_13, R); // Pin Number 13 set to LOW
			delay(350);

			delay(350);
			res = 0;
			button_count();

		}
	}
}
int button_count(void)    
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
