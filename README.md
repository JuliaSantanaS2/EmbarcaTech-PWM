# Controle de Servo Motor com Raspberry Pi Pico

Este projeto implementa o controle de um servo motor usando o Raspberry Pi Pico e a biblioteca de hardware PWM. 
Link do vídeo referente ao programa: https://youtu.be/4HRfO-mKsps 

## Funcionalidades
- Inicializa o PWM no pino **GPIO 22** para controlar o servo motor.
- Configura a frequência do PWM para **aproximadamente 50Hz**.
- Define posições específicas para o servo motor e movimenta ele entre essas posições.
- Implementa uma variação gradual do ângulo do servo usando as funções `ciclo_servo_part1` e `ciclo_servo_part2`.

## Como Usar
1. **Compilar o código** e carregar no Raspberry Pi Pico.
2. **Conectar um servo motor** ao pino **GPIO 22**.
3. **Observar o servo motor se movimentar** entre diferentes ângulos.
