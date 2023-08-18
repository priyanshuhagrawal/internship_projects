#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Student
{
    std::string name;
    int rollNumber;
    int age;

    Student(const std::string &n, int roll, int a) : name(n), rollNumber(roll), age(a) {}
};

class CollegeManagement
{
private:
    std::vector<Student> students;

public:
    void addStudent(const std::string &name, int rollNumber, int age)
    {
        students.push_back(Student(name, rollNumber, age));
    }

    void removeStudent(int rollNumber)
    {
        auto it = std::remove_if(students.begin(), students.end(),
                                 [rollNumber](const Student &student)
                                 {
                                     return student.rollNumber == rollNumber;
                                 });

        if (it != students.end())
        {
            students.erase(it, students.end());
            std::cout << "Student with roll number " << rollNumber << " removed.\n";
        }
        else
        {
            std::cout << "Student with roll number " << rollNumber << " not found.\n";
        }
    }

    void searchStudent(int rollNumber)
    {
        for (const Student &student : students)
        {
            if (student.rollNumber == rollNumber)
            {
                std::cout << "Student Found:\n";
                std::cout << "Name: " << student.name << "\n";
                std::cout << "Roll Number: " << student.rollNumber << "\n";
                std::cout << "Age: " << student.age << "\n";
                return;
            }
        }
        std::cout << "Student with roll number " << rollNumber << " not found.\n";
    }
};

int main()
{
    CollegeManagement college;

    int choice;
    do
    {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Remove Student\n";
        std::cout << "3. Search Student\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            std::string name;
            int rollNumber, age;
            std::cout << "Enter student name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            std::cout << "Enter roll number: ";
            std::cin >> rollNumber;
            std::cout << "Enter age: ";
            std::cin >> age;
            college.addStudent(name, rollNumber, age);
            break;
        }
        case 2:
        {
            int rollNumber;
            std::cout << "Enter roll number of student to remove: ";
            std::cin >> rollNumber;
            college.removeStudent(rollNumber);
            break;
        }
        case 3:
        {
            int rollNumber;
            std::cout << "Enter roll number of student to search: ";
            std::cin >> rollNumber;
            college.searchStudent(rollNumber);
            break;
        }
        case 4:
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
