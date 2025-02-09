#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define PWM_PIN 22  // 11, 12 ou 13 para LED RGB da BitDogLab ou 22 para servo motor na simulação

// Fpwm = Fclock / (wrap_period * pwm_div) = 50 Hz

const uint16_t wrap_period = 25000; // Valor máximo do contador - WRAP (Pode ir de 1 a 65535)
const float pwm_div = 100.0;        // Divisor do clock para o PWM (Pode ir de 1,0 a 255,9)
const uint16_t dc_step = 6;         // Passo de incremento/decremento para o duty cycle do LED ou servo motor
uint16_t duty_cycle = 3000;         // Nível inicial do pwm

void inicializar_PWM();

int main(){

    stdio_init_all();
    inicializar_PWM();

    // Movimentos iniciais entre 180º -> 90º -> 0º com intervalos de 5 segunds entre cada um
    pwm_set_gpio_level(PWM_PIN, duty_cycle);
    sleep_ms(5000);
    pwm_set_gpio_level(PWM_PIN, duty_cycle = 1837.5);
    sleep_ms(5000);
    pwm_set_gpio_level(PWM_PIN, duty_cycle = 625);
    sleep_ms(5000);

    uint16_t dc_level = 625;

    while (true) {
        for (; dc_level <= 3000; dc_level += dc_step){
            pwm_set_gpio_level(PWM_PIN, dc_level);
            sleep_ms(10);
        }
        for (; dc_level >= 625; dc_level -= dc_step){
            pwm_set_gpio_level(PWM_PIN, dc_level);
            sleep_ms(10);
        }
    }
}

void inicializar_PWM(){
    /// Inicializa o pino do PWM_PIN como PWW
    gpio_set_function(PWM_PIN, GPIO_FUNC_PWM);      // Habilitar o pino GPIO como PWM
    uint slice = pwm_gpio_to_slice_num(PWM_PIN);    // Obter o canal PWM da GPIO
    pwm_set_clkdiv(slice, pwm_div);                 // Define o divisor de clock do PWM
    pwm_set_wrap(slice, wrap_period);               // Definir o valor de wrap
    pwm_set_gpio_level(PWM_PIN, duty_cycle);        // Definir o ciclo de trabalho (duty cycle) do pwm
    pwm_set_enabled(slice, true);                   // Habilita o pwm no slice correspondente
}