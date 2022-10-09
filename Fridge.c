#include <main.h>
#include <lcd.c>

void main()
{   
   int16 temp = 0;
   int esik = 8;
   setup_adc(ADC_CLOCK_DIV_2);
   setup_adc_ports(AN0);
   set_adc_channel(0);
   set_tris_a(0x01);
   set_tris_b(0x01);
   set_tris_c(0x00);
   set_tris_d(0x00);
   set_tris_e(0x03);
   lcd_init();
   lcd_gotoxy(1,1);
   printf(lcd_putc, "\fMerhaba");
   while(TRUE)
   {
      if (input(PIN_E0))
      {
         esik++;
         printf(lcd_putc,"\fEsik :\n%d °C",esik);
         while (input(PIN_E0));
      }
      if (input(PIN_E1))
      {
         esik--;
         printf(lcd_putc,"\fEsik :\n%d °C",esik);
         while (input(PIN_E1));
      }
      if (input(PIN_B0))
      {
         output_low(PIN_C0);
         output_high(PIN_B7);
         printf(lcd_putc,"\fKapak Acik");
         while (input(PIN_B0));
      }
      else
      {
         output_low(PIN_B7);
         printf(lcd_putc,"\fKapak Kapali");
         delay_ms(50);
      }
      temp = read_adc() * 0.00763;
      if (temp > esik) //8 santigrat derece
      {
         output_high(PIN_C0);
      }
      else
      {
         output_low(PIN_C0);
      }
   }

}
