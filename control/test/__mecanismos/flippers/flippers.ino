#include <defines.h>

//DELAY   10    PATADITA y a veces erra
//DELAY   15    NORMAL a veces hace PATADITA
//DELAY   20    NORMAL siempre
//DELAY   25    NORMAL y seguro

void setup() {
 
 //SERIAL
 Serial.begin(9600);
 IMPRIMIR(" ");
 IMPRIMIR("INICIALIZANDO");
 IMPRIMIR("Esperar 5 segundos");
 delay(5000);

 //PINES
 pinConfig();
  
}

void loop(){
    
    String input;   //Variable para lectura de puerto serial
    
    while (Serial.available() > 0) {  // Verifica si hay datos disponibles en el puerto serial
    input = Serial.readString();  // Lee la cadena de caracteres desde el puerto serial
    input = input.substring(0, input.length() - 1); // Elimina el último carácter de la cadena "\n"
    
    //Muestra lo que se recibió
    IMPRIMIR("Comando recibido: " + input);

    //Activa según comando recibido
    if (input == "FD"){
        digitalWrite(FLIPPER_DERECHO, HIGH);
        delay(25);
        chequeoFBK(FLIPPER_DERECHO_FBK);
        digitalWrite(FLIPPER_DERECHO, LOW);
    }
    else {
        if (input == "FI") {
            digitalWrite(FLIPPER_IZQUIERDO, HIGH);
            delay(25);
            chequeoFBK(FLIPPER_IZQUIERDO_FBK);
            digitalWrite(FLIPPER_IZQUIERDO, LOW);

        } else{
            IMPRIMIR("Comando no reconocido");
        }

      }
    }

}
