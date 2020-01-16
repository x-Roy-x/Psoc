#include "lab.h"
#include "stdio.h"

static char buf1[17];
static char buf2[17];

extern uint8 direction;
extern uint8 speed;
extern uint8 value_PWM;

void lcd_stop_rotor(void);
void lcd_forward_rotor(void);
void lcd_back_rotor(void);

void lcd_init(void){
    LCD_Start();
}

void lcd_stop_rotor(void){
    LCD_ClearDisplay();
    sprintf(buf1,"Stop PWM=%d",value_PWM);
    LCD_Position(0, 0);
    LCD_PrintString(buf1);
    sprintf(buf2,"Speed=%d",speed);
    LCD_Position(1, 0);
    LCD_PrintString(buf2);
}

void lcd_forward_rotor(void){
    LCD_ClearDisplay();
    sprintf(buf1,"Forward PWM=%d",value_PWM);
    LCD_Position(0, 0);
    LCD_PrintString(buf1);
    sprintf(buf2,"Speed=%d",speed);
    LCD_Position(1, 0);
    LCD_PrintString(buf2);
}

void lcd_back_rotor(void){
    LCD_ClearDisplay();
    sprintf(buf1,"Back  PWM=%d",value_PWM);
    LCD_Position(0, 0);
    LCD_PrintString(buf1);
    sprintf(buf2,"Speed=%d",speed);
    LCD_Position(1, 0);
    LCD_PrintString(buf2);
}

void definition_direction(void){
    if(0 == direction){
        lcd_stop_rotor();
    }else if(1 == direction){
        lcd_forward_rotor();
    }else if(2 == direction){
        lcd_back_rotor();
    }
}