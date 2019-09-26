#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

//wi-fi e autenticação no Firebase
#define FIREBASE_HOST "https://casa-6f76f.firebaseio.com/"
#define FIREBASE_AUTH "AHIZt9x6KtwxehbaCRvyPzrirg1FKiZuVvCkwYvw"
#define WIFI_SSID "ifdoce"
#define WIFI_PASSWORD "10tifsul"

//mapeamento de portas
#define LED_AZUL 2
#define LED_VERMELHO 16

void autenticarFirebase(){
  //autentica e inicializa o serviço de Realtimedatabase do Firebase
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void conectarWiFi(){
  //conecta com o wifi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("\nconnecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  autenticarFirebase();
}

void setup() {
  //inicializa a comunicação serial com o monitor da IDE
  Serial.begin(9600);
  
  pinMode(LED_AZUL, OUTPUT); //led buit in azul
  pinMode(LED_VERMELHO, OUTPUT); //led buit in vermelho 

  conectarWiFi();
  
}

void loop() {
  if(WiFi.status() == WL_CONNECTED) {
    if(Firebase.success()) {
      FirebaseObject casa = Firebase.get("casa");
      
      if(casa.getBool("/ledAzul")) {
        digitalWrite(LED_AZUL, LOW);
        Serial.println("Led azul ligado.");
      } else {
        digitalWrite(LED_AZUL, HIGH);
        Serial.println("Led azul desligado.");
      }
      
      if(casa.getBool("/ledVermelho")) {
        digitalWrite(LED_VERMELHO, LOW);
        Serial.println("Led vermelho ligado.");
      } else {
        digitalWrite(LED_VERMELHO, HIGH);
        Serial.println("Led vermelho desligado.");
      }

      if(casa.getBool("/area/lampada")) {
        Serial.println("Lampada da Area: ligada.");
      } else {
        Serial.println("Lampada da Area: desligada.");
      }

      if(casa.getBool("/banheiro/lampada")) {
        Serial.println("Lampada do Banheiro: ligada.");
      } else {
        Serial.println("Lampada do Banheiro: desligada.");
      }

      if(casa.getBool("/circulacao/lampada")) {
        Serial.println("Lampada do Corredor: ligada.");
      } else {
        Serial.println("Lampada do Corredor: desligada.");
      }

      if(casa.getBool("/cozinha/lampada")) {
        Serial.println("Lampada da Cozinha: ligada.");
      } else {
        Serial.println("Lampada da Cozinha: desligada.");
      }

      if(casa.getBool("/dormitorio1/lampada")) {
        Serial.println("Lampada do Dormitorio1: ligada.");
      } else {
        Serial.println("Lampada do Dormitorio1: desligada.");
      }
      if(casa.getBool("/dormitorio1/hvac")) {
        Serial.println("Ar-condicionado do Dormitorio1: ligado.");
      } else {
        Serial.println("Ar-condicionado do Dormitorio1: desligado.");
      }

      if(casa.getBool("/dormitorio1/lampada")) {
        Serial.println("Lampada do Dormitorio1: ligada.");
      } else {
        Serial.println("Lampada do Dormitorio1: desligada.");
      }
      if(casa.getBool("/dormitorio1/hvac")) {
        Serial.println("Ar-condicionado do Dormitorio1: ligado.");
      } else {
        Serial.println("Ar-condicionado do Dormitorio1: desligado.");
      }

      if(casa.getBool("/dormitorio2/lampada")) {
        Serial.println("Lampada do Dormitorio2: ligada.");
      } else {
        Serial.println("Lampada do Dormitorio2: desligada.");
      }
      if(casa.getBool("/dormitorio2/hvac")) {
        Serial.println("Ar-condicionado do Dormitorio2: ligado.");
      } else {
        Serial.println("Ar-condicionado do Dormitorio2: desligado.");
      }

      if(casa.getBool("/dormitorio3/lampada")) {
        Serial.println("Lampada do Dormitorio3: ligada.");
      } else {
        Serial.println("Lampada do Dormitorio3: desligada.");
      }
      if(casa.getBool("/dormitorio3/hvac")) {
        Serial.println("Ar-condicionado do Dormitorio3: ligado.");
      } else {
        Serial.println("Ar-condicionado do Dormitorio3: desligado.");
      }
      
    } else {
      Serial.println("Erro na autenticão com o Firebase");
    }
  } else {
    conectarWiFi();
  }
  
  delay(500);
}
