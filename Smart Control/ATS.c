unsigned int adc;
unsigned int adc2;
// LCD module connections
sbit LCD_RS at RB4_bit;
sbit LCD_EN at RB5_bit;
sbit LCD_D4 at RB0_bit;
sbit LCD_D5 at RB1_bit;
sbit LCD_D6 at RB2_bit;
sbit LCD_D7 at RB3_bit;

sbit LCD_RS_Direction at TRISB4_bit;
sbit LCD_EN_Direction at TRISB5_bit;
sbit LCD_D4_Direction at TRISB0_bit;
sbit LCD_D5_Direction at TRISB1_bit;
sbit LCD_D6_Direction at TRISB2_bit;
sbit LCD_D7_Direction at TRISB3_bit;
// End LCD module connections

void main() {
int a,b,c;
char aa[15] ,cc[15],r[15] ;

ADCON1 = 0b10000010;

ADCON0 = 0x80;// initial channel one RA0/AN0
ADCON0 = 0x81;//  before reading adc channel

ADCON0 = 0x88;// initial channel one RA1/AN1
ADCON0 = 0x88;// before reading adc channel


 TRISA  = 0xFF;              // PORTA is input
 TRISC  = 0;                 // PORTC is output
 TRISB  = 0;                 // PORTB is output
   Lcd_Init();               // Initialize LCD
   Lcd_Cmd(_LCD_CLEAR);
   Lcd_Cmd(_LCD_CURSOR_OFF);
  
  Lcd_Out(1, 5, "WELCOM");
  for(a=5;a>=1;a--)
   {delay_ms(500);
    IntToStr(a,r);
    LCD_OUT(4,-1,r);}
    Lcd_Cmd(_LCD_CLEAR);
    Lcd_Cmd(_LCD_CURSOR_OFF);

 do {
        adc = ADC_Read(0);   //POWER SUPPLY
        a=0.49*adc;         //use integer to string command to put data in array
        intTostr(a,aa);
       
        adc2=adc_read(1);  //BATTERY BACKUP
        c=0.49*adc2;
        intTostr(c,cc);    //use integer to string command to put data in array
        
   if (a>=140)
              {  PORTC.F0=1;         //SET BIT OF PORT C HIGH
                 PORTC.F1=0;
                 LCD_OUT(1,1,"POWER SUPPLY");
                 lcd_out(3,-3,"VOLTAGE =");
                 lcd_out(3,6,aa);
                 lcd_out(3,12,"V");
                  }
        if ((c>=11)&(a<140))
              { 
              PORTC.F1=1;              // SET BIT FOR BATTERY HIGH AND ON NEXT LOW THE POWER SUPPLY
              PORTC.F0=0;            // BIT
                 LCD_OUT(1,1,"BATTERY BACKUP");
                 lcd_out(3,-3,"VOLTAGE =");
                 lcd_out(3,6,cc);
                 lcd_out(3,12,"V");         }
    

  } while(1);
}