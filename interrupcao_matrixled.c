#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "interrupcao_matrixled.h"
const uint LED_RED = 13;
const uint LED_BLUE = 12;
const uint LED_GREEN = 11;
const uint BUTTON_A = 5;
const uint BUTTON_B = 6;

#define tempo 200
static volatile uint32_t last_time = 0;
 static volatile uint a = 0;

void init_gpios(){
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED,GPIO_OUT);
    gpio_init(BUTTON_A);
    gpio_set_dir(BUTTON_A,GPIO_IN);
    gpio_pull_up(BUTTON_A);
    gpio_init(BUTTON_B);
    gpio_set_dir(BUTTON_B,GPIO_IN);
    gpio_pull_up(BUTTON_B);
}

void gpio_irq_handler();



int main()
{
    init_gpios();
    initNeoPixel();
    stdio_init_all();

    gpio_set_irq_enabled_with_callback(BUTTON_A, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
     gpio_set_irq_enabled_with_callback(BUTTON_B, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);


    while (true) {
        printf("A= %d \n",a);
        gpio_put(LED_RED,true);
        sleep_ms(200);
        gpio_put(LED_RED,false);
        sleep_ms(200);


    }
}

void gpio_irq_handler(uint gpio, uint32_t events){
   

    uint32_t current_time = to_us_since_boot(get_absolute_time());
  
  if (current_time - last_time > 300000) {
     last_time = current_time;
   switch(gpio){
      case BUTTON_A:
       a++;
       break;
      case BUTTON_B:
       a--;
       break;
      default:
      break;
   }
    switch(a){
    case 0:
        A_0();
        break;
     case 1:
        A_1();
        break;
     case 2:
        A_2();
        break;
     case 3:
        A_3();
        break;
     case 4:
        A_4();
        break;
     case 5:
        A_5();
        break;
     case 6:
        A_6();
        break;
     case 7:
        A_7();
        break;
     case 8:
        A_8();
        break;
     case 9:
        A_9();
        break;
   
    default:
       a=0;
        break;
     
  }
  }
  
  

}




