#include <iostream>
#include <string>

const int MAX_STUDENTS = 100; // Maximum number of students in the list

struct Student {
    std::string name;
    int facultyNumber;
};

// Function declarations
void displayStudents(const Student students[], int numStudents);
void addStudent(Student students[], int& numStudents);
void deleteStudent(Student students[], int& numStudents, int facultyNumber);
void changeFacultyNumber(Student students[], int numStudents, int oldFacultyNumber, int newFacultyNumber);
void findStudentByFacultyNumber(const Student students[], int numStudents, int facultyNumber);

int main() {
    Student students[MAX_STUDENTS];
    int numStudents = 0;
    int choice;

    do {
        // Display menu
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Delete Student\n";
        std::cout << "3. Change Faculty Number\n";
        std::cout << "4. Find Student by Faculty Number\n";
        std::cout << "5. Display Students\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students, numStudents);
                break;
            case 2: {
                int facultyNumber;
                std::cout << "Enter Faculty Number to delete: ";
                std::cin >> facultyNumber;
                deleteStudent(students, numStudents, facultyNumber);
                break;
            }
            case 3: {
                int oldFacultyNumber, newFacultyNumber;
                std::cout << "Enter Faculty Number to change: ";
                std::cin >> oldFacultyNumber;
                std::cout << "Enter new Faculty Number: ";
                std::cin >> newFacultyNumber;
                changeFacultyNumber(students, numStudents, oldFacultyNumber, newFacultyNumber);
                break;
            }
            case 4: {
                int facultyNumber;
                std::cout << "Enter Faculty Number to find: ";
                std::cin >> facultyNumber;
                findStudentByFacultyNumber(students, numStudents, facultyNumber);
                break;
            }
            case 5:
                displayStudents(students, numStudents);
                break;
            case 6:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 6);

    return 0;
}

void displayStudents(const Student students[], int numStudents) {
    std::cout << "\nCurrent Students:\n";
    for (int i = 0; i < numStudents; ++i) {
        std::cout << "Name: " << students[i].name << "\t";
        std::cout << "Faculty Number: " << students[i].facultyNumber << "\n";
    }
}

void addStudent(Student students[], int& numStudents) {
    if (numStudents < MAX_STUDENTS) {
        std::cout << "Enter student name: ";
        std::cin >> students[numStudents].name;
        std::cout << "Enter faculty number: ";
        std::cin >> students[numStudents].facultyNumber;
        numStudents++;
        std::cout << "Student added successfully.\n";
        displayStudents(students, numStudents);
    } else {
        std::cout << "Cannot add more students. Maximum limit reached.\n";
    }
}

void deleteStudent(Student students[], int& numStudents, int facultyNumber) {
    for (int i = 0; i < numStudents; ++i) {
        if (students[i].facultyNumber == facultyNumber) {
            // Move the last student to the deleted position
            students[i] = students[numStudents - 1];
            numStudents--;
            std::cout << "Student deleted successfully.\n";
            displayStudents(students, numStudents);
            return;
        }
    }
    std::cout << "Student not found.\n";
}

void changeFacultyNumber(Student students[], int numStudents, int oldFacultyNumber, int newFacultyNumber) {
    for (int i = 0; i < numStudents; ++i) {
        if (students[i].facultyNumber == oldFacultyNumber) {
            students[i].facultyNumber = newFacultyNumber;
            std::cout << "Faculty number changed successfully.\n";
            displayStudents(students, numStudents);
            return;
        }
    }
    std::cout << "Student not found.\n";
}

void findStudentByFacultyNumber(const Student students[], int numStudents, int facultyNumber) {
    for (int i = 0; i < numStudents; ++i) {
        if (students[i].facultyNumber == facultyNumber) {
            std::cout << "Student found:\n";
            std::cout << "Name: " << students[i].name << "\n";
            std::cout << "Faculty Number: " << students[i].facultyNumber << "\n";
            return;
        }
    }
    std::cout << "Student not found.\n";
}
