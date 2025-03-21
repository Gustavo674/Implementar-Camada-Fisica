const int txPin = 9;
const unsigned int halfPeriod = 500; 


byte messages[] = {0xA0, 0xB1, 0xC2, 0xD3};

void setup() {
  pinMode(txPin, OUTPUT);
  digitalWrite(txPin, LOW);
}

void sendBit(bool bit) {
  // Codificação Manchester:
  if (bit == 0) {
    digitalWrite(txPin, HIGH);
    delayMicroseconds(halfPeriod);
    digitalWrite(txPin, LOW);
    delayMicroseconds(halfPeriod);
  } else {
    digitalWrite(txPin, LOW);
    delayMicroseconds(halfPeriod);
    digitalWrite(txPin, HIGH);
    delayMicroseconds(halfPeriod);
  }
}

void sendByte(byte data) {
  // Envia os 8 bits do byte
  for (int i = 7; i >= 0; i--) {
    bool bitToSend = bitRead(data, i);
    sendBit(bitToSend);
  }
}

// Função para enviar um pré‐ambulo para sincronização
void sendPreamble() {
  sendByte(0xFF);
}

void loop() {
  // Para cada mensagem, envia primeiro um pré‐ambulo e depois a mensagem real
  for (int i = 0; i < 4; i++) {
    sendPreamble();     // Envia o pré‐ambulo para sincronizar o receptor
    sendByte(messages[i]); // Envia a mensagem de fato
    delay(1000); 
  }
}
