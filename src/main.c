
#include"header\keypad.h"
#include"header\lcd.h"
#include"header\Error_handling.h"
#include"header\conversion.h"
#include"header\Arith_fun.h"


void main(void)
{
    while(1)
    {
    unsigned char operand1_hex[3]={0,0,0};
    unsigned char operand2_hex[3]={0,0,0};
    unsigned char opration_sgin=0;
    unsigned char count,equal_sgin,Error_flag[4];
    int operand1_dec,operand2_dec,result_dec;
    unsigned char result_hex[3];

    initial();
    LCD_INIT();

    while (1)
    {
        for ( count = 0; count < 3; count++)
    {
    operand1_hex[count]=READ_KEY();
    if (operand1_hex[count]=='c')
    {
        LCD_CLEAR();
        break;
    }
    else
    {
        LCD_DATA(operand1_hex[count]);
    }
    
    }

    opration_sgin=READ_KEY();
    if (opration_sgin=='c')
    {
        LCD_CLEAR();
        break;
    }
    else
    {
    LCD_DATA(opration_sgin);
    }


    for ( count = 0; count < 3; count++)
    {
    operand2_hex[count]=READ_KEY();
    if (operand2_hex[count] == 'c')
    {
        LCD_CLEAR();
        break;
    }
    else
    {
        LCD_DATA(operand2_hex[count]);
    }
    
    }

    equal_sgin=READ_KEY();
    if (equal_sgin !='=')
    {
        LCD_CLEAR();
       LCD_STRING("Error\0"); 
       READ_KEY();
       break;
    }
    else
    {
        LCD_DATA(equal_sgin);
        DELAY(6);
    }
    

    Error_flag[0]=invldOpr(operand1_hex[0],operand1_hex[1],operand1_hex[2]);
    Error_flag[1]=invldOpr(operand2_hex[0],operand2_hex[1],operand2_hex[2]);
    Error_flag[2]=invldOpration(opration_sgin);

    for ( count = 0; count < 3; count++)
    {
       if(Error_flag[count]==10)
    {
        LCD_CLEAR();
        LCD_STRING("INVALD\0");
        READ_KEY();
        break;
    }
    }

    operand1_dec=hex_to_dec(operand1_hex[0],operand1_hex[1],operand1_hex[2]);
    operand2_dec=hex_to_dec(operand2_hex[0],operand2_hex[1],operand2_hex[2]);
    Error_flag[3]=divByZeroError(operand2_dec,opration_sgin);

        if(Error_flag[3]==10)
    {
        LCD_CLEAR();
        LCD_STRING("INVALD\0");
        READ_KEY();
        break;
    }

    result_dec=ArithFunc(operand1_dec,opration_sgin,operand2_dec);

    if (operand1_dec<operand2_dec && opration_sgin == '-')
    {   
        LCD_STRING("-\0");
        result_dec = ~result_dec+1;
    }
    dec_to_hex(result_dec,result_hex);
    count=0;
    while (count != 3)
    {
        if (count == 0 && result_hex[0] == '0')
        {
            count++;
        }
        if(count==1 && result_hex[1]=='0' && result_hex[0] =='0' )
        {
            count++;
        }
       LCD_DATA(result_hex[count]);
       DELAY(6);
        count++;
    }
    
    READ_KEY();
    break;
    }
    
    }
}