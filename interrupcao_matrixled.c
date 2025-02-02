#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "interrupcao_matrixled.h"

/*OBS: ABAIXEI A INTENSIDADE DAS ANIMAÇÕES DA MATRIZ DE LED 5X5 PORQUE QUANDO 
RODA NA PLACA, A INTENSIDADE É MUITO FORTE E INCOMODA UM POUCO, 
ENTÃO NA SIMULAÇÃO VAI FICAR UM POUCO CLARO, MAS DA PRA VER, E NA PLACA TAMBEM.*/

const uint LED_RED = 13;
const uint LED_BLUE = 12;
const uint LED_GREEN = 11;
const uint BUTTON_A = 5;
const uint BUTTON_B = 6;

#define tempo 200
static volatile uint32_t last_time = 0; //para fazer o debounce
 static volatile uint a = 0; //contador

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
    init_gpios(); //inicializa gpios.
    initNeoPixel(); //inicializa matrix de Led 5x5.
    stdio_init_all();

    gpio_set_irq_enabled_with_callback(BUTTON_A, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler); // configura a interrupção e exuta a interrupção.
     gpio_set_irq_enabled_with_callback(BUTTON_B, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);// configura a interrupção e exuta a interrupção.


    while (true) { //loop infinto.
        printf("A= %d \n",a);
        //o led vai piscar 5 vezes por segundo.
        gpio_put(LED_RED,true);
        sleep_ms(200);
        gpio_put(LED_RED,false);
        sleep_ms(200);


    }
}

void gpio_irq_handler(uint gpio, uint32_t events){ //definido manualmente para tratar eventos de interrupção.
   

    uint32_t current_time = to_us_since_boot(get_absolute_time());
  
  if (current_time - last_time > 300000) { //debounce
     last_time = current_time;
   switch(gpio){ //caso seja botão A, vai incrementar +1 em a, caso seja botão B, vai decrementar -1 em a.
      case BUTTON_A:
       a++;
       break;
      case BUTTON_B:
       a--;
       break;
      default:
      break;
   }
    switch(a){ // quando o contador a vai alterandoo valor, vai sicronizando com os botões.
    case 0:
        A_0(); //função void que implementa uma imagem na matrix de LED 5x5.
        break;
     case 1:
        A_1(); //função void que implementa uma imagem na matrix de LED 5x5.
        break;
     case 2:
        A_2(); //função void que implementa uma imagem na matrix de LED 5x5.
        break;
     case 3:
        A_3(); //função void que implementa uma imagem na matrix de LED 5x5.
        break;
     case 4:
        A_4(); //função void que implementa uma imagem na matrix de LED 5x5.
        break;
     case 5:
        A_5(); //função void que implementa uma imagem na matrix de LED 5x5.
        break;
     case 6:
        A_6(); //função void que implementa uma imagem na matrix de LED 5x5.
        break;
     case 7:
        A_7(); //função void que implementa uma imagem na matrix de LED 5x5.
        break;
     case 8:
        A_8(); //função void que implementa uma imagem na matrix de LED 5x5.
        break;
     case 9:
        A_9(); //função void que implementa uma imagem na matrix de LED 5x5.
        break;
   
    default:
       a=0; //caso seja diferente dos numero 0 a 9, o contador zera pra ficar em um loop.
        break;
     
  }
  }
  
  

}




