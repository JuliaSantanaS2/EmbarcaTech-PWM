#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define PWM_PIN 22

const uint16_t WRAP_PERIOD = 4000; // Período do PWM
const float PWM_DIVISER = 3.0; // Divisor de Clock
const uint16_t PWM_STEP = 200; // Passo de incremento do PWM
uint16_t DUTY_CYCLE = 480; // Ciclo de Trabalho


// Função de configuração do PWM
void pwm_setup (){

    gpio_set_function(PWM_PIN, GPIO_FUNC_PWM);
    uint slice = pwm_gpio_to_slice_num(PWM_PIN);
    pwm_set_clkdiv(slice, PWM_DIVISER); // Divisor de Clock
    pwm_set_wrap(slice, WRAP_PERIOD); // Período do PWM
    pwm_set_gpio_level(PWM_PIN, DUTY_CYCLE); // Duty Cycle (Ciclo de Trabalho)
    pwm_set_enabled(slice, true); // Habilita o PWM

}


int main ()
{
    stdio_init_all();

    // Configuração do PWM
    pwm_setup ();


    while (true) {
        pwm_set_gpio_level(PWM_PIN, DUTY_CYCLE); 
        sleep_ms(5000);
        pwm_set_gpio_level(PWM_PIN, 480); // 180 graus
        sleep_ms(5000);    
        pwm_set_gpio_level(PWM_PIN, 300); // 90 graus
        sleep_ms(5000); 

  
    }
  
    return 0;
}