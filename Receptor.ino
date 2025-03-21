const int rxPin = 8;
const unsigned int halfPeriod = 500; 

void setup() {
  Serial.begin(9600);
  pinMode(rxPin, INPUT);
}

// Função para ler um bit
bool readManchesterBit() {
  // Armazena o estado atual
  int initialState = digitalRead(rxPin);
  // Espera uma mudança de estado
  while (digitalRead(rxPin) == initialState) {
    // Loop para detectar a transição
  }
  
  // Após detectar a transição, aguarda meio período
  unsigned long startTime = micros();
  while (micros() - startTime < halfPeriod / 2) {
  
  }
  bool firstHalf = digitalRead(rxPin);
  
  // Agora espera pelo restante
  startTime = micros();
  while (micros() - startTime < halfPeriod) {
    
  }
  bool secondHalf = digitalRead(rxPin);
  
  // Decodificação Manchester
  if (firstHalf == HIGH && secondHalf == LOW)
    return 0;
  else if (firstHalf == LOW && secondHalf == HIGH)
    return 1;
  else
    return 0; 
}

// Lê 8 bits a partir dos sinais recebidos
byte readManchesterByte() {
  byte incomingByte = 0;
  for (int i = 7; i >= 0; i--) {
    bool bitVal = readManchesterBit();
    bitWrite(incomingByte, i, bitVal);
  }
  return incomingByte;
}

void loop() {
  // Primeiramente, lê e descarta o pré-ambulo para sincronização
  byte preamble = readManchesterByte();
  // Agora lê o byte real de dados
  byte receivedMessage = readManchesterByte();
  Serial.print("Mensagem recebida: 0x");
  Serial.println(receivedMessage, HEX);
}
