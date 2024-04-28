#include"header\keypad.h"

sfr KeyPadPort = 0xB0;   //P3=KeyPadPort_data pins
sbit RO1=P3^7;
sbit RO2=P3^6;
sbit RO3=P3^5;
sbit RO4=P3^4;
sbit C1=P3^0;
sbit C2=P3^1;
sbit C3=P3^2;
sbit C4=P3^3;

unsigned char READ_KEY(void){
    unsigned char key=0;

    while (key==0)
    {
    C1=C2=C3=C4=1;
    RO1=0;
    RO2=RO3=RO4=1; 
    if(C1==0){
        while(C1==0);
        key='7';
        
    }
    else if(C2==0){
        while (C2==0);
          key='8';
    }
    else if(C3==0){
        while (C3==0);
            key='9';

    }
    else if(C4==0){
        while (C4==0);
            key='/';
    
    }
    C1=C2=C3=C4=1;
    RO2=0;
    RO1=RO3=RO4=1;
    if(C1==0){
        while(C1==0);
             key='4';

    }
    else if(C2==0){
        while (C2==0);
            key='5';
    
    }
    else if(C3==0){
        while (C3==0);
             key='6';
   
    }
    else if(C4==0){
        while (C4==0);
             key='*';
   
    }
    C1=C2=C3=C4=1;
    RO3=0;
    RO2=RO1=RO4=1;
    if(C1==0){
        while(C1==0);
            key='1';

    }
    else if(C2==0){
        while (C2==0);
             key='2';
   
    }
    else if(C3==0){
        while (C3==0);
            key='3';
    
    }
    else if(C4==0){
        while (C4==0);
             key='-';
   
    }
    C1=C2=C3=C4=1;
    RO4=0;
    RO2=RO3=RO1=1;
    if(C1==0){
        while(C1==0);
            key='c';

    }
    else if(C2==0){
        while (C2==0);
             key='0';
   
    }
    else if(C3==0){
        while (C3==0);
             key='=';
   
    }
    else if(C4==0){
        while (C4==0);
             key='+';
   
    }

    }
    
       return key; 
}


