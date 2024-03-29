#include <defines.h>

#define READ_TH 8100

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

String input; 
int contadorLecturasAlta = 0;
int lecturasValidas = 0;
bool lecturaAlta = false;

int sdFbk;
int siFbk;

void loop(){
    input = Serial.readString();  // Lee la cadena de caracteres desde el puerto serial
    input = input.substring(0, input.length() - 1); // Elimina el último carácter de la cadena "\n"

    if(input == "SL"){
        digitalWrite(SLINGSHOT_DERECHO,HIGH);
        digitalWrite(SLINGSHOT_IZQUIERDO,HIGH);

        IMPRIMIR("Modo 25 segundos de HIGH en Slingshots");
        delay(25000);
        IMPRIMIR("Espero OFF");

        input = Serial.readString();  // Lee la cadena de caracteres desde el puerto serial
        input = input.substring(0, input.length() - 1); // Elimina el último carácter de la cadena "\n"

        while(input != "OFF"){
            input = Serial.readString();  // Lee la cadena de caracteres desde el puerto serial
            input = input.substring(0, input.length() - 1); // Elimina el último carácter de la cadena "\n"
        }
        
        digitalWrite(SLINGSHOT_DERECHO,HIGH);
        digitalWrite(SLINGSHOT_IZQUIERDO,HIGH);
        
    }
    //Slingshot siempre activos
    digitalWrite(SLINGSHOT_DERECHO,HIGH);
    digitalWrite(SLINGSHOT_IZQUIERDO,HIGH);

    sdFbk = analogRead(SLINGSHOT_DERECHO_FBK);
    siFbk = analogRead(SLINGSHOT_IZQUIERDO_FBK);

    Serial.print("Slingshot Derecho:    ");
    Serial.println(sdFbk);

    Serial.print("Slingshot Izquierdo:    ");
    Serial.println(siFbk);

    IMPRIMIR("--------------------------------------");
    delay(50);

 
    //Cuando detecto el feedback (un par de veces) desactivo para evitar arco fuga
    if( sdFbk > READ_TH){
       
        
        //Cuento un par de veces activo
        
        
        IMPRIMIR("Se activó:  SLINGSHOT DERECHO")
        delay(100);
        digitalWrite(SLINGSHOT_DERECHO,LOW);
        delay(100);
    }


    if(analogRead(SLINGSHOT_IZQUIERDO_FBK) > READ_TH ){
             
        //Cuento un par de veces activo
        
        
        IMPRIMIR("Se activó:  SLINGSHOT IZQUIERDO")
        delay(100);
        digitalWrite(SLINGSHOT_IZQUIERDO,LOW);
        delay(100);
    }


}
