#pragma once
#include "Book.h"

// Derived class
class PrintedBook : public Book {
    int pages;
public:
    PrintedBook(int id, const std::string& title,
                const std::string& author, int pages)
        : Book(id, title, author), pages(pages) {}

    std::string getType() const override { return "Printed"; }

    void display() const override {
        std::cout << "[" << getType() << "] ID:" << id
                  << " | " << title
                  << " | " << author
                  << " | صفحات:" << pages
                  << std::endl;
    }
};
