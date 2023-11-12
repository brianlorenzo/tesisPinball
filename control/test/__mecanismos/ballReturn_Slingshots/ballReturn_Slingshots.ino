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
    contadorLecturasAlta = 0;
    
    input = Serial.readString();  // Lee la cadena de caracteres desde el puerto serial
    input = input.substring(0, input.length() - 1); // Elimina el último carácter de la cadena "\n"

    if (input == "FD"){
        digitalWrite(FLIPPER_DERECHO, HIGH);
        delay(25);
        chequeoFBK(FLIPPER_DERECHO_FBK);
        digitalWrite(FLIPPER_DERECHO, LOW);
    }

    if (input == "FI") {
            digitalWrite(FLIPPER_IZQUIERDO, HIGH);
            delay(25);
            chequeoFBK(FLIPPER_IZQUIERDO_FBK);
            digitalWrite(FLIPPER_IZQUIERDO, LOW);
    }
    
    //Si recibo por serial "BR" activo Ball Return
    if(input == "BR"){
        
        //Activar Ball Return
        digitalWrite(BALL_RETURN, HIGH);
        delay(50);
        digitalWrite(BALL_RETURN,LOW);
        delay(50); 
    }


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

/*  Serial.print("Slingshot Derecho:    ");
    Serial.println(sdFbk);

    Serial.print("Slingshot Izquierdo:    ");
    Serial.println(siFbk);

    IMPRIMIR("--------------------------------------");
    //delay(50);
*/
 
    //Cuando detecto el feedback (un par de veces) desactivo para evitar arco fuga
    if( sdFbk > READ_TH){
       
        
        //Cuento un par de veces activo
        
        
        //IMPRIMIR("Se activó:  SLINGSHOT DERECHO")
        delay(100);
        digitalWrite(SLINGSHOT_DERECHO,LOW);
        delay(100);
    }


    if(analogRead(SLINGSHOT_IZQUIERDO_FBK) > READ_TH ){
             
        //Cuento un par de veces activo
        
        
        //IMPRIMIR("Se activó:  SLINGSHOT IZQUIERDO")
        delay(100);
        digitalWrite(SLINGSHOT_IZQUIERDO,LOW);
        delay(100);
    }


    if( digitalRead(BALL_RETURN_FBK)){

       // IMPRIMIR("Bola detectada");
        // Sumar varias lecturas para darla por válida después de haber leído la primera
        for (int i = 0; i < 10; i++) {
            if (digitalRead(BALL_RETURN_FBK) == HIGH) {
            contadorLecturasAlta++;
            delay(5);  // Espera 5 ms entre lecturas
            }
        }

       // Serial.print("Cantidad de lecturas: ");
       // Serial.println(contadorLecturasAlta);
    
        if (contadorLecturasAlta >= 10) {
            lecturasValidas++;
        } else {
            lecturasValidas = 0;
        }
    
        if (lecturasValidas > 0) {
            lecturaAlta = true;
           
        } else {
            lecturaAlta = false;
        }
        
        if (lecturaAlta) {
            //Activar Ball Return
            digitalWrite(BALL_RETURN, HIGH);
            delay(50);
            digitalWrite(BALL_RETURN,LOW);
            delay(50); 
        
        }
        
    }


}
