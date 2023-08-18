#include <iostream>
#include <string>
#include <map>

class LibraryManagementSystem
{
private:
    std::map<std::string, std::string> users;

public:
    LibraryManagementSystem()
    {
        // Pre-populating with sample user data for demonstration purposes
        users["student1"] = "password1";
        users["librarian1"] = "password2";
    }

    bool login(const std::string &username, const std::string &password)
    {
        auto it = users.find(username);
        if (it != users.end() && it->second == password)
        {
            return true;
        }
        return false;
    }

    void studentMenu()
    {
        std::cout << "Student Menu\n";
        // Implement student-specific actions here
    }

    void librarianMenu()
    {
        std::cout << "Librarian Menu\n";
        // Implement librarian-specific actions here
    }
};

int main()
{
    LibraryManagementSystem library;

    int choice;
    std::string username, password;

    do
    {
        std::cout << "\nMenu:\n";
        std::cout << "1. Login\n";
        std::cout << "2. Student\n";
        std::cout << "3. Librarian\n";
        std::cout << "4. Search\n";
        std::cout << "5. Close Application\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "Enter username: ";
            std::cin >> username;
            std::cout << "Enter password: ";
            std::cin >> password;
            if (library.login(username, password))
            {
                std::cout << "Login successful.\n";
            }
            else
            {
                std::cout << "Login failed. Invalid credentials.\n";
            }
            break;
        case 2:
            if (library.login(username, password))
            {
                library.studentMenu();
            }
            else
            {
                std::cout << "Please login first.\n";
            }
            break;
        case 3:
            if (library.login(username, password))
            {
                library.librarianMenu();
            }
            else
            {
                std::cout << "Please login first.\n";
            }
            break;
        case 4:
            std::cout << "Search operation\n";
            // Implement search functionality here
            break;
        case 5:
            std::cout << "Closing application.\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
