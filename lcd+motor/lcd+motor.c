#include<avr/io.h>
#define F_CPU 8000000
#include<util/delay.h>
#include<lcdavr.h>
void main()
{
   DDRB=0xff;
   lcd_init();
   DDRC=0xff;
   DDRA=0x00;
   PORTA=0b11110000;

   while(1)
   {   if((PINA & 0b11110000)==0b01110000) //switch 1 closed
        { lcd_clear();
	     lcd_command(0x80);
	     lcd_string("forward");
	      lcd_command(0xc0);
	      lcd_string(" direction");
            PORTC=0b10100000;
	        _delay_ms(200);}
			else
			 lcd_clear();
			 PORTC=0x00;

          if((PINA & 0b11110000)==0b10110000)  //switch 2 closed
		  {
		      lcd_command(0x80);
			  lcd_string("backward");
             lcd_command(0xc0);
	          lcd_string(" direction");
			  PORTC=0b01010000;
			  _delay_ms(200);
			  }
			  else
			  lcd_clear();
			  PORTC=0x00;
                
				if((PINA & 0b11110000)==0b11010000)  // switch 1 is closed
                       {
					        lcd_command(0x80);
                             lcd_string("right");
							  lcd_command(0xc0);
	                       lcd_string(" direction");
						   PORTC=0b10010000;
						   _delay_ms(200);
						   }
						   else
						   lcd_clear();
						   PORTC=0x00;

                    if((PINA & 0b11110000)==0b11100000)  //switch 4 is closed
					   {
					         lcd_command(0x80);
							 lcd_string("left");
                              lcd_command(0xc0);
	                              lcd_string(" direction");
								  PORTC=0b01100000;
								  _delay_ms(200);
								  }

								  else
								  lcd_clear();
								  PORTC=0x00;


	   }
	   }
