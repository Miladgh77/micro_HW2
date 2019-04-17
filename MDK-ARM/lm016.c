#include "lm016.h"
void lcd_init(lcd_t * lcd)
{
	//HAL_GPIO_WritePin(LED_GPIO_Port,LED_Pin,GPIO_PIN_SET);
	(*lcd).status = command_mode;
	if(lcd->mode ==BIT_8)
	{
	lcd_putchar(lcd , 0x30);
	lcd_putchar(lcd , 0x30);
	lcd_putchar(lcd , 0x30);
	lcd_putchar(lcd , 0x38);
	lcd_putchar(lcd , 0x0E);
	lcd_putchar(lcd , 0x06);
	lcd_putchar(lcd , 0x01);
	lcd_putchar(lcd , 0x02);
	}
	else if (lcd->mode== BIT_4)
	{
	lcd_putchar(lcd , 0x33);
  lcd_putchar(lcd , 0x32);
	lcd_putchar(lcd , 0x28);
	lcd_putchar(lcd , 0x0E);
	lcd_putchar(lcd , 0x06);
	lcd_putchar(lcd , 0x01);
	lcd_putchar(lcd , 0x02);
	}
		
	(*lcd).status = show_mode;
	
}
void lcd_putchar(lcd_t *  lcd, uint8_t character)
	{
			HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, GPIO_PIN_SET);
			if ((*lcd).status == command_mode)
				HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, GPIO_PIN_RESET);
			
	if (lcd->mode == BIT_8)
	{
			if((character & 0x80) == 0x80)
				HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, GPIO_PIN_SET);
			else
				HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, GPIO_PIN_RESET);
			
			if((character & 0x40) == 0x40)
				HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_SET);
			else
				HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_RESET);
			
			if((character & 0x20) == 0x20)
				HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_SET);
			else
				HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_RESET);
			
			if((character & 0x10) == 0x10)
				HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_SET);
			else
				HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_RESET);
	
			if((character & 0x08) == 0x08)
				HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, GPIO_PIN_SET);
			else
				HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, GPIO_PIN_RESET);
			
			if((character & 0x04) == 0x04)
				HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, GPIO_PIN_SET);
			else
				HAL_GPIO_WritePin(D2_GPIO_Port, D2_Pin, GPIO_PIN_RESET);
			
			if((character & 0x02) == 0x02)
				HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, GPIO_PIN_SET);
			else
				HAL_GPIO_WritePin(D1_GPIO_Port, D1_Pin, GPIO_PIN_RESET);
			
			if((character & 0x01) == 0x01)
				HAL_GPIO_WritePin(D0_GPIO_Port, D0_Pin, GPIO_PIN_SET);
			else
				HAL_GPIO_WritePin(D0_GPIO_Port, D0_Pin, GPIO_PIN_RESET);
			
			HAL_Delay(50);
			HAL_GPIO_WritePin(enable_GPIO_Port, enable_Pin, GPIO_PIN_SET);
			HAL_Delay(50);
			HAL_GPIO_WritePin(enable_GPIO_Port, enable_Pin, GPIO_PIN_RESET);
		}
	else if(lcd->mode == BIT_4)
	{
		if((character & 0x80) == 0x80)
				HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, GPIO_PIN_SET);
			else
				HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, GPIO_PIN_RESET);
			
			if((character & 0x40) == 0x40)
				HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_SET);
			else
				HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_RESET);
			
			if((character & 0x20) == 0x20)
				HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_SET);
			else
				HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_RESET);
			
			if((character & 0x10) == 0x10)
				HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_SET);
			else
				HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_RESET);
			HAL_Delay(50);
			HAL_GPIO_WritePin(enable_GPIO_Port, enable_Pin, GPIO_PIN_SET);
			HAL_Delay(50);
			HAL_GPIO_WritePin(enable_GPIO_Port, enable_Pin, GPIO_PIN_RESET);
			
			if((character & 0x08) == 0x08)
				HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, GPIO_PIN_SET);
			else
				HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, GPIO_PIN_RESET);
			
			if((character & 0x04) == 0x04)
				HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_SET);
			else
				HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, GPIO_PIN_RESET);
			
			if((character & 0x02) == 0x02)
				HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_SET);
			else
				HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, GPIO_PIN_RESET);
			
			if((character & 0x01) == 0x01)
				HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_SET);
			else
				HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, GPIO_PIN_RESET);
			
			HAL_Delay(50);
			HAL_GPIO_WritePin(enable_GPIO_Port, enable_Pin, GPIO_PIN_SET);
			HAL_Delay(50);
			HAL_GPIO_WritePin(enable_GPIO_Port, enable_Pin, GPIO_PIN_RESET);
	}
	}
	void lcd_puts(lcd_t * lcd, char* str, int length){
		for(int i =0 ; i<length ; i++)
		{
			lcd_putchar(lcd ,str[i]);
		}
	}