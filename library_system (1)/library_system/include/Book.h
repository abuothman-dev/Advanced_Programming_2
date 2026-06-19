#pragma once
#include <iostream>
#include <string>

// Abstract base class
class Book {
protected:
    int id;
    std::string title;
    std::string author;

public:
    Book(int id, const std::string& title, const std::string& author)
        : id(id), title(title), author(author) {}

    virtual ~Book() = default;

    virtual void display() const = 0;
    virtual std::string getType() const = 0;

    int getId() const { return id; }
    const std::string& getTitle()  const { return title; }
    const std::string& getAuthor() const { return author; }

    // operator== كما طلبه الملف
    bool operator==(const Book& o) const { return id == o.id; }

    // operator>> كما طلبه الملف
    friend std::istream& operator>>(std::istream& is, Book& b) {
        std::cout << "العنوان: ";
        std::getline(is >> std::ws, b.title);
        std::cout << "المؤلف: ";
        std::getline(is >> std::ws, b.author);
        return is;
    }
};
