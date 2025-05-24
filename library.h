#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <vector>
#include <map>
#include "book.h"
#include "member.h"

// คลาสสำหรับจัดการห้องสมุด
class Library {
private:
    std::map<std::string, Book*> books;           // รายการหนังสือ (key: ID, value: Book*)
    std::map<std::string, Member*> members;       // รายการสมาชิก (key: ID, value: Member*)
    int lastBookId;                               // ID ล่าสุดของหนังสือ
    int lastMemberId;                             // ID ล่าสุดของสมาชิก
    
    // ข้อมูลไฟล์
    std::string booksFile;                        // ไฟล์เก็บข้อมูลหนังสือ
    std::string membersFile;                      // ไฟล์เก็บข้อมูลสมาชิก
    std::string borrowingsFile;                   // ไฟล์เก็บข้อมูลการยืม

public:
    // Constructor และ Destructor
    Library(const std::string& booksFile = "books.csv", 
            const std::string& membersFile = "members.csv",
            const std::string& borrowingsFile = "borrowings.csv");
    ~Library();
    
    // ระบบจัดการหนังสือ (Book Management)
    std::string addBook(const std::string& title, const std::string& author, 
                        const std::string& isbn, const std::string& category);
    bool updateBook(const std::string& id, const std::string& title, const std::string& author, 
                    const std::string& isbn, const std::string& category);
    bool removeBook(const std::string& id);
    Book* findBookById(const std::string& id);
    std::vector<Book*> findBooksByTitle(const std::string& title);
    std::vector<Book*> findBooksByISBN(const std::string& isbn);
    std::vector<Book*> findBooksByCategory(const std::string& category);
    std::vector<Book*> getAllBooks() const;
    
    // ระบบจัดการสมาชิก (Member Management)
    std::string addMember(const std::string& name, const std::string& contactInfo);
    bool updateMember(const std::string& id, const std::string& name, const std::string& contactInfo);
    bool removeMember(const std::string& id);
    Member* findMemberById(const std::string& id);
    std::vector<Member*> findMembersByName(const std::string& name);
    std::vector<Member*> getAllMembers() const;
    
    // ระบบยืม-คืนหนังสือ (Borrow & Return)
    bool borrowBook(const std::string& memberId, const std::string& bookId);
    bool returnBook(const std::string& memberId, const std::string& bookId);
    std::vector<std::pair<Book*, std::string>> getBorrowedBooks(const std::string& memberId);
    
    // การจัดการข้อมูลไฟล์ (File I/O)
    bool saveData();
    bool loadData();
};

#endif // LIBRARY_H
