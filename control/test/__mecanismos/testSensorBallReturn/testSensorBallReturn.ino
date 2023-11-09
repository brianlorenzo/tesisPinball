#include <defines.h>

void setup() {
 
 //SERIAL
 Serial.begin(9600);
 IMPRIMIR(" ");
 IMPRIMIR("INICIALIZANDO");
 IMPRIMIR("Esperar 5 segundos");
 delay(5000);

 //PINES
 //pinConfig();
  pinMode(BALL_RETURN,OUTPUT);
  pinMode(BALL_RETURN_FBK,INPUT);
}
String input;
void loop(){
    input = Serial.readString();  // Lee la cadena de caracteres desde el puerto serial
    input = input.substring(0, input.length() - 1); // Elimina el último carácter de la cadena "\n"

    if (input == "BR"){
      digitalWrite(BALL_RETURN, HIGH);
      delay(50);
      digitalWrite(BALL_RETURN,LOW);
      delay(50);      
    }
    
    if(digitalRead(BALL_RETURN_FBK)){

      IMPRIMIR(" ON ");
    }
    else
    {
      IMPRIMIR("off");
    }
    delay(10);

}
