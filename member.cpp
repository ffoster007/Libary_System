#include "member.h"
#include <iostream>
#include <algorithm>

// Constructor
Member::Member(std::string id, std::string name, std::string contactInfo)
    : id(id), name(name), contactInfo(contactInfo) {
}

// Getters
std::string Member::getId() const {
    return id;
}

std::string Member::getName() const {
    return name;
}

std::string Member::getContactInfo() const {
    return contactInfo;
}

std::vector<std::string> Member::getBorrowedBooks() const {
    return borrowedBooks;
}

// Setters
void Member::setName(const std::string& name) {
    this->name = name;
}

void Member::setContactInfo(const std::string& contactInfo) {
    this->contactInfo = contactInfo;
}

// Methods
// ยืมหนังสือ
void Member::borrowBook(const std::string& bookId) {
    borrowedBooks.push_back(bookId);
}

// คืนหนังสือ
bool Member::returnBook(const std::string& bookId) {
    auto it = std::find(borrowedBooks.begin(), borrowedBooks.end(), bookId);
    if (it != borrowedBooks.end()) {
        borrowedBooks.erase(it);
        return true;
    }
    return false;
}

// ตรวจสอบว่าสมาชิกยืมหนังสือเล่มนี้หรือไม่
bool Member::hasBorrowed(const std::string& bookId) const {
    return std::find(borrowedBooks.begin(), borrowedBooks.end(), bookId) != borrowedBooks.end();
}

// แสดงข้อมูลสมาชิก
void Member::display() const {
    std::cout << "รหัสสมาชิก: " << id << std::endl;
    std::cout << "ชื่อ: " << name << std::endl;
    std::cout << "ข้อมูลติดต่อ: " << contactInfo << std::endl;
    std::cout << "จำนวนหนังสือที่ยืม: " << borrowedBooks.size() << std::endl;
}

// จำนวนหนังสือที่ยืม
int Member::borrowedCount() const {
    return borrowedBooks.size();
}

// สำหรับการบันทึกลงไฟล์
std::string Member::toString() const {
    std::string result = id + "," + name + "," + contactInfo;
    
    // เพิ่มรายการหนังสือที่ยืม
    if (!borrowedBooks.empty()) {
        result += ",";
        for (size_t i = 0; i < borrowedBooks.size(); ++i) {
            result += borrowedBooks[i];
            if (i < borrowedBooks.size() - 1) {
                result += "|";
            }
        }
    }
    
    return result;
}
