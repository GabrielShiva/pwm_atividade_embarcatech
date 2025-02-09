# Controle de Servo Motor via PWM com Raspberry Pi Pico

Este projeto faz parte do capítulo 7 do curso **Embarcatech Unity 4**, onde exploramos o controle de um servo motor utilizando PWM (Modulação por Largura de Pulso) com a placa **Raspberry Pi Pico**. O código foi desenvolvido em C e utiliza a biblioteca `pico-sdk` para configurar e controlar o servo motor.

## Descrição do Projeto

O objetivo deste projeto é demonstrar como controlar um servo motor utilizando PWM. O servo motor é controlado por pulsos de largura variável, onde a largura do pulso determina a posição do eixo do motor. O código implementado permite que o servo motor se mova entre três posições principais: 0°, 90° e 180°, e também realiza um movimento contínuo entre essas posições.

## Configuração do Hardware

- **Raspberry Pi Pico**: Microcontrolador utilizado para gerar os sinais PWM.
- **Servo Motor**: Conectado ao pino GPIO 12 (ou 22, conforme definido no código).
- **LED Azul (opcional)**: Conectado ao pino GPIO 12 para testes visuais.

## Configuração do Software

O código foi desenvolvido utilizando a linguagem C e a biblioteca `pico-sdk`. Abaixo estão as principais configurações e funções implementadas:

### Definições e Constantes

- **SERVO_PIN**: Define o pino GPIO conectado ao servo motor (ou LED para testes).
- **PULSE_PERIOD_US**: Período do pulso PWM em microssegundos (20ms para servo motores padrão).
- **PWM_CLK_DIVISER**: Divisor de clock para ajustar a frequência do PWM.
- **PWM_WRAP**: Valor máximo do contador PWM.

### Funções Principais

- **set_position**: Calcula a largura do pulso ativo com base no tempo fornecido e aplica esse valor ao canal PWM.
- **pwm_setup**: Configura o PWM para o pino especificado, definindo o divisor de clock, o valor máximo do contador e habilitando o PWM.

### Funcionamento do Código

1. **Inicialização**: O sistema de I/O é inicializado e o PWM é configurado para operar a 50Hz.
2. **Posicionamento do Servo**: O servo motor é movido para três posições distintas (0°, 90° e 180°) com um intervalo de 5 segundos entre cada movimento.
3. **Movimento Contínuo**: Após os movimentos iniciais, o servo motor começa a se mover continuamente entre 0° e 180° em incrementos de 5μs, com um intervalo de 10ms entre cada movimento.

## Como Utilizar

Para vizualizar na placa BITDOGLAB, descomente a linha que define a GPIO 12 e comente a linha que define a GPIO 22

### Compilação e Upload
1. Clone o repositório utilizando o comando abaixo.
```
git clone https://github.com/GabrielShiva/pwm_atividade_embarcatech.git
```
2. No VsCode, clique na extensão `Raspberry Pi Pico W`, depois em *Importar Projeto*, selecione a pasta do projeto, escolha a versão do SDK (2.1.0) e, por fim, em *Importar*.

## Vídeo de Apresentação

Assita ao vídeo com a apresentação do projeto (clicando aqui)[https://youtu.be/MyNR6LphnCY].
