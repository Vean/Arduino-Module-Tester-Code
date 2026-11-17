# Arduino-Module-Tester-Code

![Platform](https://img.shields.io/badge/Platform-Arduino%20%7C%20ESP32%20%7C%20ESP8266-00979D?style=flat-square&logo=arduino)
![Language](https://img.shields.io/badge/Comments-EN%20%2F%20ID-2ea44f?style=flat-square)
![Maintainer](https://img.shields.io/badge/Maintainer-FansElectronics.com-orange?style=flat-square)

Universal, ready-to-upload **Arduino, ESP32, and ESP8266 module tester codes** for verifying development boards, sensors, displays, communication interfaces, and electronic modules. Built by **[Fans Electronics](https://www.fanselectronics.com)** to streamline hardware Quality Control (QC), store inventory testing, and rapid prototyping without repetitive code modifications.

---

## English Documentation

### Overview
Testing electronic modules across different microcontroller architectures often requires manual pin remapping and logic adjustments. **Arduino-Module-Tester-Code** solves this problem by providing standardized, plug-and-play testing sketches with automatic board detection and clear bilingual inline documentation (`// EN:` and `// ID:`).

### Key Features
* **Multi-Board Auto Detection:** Automatically adapts GPIO pin mappings and logic levels across Arduino (AVR), ESP8266, and ESP32 variants (Classic, S2, S3, C3, and ESP32-CAM).
* **Standardized QC Workflow:** Plug in the target board, select the board profile in Arduino IDE, upload, and verify functionality immediately via onboard indicators or Serial Monitor (`115200 baud`).
* **Bilingual Inline Comments:** Every functional block is documented in both English and Indonesian to assist technicians, students, and makers.
* **Categorized Structure:** Organized by hardware category (`01_MCU_Board`, `02_Communication`, etc.) for fast lookup during store QC or project debugging.

### Repository Structure
```text
Arduino-Module-Tester-Code/
├── 01_MCU_Board/
│   └── Tester_001_Universal_Blinking/
│       └── Tester_001_Universal_Blinking.ino   # Universal built-in LED test (Arduino, ESP8266, ESP32)
├── 02_Communication/                         # (Coming Soon) I2C Scanner, SPI, UART Loopback
├── 03_Display/                               # (Coming Soon) OLED SSD1306, LCD 16x2/20x4, LED Matrix
├── 04_Sensor/                                # (Coming Soon) Ultrasonic, DHT, MPU6050, IR, etc.
├── 05_Actuator_Driver/                       # (Coming Soon) Relay, Servo, Motor & Stepper Drivers
└── README.md
```

### How to Use
1. Clone or download this repository as a ZIP file.
2. Open the desired `.ino` file inside its matching folder using **Arduino IDE**.
3. Select your target **Board** and **Port** under the `Tools` menu.
4. Click **Upload** and open the **Serial Monitor** at `115200 baud` to inspect real-time diagnostic output.

---

## Dokumentasi Bahasa Indonesia

### Ringkasan
Pengujian modul elektronika pada berbagai varian mikrokontroler sering kali memakan waktu karena perbedaan pemetaan pin dan logika output. **Arduino-Module-Tester-Code** hadir sebagai kumpulan program uji siap pakai (*ready-to-upload*) dengan deteksi arsitektur board otomatis serta komentar kode dwibahasa (`// EN:` dan `// ID:`).

### Fitur Utama
* **Deteksi Otomatis Multi-Board:** Menyesuaikan pin GPIO dan logika sinyal secara otomatis untuk keluarga Arduino (AVR), ESP8266, dan ESP32 (Classic, S2, S3, C3, serta ESP32-CAM).
* **Alur Kerja QC Terstandar:** Cukup hubungkan board, pilih jenis board di Arduino IDE, unggah program, dan verifikasi hasil pengujian melalui indikator LED maupun Serial Monitor (`115200 baud`).
* **Komentar Dwibahasa (EN/ID):** Setiap bagian kode dilengkapi penjelasan dalam bahasa Inggris dan bahasa Indonesia agar mudah dipahami oleh teknisi toko, pelajar, maupun penghobi elektronika.
* **Struktur Folder Terkategori:** Dikelompokkan berdasarkan kategori perangkat keras (`01_MCU_Board`, `02_Communication`, dan seterusnya) untuk mempercepat pencarian kode pengujian.

### Cara Penggunaan
1. *Clone* repository ini atau unduh dalam format ZIP.
2. Buka file `.ino` yang diinginkan melalui **Arduino IDE**.
3. Pilih tipe **Board** dan **Port** yang sesuai pada menu `Tools`.
4. Klik **Upload**, lalu buka **Serial Monitor** pada baud rate `115200` untuk memantau informasi diagnostik board/modul.

---

## Credit & Maintainer
* **Writer:** Irfan Indra Kurniawan @Vean
* **Website:** [www.fanselectronics.com](https://www.fanselectronics.com)
