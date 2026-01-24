#include <WiFi.h>
#include <WebServer.h>

// ==========================================
// KONFIGURASI WIFI
// ==========================================
const char* ssid = "NAMA_WIFI_ANDA";
const char* password = "PASSWORD_WIFI_ANDA";

// ==========================================
// KONFIGURASI HARDWARE
// ==========================================
// Jika menggunakan ESP32-CAM, LED Flash biasanya di GPIO 4
// Jika menggunakan ESP32 Devkit biasa, Built-in LED biasanya GPIO 2
#define LED_PIN 4 

WebServer server(80);

// Status variabel
unsigned long lastPresenceTime = 0;
const long ledDuration = 3000; // LED menyala selama 3 detik setelah presensi berhasil
bool isLedOn = false;

void setup() {
  Serial.begin(115200);
  
  // Setup LED
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  // Setup WiFi
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // Setup Routes
  server.on("/", handleRoot);
  server.on("/presensi", handlePresensi); // Endpoint untuk menerima data presensi
  
  // Enable CORS (Penting agar bisa diakses dari browser laptop)
  server.enableCORS(true);

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
  handleLedTimer();
}

// Handler untuk root
void handleRoot() {
  server.send(200, "text/plain", "ESP32 Presence System Ready");
}

// Handler saat presensi valid diterima dari Web
void handlePresensi() {
  addCorsHeaders(); // Tambahkan header CORS
  
  Serial.println("Presensi Valid Diterima!");
  
  // Nyalakan LED
  digitalWrite(LED_PIN, HIGH);
  isLedOn = true;
  lastPresenceTime = millis();
  
  server.send(200, "application/json", "{\"status\":\"success\", \"message\":\"Presensi Berhasil, LED Menyala\"}");
}

// Logic untuk mematikan LED otomatis setelah beberapa detik
void handleLedTimer() {
  if (isLedOn && (millis() - lastPresenceTime >= ledDuration)) {
    digitalWrite(LED_PIN, LOW);
    isLedOn = false;
    Serial.println("LED Mati (Auto-off)");
  }
}

// Helper untuk CORS
void addCorsHeaders() {
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.sendHeader("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
  server.sendHeader("Access-Control-Allow-Headers", "Content-Type");
}
