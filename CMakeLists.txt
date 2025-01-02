cmake_minimum_required(VERSION 3.10)

# Nama proyek
project(TLX-TOKI LANGUAGES C CXX)

# Set standar C dan C++
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER "C:/Program Files (x86)/Microsoft Visual Studio/2019/BuildTools/VC/Tools/MSVC/14.29.30133/bin/Hostx86/x64/cl.exe")
set(CMAKE_MAKE_PROGRAM "C:/Program Files (x86)/Microsoft Visual Studio/2019/BuildTools/VC/Tools/MSVC/14.29.30133/bin/Hostx86/x64/nmake.exe")


# Cari semua file .c di direktori src dan tambahkan ke executable
file(GLOB_RECURSE SOURCE_FILES "src/*.c")

add_executable(MyProject ${SOURCE_FILES})

# Opsi untuk pengujian
enable_testing()

# Tambahkan target untuk pengujian
add_test(NAME MyTest COMMAND MyProject)

# Opsi install (opsional, jika Anda ingin membuat distribusi)
install(TARGETS MyProject DESTINATION bin)
install(FILES README.md DESTINATION share/MyProject)
