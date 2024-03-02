/*Programa para crear un servidor de una pagina web con HTML
Con este programa tenemos el proposito de crear una red wifi con un nombre SSID 
determinado y una contraseña que se desee (dejar NULL si no 
se quiere poner contraseña) 
*/

#include <ESPAsyncWebSrv.h>
#include <WiFi.h>


const char *ssid = "Kratos"; //Nombre de la red a crear
const char *password = "PILARES1234"; // No hay contraseña

AsyncWebServer server(80);

void setup() {
  pinMode (15, OUTPUT);
  pinMode (2, OUTPUT);
  pinMode (4, OUTPUT);
  pinMode (16, OUTPUT);
  Serial.begin(115200);

  // Configurar el ESP32 como Access Point
  WiFi.softAP(ssid, password);

  // Obtener la dirección IP del Access Point
  IPAddress ip = WiFi.softAPIP();
  Serial.print("Dirección IP del Access Point: ");
  Serial.println(ip);

  // Ruta para manejar las solicitudes web
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    String html ="<html><body style='background-color:RGB(128,0,64); color: white;'><h1 style='font-size: 3em;'>PILARES</h1><button style='background-color: black; color:RGB(255,255,255); padding: 10px 20px; border: none; font-size: 1.5em;'>Avanzar</button><button style='background-color: black; color: RGB(255,255,255); padding: 10px 20px; border: none; font-size: 1.5em;'>Detener</button></body></html>";

    request->send(200, "text/html", html);
  });

  // Iniciar el servidor
  server.begin();

  
}

void loop() {
  // Codigo del main loop
}
