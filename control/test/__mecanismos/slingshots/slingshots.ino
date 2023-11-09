#include <defines.h>

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


void loop(){
    input = Serial.readString();  // Lee la cadena de caracteres desde el puerto serial
    input = input.substring(0, input.length() - 1); // Elimina el último carácter de la cadena "\n"

    //Si recibo por serial "SD" activo Slingshot Derecho
    if(input == "SD"){
        
        //Activar Ball Return
        digitalWrite(SLINGSHOT_DERECHO, HIGH);
        delay(50);
        digitalWrite(SLINGSHOT_DERECHO,LOW);
        delay(50); 
    }

    //Si se activa feedback derecho -> activo slingshot derecho
    if( digitalRead(SLINGSHOT_DERECHO_FBK)){
       
       //Activar Ball Return
        digitalWrite(SLINGSHOT_DERECHO, HIGH);
        delay(50);
        digitalWrite(SLINGSHOT_DERECHO,LOW);
        delay(50); 
    }

    //Si recibo por serial "SI" activo Slingshot Izquierdo
    if(input == "SI"){
        
        //Activar Ball Return
        digitalWrite(SLINGSHOT_IZQUIERDO, HIGH);
        delay(50);
        digitalWrite(SLINGSHOT_IZQUIERDO,LOW);
        delay(50); 
    }
    //Si se activa feedback izquierdo -> activo slingshot izquierdo
    if( digitalRead(SLINGSHOT_IZQUIERDO_FBK)){
       
       //Activar Ball Return
        digitalWrite(SLINGSHOT_IZQUIERDO, HIGH);
        delay(50);
        digitalWrite(SLINGSHOT_IZQUIERDO,LOW);
        delay(50); 
    }
        
}

    

