# วิธีการติดตั้งและรันโปรแกรม

## การติดตั้งสภาพแวดล้อมสำหรับคอมไพล์ C++ บน Windows

### 1. ติดตั้ง MinGW (Minimalist GNU for Windows)

1. ดาวน์โหลด MinGW Installer จาก: https://sourceforge.net/projects/mingw/

2. รันไฟล์ที่ดาวน์โหลด และทำตามขั้นตอนการติดตั้ง

3. เมื่อเข้าสู่ MinGW Installation Manager ให้เลือกแพคเกจดังนี้:
   - mingw32-base
   - mingw32-gcc-g++
   - msys-base

4. คลิกที่ Installation > Apply Changes เพื่อติดตั้งแพคเกจที่เลือก

5. เพิ่ม MinGW ลงใน PATH ของระบบ:
   - ค้นหา "Environment Variables" ใน Windows Search
   - คลิกที่ "Edit the system environment variables"
   - คลิกที่ "Environment Variables"
   - ในส่วน "System Variables" หา "Path" และคลิก "Edit"
   - คลิก "New" และเพิ่ม "C:\MinGW\bin" (อาจต้องเปลี่ยนตามที่อยู่ที่คุณติดตั้ง)
   - กดปุ่ม OK ทั้งหมด

6. ตรวจสอบการติดตั้งโดยเปิด Command Prompt และพิมพ์:
   ```
   g++ --version
   ```

## วิธีการคอมไพล์โดยไม่ต้องใช้ Makefile

หากคุณไม่ต้องการใช้ Makefile สามารถใช้คำสั่งดังต่อไปนี้เพื่อคอมไพล์โปรแกรม:

```
cd "c:\Users\ACER\OneDrive\เอกสาร\Coding\simple-library"
g++ -std=c++11 -Wall -Wextra main.cpp book.cpp member.cpp library.cpp -o library_management.exe
```

จากนั้นรันโปรแกรมด้วยคำสั่ง:

```
library_management.exe
```

## การใช้ IDE สำหรับ C/C++

ทางเลือกอีกอย่างคือการใช้ IDE ที่รองรับ C/C++ เช่น:

1. **Visual Studio Code**
   - ติดตั้ง Extension สำหรับ C/C++ โดย Microsoft
   - ตั้งค่า C/C++ Extension และระบุ compiler path

2. **Visual Studio Community**
   - ดาวน์โหลดและติดตั้ง Visual Studio Community Edition
   - เลือกติดตั้ง "Desktop development with C++"
   - เปิดโปรเจคและคอมไพล์ได้เลย

3. **Code::Blocks**
   - ดาวน์โหลดเวอร์ชันที่มา MinGW bundled มาด้วย
   - สร้างโปรเจคใหม่และเพิ่มไฟล์ทั้งหมดลงไป
   - คอมไพล์และรันในโปรแกรม
