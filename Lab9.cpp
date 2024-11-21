#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

struct Book {
    string title;
    string author;
    string isbn;
    int year;

    Book(string t, string a, string i, int y)
        : title(t), author(a), isbn(i), year(y) {}
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    bool removeBookByISBN(const string& isbn) {
        for (size_t i = 0; i < books.size(); ++i) {
            if (books[i].isbn == isbn) {
                books.erase(books.begin() + i);
                return true;
            }
        }
        return false;
    }

    vector<Book> findBooksByAuthor(const string& author) const {
        vector<Book> result;
        for (size_t i = 0; i < books.size(); ++i) {
            if (books[i].author == author) {
                result.push_back(books[i]);
            }
        }
        return result;
    }

    void listAllBooks() const {
        if (books.empty()) {
            cout << "Бібліотека порожня." << endl;
        }
        else {
            for (size_t i = 0; i < books.size(); ++i) {
                cout << "Назва: " << books[i].title
                    << ", Автор: " << books[i].author
                    << ", ISBN: " << books[i].isbn
                    << ", Рік: " << books[i].year << endl;
            }
        }
    }

    vector<Book> findBooksByYearRange(int startYear, int endYear) const {
        vector<Book> result;
        for (size_t i = 0; i < books.size(); ++i) {
            if (books[i].year >= startYear && books[i].year <= endYear) {
                result.push_back(books[i]);
            }
        }
        return result;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Library library;

    library.addBook(Book("Кобзар", "Тарас Шевченко", "123456789", 1840));
    library.addBook(Book("Лісова пісня", "Леся Українка", "987654321", 1911));
    library.addBook(Book("Тіні забутих предків", "Михайло Коцюбинський", "192837465", 1912));

    cout << "Всі книги у бібліотеці:" << endl;
    library.listAllBooks();

    cout << "\nКниги автора 'Леся Українка':" << endl;
    vector<Book> authorBooks = library.findBooksByAuthor("Леся Українка");
    for (size_t i = 0; i < authorBooks.size(); ++i) {
        cout << "Назва: " << authorBooks[i].title
            << ", Рік: " << authorBooks[i].year << endl;
    }

    cout << "\nКниги, видані між 1900 і 2000 роками:" << endl;
    vector<Book> yearRangeBooks = library.findBooksByYearRange(1900, 2000);
    for (size_t i = 0; i < yearRangeBooks.size(); ++i) {
        cout << "Назва: " << yearRangeBooks[i].title
            << ", Рік: " << yearRangeBooks[i].year << endl;
    }

    cout << "\nВидалення книги з ISBN 123456789." << endl;
    if (library.removeBookByISBN("123456789")) {
        cout << "Книга успішно видалена." << endl;
    }
    else {
        cout << "Книга з таким ISBN не знайдена." << endl;
    }

    cout << "\nОновлений список книг:" << endl;
    library.listAllBooks();

    return 0;
}
