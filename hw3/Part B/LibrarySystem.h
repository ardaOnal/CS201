// Arda Onal 21903350 Section1
#ifndef __LIBRARYSYSTEM_H
#define __LIBRARYSYSTEM_H
#include <string>
#include "Book.h"
#include "BookList.h"
#include "Student.h"
#include "StudentList2.h"
class LibrarySystem
{
private:
    BookList notBorrowedBooks;
    StudentList2 students;

public:
    LibrarySystem();
    ~LibrarySystem();
    void addBook(const int bookId, const string bookName, const int bookYear);
    void deleteBook(const int bookId);
    void addStudent(const int studentId, const string studentName);
    void deleteStudent(const int studentId);
    void checkoutBook(const int bookId, const int studentId);
    void returnBook(const int bookId);
    void showAllBooks() const;
    void showBook(const int bookId) const;
    void showStudent(const int studentId) const;
};
#endif
