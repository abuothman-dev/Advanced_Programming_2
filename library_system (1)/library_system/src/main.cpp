#include <iostream>
#include <memory>
#include "../include/Library.h"
#include "../include/PrintedBook.h"
#include "../include/Stack.h"

int main() {
    Library lib;

    // unique_ptr + shared_ptr + هرمية كما طلبه الملف
    try {
        lib.addBook(std::make_shared<PrintedBook>(1, "Clean Code",               "Robert Martin", 431));
        lib.addBook(std::make_shared<PrintedBook>(2, "The Pragmatic Programmer", "Andrew Hunt",   352));
        lib.addBook(std::make_shared<PrintedBook>(3, "Algorithms",               "Sedgewick",     976));
        lib.addBook(std::make_shared<PrintedBook>(4, "Design Patterns",          "GoF",           395));

        // Exception handling: إضافة ID مكرر
        lib.addBook(std::make_shared<PrintedBook>(1, "كتاب مكرر", "مؤلف", 100));

    } catch (const std::exception& e) {
        std::cerr << "خطأ: " << e.what() << std::endl;
    }

    // عرض الكل
    lib.displayAll();

    // STL بحث
    lib.searchByTitle("Clean");

    // STL فلترة
    lib.filterByType("Printed");

    // STL فرز
    lib.displaySortedByTitle();

    // STL تجميع
    std::cout << "\nإجمالي الكتب: " << lib.totalBooks() << std::endl;

    // operator==
    std::cout << "\n===== operator== =====\n";
    PrintedBook b1(10, "Test", "Author", 100);
    PrintedBook b2(10, "Test", "Author", 100);
    PrintedBook b3(11, "Other", "Author", 200);
    std::cout << "b1 == b2: " << (b1 == b2 ? "نعم" : "لا") << std::endl;
    std::cout << "b1 == b3: " << (b1 == b3 ? "نعم" : "لا") << std::endl;

    // Stack<T> كما طلبه الملف
    std::cout << "\n===== Stack<T> =====\n";
    Stack<std::string> stack;
    stack.push("كتاب أ");
    stack.push("كتاب ب");
    stack.push("كتاب ج");
    std::cout << "الأعلى: " << stack.top() << std::endl;
    while (!stack.empty())
        std::cout << "pop: " << stack.pop() << std::endl;

    // Exception handling على Stack
    try { stack.pop(); }
    catch (const std::exception& e) {
        std::cerr << "خطأ Stack: " << e.what() << std::endl;
    }

    return 0;
}
