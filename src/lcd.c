#include"REG52.H"
#include"header\keypad.h"
#include"header\lcd.h"
#include"header\Error_handling.h"
sfr LCD_PORT = 0x90;    //P1=KeyPadPort_data pins
sfr KeyPadPort = 0xB0;   //P3=KeyPadPort_data pins
sbit RO1=P3^7;
sbit RO2=P3^6;
sbit RO3=P3^5;
sbit RO4=P3^4;
sbit C1=P3^0;
sbit C2=P3^1;
sbit C3=P3^2;
sbit C4=P3^3;
sbit RS=P2^1;
sbit E=P2^2;
sbit c=ACC^0;
unsigned char key;

void initial(void){
    LCD_PORT=0;
    RS=0;
    E=0;
    KeyPadPort=0x0f;
    P0=0;
}

void LCD_COMM(unsigned char command){
    LCD_PORT=command;
    RS=0;
    E=1;
    DELAY(1);
    E=0;
}
void LCD_INIT(void){
    LCD_COMM(0X38);        //for using 2 lines and 5x7 matrix of lcd
    DELAY(10);
    LCD_COMM(0x0E);         //to turn display on, cursor blinking 
    DELAY(10);
    LCD_COMM(0x01);         //clear screen
    DELAY(10);
}
void LCD_CLEAR(){
    LCD_COMM(0X01);
    DELAY(10);
}
void LCD_DATA(unsigned char disp_data){
    LCD_PORT=disp_data;
    RS=1;
    E=1;
    DELAY(1);
    E=0;
}
void LCD_STRING(char *str){         //dispal string on screen
    int i;
    for(i=0;str[i]!=0;i++){   //send each character of the string till the null
        LCD_DATA(str[i]);
    }
}





