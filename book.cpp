#include "book.h"
#include <iostream>

// Constructor
Book::Book(std::string id, std::string title, std::string author, std::string isbn, std::string category)
    : id(id), title(title), author(author), isbn(isbn), category(category), isAvailable(true) {
}

// Getters
std::string Book::getId() const {
    return id;
}

std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

std::string Book::getIsbn() const {
    return isbn;
}

std::string Book::getCategory() const {
    return category;
}

bool Book::getAvailability() const {
    return isAvailable;
}

// Setters
void Book::setTitle(const std::string& title) {
    this->title = title;
}

void Book::setAuthor(const std::string& author) {
    this->author = author;
}

void Book::setIsbn(const std::string& isbn) {
    this->isbn = isbn;
}

void Book::setCategory(const std::string& category) {
    this->category = category;
}

// Methods
void Book::borrowBook() {
    isAvailable = false;
}

void Book::returnBook() {
    isAvailable = true;
}

// แสดงข้อมูลหนังสือ
void Book::display() const {
    std::cout << "รหัสหนังสือ: " << id << std::endl;
    std::cout << "ชื่อหนังสือ: " << title << std::endl;
    std::cout << "ผู้แต่ง: " << author << std::endl;
    std::cout << "ISBN: " << isbn << std::endl;
    std::cout << "หมวดหมู่: " << category << std::endl;
    std::cout << "สถานะ: " << (isAvailable ? "ว่าง" : "ถูกยืม") << std::endl;
}

// สำหรับการบันทึกลงไฟล์
std::string Book::toString() const {
    return id + "," + title + "," + author + "," + isbn + "," + category + "," + (isAvailable ? "1" : "0");
}
