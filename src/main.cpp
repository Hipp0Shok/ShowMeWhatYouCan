#include <avr/io.h>
#include <util/delay.h>
//#include <Arduino.h>
#include <C:\Users\Orion\Documents\PlatformIO\Projects\ShowMeWhatYouCan\lib\Remote\IRremote.h>

void USARTInit()
{
  UBRR0H = 0;
  UBRR0L = 8; //115200 baud
  UCSR0A = 0;
  UCSR0B = (1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0);
  UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);
}

void UARTSend(unsigned char c)
{
  while(!(UCSR0A & (1<<UDRE0)));
}

void UARTSendString(char *s)
{
  while(*s != 0)
  {
    UARTSend(*s++);
  }
}

void UARTSendUInt(uint16_t c)
{
  unsigned char temp;
  c = c % 10000;
  temp = c/100;
  UARTSend(temp/10 + '0');
  UARTSend(temp%10 +'0');
  temp = c % 100;
  UARTSend(temp/10 + '0');
  UARTSend(temp%10 + '0');
}

void setup()
{
  DDRD |= (1<<PD3);
  USARTInit();
}

int main(void)
{
  //setup();
  while(1)
  {
    /*for( int i = 20; i < 10000; i += 50)
    {
      tone(PD3, i);
      UARTSendUInt(i);
      delay(250);
    }
    noTone(PD3);
    delay(1000); */
     tone(3, 1000);
  delay(100);
  noTone(3);
  delay(250);
  }
  return 0;
}