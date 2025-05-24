#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "library.h"

// สร้างเพื่อทำความสะอาดหน้าจอ
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// แสดงเมนูหลัก
void showMainMenu() {
    std::cout << "\n===================================\n";
    std::cout << "📚 ระบบจัดการห้องสมุด (Library Management System)\n";
    std::cout << "===================================\n";
    std::cout << "1. จัดการหนังสือ (Book Management)\n";
    std::cout << "2. จัดการสมาชิก (Member Management)\n";
    std::cout << "3. ระบบยืม-คืนหนังสือ (Borrow & Return)\n";
    std::cout << "4. ออกจากระบบ (Exit)\n";
    std::cout << "===================================\n";
    std::cout << "เลือกรายการ (1-4): ";
}

// แสดงเมนูจัดการหนังสือ
void showBookMenu() {
    clearScreen();
    std::cout << "\n===================================\n";
    std::cout << "📚 จัดการหนังสือ (Book Management)\n";
    std::cout << "===================================\n";
    std::cout << "1. เพิ่มหนังสือใหม่ (Add New Book)\n";
    std::cout << "2. แก้ไขข้อมูลหนังสือ (Edit Book)\n";
    std::cout << "3. ลบหนังสือ (Delete Book)\n";
    std::cout << "4. ค้นหาหนังสือ (Search Book)\n";
    std::cout << "5. แสดงหนังสือทั้งหมด (Show All Books)\n";
    std::cout << "6. กลับเมนูหลัก (Back to Main Menu)\n";
    std::cout << "===================================\n";
    std::cout << "เลือกรายการ (1-6): ";
}

// แสดงเมนูจัดการสมาชิก
void showMemberMenu() {
    clearScreen();
    std::cout << "\n===================================\n";
    std::cout << "👤 จัดการสมาชิก (Member Management)\n";
    std::cout << "===================================\n";
    std::cout << "1. เพิ่มสมาชิกใหม่ (Add New Member)\n";
    std::cout << "2. แก้ไขข้อมูลสมาชิก (Edit Member)\n";
    std::cout << "3. ลบสมาชิก (Delete Member)\n";
    std::cout << "4. ค้นหาสมาชิก (Search Member)\n";
    std::cout << "5. แสดงสมาชิกทั้งหมด (Show All Members)\n";
    std::cout << "6. กลับเมนูหลัก (Back to Main Menu)\n";
    std::cout << "===================================\n";
    std::cout << "เลือกรายการ (1-6): ";
}

// แสดงเมนูค้นหาหนังสือ
void showBookSearchMenu() {
    clearScreen();
    std::cout << "\n===================================\n";
    std::cout << "🔍 ค้นหาหนังสือ (Search Books)\n";
    std::cout << "===================================\n";
    std::cout << "1. ค้นหาด้วยรหัส (By ID)\n";
    std::cout << "2. ค้นหาด้วยชื่อหนังสือ (By Title)\n";
    std::cout << "3. ค้นหาด้วย ISBN (By ISBN)\n";
    std::cout << "4. ค้นหาด้วยหมวดหมู่ (By Category)\n";
    std::cout << "5. กลับเมนูจัดการหนังสือ (Back to Book Menu)\n";
    std::cout << "===================================\n";
    std::cout << "เลือกรายการ (1-5): ";
}

// แสดงเมนูค้นหาสมาชิก
void showMemberSearchMenu() {
    clearScreen();
    std::cout << "\n===================================\n";
    std::cout << "🔍 ค้นหาสมาชิก (Search Members)\n";
    std::cout << "===================================\n";
    std::cout << "1. ค้นหาด้วยรหัสสมาชิก (By ID)\n";
    std::cout << "2. ค้นหาด้วยชื่อ (By Name)\n";
    std::cout << "3. กลับเมนูจัดการสมาชิก (Back to Member Menu)\n";
    std::cout << "===================================\n";
    std::cout << "เลือกรายการ (1-3): ";
}

// แสดงเมนูยืม-คืนหนังสือ
void showBorrowReturnMenu() {
    clearScreen();
    std::cout << "\n===================================\n";
    std::cout << "📖 ระบบยืม-คืนหนังสือ (Borrow & Return)\n";
    std::cout << "===================================\n";
    std::cout << "1. ยืมหนังสือ (Borrow Book)\n";
    std::cout << "2. คืนหนังสือ (Return Book)\n";
    std::cout << "3. ตรวจสอบหนังสือที่สมาชิกยืม (Check Member Borrowing)\n";
    std::cout << "4. กลับเมนูหลัก (Back to Main Menu)\n";
    std::cout << "===================================\n";
    std::cout << "เลือกรายการ (1-4): ";
}

// สำหรับรอกดปุ่มใดๆ เพื่อดำเนินการต่อ
void waitForKeyPress() {
    std::cout << "\nกดปุ่มใดๆ เพื่อดำเนินการต่อ...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

// แสดงรายการหนังสือ
void displayBooks(const std::vector<Book*>& books) {
    if (books.empty()) {
        std::cout << "ไม่พบหนังสือ\n";
        return;
    }
    
    std::cout << "\n=== รายการหนังสือ ===\n";
    std::cout << "รหัส\tชื่อหนังสือ\tผู้แต่ง\tISBN\tหมวดหมู่\tสถานะ\n";
    std::cout << "-------------------------------------------------------------\n";
    
    for (Book* book : books) {
        std::cout << book->getId() << "\t" 
                  << book->getTitle() << "\t" 
                  << book->getAuthor() << "\t" 
                  << book->getIsbn() << "\t" 
                  << book->getCategory() << "\t" 
                  << (book->getAvailability() ? "ว่าง" : "ถูกยืม") << "\n";
    }
    std::cout << "-------------------------------------------------------------\n";
}

// แสดงรายการสมาชิก
void displayMembers(const std::vector<Member*>& members) {
    if (members.empty()) {
        std::cout << "ไม่พบสมาชิก\n";
        return;
    }
    
    std::cout << "\n=== รายการสมาชิก ===\n";
    std::cout << "รหัส\tชื่อ\tข้อมูลติดต่อ\tจำนวนหนังสือที่ยืม\n";
    std::cout << "-------------------------------------------------------------\n";
    
    for (Member* member : members) {
        std::cout << member->getId() << "\t" 
                  << member->getName() << "\t" 
                  << member->getContactInfo() << "\t" 
                  << member->borrowedCount() << "\n";
    }
    std::cout << "-------------------------------------------------------------\n";
}

// จัดการเมนูหนังสือ
void handleBookMenu(Library& library) {
    int choice = 0;
    
    do {
        showBookMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch (choice) {
            case 1: { // เพิ่มหนังสือใหม่
                clearScreen();
                std::cout << "\n=== เพิ่มหนังสือใหม่ ===\n";
                
                std::string title, author, isbn, category;
                
                std::cout << "ชื่อหนังสือ: ";
                std::getline(std::cin, title);
                
                std::cout << "ผู้แต่ง: ";
                std::getline(std::cin, author);
                
                std::cout << "ISBN: ";
                std::getline(std::cin, isbn);
                
                std::cout << "หมวดหมู่: ";
                std::getline(std::cin, category);
                
                std::string bookId = library.addBook(title, author, isbn, category);
                
                std::cout << "\nเพิ่มหนังสือสำเร็จ! รหัสหนังสือคือ: " << bookId << std::endl;
                waitForKeyPress();
                break;
            }
            case 2: { // แก้ไขข้อมูลหนังสือ
                clearScreen();
                std::cout << "\n=== แก้ไขข้อมูลหนังสือ ===\n";
                
                std::string id;
                std::cout << "กรอกรหัสหนังสือที่ต้องการแก้ไข: ";
                std::getline(std::cin, id);
                
                Book* book = library.findBookById(id);
                if (book == nullptr) {
                    std::cout << "ไม่พบหนังสือที่มีรหัส: " << id << std::endl;
                    waitForKeyPress();
                    break;
                }
                
                std::cout << "\nข้อมูลหนังสือปัจจุบัน:\n";
                book->display();
                
                std::string title, author, isbn, category;
                
                std::cout << "\nชื่อหนังสือใหม่ (เว้นว่างเพื่อไม่เปลี่ยนแปลง): ";
                std::getline(std::cin, title);
                if (title.empty()) title = book->getTitle();
                
                std::cout << "ผู้แต่งใหม่ (เว้นว่างเพื่อไม่เปลี่ยนแปลง): ";
                std::getline(std::cin, author);
                if (author.empty()) author = book->getAuthor();
                
                std::cout << "ISBN ใหม่ (เว้นว่างเพื่อไม่เปลี่ยนแปลง): ";
                std::getline(std::cin, isbn);
                if (isbn.empty()) isbn = book->getIsbn();
                
                std::cout << "หมวดหมู่ใหม่ (เว้นว่างเพื่อไม่เปลี่ยนแปลง): ";
                std::getline(std::cin, category);
                if (category.empty()) category = book->getCategory();
                
                if (library.updateBook(id, title, author, isbn, category)) {
                    std::cout << "\nอัพเดทข้อมูลหนังสือสำเร็จ!\n";
                } else {
                    std::cout << "\nไม่สามารถอัพเดทข้อมูลหนังสือได้\n";
                }
                
                waitForKeyPress();
                break;
            }
            case 3: { // ลบหนังสือ
                clearScreen();
                std::cout << "\n=== ลบหนังสือ ===\n";
                
                std::string id;
                std::cout << "กรอกรหัสหนังสือที่ต้องการลบ: ";
                std::getline(std::cin, id);
                
                Book* book = library.findBookById(id);
                if (book == nullptr) {
                    std::cout << "ไม่พบหนังสือที่มีรหัส: " << id << std::endl;
                    waitForKeyPress();
                    break;
                }
                
                std::cout << "\nข้อมูลหนังสือที่จะลบ:\n";
                book->display();
                
                char confirm;
                std::cout << "\nต้องการลบหนังสือนี้ใช่หรือไม่? (y/n): ";
                std::cin >> confirm;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                if (confirm == 'y' || confirm == 'Y') {
                    if (library.removeBook(id)) {
                        std::cout << "\nลบหนังสือสำเร็จ!\n";
                    } else {
                        std::cout << "\nไม่สามารถลบหนังสือได้\n";
                    }
                } else {
                    std::cout << "\nยกเลิกการลบหนังสือ\n";
                }
                
                waitForKeyPress();
                break;
            }
            case 4: { // ค้นหาหนังสือ
                int searchChoice = 0;
                
                do {
                    showBookSearchMenu();
                    std::cin >> searchChoice;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    
                    switch (searchChoice) {
                        case 1: { // ค้นหาด้วยรหัส
                            clearScreen();
                            std::cout << "\n=== ค้นหาหนังสือด้วยรหัส ===\n";
                            
                            std::string id;
                            std::cout << "กรอกรหัสหนังสือ: ";
                            std::getline(std::cin, id);
                            
                            Book* book = library.findBookById(id);
                            if (book != nullptr) {
                                std::cout << "\nพบหนังสือ:\n";
                                book->display();
                            } else {
                                std::cout << "\nไม่พบหนังสือที่มีรหัส: " << id << std::endl;
                            }
                            
                            waitForKeyPress();
                            break;
                        }
                        case 2: { // ค้นหาด้วยชื่อหนังสือ
                            clearScreen();
                            std::cout << "\n=== ค้นหาหนังสือด้วยชื่อ ===\n";
                            
                            std::string title;
                            std::cout << "กรอกชื่อหนังสือ (หรือบางส่วน): ";
                            std::getline(std::cin, title);
                            
                            std::vector<Book*> foundBooks = library.findBooksByTitle(title);
                            displayBooks(foundBooks);
                            
                            waitForKeyPress();
                            break;
                        }
                        case 3: { // ค้นหาด้วย ISBN
                            clearScreen();
                            std::cout << "\n=== ค้นหาหนังสือด้วย ISBN ===\n";
                            
                            std::string isbn;
                            std::cout << "กรอก ISBN (หรือบางส่วน): ";
                            std::getline(std::cin, isbn);
                            
                            std::vector<Book*> foundBooks = library.findBooksByISBN(isbn);
                            displayBooks(foundBooks);
                            
                            waitForKeyPress();
                            break;
                        }
                        case 4: { // ค้นหาด้วยหมวดหมู่
                            clearScreen();
                            std::cout << "\n=== ค้นหาหนังสือด้วยหมวดหมู่ ===\n";
                            
                            std::string category;
                            std::cout << "กรอกหมวดหมู่ (หรือบางส่วน): ";
                            std::getline(std::cin, category);
                            
                            std::vector<Book*> foundBooks = library.findBooksByCategory(category);
                            displayBooks(foundBooks);
                            
                            waitForKeyPress();
                            break;
                        }
                    }
                    
                } while (searchChoice != 5);
                
                break;
            }
            case 5: { // แสดงหนังสือทั้งหมด
                clearScreen();
                std::cout << "\n=== แสดงหนังสือทั้งหมด ===\n";
                
                std::vector<Book*> allBooks = library.getAllBooks();
                displayBooks(allBooks);
                
                waitForKeyPress();
                break;
            }
        }
        
    } while (choice != 6);
}

// จัดการเมนูสมาชิก
void handleMemberMenu(Library& library) {
    int choice = 0;
    
    do {
        showMemberMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch (choice) {
            case 1: { // เพิ่มสมาชิกใหม่
                clearScreen();
                std::cout << "\n=== เพิ่มสมาชิกใหม่ ===\n";
                
                std::string name, contactInfo;
                
                std::cout << "ชื่อ: ";
                std::getline(std::cin, name);
                
                std::cout << "ข้อมูลติดต่อ: ";
                std::getline(std::cin, contactInfo);
                
                std::string memberId = library.addMember(name, contactInfo);
                
                std::cout << "\nเพิ่มสมาชิกสำเร็จ! รหัสสมาชิกคือ: " << memberId << std::endl;
                waitForKeyPress();
                break;
            }
            case 2: { // แก้ไขข้อมูลสมาชิก
                clearScreen();
                std::cout << "\n=== แก้ไขข้อมูลสมาชิก ===\n";
                
                std::string id;
                std::cout << "กรอกรหัสสมาชิกที่ต้องการแก้ไข: ";
                std::getline(std::cin, id);
                
                Member* member = library.findMemberById(id);
                if (member == nullptr) {
                    std::cout << "ไม่พบสมาชิกที่มีรหัส: " << id << std::endl;
                    waitForKeyPress();
                    break;
                }
                
                std::cout << "\nข้อมูลสมาชิกปัจจุบัน:\n";
                member->display();
                
                std::string name, contactInfo;
                
                std::cout << "\nชื่อใหม่ (เว้นว่างเพื่อไม่เปลี่ยนแปลง): ";
                std::getline(std::cin, name);
                if (name.empty()) name = member->getName();
                
                std::cout << "ข้อมูลติดต่อใหม่ (เว้นว่างเพื่อไม่เปลี่ยนแปลง): ";
                std::getline(std::cin, contactInfo);
                if (contactInfo.empty()) contactInfo = member->getContactInfo();
                
                if (library.updateMember(id, name, contactInfo)) {
                    std::cout << "\nอัพเดทข้อมูลสมาชิกสำเร็จ!\n";
                } else {
                    std::cout << "\nไม่สามารถอัพเดทข้อมูลสมาชิกได้\n";
                }
                
                waitForKeyPress();
                break;
            }
            case 3: { // ลบสมาชิก
                clearScreen();
                std::cout << "\n=== ลบสมาชิก ===\n";
                
                std::string id;
                std::cout << "กรอกรหัสสมาชิกที่ต้องการลบ: ";
                std::getline(std::cin, id);
                
                Member* member = library.findMemberById(id);
                if (member == nullptr) {
                    std::cout << "ไม่พบสมาชิกที่มีรหัส: " << id << std::endl;
                    waitForKeyPress();
                    break;
                }
                
                std::cout << "\nข้อมูลสมาชิกที่จะลบ:\n";
                member->display();
                
                char confirm;
                std::cout << "\nต้องการลบสมาชิกนี้ใช่หรือไม่? (y/n): ";
                std::cin >> confirm;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                if (confirm == 'y' || confirm == 'Y') {
                    if (library.removeMember(id)) {
                        std::cout << "\nลบสมาชิกสำเร็จ!\n";
                    } else {
                        std::cout << "\nไม่สามารถลบสมาชิกได้\n";
                    }
                } else {
                    std::cout << "\nยกเลิกการลบสมาชิก\n";
                }
                
                waitForKeyPress();
                break;
            }
            case 4: { // ค้นหาสมาชิก
                int searchChoice = 0;
                
                do {
                    showMemberSearchMenu();
                    std::cin >> searchChoice;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    
                    switch (searchChoice) {
                        case 1: { // ค้นหาด้วยรหัสสมาชิก
                            clearScreen();
                            std::cout << "\n=== ค้นหาสมาชิกด้วยรหัส ===\n";
                            
                            std::string id;
                            std::cout << "กรอกรหัสสมาชิก: ";
                            std::getline(std::cin, id);
                            
                            Member* member = library.findMemberById(id);
                            if (member != nullptr) {
                                std::cout << "\nพบสมาชิก:\n";
                                member->display();
                            } else {
                                std::cout << "\nไม่พบสมาชิกที่มีรหัส: " << id << std::endl;
                            }
                            
                            waitForKeyPress();
                            break;
                        }
                        case 2: { // ค้นหาด้วยชื่อ
                            clearScreen();
                            std::cout << "\n=== ค้นหาสมาชิกด้วยชื่อ ===\n";
                            
                            std::string name;
                            std::cout << "กรอกชื่อสมาชิก (หรือบางส่วน): ";
                            std::getline(std::cin, name);
                            
                            std::vector<Member*> foundMembers = library.findMembersByName(name);
                            displayMembers(foundMembers);
                            
                            waitForKeyPress();
                            break;
                        }
                    }
                    
                } while (searchChoice != 3);
                
                break;
            }
            case 5: { // แสดงสมาชิกทั้งหมด
                clearScreen();
                std::cout << "\n=== แสดงสมาชิกทั้งหมด ===\n";
                
                std::vector<Member*> allMembers = library.getAllMembers();
                displayMembers(allMembers);
                
                waitForKeyPress();
                break;
            }
        }
        
    } while (choice != 6);
}

// จัดการเมนูยืม-คืนหนังสือ
void handleBorrowReturnMenu(Library& library) {
    int choice = 0;
    
    do {
        showBorrowReturnMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch (choice) {
            case 1: { // ยืมหนังสือ
                clearScreen();
                std::cout << "\n=== ยืมหนังสือ ===\n";
                
                std::string memberId, bookId;
                
                std::cout << "กรอกรหัสสมาชิก: ";
                std::getline(std::cin, memberId);
                
                Member* member = library.findMemberById(memberId);
                if (member == nullptr) {
                    std::cout << "ไม่พบสมาชิกที่มีรหัส: " << memberId << std::endl;
                    waitForKeyPress();
                    break;
                }
                
                std::cout << "กรอกรหัสหนังสือที่ต้องการยืม: ";
                std::getline(std::cin, bookId);
                
                Book* book = library.findBookById(bookId);
                if (book == nullptr) {
                    std::cout << "ไม่พบหนังสือที่มีรหัส: " << bookId << std::endl;
                    waitForKeyPress();
                    break;
                }
                
                if (!book->getAvailability()) {
                    std::cout << "หนังสือเล่มนี้ถูกยืมไปแล้ว ไม่สามารถยืมได้\n";
                    waitForKeyPress();
                    break;
                }
                
                if (library.borrowBook(memberId, bookId)) {
                    std::cout << "\nยืมหนังสือสำเร็จ!\n";
                    std::cout << "ชื่อหนังสือ: " << book->getTitle() << "\n";
                    std::cout << "ผู้ยืม: " << member->getName() << "\n";
                    std::cout << "กำหนดคืน: 14 วันนับจากวันนี้\n"; // สมมติกำหนด 14 วัน
                } else {
                    std::cout << "\nไม่สามารถยืมหนังสือได้\n";
                }
                
                waitForKeyPress();
                break;
            }
            case 2: { // คืนหนังสือ
                clearScreen();
                std::cout << "\n=== คืนหนังสือ ===\n";
                
                std::string memberId, bookId;
                
                std::cout << "กรอกรหัสสมาชิก: ";
                std::getline(std::cin, memberId);
                
                Member* member = library.findMemberById(memberId);
                if (member == nullptr) {
                    std::cout << "ไม่พบสมาชิกที่มีรหัส: " << memberId << std::endl;
                    waitForKeyPress();
                    break;
                }
                
                std::cout << "กรอกรหัสหนังสือที่ต้องการคืน: ";
                std::getline(std::cin, bookId);
                
                Book* book = library.findBookById(bookId);
                if (book == nullptr) {
                    std::cout << "ไม่พบหนังสือที่มีรหัส: " << bookId << std::endl;
                    waitForKeyPress();
                    break;
                }
                
                if (!member->hasBorrowed(bookId)) {
                    std::cout << "สมาชิกนี้ไม่ได้ยืมหนังสือเล่มนี้\n";
                    waitForKeyPress();
                    break;
                }
                
                if (library.returnBook(memberId, bookId)) {
                    std::cout << "\nคืนหนังสือสำเร็จ!\n";
                    std::cout << "ชื่อหนังสือ: " << book->getTitle() << "\n";
                    std::cout << "ผู้คืน: " << member->getName() << "\n";
                } else {
                    std::cout << "\nไม่สามารถคืนหนังสือได้\n";
                }
                
                waitForKeyPress();
                break;
            }
            case 3: { // ตรวจสอบหนังสือที่สมาชิกยืม
                clearScreen();
                std::cout << "\n=== ตรวจสอบหนังสือที่สมาชิกยืม ===\n";
                
                std::string memberId;
                std::cout << "กรอกรหัสสมาชิก: ";
                std::getline(std::cin, memberId);
                
                Member* member = library.findMemberById(memberId);
                if (member == nullptr) {
                    std::cout << "ไม่พบสมาชิกที่มีรหัส: " << memberId << std::endl;
                    waitForKeyPress();
                    break;
                }
                
                std::cout << "\nข้อมูลสมาชิก:\n";
                member->display();
                
                std::vector<std::pair<Book*, std::string>> borrowedBooks = library.getBorrowedBooks(memberId);
                
                if (borrowedBooks.empty()) {
                    std::cout << "\nสมาชิกนี้ไม่ได้ยืมหนังสือเล่มใด\n";
                } else {
                    std::cout << "\n=== รายการหนังสือที่ยืม ===\n";
                    std::cout << "รหัส\tชื่อหนังสือ\tผู้แต่ง\tISBN\tวันครบกำหนด\n";
                    std::cout << "-------------------------------------------------------------\n";
                    
                    for (auto& pair : borrowedBooks) {
                        Book* book = pair.first;
                        std::string dueDate = pair.second;
                        
                        std::cout << book->getId() << "\t" 
                                  << book->getTitle() << "\t" 
                                  << book->getAuthor() << "\t" 
                                  << book->getIsbn() << "\t" 
                                  << dueDate << "\n";
                    }
                    std::cout << "-------------------------------------------------------------\n";
                }
                
                waitForKeyPress();
                break;
            }
        }
        
    } while (choice != 4);
}

int main() {
    // สร้างออบเจกต์ Library
    Library library;
    
    int choice = 0;
    
    do {
        clearScreen();
        showMainMenu();
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch (choice) {
            case 1:
                handleBookMenu(library);
                break;
            case 2:
                handleMemberMenu(library);
                break;
            case 3:
                handleBorrowReturnMenu(library);
                break;
            case 4:
                std::cout << "\nขอบคุณที่ใช้บริการระบบจัดการห้องสมุด! กำลังบันทึกข้อมูล...\n";
                library.saveData();
                break;
            default:
                std::cout << "โปรดเลือกรายการที่ถูกต้อง (1-4)\n";
                waitForKeyPress();
                break;
        }
        
    } while (choice != 4);
    
    return 0;
}
