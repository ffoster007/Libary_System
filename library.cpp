#include "library.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <ctime>

// Constructor
Library::Library(const std::string& booksFile, const std::string& membersFile, const std::string& borrowingsFile) 
    : booksFile(booksFile), membersFile(membersFile), borrowingsFile(borrowingsFile), lastBookId(0), lastMemberId(0) {
    loadData();
}

// Destructor
Library::~Library() {
    // บันทึกข้อมูลก่อนปิดโปรแกรม
    saveData();
    
    // ลบข้อมูลที่จองไว้
    for (auto& book : books) {
        delete book.second;
    }
    
    for (auto& member : members) {
        delete member.second;
    }
}

// ระบบจัดการหนังสือ (Book Management)
std::string Library::addBook(const std::string& title, const std::string& author, 
                    const std::string& isbn, const std::string& category) {
    lastBookId++;
    std::string id = "B" + std::to_string(lastBookId);
    
    Book* book = new Book(id, title, author, isbn, category);
    books[id] = book;
    
    return id;
}

bool Library::updateBook(const std::string& id, const std::string& title, const std::string& author, 
                const std::string& isbn, const std::string& category) {
    auto it = books.find(id);
    if (it == books.end()) {
        return false;
    }
    
    Book* book = it->second;
    book->setTitle(title);
    book->setAuthor(author);
    book->setIsbn(isbn);
    book->setCategory(category);
    
    return true;
}

bool Library::removeBook(const std::string& id) {
    auto it = books.find(id);
    if (it == books.end()) {
        return false;
    }
    
    delete it->second;
    books.erase(it);
    
    return true;
}

Book* Library::findBookById(const std::string& id) {
    auto it = books.find(id);
    if (it == books.end()) {
        return nullptr;
    }
    
    return it->second;
}

std::vector<Book*> Library::findBooksByTitle(const std::string& title) {
    std::vector<Book*> result;
    
    for (auto& book : books) {
        if (book.second->getTitle().find(title) != std::string::npos) {
            result.push_back(book.second);
        }
    }
    
    return result;
}

std::vector<Book*> Library::findBooksByISBN(const std::string& isbn) {
    std::vector<Book*> result;
    
    for (auto& book : books) {
        if (book.second->getIsbn().find(isbn) != std::string::npos) {
            result.push_back(book.second);
        }
    }
    
    return result;
}

std::vector<Book*> Library::findBooksByCategory(const std::string& category) {
    std::vector<Book*> result;
    
    for (auto& book : books) {
        if (book.second->getCategory().find(category) != std::string::npos) {
            result.push_back(book.second);
        }
    }
    
    return result;
}

std::vector<Book*> Library::getAllBooks() const {
    std::vector<Book*> result;
    
    for (auto& book : books) {
        result.push_back(book.second);
    }
    
    return result;
}

// ระบบจัดการสมาชิก (Member Management)
std::string Library::addMember(const std::string& name, const std::string& contactInfo) {
    lastMemberId++;
    std::string id = "M" + std::to_string(lastMemberId);
    
    Member* member = new Member(id, name, contactInfo);
    members[id] = member;
    
    return id;
}

bool Library::updateMember(const std::string& id, const std::string& name, const std::string& contactInfo) {
    auto it = members.find(id);
    if (it == members.end()) {
        return false;
    }
    
    Member* member = it->second;
    member->setName(name);
    member->setContactInfo(contactInfo);
    
    return true;
}

bool Library::removeMember(const std::string& id) {
    auto it = members.find(id);
    if (it == members.end()) {
        return false;
    }
    
    delete it->second;
    members.erase(it);
    
    return true;
}

Member* Library::findMemberById(const std::string& id) {
    auto it = members.find(id);
    if (it == members.end()) {
        return nullptr;
    }
    
    return it->second;
}

std::vector<Member*> Library::findMembersByName(const std::string& name) {
    std::vector<Member*> result;
    
    for (auto& member : members) {
        if (member.second->getName().find(name) != std::string::npos) {
            result.push_back(member.second);
        }
    }
    
    return result;
}

std::vector<Member*> Library::getAllMembers() const {
    std::vector<Member*> result;
    
    for (auto& member : members) {
        result.push_back(member.second);
    }
    
    return result;
}

// ระบบยืม-คืนหนังสือ (Borrow & Return)
bool Library::borrowBook(const std::string& memberId, const std::string& bookId) {
    // ตรวจสอบว่ามีหนังสือและสมาชิกที่ต้องการหรือไม่
    Book* book = findBookById(bookId);
    Member* member = findMemberById(memberId);
    
    if (book == nullptr || member == nullptr) {
        return false;
    }
    
    // ตรวจสอบว่าหนังสือว่างหรือไม่
    if (!book->getAvailability()) {
        return false;
    }
    
    // ทำการยืม
    book->borrowBook();
    member->borrowBook(bookId);
    
    return true;
}

bool Library::returnBook(const std::string& memberId, const std::string& bookId) {
    // ตรวจสอบว่ามีหนังสือและสมาชิกที่ต้องการหรือไม่
    Book* book = findBookById(bookId);
    Member* member = findMemberById(memberId);
    
    if (book == nullptr || member == nullptr) {
        return false;
    }
    
    // ตรวจสอบว่าสมาชิกได้ยืมหนังสือนี้หรือไม่
    if (!member->hasBorrowed(bookId)) {
        return false;
    }
    
    // ทำการคืนหนังสือ
    book->returnBook();
    member->returnBook(bookId);
    
    return true;
}

std::vector<std::pair<Book*, std::string>> Library::getBorrowedBooks(const std::string& memberId) {
    std::vector<std::pair<Book*, std::string>> result;
    
    Member* member = findMemberById(memberId);
    if (member == nullptr) {
        return result;
    }
    
    std::vector<std::string> borrowedBooks = member->getBorrowedBooks();
    for (const std::string& bookId : borrowedBooks) {
        Book* book = findBookById(bookId);
        if (book != nullptr) {
            // สมมติให้ระยะเวลายืม 14 วัน
            std::string dueDate = "14 วันนับจากวันยืม"; // ควรมีการเก็บวันที่ยืมจริงๆ
            result.push_back(std::make_pair(book, dueDate));
        }
    }
    
    return result;
}

// การจัดการข้อมูลไฟล์ (File I/O)
bool Library::saveData() {
    // บันทึกข้อมูลหนังสือ
    std::ofstream bookFile(booksFile);
    if (bookFile.is_open()) {
        bookFile << "id,title,author,isbn,category,available" << std::endl;
        for (const auto& book : books) {
            bookFile << book.second->toString() << std::endl;
        }
        bookFile.close();
    } else {
        return false;
    }
    
    // บันทึกข้อมูลสมาชิก
    std::ofstream memberFile(membersFile);
    if (memberFile.is_open()) {
        memberFile << "id,name,contactInfo,borrowedBooks" << std::endl;
        for (const auto& member : members) {
            memberFile << member.second->toString() << std::endl;
        }
        memberFile.close();
    } else {
        return false;
    }
    
    return true;
}

bool Library::loadData() {
    // ล้างข้อมูลเดิม
    for (auto& book : books) {
        delete book.second;
    }
    books.clear();
    
    for (auto& member : members) {
        delete member.second;
    }
    members.clear();
    
    lastBookId = 0;
    lastMemberId = 0;
    
    // อ่านข้อมูลหนังสือ
    std::ifstream bookFile(booksFile);
    if (bookFile.is_open()) {
        std::string line;
        // ข้ามบรรทัดแรก (header)
        std::getline(bookFile, line);
        
        while (std::getline(bookFile, line)) {
            std::istringstream iss(line);
            std::string id, title, author, isbn, category, availableStr;
            
            std::getline(iss, id, ',');
            std::getline(iss, title, ',');
            std::getline(iss, author, ',');
            std::getline(iss, isbn, ',');
            std::getline(iss, category, ',');
            std::getline(iss, availableStr, ',');
            
            Book* book = new Book(id, title, author, isbn, category);
            if (availableStr == "0") {
                book->borrowBook();
            }
            
            books[id] = book;
            
            // อัพเดท lastBookId
            int numericId = std::stoi(id.substr(1));
            if (numericId > lastBookId) {
                lastBookId = numericId;
            }
        }
        bookFile.close();
    }
    
    // อ่านข้อมูลสมาชิก
    std::ifstream memberFile(membersFile);
    if (memberFile.is_open()) {
        std::string line;
        // ข้ามบรรทัดแรก (header)
        std::getline(memberFile, line);
        
        while (std::getline(memberFile, line)) {
            std::istringstream iss(line);
            std::string id, name, contactInfo, borrowedBooksStr;
            
            std::getline(iss, id, ',');
            std::getline(iss, name, ',');
            std::getline(iss, contactInfo, ',');
            std::getline(iss, borrowedBooksStr);
            
            Member* member = new Member(id, name, contactInfo);
            
            // แยกรหัสหนังสือที่ยืม
            if (!borrowedBooksStr.empty()) {
                std::istringstream biss(borrowedBooksStr);
                std::string bookId;
                
                while (std::getline(biss, bookId, '|')) {
                    member->borrowBook(bookId);
                }
            }
            
            members[id] = member;
            
            // อัพเดท lastMemberId
            int numericId = std::stoi(id.substr(1));
            if (numericId > lastMemberId) {
                lastMemberId = numericId;
            }
        }
        memberFile.close();
    }
    
    return true;
}
