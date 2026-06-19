#include "../include/Library.h"
#include <algorithm>
#include <numeric>
#include <stdexcept>
#include <vector>
#include <iostream>

void Library::addBook(std::shared_ptr<Book> book) {
    // Exception handling كما طلبه الملف
    if (catalog.count(book->getId()))
        throw std::invalid_argument("ID موجود مسبقاً: " + std::to_string(book->getId()));
    catalog[book->getId()] = book;
}

void Library::displayAll() const {
    std::cout << "\n===== جميع الكتب (" << catalog.size() << ") =====\n";
    for (const auto& [id, book] : catalog)
        book->display();
}

void Library::searchByTitle(const std::string& keyword) const {
    std::cout << "\n--- نتائج البحث عن: " << keyword << " ---\n";
    // STL بحث
    auto it = std::find_if(catalog.begin(), catalog.end(),
        [&](const auto& pair) {
            return pair.second->getTitle().find(keyword) != std::string::npos;
        });
    if (it == catalog.end())
        std::cout << "لم يُوجد\n";
    else
        it->second->display();
}

void Library::filterByType(const std::string& type) const {
    std::cout << "\n--- كتب من نوع: " << type << " ---\n";
    // STL فلترة
    std::vector<std::shared_ptr<Book>> result;
    for (const auto& [id, book] : catalog)
        if (book->getType() == type) result.push_back(book);

    if (result.empty()) { std::cout << "لا يوجد\n"; return; }
    for (const auto& b : result) b->display();
}

void Library::displaySortedByTitle() const {
    std::cout << "\n--- مرتبة حسب العنوان ---\n";
    std::vector<std::shared_ptr<Book>> sorted;
    for (const auto& [id, book] : catalog) sorted.push_back(book);

    // STL فرز
    std::sort(sorted.begin(), sorted.end(),
        [](const auto& a, const auto& b) {
            return a->getTitle() < b->getTitle();
        });

    for (const auto& b : sorted) b->display();
}

int Library::totalBooks() const {
    // STL تجميع
    return std::accumulate(catalog.begin(), catalog.end(), 0,
        [](int sum, const auto&) { return sum + 1; });
}
