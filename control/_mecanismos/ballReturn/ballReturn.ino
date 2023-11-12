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
    
    contadorLecturasAlta = 0 ;
    
    input = Serial.readString();  // Lee la cadena de caracteres desde el puerto serial
    input = input.substring(0, input.length() - 1); // Elimina el último carácter de la cadena "\n"

    //Si recibo por serial "BR" activo Ball Return
    if(input == "BR"){
        
        //Activar Ball Return
        digitalWrite(BALL_RETURN, HIGH);
        delay(50);
        digitalWrite(BALL_RETURN,LOW);
        delay(50); 
    }

    if( digitalRead(BALL_RETURN_FBK)){

        IMPRIMIR("Bola detectada");
        // Sumar varias lecturas para darla por válida después de haber leído la primera
        for (int i = 0; i < 10; i++) {
            if (digitalRead(BALL_RETURN_FBK) == HIGH) {
            contadorLecturasAlta++;
            delay(5);  // Espera 5 ms entre lecturas
            }
        }

        Serial.print("Cantidad de lecturas: ");
        Serial.println(contadorLecturasAlta);
    
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
