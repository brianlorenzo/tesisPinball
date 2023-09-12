#include <WiFi.h>

//valores de ejemplo para conectarse a un AP
const char* ssid = "Caliope";         // Reemplaza con el nombre de tu red Wi-Fi
const char* password = "nohaylugar"; // Reemplaza con la contraseña de tu red Wi-Fi

WiFiServer server(80); // Crea un servidor en el puerto 80

void setup() {
  // Inicializa la conexión Wi-Fi
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a Wi-Fi...");
  }

  Serial.println("Conexión Wi-Fi establecida");


  server.begin(); // Inicia el servidor
  Serial.println("Servidor iniciado");

}

void loop() {
  


  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Conexión Wi-Fi perdida, intentando reconectar...");
    WiFi.reconnect();
    delay(5000); // Espera 5 segundos antes de intentar nuevamente
  }


}


WiFiClient client = server.available();
  if (client) {
  Serial.println("Nueva conexión");
  
  while (client.connected()) {
      if (client.available()) {
        String command = client.readStringUntil('\n'); // Lee el comando hasta que se reciba un salto de línea
        command.trim(); // Elimina espacios en blanco adicionales

        // Verifica el comando recibido y ejecuta una acción
        if (command == "FD") {
          // Ejecuta una acción para encender algo
          Serial.println("Activar Flipper Derecho");
          // Aquí puedes agregar tu código para encender un dispositivo
        } else if (command == "FI") {
          // Ejecuta una acción para apagar algo
          Serial.println("Activar Flipper Izquierdo");
          // Aquí puedes agregar tu código para apagar un dispositivo
        } else {
          // Comando desconocido
          Serial.println("Comando desconocido: " + command);
  
  
  
  
  
  
  }
  
  // Maneja la conexión del cliente aquí
  client.stop();            // Cierra la conexión
  Serial.println("Conexión cerrada");