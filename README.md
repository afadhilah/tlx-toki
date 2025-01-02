# tlx-toki

# **C Programming Project**

## **Deskripsi Proyek**
Proyek ini adalah kumpulan program yang ditulis dalam bahasa C untuk berbagai kebutuhan, termasuk implementasi algoritma, pemrosesan data, dan logika bisnis. Struktur proyek dirancang untuk mendukung kompilasi multi-file dengan **Makefile**, mempermudah pengelolaan, kompilasi, dan eksekusi program.

## **Fitur Utama**
- **Kompilasi Multi-File**: Program dengan beberapa file sumber dapat dengan mudah dikompilasi menggunakan Makefile.
- **Struktur Proyek Terorganisir**: File sumber dan output disusun secara rapi untuk memudahkan pengembangan.
- **Custom Build Rules**: Aturan khusus untuk membersihkan file, menjalankan program, dan mempercepat pengembangan.
- **Lintasan Kesalahan Umum**: Solusi untuk menangani error umum seperti "multiple definition of `main`".

## **Struktur Proyek**
```
project/
│
├── src/
│   ├── 1.c       # File sumber pertama
│   ├── 2.c       # File sumber kedua
│   ├── 3.c       # File sumber ketiga
│   └── ...       # Tambahkan file lainnya di sini
│
├── build/        # Folder untuk file hasil kompilasi (opsional)
├── Makefile      # File Makefile untuk kompilasi dan pengelolaan
└── README.md     # Dokumentasi proyek
```

## **Cara Menggunakan**
### **1. Prasyarat**
Pastikan Anda telah menginstal:
- **GCC**: Compiler untuk C.
- **Make**: Build automation tool.

### **2. Langkah Kompilasi**
- **Kompilasi Program:**
  Jalankan perintah berikut untuk meng-compile semua file sumber:
  ```bash
  make
  ```
- **Menjalankan Program:**
  Jalankan perintah berikut untuk menjalankan program:
  ```bash
  make run
  ```
- **Membersihkan File Output:**
  Bersihkan file hasil kompilasi untuk memulai dari awal:
  ```bash
  make clean
  ```

## **Solusi Masalah Umum**
1. **Multiple Definition of `main`:**
   - Penyebab: Beberapa file `.c` memiliki fungsi `main()`.
   - Solusi: 
     - Pastikan hanya ada satu file dengan fungsi `main()`.
     - Atur file utama di Makefile.

2. **Folder `.vscode` atau File `.exe` Muncul di Git:**
   - Solusi:
     - Tambahkan aturan berikut ke `.gitignore`:
       ```
       .vscode/
       *.exe
       ```

3. **Kesalahan Linking:**
   - Penyebab: Dependensi antar file tidak terhubung dengan benar.
   - Solusi:
     - Pastikan semua file `.c` yang dibutuhkan dicantumkan di `SRC` pada Makefile.

## **Contoh Makefile**
```makefile
# Nama file output
TARGET = program

# File sumber
SRC = src/1.c src/2.c src/3.c

# Compiler dan opsi
CC = gcc
CFLAGS = -Wall -g

# Rule utama
all: $(TARGET)

# Rule untuk menghasilkan file output
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Rule untuk menjalankan program
run: all
	./$(TARGET)

# Rule untuk membersihkan file yang dihasilkan
clean:
	rm -f $(TARGET)
```

## **Kontribusi**
Anda dipersilakan untuk menambahkan fitur, memperbaiki bug, atau meningkatkan dokumentasi ini. Silakan buat **pull request** atau laporkan masalah melalui **issue**.

