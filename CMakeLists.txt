cmake_minimum_required(VERSION 3.10)

# Nama proyek
project(MyProject VERSION 1.0 LANGUAGES C CXX)

# Set standar C dan C++
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Tambahkan file sumber ke executable
add_executable(MyProject
    src/main.c
    # Tambahkan file sumber lain jika ada
)

# Opsi untuk pengujian
enable_testing()

# Tambahkan target untuk pengujian
add_test(NAME MyTest COMMAND MyProject)

# Opsi install (opsional, jika Anda ingin membuat distribusi)
install(TARGETS MyProject DESTINATION bin)
install(FILES README.md DESTINATION share/MyProject)
