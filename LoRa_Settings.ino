// Ардуино МЕГА


void setup()
{
  Serial.begin(9600);
  Serial3.begin(9600);

  
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  
  delay(2000);
  
  Serial3.write(0xC0); // C0 - сохранить настройки, C2 - сбросить после отключения от питания
  Serial3.write(0x0);  // Верхний байт адреса. Если оба байта 0xFF - передача и прием по всем адресам на канале
  Serial3.write(0x0);  // Нижний байт адреса. Если оба байта 0xFF - передача и прием по всем адресам на канале
  Serial3.write(0x18); // Параметры скорости
  Serial3.write(0x06); // Канал (частота), 0x06 - 868 МГц, шаг частоты - 1 МГц (0x07 - 869 МГц)
  Serial3.write(0x44); // Служебные опции
}

void loop()
{
 delay(2000);
 Serial3.write(0xC1);
 Serial3.write(0xC1);
 Serial3.write(0xC1);
  
 while(Serial3.available())
 {
  int inByte = Serial3.read();
  Serial.print(inByte, HEX);
  Serial.print(" ");
 }
 Serial.println(); 
}
