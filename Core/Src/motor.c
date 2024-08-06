#include "motor.h"

void motor_init(){
	TIM2 -> CCR1 = 0;
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, GPIO_PIN_RESET);
}

void motor_pwm(float u)
{
	if (fabs(u) >= MAX_DUTY_CYCLE)
	{
		u = u > 0 ? MAX_DUTY_CYCLE : -MAX_DUTY_CYCLE;
	}
	if (fabs(u) <= MIN_DUTY_CYCLE)
	{
		u = u > 0 ? MIN_DUTY_CYCLE : -MIN_DUTY_CYCLE;
	}
	TIM2 -> CCR1 = fabs(u);
	if (u > 0)
	{
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, GPIO_PIN_SET);
	}
	else if (u < 0)
	{
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_SET);
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, GPIO_PIN_RESET);
	}
	else
	{
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_1, GPIO_PIN_RESET);
	}
}
