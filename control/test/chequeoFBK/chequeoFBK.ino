#include <defines.h>

// Uso general: al querer usar tal mecanismo 
/*
    Recibo orden de activar Mecanismo (por serial, por ISR, por chequeo pooling, por circuito)
    Activo Mecanismo
    Chequeo FBK Mecanismo
    Sumo score mecanismo
    Hago log mecanismo

    ...vuelvo a esperar recibir orden
*/

#define FBK_OK IMPRIMIR("Feedback correcto")
#define FBK_ERROR IMPRIMIR("Feedback INCORRECTO, no se pudo detectar")
#define tiempoFBK 100 //Tiempo de delay para esperar feedback (us)

void chequeoFBK(int PIN_MECANISMO_FBK) {
    if (digitalRead(PIN_MECANISMO_FBK)) {
        // Si recibo el FBK correctamente, determino FBK OK
        FBK_OK;
    } else {
        // Si no recibo FBK correctamente, espero un tiempo y vuelvo a intentar una vez más
        delay(tiempoFBK);
        if (digitalRead(PIN_MECANISMO_FBK)) {
            FBK_OK;
        } else {
            FBK_ERROR;
        }
    }
}

/*
void chequeoFBK(int PIN_MECANISMO_FBK) {
    (digitalRead(PIN_MECANISMO_FBK) ? FBK_OK : (delay(tiempoFBK), digitalRead(PIN_MECANISMO_FBK) ? FBK_OK : FBK_ERROR));
}
*/

/*
boolean chequeoFBK (int PIN_MECANISMO_FBK){
    if (digitalRead(PIN_MECANISMO_FBK)){
    // Si recibo el FBK correctamente determino FBK OK
        FBK_OK;
        return true; 
    }
    else{
    // Si no recibo FBK correctamente espero un tiempo y vuelvo a intentar una vez más   
        delay(tiempoFBK);
        if(digitalRead(PIN_MECANISMO_FBK)){
            FBK_OK; 
            return true;
        }
        else{
            FBK_ERROR;
            return false;
        }    
    }  
}
*/