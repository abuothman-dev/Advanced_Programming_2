#pragma once
#include "Book.h"
#include "Stack.h"
#include <map>
#include <memory>
#include <string>

class Library {
    // std::map<int, shared_ptr<Book>> كما طلبه الملف
    std::map<int, std::shared_ptr<Book>> catalog;

public:
    // إضافة كتاب
    void addBook(std::shared_ptr<Book> book);

    // عرض الكل
    void displayAll() const;

    // بحث بالعنوان — STL بحث
    void searchByTitle(const std::string& keyword) const;

    // فلترة حسب النوع — STL فلترة
    void filterByType(const std::string& type) const;

    // فرز حسب العنوان — STL فرز
    void displaySortedByTitle() const;

    // تجميع: عدد الكتب — STL تجميع
    int totalBooks() const;
};
