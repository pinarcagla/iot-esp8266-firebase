// Firebase Realtime Database'e bağlanıp veri gönderme
#include "arduino_secrets.h"

#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>

FirebaseData firebaseData;

void setup() {
    Serial.begin(9600);
    delay(1000);

    // WiFi bağlantısı
    Serial.print("WiFi'a bağlanıyor...");
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("\nWiFi bağlantısı başarılı!");
    Serial.print("IP adresi: ");
    Serial.println(WiFi.localIP());

    // Firebase bağlantısı
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
    Firebase.reconnectWiFi(true);

    Serial.println("Sistem hazır...");

    randomSeed(analogRead(0));
}

void loop() {

    int desibel = random(30, 100);

    Serial.print("Desibel: ");
    Serial.println(desibel);

    String status = "";
    bool success = true;

    if (desibel > 70) {
        status = "Gürültü kirliliği var!";

        if (!Firebase.setString(firebaseData, "/SoundPollution/Status", status)) {
            Serial.println(firebaseData.errorReason());
            success = false;
        }

        if (!Firebase.setInt(firebaseData, "/SoundPollution/HighDesibelValue", desibel)) {
            Serial.println(firebaseData.errorReason());
            success = false;
        }

    } else {
        status = "Gürültü kirliliği yok.";

        if (!Firebase.setString(firebaseData, "/SoundPollution/Status", status)) {
            Serial.println(firebaseData.errorReason());
            success = false;
        }
    }

    Firebase.setInt(firebaseData, "/SoundPollution/Desibel", desibel);

    if (!success) {
        Serial.println("Firebase hatası!");
    }

    delay(5000);
}