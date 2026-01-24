# Laporan Proyek UAS Ubiquitous Computing
## Sistem Presensi Wajah IoT dengan ESP32

**Nama:** Rezananda
**NIM:** 202303110012
**Mata Kuliah:** Internet of Things & Ubiquitous Computing

---

### A. Deskripsi Sistem
Sistem ini adalah aplikasi **Face Recognition Attendance** berbasis Web yang terintegrasi dengan perangkat IoT (ESP32). Sistem dirancang untuk melakukan verifikasi identitas pengguna menggunakan kamera laptop dan memberikan umpan balik fisik (Physical Feedback) berupa nyala LED pada perangkat ESP32 ketika presensi berhasil valid.

Konsep **Ubiquitous Computing** diterapkan melalui interaksi seamless antara:
1.  **Software (Web App)**: Mendeteksi dan memvalidasi wajah secara cerdas (Context Awareness).
2.  **Hardware (ESP32)**: Bertindak sebagai aktuator yang merespons konteks (wajah valid) dari lingkungan jaringan lokal.

### B. Spesifikasi Teknis
#### 1. Perangkat Keras (IoT)
*   **Microcontroller:** ESP32 (Support WiFi stack).
*   **Indikator:** LED Built-in (GPIO 4 / GPIO 2) atau LED Eksternal.
*   **Komunikasi:** WiFi (HTTP Protocol).

#### 2. Perangkat Lunak (Web App)
*   **Platform:** Web Browser (Client-side Processing).
*   **Framework/Libraries:**
    *   **OpenCV.js:** Library Computer Vision untuk deteksi wajah (Haar Cascade) dan histogram matching.
    *   **TailwindCSS:** Framework CSS untuk antarmuka pengguna yang modern dan responsif.
    *   **JavaScript (ES6):** Logika utama sistem.

### C. Mekanisme Kerja
1.  **Inisialisasi**: Pengguna membuka `index.html`. Sistem memuat OpenCV.js dan menghubungkan kamera laptop.
2.  **Registrasi Referensi**: Pengguna mengambil foto waja sendiri sebagai data acuan (Reference Face).
3.  **Proses Monitoring**:
    *   Kamera terus menerus menangkap frame video.
    *   Algoritma Haar Cascade mendeteksi keberadaan wajah.
    *   Jika wajah terdeteksi, sistem membandingkan histogram wajah tersebut dengan histogram wajah referensi.
4.  **Verifikasi & Aksi**:
    *   Jika tingkat kemiripan (Similarity Score) > Threshold (0.5), wajah dianggap **VALID**.
    *   Aplikasi mengirim request HTTP GET ke ESP32: `http://[IP_ESP32]/presensi`.
5.  **Umpan Balik**:
    *   ESP32 menerima request.
    *   ESP32 menyalakan LED selama 3 detik.
    *   Web menampilkan indikator "PRESENSI BERHASIL".

### D. Struktur Kode
Repository terdiri dari file-file berikut:

| File | Deskripsi |
|------|-----------|
| `index.html` | Aplikasi utama. Berisi UI, logika Kamera, OpenCV.js, dan komunikasi ke ESP32. |
| `esp32_presensi.ino` | Firmware untuk ESP32. Mengatur koneksi WiFi dan mengontrol LED. |
| `haarcascade_...xml` | (Dimuat via URL) Model deteksi wajah untuk OpenCV. |

#### Potongan Kode Penting (index.html)
Logika pengiriman sinyal ke IoT:
```javascript
function triggerPresensi() {
    fetch(`http://${espIp}/presensi`)
        .then(response => {
            console.log("ESP32 Response: LED ON");
            showSuccessUI();
        });
}
```

#### Potongan Kode Penting (ESP32)
Logic menyalakan LED saat request diterima:
```cpp
void handlePresensi() {
  server.sendHeader("Access-Control-Allow-Origin", "*"); // CORS
  digitalWrite(LED_PIN, HIGH); // Nyalakan LED
  server.send(200, "application/json", "{\"status\":\"ok\"}");
}
```

### E. Bukti Implementasi
*(Bagian ini diisi dengan Link Video YouTube bukti kerja sistem yang direkam oleh mahasiswa)*

**Link Video:** [Masukkan Link Video Di Sini]
**Link Repository:** [Masukkan Link GitHub Di Sini]

---
*Laporan ini disusun untuk memenuhi tugas UAS Mata Kuliah Ubiquitous Computing.*
