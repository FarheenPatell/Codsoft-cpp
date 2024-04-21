#include <iostream>
#include <vector>
#include <string>

// Define a structure to represent a book
struct Book {
    std::string title;
    std::string author;
    std::string ISBN;
    bool available;
};

// Define a structure to represent a borrower
struct Borrower {
    std::string name;
    std::string ID;
};

// Define a structure to represent a transaction
struct Transaction {
    Book book;
    Borrower borrower;
    std::string checkoutDate;
    std::string returnDate;
    double fine;
};

// Define a library class to manage books, borrowers, and transactions
class Library {
private:
    std::vector<Book> books;
    std::vector<Borrower> borrowers;
    std::vector<Transaction> transactions;

public:
    // Function to add a book to the library
    void addBook(const Book& book) {
        books.push_back(book);
    }

    // Function to search for books by title, author, or ISBN
    void searchBooks(const std::string& query) {
        for (const auto& book : books) {
            if (book.title == query || book.author == query || book.ISBN == query) {
                std::cout << "Book Found: " << book.title << " by " << book.author << " (ISBN: " << book.ISBN << ")\n";
            }
        }
    }

    // Function to check out a book to a borrower
    void checkoutBook(const Book& book, const Borrower& borrower, const std::string& checkoutDate) {
        for (auto& b : books) {
            if (b.ISBN == book.ISBN && b.available) {
                b.available = false;
                transactions.push_back({book, borrower, checkoutDate, "", 0.0});
                std::cout << "Book checked out successfully.\n";
                return;
            }
        }
        std::cout << "Book not available for checkout.\n";
    }

    // Function to return a book
    void returnBook(const Book& book, const std::string& returnDate, double fine) {
        for (auto& b : books) {
            if (b.ISBN == book.ISBN) {
                b.available = true;
                for (auto& trans : transactions) {
                    if (trans.book.ISBN == book.ISBN && trans.returnDate.empty()) {
                        trans.returnDate = returnDate;
                        trans.fine = fine;
                        std::cout << "Book returned successfully.\n";
                        return;
                    }
                }
            }
        }
        std::cout << "Book not found or already returned.\n";
    }
};

int main() {
    // Create a library object
    Library library;

    // Add some books to the library
    library.addBook({"The Great Gatsby", "F. Scott Fitzgerald", "9780743273565", true});
    library.addBook({"To Kill a Mockingbird", "Harper Lee", "9780061120084", true});
    library.addBook({"1984", "George Orwell", "9780451524935", true});

    // Search for a book
    library.searchBooks("George Orwell");

    // Perform a book checkout
    Borrower borrower = {"John Doe", "12345"};
    library.checkoutBook({"1984", "George Orwell", "9780451524935", true}, borrower, "2022-04-15");

    // Perform a book return
    library.returnBook({"1984", "George Orwell", "9780451524935", true}, "2022-05-01", 0.0);

    return 0;
}
