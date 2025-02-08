#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

// #define SERVO_PIN 12 // define o pino conectado ao LED azul para teste na placa BITDOGLAB
#define SERVO_PIN 22 // define o pino conectado ao servo motor

#define PULSE_PERIOD_US 20000 // período do pulso em microsegundos

const float PWM_CLK_DIVISER = 100.0;
const uint16_t PWM_WRAP = 24999;
static uint channel = {0};
static uint slice = {0};

// calcula a largura de pulso (ativo) para o tempo (μs) fornecido, e aplica este valor para o slice (canal) fornecido
void set_position(uint slice, uint channel, uint pulse_us) {
    uint pulse_width = (pulse_us * PWM_WRAP) / PULSE_PERIOD_US;
    pwm_set_chan_level(slice, channel, pulse_width);
}

// configuração do PWM para o canal
void pwm_setup() {
    gpio_set_function(SERVO_PIN, GPIO_FUNC_PWM); // define o pino conectado ao servo como pwm
    slice = pwm_gpio_to_slice_num(SERVO_PIN); // obtem o slice PWM referente ao pino conectado ao servo
    channel = pwm_gpio_to_channel(SERVO_PIN); // obtem o canal PWM do pino 22

    pwm_set_clkdiv(slice, PWM_CLK_DIVISER); // define o divisor de clock do PWM (50Hz)
    pwm_set_wrap(slice, PWM_WRAP); // define o valor máximo do contador PWM
    pwm_set_enabled(slice, true);
}

int main() {
    stdio_init_all(); // inicializa o sistema padrão I/O
    pwm_setup(); // configuração do PWM para uma frequência de 50Hz

    // Define a posição de 180 graus
    set_position(slice, channel, 2400);
    sleep_ms(5000); // define atraso de 5 segundos para esperar na posição

    // Define a posição de 90 graus
    set_position(slice, channel, 1470);
    sleep_ms(5000); // define atraso de 5 segundos para esperar na posição

    // Define a posição de 0 graus
    set_position(slice, channel, 500);
    sleep_ms(5000); // define atraso de 5 segundos para esperar na posição

    while (true) {
        // define a posição para 0 graus (500μs) e incrementa este valor em 5μs enquanto não for maior que 2400μs (180 graus).
        // caso não seja maior que 2400, chama a função set_position para definir a posição do servo motor 
        for (int pulse_active = 500; pulse_active <= 2400; pulse_active = pulse_active + 5) { 
            set_position(slice, channel, pulse_active);
            sleep_ms(10); // define atraso de 10 milisegundos para esperar na posição
        }

        // define a posição para 180 graus (2400μs) e decrementa este valor em 5μs enquanto não for menor que 500μs (0 graus).
        // caso não seja menor que 500, chama a função set_position para definir a posição do servo motor 
        for (int pulse_active = 2400; pulse_active >= 500; pulse_active = pulse_active - 5) {
            set_position(slice, channel, pulse_active);
            sleep_ms(10); // define atraso de 10 milisegundos para esperar na posição
        }
    }

    return 0;
}
