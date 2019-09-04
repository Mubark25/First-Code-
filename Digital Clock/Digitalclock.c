// LCD module connections for initilize the LCD
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
void main()
{ char m [5], u [5] , a[5];
 int i , b , c ;
   TRISC0_bit = 1;
   Lcd_Init();                         // Initialize LCD
   Lcd_Cmd(_LCD_CURSOR_OFF);           // Cursor off
   Lcd_Cmd(_LCD_CLEAR);               // Clear display
   Lcd_Out(1,2," DIGITAL CLOCK");           // Write text in 1st row
    Lcd_Out(3,-1,"HOUR  MIN  SEC");
  while (1){
  for(i=0;i<=60;i++)   // for loop second for sec
   {LCD_OUT(2,13,":");
   if (PORTC=0) {        //  button to minimize delay
   delay_ms(1000);
    inttostr(i,m);
    LCD_OUT(2,11,m);}

   inttostr(i,m);
    LCD_OUT(2,11,m);}
 //----------------------------------------//
    if (i=60)          // if second reach at 60 then counter start form min
     {b=b+1;
     inttostr(b,u);
     LCD_OUT(2,5,u);
     LCD_OUT (2,7, ":") ;
  //----------------------------------------//
    if (b==60)            // same statement used for min also for hour
    {b=0;
    c=c+1;
 inttostr(c,a);
 LCD_OUT(2,-1,a);}
    if (c==24)
        {c=0;            // set int at 0 after 24 hour
                    }}}}