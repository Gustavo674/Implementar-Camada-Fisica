# Simulador-de-dispositivos-IoT

## Descrição
Este projeto implementa uma camada física de comunicação entre dois microcontroladores (Arduino) utilizando um protocolo com codificação Manchester. O sistema transmite mensagens com 4 tipos distintos: INIT, DATA, ACK e ERROR.

## Arquivos do Projeto
- `Transmissor.ino`: Código-fonte para o Arduino que envia as mensagens com codificação Manchester.
- `Receptor.ino`: Código-fonte para o Arduino que recebe e decodifica as mensagens.

## Funcionamento
1. **Transmissor:**
   - Envia um pré-âm­bu­lo para sincronizar o receptor.
   - Em seguida, envia uma das 4 mensagens definidas (por exemplo, INIT, DATA, ACK, ERROR).
   - A codificação Manchester é utilizada para garantir transições e facilitar a sincronização.

2. **Receptor:**
   - Lê e descarta o pré-âm­bu­lo para se sincronizar.
   - Recebe os dados reais e reconstrói o byte a partir dos bits amostrados.
   - Exibe o valor recebido no Monitor Serial.

## Configuração do Circuito
- **Conexões:**
  - **Transmissor:** Usa o pino digital 9 para transmissão (TX).
  - **Receptor:** Usa o pino digital 8 para recepção (RX).
  - **GND:** Certifique-se de que os Arduinos compartilhem o mesmo GND.

## Como Executar
1. Abra os arquivos `Transmissor.ino` e `Receptor.ino` na Arduino IDE.
2. Faça as conexões conforme descrito.
3. Carregue o código no respectivo Arduino.
4. Abra o Monitor Serial para visualizar as mensagens recebidas pelo receptor.

![image](https://github.com/user-attachments/assets/84121d3f-5219-4265-8bf6-a2a4790c5833)

![video](https://drive.google.com/file/d/1MlB-3Is6MAPtyLfKhe4MwVPOms2z_b_R/view?usp=sharing)
