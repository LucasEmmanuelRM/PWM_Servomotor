Este código foi desenvolvido segundo a atividade do capítulo 7 - unidade 4 do Embarcetch (CEPEDI). Trata-se de um experimento utilizando conhecimentos básicos de PWM (Modulação por Largura de Onda) para movimentar o ângulo de um servomotor ou alterar a intensidade de um LED.

A atividade apresenta 6 grandes objetivos:
- 1º: Definir a frequência de PWM do pino utilizado para, aproximadamente, 50Hz – período de 20ms;
- 2º: Iniciar com um duty cycle de 0,12% (2,4ms), posicionando o braço do servomotor em 180°, e aguardar 5 segundos;
- 3º: Alterar o duty cycle para 0,0735% (1,47ms), posicionando o braço do servomotor em 90°, e aguardar 5 segundos;
- 4º: Alterar novamente o duty cycle, agora para 0,025% (0,5ms), posicionando o braço do servomotor em 0°, e aguardar 5 segundos;
- 5º: Criar uma rotina que faça o duty cycle alternar entre 0,12% e 0,025% através de um incremento de 0,00025% (0,005ms), o que fará o rotacionamento periódico e gradual do braço entre 0 e 180° a cada 10ms;
- 6º: Utilizar a BitDogLab para experimentar o código no LED RGB na cor azul.

Para a definição da frequência de pwm, foi utilizada a fórmula simplificada **Fpwm = Fclock / (Div_Clock * Wrap)**.
Os valores do divisor do clock e de wrap podem ser definidos quase que arbitrariamente para alcançar os 50Hz, desde que obedeçam o intevalo de valores possíveis para eles, e a combinação escolhida foi de Wrap = 25.000 e Divisor de Clock = 100,0;
Assim, com uma frequência de clock de 125MHz para a Raspberry Pi Pico W (RP2040), temos Fpwm = 125.000.000 / 25.000.000 = 50Hz ou 20ms.

A partir desse passo, os próximos foram apenas uma questão de multiplicar o valor escolhido de Wrap pela porcentagem de duty cycle desejado para obter, na ordem dos objetivos, 3.000, 1837.5 e 625 de duty cycle.
Em seguida, para a rotação periódica, basta estabelecer um incremento ou decremento de 6 (0,00025% de 25.000 ≈ 6) no duty cycle para fazê-lo ir e voltar entre os ângulos de 0° e 180°.
Essa rotação gradual e periódica é a única a ficar dentro do loop infinito, pois as mudanças anteriores devem ser realizadas uma única vez.

A visualização do funcionamento do código com um servomotor pode ser visto na simulação o Wokwi.
Para empregar o uso da BitDogLab e experimentar o código em seu LED, é necessário apenas trocar o pino a ser utilizado de pwm no início do código, onde será visível as alterações na intensidade da cor do LED.

Um vídeo demonstrativo pode ser acessado no seguinte link:
[https://drive.google.com/file/d/1hAuDUHE8lAct18I1QrjPOYQW_kboj7km/view?usp=sharing]
