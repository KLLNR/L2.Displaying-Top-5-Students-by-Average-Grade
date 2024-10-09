#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

class Student {
private:
    string surname;
    string id;
    vector<int> grades;

public:
    Student(string surname, string id, vector<int> grades)
        : surname(surname), id(id), grades(grades) {}

    string getSurname() const {
        return surname;
    }

    string getId() const {
        return id;
    }

    double getAverageGrade() const {
        if (grades.empty()) return 0;
        double sum = 0;
        for (int grade : grades) {
            sum += grade;
        }
        return sum / grades.size();
    }

    bool operator<(const Student& other) const {
        return this->getAverageGrade() > other.getAverageGrade();
    }
};

class Group {
private:
    vector<Student> students;

public:
    Group(vector<Student> students) : students(students) {}

    void printTop5Students() {
        sort(students.begin(), students.end());

        cout << "Top 5 students with the highest average grade:\n";
        for (int i = 0; i < 5 && i < students.size(); ++i) {
            cout << i + 1 << ". " << students[i].getSurname()
                << " (ID: " << students[i].getId()
                << ", Average Grade: " << students[i].getAverageGrade() << ")\n";
        }
    }
};

int main() {
    Student student1("Petrenko", "12345", { 50, 46, 54, 52 });
    Student student2("Ivanenko", "23456", { 31, 44, 56, 39 });
    Student student3("Sydorenko", "34567", { 61, 78, 80, 50 });
    Student student4("Kovalenko", "45678", { 90, 97, 81, 90 });
    Student student5("Melnyk", "56789", { 42, 80, 58, 30 });
    Student student6("Shevchenko", "67890", { 78, 87, 90, 96 });
    Student student7("Navchenko", "67890", { 100, 89, 90, 98 });
    Student student8("Kuprichenko", "67890", { 50, 65, 87, 98 });

    Group group({ student1, student2, student3, student4, student5, student6, student7, student8 });

    group.printTop5Students();

    return 0;
}
