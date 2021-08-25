// Arda Onal 21903350 Section1
#include <string>
#include <iostream>
#include "LibrarySystem.h"
LibrarySystem::LibrarySystem()
{

}
LibrarySystem::~LibrarySystem()
{
    //notBorrowedBooks.~BookList();
    //students.~StudentList2();
}
void LibrarySystem::addBook(const int bookId, const string bookName, const int bookYear)
{
    if ( bookId < 1)
    {
        cout << "Book id must be a positive integer." << endl;
    }

    // Checking if the book already exists in the library.
    bool alreadyExists1 = false;
    for ( int i = 1; i <= notBorrowedBooks.getLength(); i++)
    {
        if (notBorrowedBooks.find(i)->item.getId() == bookId)
        {
            alreadyExists1 = true;
            break;
        }
    }

    // Checking if the book already exists and it is checked out.
    bool alreadyExists2 = false;
    for ( int i = 1; i <= students.getLength();i++)
    {
        for (int j = 1; j <= students.find(i)->item.booksBorrowed.getLength(); j++)
        {
            if ( students.find(i)->item.booksBorrowed.find(j)->item.getId() == bookId)
            {
                alreadyExists2 = true;
                break;
            }
        }

    }

    if ( alreadyExists1 || alreadyExists2)
        cout << "Book " << bookId << " already exists" << endl;
    else
    {
        notBorrowedBooks.insert(notBorrowedBooks.getLength()+ 1, Book(bookId,bookName,bookYear));
        cout << "Book " << bookId << " has been added" << endl;
    }

}
void LibrarySystem::deleteBook(const int bookId)
{
    if ( bookId < 1)
    {
        cout << "Book id must be a positive integer.";
    }

    // Checking if the book is a checked out book
    bool exists = false;
    for ( int i = 1; i <= students.getLength(); i++)
    {
        for ( int j = 1; j <= students.find(i)->item.booksBorrowed.getLength(); j++)
        {
            if (students.find(i)->item.booksBorrowed.find(j)->item.getId() == bookId)
            {
                exists = true;
                students.find(i)->item.booksBorrowed.remove(j); // Deleting the book that student holds.
                cout << "Book " << bookId << " has been returned" << endl;
                cout << "Book " << bookId << " has been deleted" << endl;
                return;
            }
        }
    }

    // Checking if the book is a not checked out book
    for ( int i = 1; i <= notBorrowedBooks.getLength(); i++)
    {
        if (notBorrowedBooks.find(i)->item.getId() == bookId)
        {
            exists = true;
            notBorrowedBooks.remove(i); // Deleting the book.
            cout << "Book " << bookId << " has not been checked out" << endl;
            cout << "Book " << bookId << " has been deleted" << endl;
            return;
        }
    }

    if ( !exists)
        cout << "Book " << bookId << " does not exist" << endl;
}
void LibrarySystem::addStudent(const int studentId, const string studentName)
{
    if ( studentId < 1)
    {
        cout << "Id must be greater than 0" << endl;
        return;
    }

    // Checking if student already exists.
    bool alreadyExists = false;
    for ( int i = 1; i <= students.getLength(); i++)
    {
        if (students.find(i)->item.getId() == studentId)
        {
            alreadyExists = true;
            break;
        }
    }

    if ( alreadyExists)
        cout << "Student " << studentId << " already exists" << endl;
    else
    {
        students.insert((students.getLength()+1), Student(studentId,studentName)); // Adding the student.
        cout << "Student " << studentId << " has been added" << endl;
    }

}
void LibrarySystem::deleteStudent(const int studentId)
{
    for ( int i = 1; i <= students.getLength(); i++)
    {
        if (students.find(i)->item.getId() == studentId)
        {
            // This for loop returns the books of the students that is going to be deleted.
            for ( int j = 1; j <= students.find(i)->item.booksBorrowed.getLength(); j++)
            {
                notBorrowedBooks.insert(notBorrowedBooks.getLength()+1,students.find(i)->item.booksBorrowed.find(j)->item);
                cout << "Book " << students.find(i)->item.booksBorrowed.find(j)->item.getId() << " has been returned" << endl;
            }

            students.remove(i); // deleting student.
            cout << "Student " << studentId << " has been deleted" << endl;
            return;
        }
    }
    cout << "Student " << studentId << " does not exist" << endl;
}
void LibrarySystem::checkoutBook(const int bookId, const int studentId)
{
    if ( bookId < 1 || studentId < 1)
    {
        cout << "Error: Id must be greater than 0." << endl;
        return;
    }

    bool bookExists = false;
    int bookIndex;
    // Checking if the book is in the library.
    for ( int i = 1; i <= notBorrowedBooks.getLength(); i++)
    {
        if ( notBorrowedBooks.find(i)->item.getId() == bookId)
        {
            bookExists = true;
            bookIndex = i;
            break;
        }
    }

    bool checkedOutByOtherStudent = false;
    // Checking if the book is checked out by other student.
    for ( int i = 1; i <= students.getLength(); i++)
    {
        for ( int j = 1; j <= students.find(i)->item.booksBorrowed.getLength();j++)
        {
            if ( students.find(i)->item.booksBorrowed.find(j)->item.getId() == bookId)
            {
                checkedOutByOtherStudent = true;
                break;
            }
        }
    }

    if ( checkedOutByOtherStudent)
    {
        cout << "Book " << bookId << " has been already checked out by another student" << endl;
        return;
    }

    if ( !bookExists)
    {
        cout << "Book " << bookId << " does not exist for checkout" << endl;
        return;
    }

    int studIndex;
    bool studExists = false;
    // Checking if the student with studentId exists.
    for ( int i = 1; i <= students.getLength(); i++)
    {
        if ( students.find(i)->item.getId() == studentId)
        {
            studExists = true;
            studIndex = i;
            break;
        }
    }

    if ( !studExists)
    {
        cout << "Student " << studentId << " does not exist for checkout" << endl;
        return;
    }

    // Adding the book to the students BookList
    students.find(studIndex)->item.booksBorrowed.insert(students.find(studIndex)->item.booksBorrowed.getLength()+1,notBorrowedBooks.find(bookIndex)->item);
    // Deleting the book from not checked out books.
    notBorrowedBooks.remove(bookIndex);

    cout << "Book " << bookId << " has been checked out by student " << studentId << endl;
    return;

}
void LibrarySystem::returnBook(const int bookId)
{
    // Finding the book in all of the students checked out books
    for ( int i = 1; i <= students.getLength(); i++)
    {
        for ( int j = 1; j <= students.find(i)->item.booksBorrowed.getLength(); j++)
        {
            if ( students.find(i)->item.booksBorrowed.find(j)->item.getId() == bookId)
            {
                // Adding the book back to the library
                notBorrowedBooks.insert(notBorrowedBooks.getLength()+1,Book(bookId,students.find(i)->item.booksBorrowed.find(j)->item.getTitle(),students.find(i)->item.booksBorrowed.find(j)->item.getYear()));
                // Deleting the book from the students checked out books
                students.find(i)->item.getBooksBorrowed().remove(j);
                cout << "Book " << bookId << " has been returned" << endl;
                return;
            }
        }
    }

    cout << "Book " << bookId << " has not been checked out" << endl;
}
void LibrarySystem::showAllBooks() const
{
    if ( notBorrowedBooks.getLength() != 0)
        cout << "Book id    Book name               Year    Status" << endl;

    int idLengthCount = 0;
    int nameLengthCount = 0;
    int tmpId;
    bool case1 = false;
    for ( int i = 1; i <= notBorrowedBooks.getLength(); i++)
    {
        case1 = true;
        cout << notBorrowedBooks.find(i)->item.getId();

        // Finding the digit number of id
        tmpId = notBorrowedBooks.find(i)->item.getId();
        while(tmpId != 0)
        {
            tmpId = tmpId / 10;
            idLengthCount++;
        }

        // Printing spaces according to the id digits Note: works for max 11 digits of book id
        for ( int x = 0; x < 11 - idLengthCount; x++)
            cout << " ";

        cout << notBorrowedBooks.find(i)->item.getTitle();

        // Finding the length of the Title string
        nameLengthCount = notBorrowedBooks.find(i)->item.getTitle().size();
        // Printing spaces according to the name length Note: works for max 24 chars of book titles
        for ( int y = 0; y < 24 - nameLengthCount; y++)
            cout << " ";

        // Assuming that year is 4 digits, it is very hard to have books printed before the year 1000
        cout << notBorrowedBooks.find(i)->item.getYear() << "    ";
        cout << "Not checked out" << endl;
        idLengthCount = 0;
        nameLengthCount = 0;

    }

    idLengthCount = 0;
    nameLengthCount = 0;
    bool case2 = true;

    for ( int i = 1; i <= students.getLength(); i++)
    {
        for ( int j = 1; j <= students.find(i)->item.booksBorrowed.getLength(); j++)
        {
            if ( case2 && !case1)
            {
                cout << "Book id    Book name               Year    Status" << endl;
                case2 = false;
            }

            cout << students.find(i)->item.booksBorrowed.find(j)->item.getId();

            tmpId = students.find(i)->item.booksBorrowed.find(j)->item.getId();
            // Finding the digit number of id
            while(tmpId != 0) {
                tmpId = tmpId / 10;
                idLengthCount++;
            }
            // Printing spaces according to the id digits Note: works for max 11 digits of book id
            for ( int y = 0; y < 11 - idLengthCount; y++)
                cout << " ";

            cout << students.find(i)->item.booksBorrowed.find(j)->item.getTitle();

            // Finding the length of the Title string
            nameLengthCount = students.find(i)->item.booksBorrowed.find(j)->item.getTitle().size();
            // Printing spaces according to the name length Note: works for max 24 chars of book titles
            for ( int x = 0; x < 24 - nameLengthCount; x++)
                cout << " ";

            // Assuming that year is 4 digits, it is very hard to have books printed before the year 1000
            cout << students.find(i)->item.booksBorrowed.find(j)->item.getYear() << "    ";
            cout << "Checked out by student " << students.find(i)->item.getId() <<endl;
            idLengthCount = 0;
            nameLengthCount = 0;
        }
    }

    if ( !case1 && case2)
        cout << "There are no books in the library" << endl;
}

void LibrarySystem::showBook(const int bookId) const
{
    int idLengthCount = 0;
    int nameLengthCount = 0;
    int tmpId;

    for ( int i = 1; i <= students.getLength();i++)
    {
        for ( int j = 1; j <= students.find(i)->item.booksBorrowed.getLength(); j++)
        {
            if ( students.find(i)->item.booksBorrowed.find(j)->item.getId() == bookId)
            {
                cout << students.find(i)->item.booksBorrowed.find(j)->item.getId();

                tmpId = students.find(i)->item.booksBorrowed.find(j)->item.getId();
                while(tmpId != 0) {
                    tmpId = tmpId / 10;
                    idLengthCount++;
                }
                for ( int x = 0; x < 11 - idLengthCount; x++)
                    cout << " ";

                cout << students.find(i)->item.booksBorrowed.find(j)->item.getTitle();

                nameLengthCount = students.find(i)->item.booksBorrowed.find(j)->item.getTitle().size();
                for ( int y = 0; y < 24 - nameLengthCount; y++)
                    cout << " ";

                cout << students.find(i)->item.booksBorrowed.find(j)->item.getYear() << "    ";
                cout << "Checked out by student " << students.find(i)->item.getId() <<endl;
                return;
            }
        }
    }


    for ( int i = 1; i <= notBorrowedBooks.getLength();i++)
    {
        if ( notBorrowedBooks.find(i)->item.getId() == bookId)
        {
            cout << notBorrowedBooks.find(i)->item.getId();

            tmpId = notBorrowedBooks.find(i)->item.getId();
            while(tmpId != 0) {
                tmpId = tmpId / 10;
                idLengthCount++;
            }
            for ( int x = 0; x < 11 - idLengthCount; x++)
                cout << " ";

            cout << notBorrowedBooks.find(i)->item.getTitle();

            nameLengthCount = notBorrowedBooks.find(i)->item.getTitle().size();
            for ( int y = 0; y < 24 - nameLengthCount; y++)
                cout << " ";

            cout << notBorrowedBooks.find(i)->item.getYear() << "    ";
            cout << "Not checked out" << endl;
            return;
        }
    }

    cout << "Book " << bookId << "does not exist." << endl;

}
void LibrarySystem::showStudent(const int studentId) const
{
    int idLengthCount;
    int nameLengthCount;
    int tmpId;
    bool exists = false;

    for ( int i = 1; i <= students.getLength(); i++)
    {
        if ( students.find(i)->item.getId() == studentId)
        {
            exists = true;
            cout << "Student id: " << studentId << " student name: " << students.find(i)->item.getName() << endl;

            if (students.find(i)->item.booksBorrowed.getLength() < 1)
            {
                cout << "Student " << studentId << " has no books" << endl;
                return;
            }

            cout << "Student " << studentId << " has checked out the following books:" << endl;
            cout << "Book id    Book name               Year" << endl;

            for ( int j = 1; j <= students.find(i)->item.booksBorrowed.getLength(); j++)
            {
                cout << students.find(i)->item.booksBorrowed.find(j)->item.getId();

                tmpId = students.find(i)->item.booksBorrowed.find(j)->item.getId();
                while(tmpId != 0) {
                    tmpId = tmpId / 10;
                    idLengthCount++;
                }
                for ( int x = 0; x < 11 - idLengthCount; x++)
                    cout << " ";

                cout << students.find(i)->item.booksBorrowed.find(j)->item.getTitle();

                nameLengthCount = students.find(i)->item.booksBorrowed.find(j)->item.getTitle().size();
                for ( int y = 0; y < 24 - nameLengthCount; y++)
                    cout << " ";

                cout << students.find(i)->item.booksBorrowed.find(j)->item.getYear() << endl;

                idLengthCount = 0;
                nameLengthCount = 0;
            }
            break;
        }
    }

    if ( !exists)
        cout << "Student " << studentId << " does not exits" << endl;
}
