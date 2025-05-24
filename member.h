#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <vector>
#include "book.h"

// คลาสสำหรับจัดการข้อมูลสมาชิก
class Member {
private:
    std::string id;             // รหัสสมาชิก
    std::string name;           // ชื่อสมาชิก
    std::string contactInfo;    // ข้อมูลการติดต่อ
    std::vector<std::string> borrowedBooks;  // รหัสหนังสือที่ยืม
    
public:
    // Constructor
    Member(std::string id, std::string name, std::string contactInfo);
    
    // Getters
    std::string getId() const;
    std::string getName() const;
    std::string getContactInfo() const;
    std::vector<std::string> getBorrowedBooks() const;
    
    // Setters
    void setName(const std::string& name);
    void setContactInfo(const std::string& contactInfo);
    
    // Methods
    // ยืมหนังสือ
    void borrowBook(const std::string& bookId);
    
    // คืนหนังสือ
    bool returnBook(const std::string& bookId);
    
    // ตรวจสอบว่าสมาชิกยืมหนังสือเล่มนี้หรือไม่
    bool hasBorrowed(const std::string& bookId) const;
    
    // แสดงข้อมูลสมาชิก
    void display() const;
    
    // จำนวนหนังสือที่ยืม
    int borrowedCount() const;
    
    // สำหรับการบันทึกลงไฟล์
    std::string toString() const;
};

#endif // MEMBER_H
