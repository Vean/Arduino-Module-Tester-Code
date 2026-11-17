/*------------------------------------------------------------------------------
  Universal Blink Tester Board - Uji Blink Semua Board MCU
  - Irfan Indra Kurniawan @Vean
  - www.fanselectronics.com
*/

// EN: Automatic board architecture and built-in LED pin detection
// ID: Deteksi otomatis arsitektur board dan pin LED bawaan
#if defined(ESP32)
#if CONFIG_IDF_TARGET_ESP32C3
// EN: ESP32-C3 SuperMini / DevKit typically uses GPIO 8 with Active-Low logic
// ID: ESP32-C3 SuperMini / DevKit umumnya menggunakan GPIO 8 dengan logika Active-Low
#define TEST_LED_PIN 8
#define LED_ACTIVE_LOW true
#elif CONFIG_IDF_TARGET_ESP32S3
// EN: ESP32-S3 boards use built-in LED definition or fallback to GPIO 2
// ID: Board ESP32-S3 menggunakan definisi LED bawaan atau cadangan ke GPIO 2
#if defined(LED_BUILTIN)
#define TEST_LED_PIN LED_BUILTIN
#else
#define TEST_LED_PIN 2
#endif
#define LED_ACTIVE_LOW false
#elif CONFIG_IDF_TARGET_ESP32S2
// EN: ESP32-S2 boards typically map the onboard LED to GPIO 15
// ID: Board ESP32-S2 umumnya memetakan LED bawaan ke GPIO 15
#define TEST_LED_PIN 15
#define LED_ACTIVE_LOW false
#elif defined(CAMERA_MODEL_AI_THINKER) || defined(BOARD_ESP32CAM_AITHINKER)
// EN: AI-Thinker ESP32-CAM uses GPIO 33 for the rear red status LED (Active-Low)
// ID: AI-Thinker ESP32-CAM menggunakan GPIO 33 untuk LED status merah di belakang (Active-Low)
#define TEST_LED_PIN 33
#define LED_ACTIVE_LOW true
#else
// EN: Standard ESP32 DevKit V1 (30/38-pin) uses GPIO 2 with Active-High logic
// ID: ESP32 DevKit V1 standar (30/38-pin) menggunakan GPIO 2 dengan logika Active-High
#if defined(LED_BUILTIN)
#define TEST_LED_PIN LED_BUILTIN
#else
#define TEST_LED_PIN 2
#endif
#define LED_ACTIVE_LOW false
#endif

#elif defined(ESP8266)
// EN: NodeMCU V2/V3 and Wemos D1 Mini use GPIO 2 (D4) with Active-Low logic
// ID: NodeMCU V2/V3 dan Wemos D1 Mini menggunakan GPIO 2 (D4) dengan logika Active-Low
#if defined(LED_BUILTIN)
#define TEST_LED_PIN LED_BUILTIN
#else
#define TEST_LED_PIN 2
#endif
#define LED_ACTIVE_LOW true

#elif defined(__AVR__)
// EN: Arduino Uno, Nano, Mega, and Pro Mini use digital pin 13 with Active-High logic
// ID: Arduino Uno, Nano, Mega, dan Pro Mini menggunakan pin digital 13 dengan logika Active-High
#if defined(LED_BUILTIN)
#define TEST_LED_PIN LED_BUILTIN
#else
#define TEST_LED_PIN 13
#endif
#define LED_ACTIVE_LOW false

#else
// EN: Fallback configuration for other boards such as STM32 or RP2040
// ID: Konfigurasi cadangan untuk board lain seperti STM32 atau RP2040
#if defined(LED_BUILTIN)
#define TEST_LED_PIN LED_BUILTIN
#else
#define TEST_LED_PIN 13
#endif
#define LED_ACTIVE_LOW false
#endif

// EN: Helper function to abstract Active-High and Active-Low LED switching
// ID: Fungsi bantu untuk menyamakan logika penyalaan LED Active-High dan Active-Low
void setLed(bool state) {
  if (LED_ACTIVE_LOW) {
    digitalWrite(TEST_LED_PIN, state ? LOW : HIGH);
  } else {
    digitalWrite(TEST_LED_PIN, state ? HIGH : LOW);
  }
}

// EN: Initialize serial communication, configure LED pin, and print board diagnostics
// ID: Inisialisasi komunikasi serial, atur pin LED, dan tampilkan info diagnostik board
void setup() {
  Serial.begin(115200);
  pinMode(TEST_LED_PIN, OUTPUT);
  setLed(false);

  // EN: Short delay so the Serial Monitor captures the startup banner after USB connection
  // ID: Jeda singkat agar Serial Monitor sempat menangkap teks awal setelah USB terhubung
  delay(500);
  Serial.println("\n=========================================");
  Serial.println("FANS ELECTRONICS - QC LED TEST STARTED");
  Serial.print("Target Pin GPIO : ");
  Serial.println(TEST_LED_PIN);
  Serial.print("LED Logic       : ");
  Serial.println(LED_ACTIVE_LOW ? "ACTIVE LOW" : "ACTIVE HIGH");
  Serial.println("=========================================");
}

// EN: Execute a distinct double-blink heartbeat pattern to verify successful firmware upload
// ID: Jalankan pola kedip ganda untuk memastikan proses upload firmware berhasil menimpa program lama
void loop() {
  // EN: First quick pulse ON and OFF
  // ID: Kedipan cepat pertama NYALA lalu MATI
  setLed(true);
  Serial.println("[QC] LED ON");
  delay(150);

  setLed(false);
  Serial.println("[QC] LED OFF");
  delay(150);

  // EN: Second quick pulse followed by a longer pause
  // ID: Kedipan cepat kedua diikuti jeda mati yang lebih lama
  setLed(true);
  delay(150);

  setLed(false);
  delay(800);
}