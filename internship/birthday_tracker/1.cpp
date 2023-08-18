#include <iostream>
#include <string>
#include <vector>
#include <map>

struct Birthday
{
    std::string name;
    int day;
    int month;
};

class BirthdayTracker
{
private:
    std::map<std::string, Birthday> birthdayMap;

public:
    void addBirthday(const std::string &name, int day, int month)
    {
        birthdayMap[name] = {name, day, month};
    }

    void displayBirthdays()
    {
        std::cout << "List of Birthdays:\n";
        for (const auto &entry : birthdayMap)
        {
            const Birthday &birthday = entry.second;
            std::cout << birthday.name << ": " << birthday.day << "/" << birthday.month << "\n";
        }
    }

    void searchBirthdayByName(const std::string &name)
    {
        auto it = birthdayMap.find(name);
        if (it != birthdayMap.end())
        {
            const Birthday &birthday = it->second;
            std::cout << "Birthday of " << birthday.name << ": " << birthday.day << "/" << birthday.month << "\n";
        }
        else
        {
            std::cout << "Birthday not found for " << name << "\n";
        }
    }

    void displayMonthlyBirthdays(int targetMonth)
    {
        std::cout << "Monthly Birthdays for Month " << targetMonth << ":\n";
        for (const auto &entry : birthdayMap)
        {
            const Birthday &birthday = entry.second;
            if (birthday.month == targetMonth)
            {
                std::cout << birthday.name << ": " << birthday.day << "/" << birthday.month << "\n";
            }
        }
    }
};

int main()
{
    BirthdayTracker tracker;

    // Adding sample birthdays
    tracker.addBirthday("John", 15, 8);
    tracker.addBirthday("Alice", 10, 8);
    tracker.addBirthday("Bob", 25, 9);
    tracker.addBirthday("Emily", 5, 7);
    tracker.addBirthday("David", 20, 8);

    int choice;
    do
    {
        std::cout << "\nMenu:\n";
        std::cout << "1. Display Birthdays\n";
        std::cout << "2. Search Birthday by Name\n";
        std::cout << "3. View Monthly Birthdays\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            tracker.displayBirthdays();
            break;
        case 2:
            std::cout << "Enter name to search: ";
            std::string searchName;
            std::cin.ignore();
            std::getline(std::cin, searchName);
            tracker.searchBirthdayByName(searchName);
            break;
        case 3:
            int targetMonth;
            std::cout << "Enter month to view birthdays: ";
            std::cin >> targetMonth;
            tracker.displayMonthlyBirthdays(targetMonth);
            break;
        case 4:
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
