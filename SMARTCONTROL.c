void main_2(void);
void main_3(void);
unsigned int adc4;
unsigned int adc3;
unsigned int adc2;
unsigned int adc;

void main()
{
char m[15];
char u[15];

char r[15];
char aa[15], bb[15],cc[15],dd[15],ff[15];

int a,b,c,d,f;
int i,s,l,j,ll,lll;

PORTB=0;
TRISB=0;
PORTD=0;
TRISC=0;
TRISC.F1=1;         //GENERATER INPUT SENSOR

TRISC.F3=0;        //WIND POWER OUTPUT
TRISC.F4=0;        // SOLAR POWER OUTPUT
TRISC.F5=0;        //WAPDA POWER OUTPUT
TRISC.F6=0;        // GENERATOR POWER OUTPUT
TRISC.F7=0;        // GENERATOR POWER STARTER

TRISD.F7=0;
TRISD.F4=0;
TRISD.F5=0;
TRISD.F6=0;

ADCON1 = 0b10000010;

ADCON0 = 0x80;// initial channel one RA0/AN0
ADCON0 = 0x81;//  before reading adc channel



ADCON0 = 0x88;// initial channel one RA1/AN1
ADCON0 = 0x88;// before reading adc channel



ADCON0 = 0x90 ;// initial channel one RA2/AN2
ADCON0 =0x91;//  before reading adc channel



ADCON0 = 0x98 ;// initial channel one RA3/AN3
ADCON0 =0x98;//  before reading adc channel


ADCON0 = 0xA0 ;// initial channel one RA4/AN4
ADCON0 =0xA1;//  before reading adc channel


  Lcd_Init(&PORTB);
  Lcd_Cmd(Lcd_CLEAR);
  Lcd_Cmd(Lcd_CURSOR_OFF);
   Lcd_Out(1, 5, "WELCOM");
  for(i=5;i>=1;i--)
   {delay_ms(100);
   inttostr(i,m);
      LCD_OUT(4,-1,m);}
    Lcd_Cmd(Lcd_CLEAR);
  Lcd_Cmd(Lcd_CURSOR_OFF);
two:{do
{

                     adc=adc_read(0);  // wapda sensor
                     a=0.49*adc;
                     intTostr(a,aa);



                     adc2=adc_read(1);  //generator sensor
                     b=0.49*adc2;
                     intTostr(b,bb);


                     adc=adc_read(2);     // solar battery
                     c=0.49*adc;
                     intTostr(c,cc);
                     

                     adc4=adc_read(4);     // wind power
                     f=0.49*adc4;
                     intTostr(f,ff);


   if (f>=11)
              {  PORTC.F3=1;
                 PORTC.F4==0;
                 PORTC.F5==0;
                 PORTC.F6==0;
                 PORTC.F7==0;
                 PORTD.F6==0;
                 LCD_OUT(1,1,"WIND POWER");
                 lcd_out(3,-3,"VOLTAGE =");
                 lcd_out(3,6,ff);
                 lcd_out(3,12,"V");         }








   if ((c>=11)&(f<11))
              {  PORTC.F4=1;
                 PORTC.F3==0;
                 PORTC.F5==0;
                 PORTC.F6==0;
                 PORTC.F7==0;
                 PORTD.F6==0;
                 LCD_OUT(1,1,"SOLAR POWER");
                 lcd_out(3,-3,"VOLTAGE =");
                 lcd_out(3,6,cc);
                 lcd_out(3,12,"V");         }
                 

    if((c>=9)&(c<11)&(f<11))
             {   PORTC.F4=1;
                 PORTC.F5==0;
                 PORTC.F6==0;
                 PORTC.F7==0;
                 PORTD.F6==0;
                  LCD_OUT(1,1,"BATTERY LOW");
                   lcd_out(3,-3,"VOLTAGE =");
                    lcd_out(3,6,cc);
                    lcd_out(3,12,"V");    }


                     
 if((c<9)&(f<11))

{
   if(a>=100)
                 { PORTC.F5=1;         //WAPDA POWER ENABLE
                   PORTC.F4==0;
                   PORTC.F3==0;
                   PORTC.F6==0;
                   PORTC.F7==0;
                   PORTD.F6==0;
                   LCD_OUT(1,1,"WAPDA POWER");
                    lcd_out(3,-3,"VOLTAGE =");
                     lcd_out(3,6,aa);
                     lcd_out(3,12,"V");}


                     
   if((a<100)&(c<9)&(f<11))
       {  PORTD.F6=1;
         for(i=0;i<=3;i++)
                   {
                                     if(f>=11)
                                       {goto two;}

                                     if(a>=100)
                                       {goto two;}

                                     if (c>=11)
                                       {goto two;}

                   { portc.f6=1;
                      { lcd_out(1,1,"GENERATOR START");
                        lcd_out(2,5,". . .");
                       delay_ms(5000);


                      if( portc.f1==1)
                         {
                         Lcd_Cmd(Lcd_CLEAR);
                          PORTD.F6=1;
                         portc.f6=0;
                       main_2();
                        break; } }

                         }
                      portc.f6=0;
                      {  Lcd_Cmd(Lcd_CLEAR);
                      delay_ms(500);
                       }} main_3();

                      }

                      }
                          }while(1); }  }


   void main_2()                              /// GENERATOR POWER
    {     char bb[15];
         int c,b,a,f;
         do       {
                          adc=adc_read(0);
                          a=0.49*adc;
                          adc2=adc_read(1);
                          b=0.49*adc2;
                          adc=adc_read(2);
                          c=0.49*adc;
                          adc4=adc_read(4);
                          f=0.49*adc4;

                         PORTc.F7=1;
                         PORTD.F6=1;
                         PORTC.F6==0;
                         PORTC.F3==0;
                         PORTC.F5==0;
                         PORTC.F4==0;
                         LCD_OUT(1,1,"GENERATOR POWER");
                         lcd_out(3,-3,"VOLTAGE =");
                         intTostr(b,bb);
                         lcd_out(3,6,bb);
                         lcd_out(3,12,"V");

                                          if(f>=11)
                                       { Lcd_Cmd(Lcd_CLEAR);
                                                    return ;}
                                                    
                                        if(a>=100)
                                       { Lcd_Cmd(Lcd_CLEAR);
                                                    return ;}
                                                    
                                        if (c>=11)
                                       { Lcd_Cmd(Lcd_CLEAR);
                                                      return;}

                        if(portc.f1==0)
                         {Lcd_Cmd(Lcd_CLEAR);
                         main_3();
                          }
                          } while(portc.f1==1);
                             }
void main_3()                                          // UPS BATTERY
{ char aa[15],bb[15],cc[15],dd[15],ff[15];
  int a,b,c,d,f;

  do{                     adc4=adc_read(4);
                          f=0.49*adc4;
                          intTostr(f,ff);

                          adc=adc_read(0);
                          a=0.49*adc;
                           intTostr(a,aa);
                          adc2=adc_read(1);
                          b=0.49*adc2;
                           intTostr(b,bb);
                          adc=adc_read(2);
                          c=0.49*adc;
                           intTostr(c,cc);
                          adc2=adc_read(3);    //ups battery
                          d=0.49*adc2;
                          inttostr(d,dd);


                           PORTC.F5=0;           ///ups POWER ENABLE
                           PORTC.F4=0;
                           PORTC.F3=0;
                           PORTC.F6=0;
                           PORTD.F4=0;
                           PORTD.F6=0;
                           PORTc.F7=0;
                                        if(f>=11)
                                       { Lcd_Cmd(Lcd_CLEAR);
                                                    return ;}
                                                    
                                       if(a>=100)
                                       { Lcd_Cmd(Lcd_CLEAR);
                                                    return ;}
                                                    
                                        if (c>=11)
                                       { Lcd_Cmd(Lcd_CLEAR);
                                                      return;}

                          if(d>=10)
                           {
                            LCD_OUT(1,1,"UPS POWER");
                            lcd_out(3,-3,"VOLTAGE =");
                             lcd_out(3,6,dd);
                            lcd_out(3,12,"V");}

                             if(d<10)
                            { PORTD.F5=1;}
                                               }while(1);}