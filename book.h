#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <vector>

// คลาสสำหรับจัดการข้อมูลหนังสือ
class Book {
private:
    std::string id;         // รหัสหนังสือ
    std::string title;      // ชื่อหนังสือ
    std::string author;     // ผู้แต่ง
    std::string isbn;       // รหัส ISBN
    std::string category;   // หมวดหมู่
    bool isAvailable;       // สถานะการยืม (ว่างหรือไม่)

public:
    // Constructor
    Book(std::string id, std::string title, std::string author, std::string isbn, std::string category);
    
    // Getters
    std::string getId() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getIsbn() const;
    std::string getCategory() const;
    bool getAvailability() const;
    
    // Setters
    void setTitle(const std::string& title);
    void setAuthor(const std::string& author);
    void setIsbn(const std::string& isbn);
    void setCategory(const std::string& category);
    
    // Methods
    void borrowBook();      // เปลี่ยนสถานะเป็นไม่ว่าง
    void returnBook();      // เปลี่ยนสถานะเป็นว่าง
    
    // แสดงข้อมูลหนังสือ
    void display() const;
    
    // สำหรับการบันทึกลงไฟล์
    std::string toString() const;
};

#endif // BOOK_H
