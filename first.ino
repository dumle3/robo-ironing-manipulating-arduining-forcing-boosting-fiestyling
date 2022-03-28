/*
Энкодер:
  CLK и DT иногда ловят контакт с вращающимся диском с прорезями и дают 1.
    Подключение:
      CLK: A0, A2, A4
      DT:  A1, A3, A5
      GND
      VCC
      SW - кнопка, пока не используется(если что, не забыть подтяжку)
Серво:
  Если смотреть на вал сверху, а провода будут торчать вперёд, слева направо видим такое: сигнал, VCC, GND
    Подключение:
      сигнал: D9, D10, D11
      VCC
      GND
*/

#include <Servo.h>

#define servo1Pin 9
#define servo2Pin 10
#define servo3Pin 11 

Servo Servo1;
Servo Servo2;
Servo Servo3;

#define CLK1 A0                         // Указываем к какому выводу CLK энкодер подключен к Arduino
#define DT1 A1                          // Указываем к какому выводу DT энкодер подключен к Arduino
#define CLK2 A2                         // Указываем к какому выводу CLK энкодер подключен к Arduino
#define DT2 A3                          // Указываем к какому выводу DT энкодер подключен к Arduino
#define CLK3 A4                         // Указываем к какому выводу CLK энкодер подключен к Arduino
#define DT3 A5                          // Указываем к какому выводу DT энкодер подключен к Arduino
 
int counter1 = 0;                      // Создаем переменную counter
int currentStateCLK1;                  // Создаем переменную currentStateCLK
int lastStateCLK1;                     // Создаем переменную lastStateCLK
int counter2 = 0;                      // Создаем переменную counter
int currentStateCLK2;                  // Создаем переменную currentStateCLK
int lastStateCLK2;
int counter3 = 0;                      // Создаем переменную counter
int currentStateCLK3;                  // Создаем переменную currentStateCLK
int lastStateCLK3;
 
void setup() 
{
  Serial.begin(9600);                 // Создаем последовательную связь 

  pinMode(CLK1, INPUT);                // Указываем вывод CLK как вход
  pinMode(DT1, INPUT);                 // Указываем вывод DT как вход
  lastStateCLK1 = digitalRead(CLK1);    // Считываем значение с CLK

  pinMode(CLK2, INPUT);                // Указываем вывод CLK как вход
  pinMode(DT2, INPUT);                 // Указываем вывод DT как вход
  lastStateCLK2 = digitalRead(CLK2);    // Считываем значение с CLK

  pinMode(CLK3, INPUT);                // Указываем вывод CLK как вход
  pinMode(DT3, INPUT);                 // Указываем вывод DT как вход
  lastStateCLK3 = digitalRead(CLK3);    // Считываем значение с CLK

  Servo1.attach(servo1Pin);
  Servo2.attach(servo2Pin);
  Servo3.attach(servo3Pin);
}

void loop() 
{
// Считываем значение с CLK  
  currentStateCLK1 = digitalRead(CLK1);
// Проверяем изменилось ли соcтояние CLK
  if (currentStateCLK1 != lastStateCLK1 && currentStateCLK1 == 0)
    if (digitalRead(DT1) != currentStateCLK1)
      counter1 --;    
    else
      counter1 ++;
// Запопоследнее состояние CLK      
  lastStateCLK1 = currentStateCLK1;

// Считываем значение с CLK  
  currentStateCLK2 = digitalRead(CLK2);
// Проверяем изменилось ли соcтояние CLK
  if (currentStateCLK2 != lastStateCLK2 && currentStateCLK2 == 0)
    if (digitalRead(DT2) != currentStateCLK2)
      counter2 --;    
    else
      counter2 ++;
// Запопоследнее состояние CLK      
  lastStateCLK2 = currentStateCLK2;

// Считываем значение с CLK  
  currentStateCLK3 = digitalRead(CLK3);
// Проверяем изменилось ли соcтояние CLK
  if (currentStateCLK3 != lastStateCLK3 && currentStateCLK3 == 0)
    if (digitalRead(DT3) != currentStateCLK3)
      counter3 --;    
    else
      counter3 ++;
// Запопоследнее состояние CLK      
  lastStateCLK3 = currentStateCLK3;  

  Servo1.write((counter1+14)*180/14);
  Servo2.write((counter2+14)*180/14);
  Servo3.write((counter3+14)*180/14);
}
