#include "lab.h"
#include "stdio.h"

static char buf1[17];
static char buf2[17];

extern int x;
extern int y;

void lcd_init(void){
    LCD_Start();
    LCD_ClearDisplay();
}

void lcd_degree(void){
    LCD_ClearDisplay();
    sprintf(buf1,"Degrees");
    LCD_Position(0, 0);
    LCD_PrintString(buf1);
    sprintf(buf2,"x=%d y=%d",x,y);
    LCD_Position(1, 0);
    LCD_PrintString(buf2);
}
