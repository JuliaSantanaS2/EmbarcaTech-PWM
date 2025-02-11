#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"


#define PWM_PIN 22  // Pino do Servo Motor

const uint16_t WRAP_PERIOD = 25000; // Período para aproxidamente 50Hz
const float PWM_DIVISER = 125;     
const uint16_t STEP  = 5; 

// Definição dos pulsos corretos para o Servo
uint16_t SERVO_0  = 500;  // 0°  Graus

// Configuração do PWM para o Servo Motor
void pwm_setup_servo() {
    gpio_set_function(PWM_PIN, GPIO_FUNC_PWM);
    uint slice = pwm_gpio_to_slice_num(PWM_PIN);
    pwm_set_clkdiv(slice, PWM_DIVISER);
    pwm_set_wrap(slice, WRAP_PERIOD);
    pwm_set_gpio_level(PWM_PIN, SERVO_0);
    pwm_set_enabled(slice, true); // Ativa o PWM
}

// Função para mover o servo para um ângulo específico
void mover_servo(uint16_t duty) {
    pwm_set_gpio_level(PWM_PIN, duty);
    printf("Servo Posição: %d\n", duty);
    
}

void ciclo_servo_part1() {

    pwm_set_gpio_level(PWM_PIN, SERVO_0);
    printf("Servo Posição: %d\n", SERVO_0);
    SERVO_0 += STEP; // Incrementa o nível do LED
    sleep_ms(10);
    
}

void ciclo_servo_part2() {

    pwm_set_gpio_level(PWM_PIN, SERVO_0);
    printf("Servo Posição: %d\n", SERVO_0);
    SERVO_0 -= STEP; // Incrementa o nível do LED
    sleep_ms(10);
    

}

int main() {

    stdio_init_all();
    pwm_setup_servo();

    while (true) {

        // Movimento do Servo
        printf("Servo Posição: %d\n", SERVO_0);
        mover_servo(2400);
        sleep_ms(5000);
        mover_servo(1470);
        sleep_ms(5000);
        mover_servo(500);
        sleep_ms(5000);
       
        
        while (SERVO_0 < 2600) {
            ciclo_servo_part1();
        }

        while (500 < SERVO_0) {
            ciclo_servo_part2();
        }

    }

    return 0;
}
