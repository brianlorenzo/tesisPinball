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


String input;               // Variable para lectura de puerto serial
String input_old = "xxxxx"; // Variable para comparar

int tdelay = 300; //tiempo de delay
void loop(){
    
    
    while (Serial.available() > 0) {  // Verifica si hay datos disponibles en el puerto serial
        input = Serial.readString();  // Lee la cadena de caracteres desde el puerto serial
        input = input.substring(0, input.length() - 1); // Elimina el último carácter de la cadena "\n"
        
        IMPRIMIR("Comando recibido: " + input);

        //Si recibi algo NUEVO
        if (input != input_old){
            input_old = input ;
            IMPRIMIR("nuevo delay:  " + input);

            tdelay = input.toInt();
            
            //activo
            for (int i = 0; i < 4; i++){
                digitalWrite(FLIPPER_DERECHO,HIGH);
                delay(tdelay);
                chequeoFBK(FLIPPER_DERECHO_FBK);
                digitalWrite(FLIPPER_DERECHO,LOW);

                Serial.print("#");
                Serial.println(i+1);
                delay(1000);
            }
        }



    }
}
