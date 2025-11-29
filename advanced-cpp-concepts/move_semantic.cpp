// move semantic
// Introduces in Modern C++ (C++11 and later) 
// It transfers ownership of resources from one object to another without making a copy
// Used in performance optimization avoiding unnecessary deep copies of large objects
// Involves rvalue references (&&), move constructors and move assignment operators

// copy constructor and copy assignment operator create deep copies of objects
// move constructor and move assignment operator transfer ownership of resources from one object to another


#include <iostream>
#include <vector>
#include <string>

class StudentRecord {
private:
    std::vector<int> stmarks;
    std::string stName;

public:
    StudentRecord() = default;

    StudentRecord(const StudentRecord& other) noexcept // take const lvalue reference
        : stmarks(other.stmarks), stName(other.stName)
    {
        std::cout << "Copy Constructor\n";
    }

    StudentRecord(StudentRecord&& other) noexcept // take rvalue reference
        : stmarks(std::move(other.stmarks)), stName(std::move(other.stName))
    {
        std::cout << "Move Constructor\n";
    }

    StudentRecord& operator=(const StudentRecord& other) noexcept {
        std::cout << "Copy Assignment\n";
        if (this != &other) {
            stmarks = other.stmarks;
            stName = other.stName;
        }
        return *this;
    }

    StudentRecord& operator=(StudentRecord&& other) noexcept {
        std::cout << "Move Assignment\n";
        if (this != &other) {
            stmarks = std::move(other.stmarks);
            stName = std::move(other.stName);
        }
        return *this;
    }

    void setData(std::string name, std::vector<int> marks) {
        stName = std::move(name);
        stmarks = std::move(marks);
    }

    void display() const {
        std::cout << "Name: " << stName << "\nMarks: ";
        for (int m : stmarks) std::cout << m << " ";
        std::cout << "\n";
    }
};

StudentRecord createStudentRecord() {
    StudentRecord s;
    s.setData("Johny Johny", {85, 90, 78, 92});
    return s;
}

int main() {
    StudentRecord r1 = createStudentRecord();
    r1.display();

    StudentRecord r2;
    r2 = std::move(r1);
    r1.display(); // r1 is in a valid but unspecified state

    StudentRecord r3 = std::move(r2);

    r3.display();
}
/*
Name: Johny Johny
Marks: 85 90 78 92 
Move Assignment
Move Constructor
Name: Johny Johny
Marks: 85 90 78 92*/
