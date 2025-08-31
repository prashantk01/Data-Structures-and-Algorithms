#include <iostream>

void func1() noexcept { std::cout << "No exception\n"; }
void func2() { std::cout << "May throw\n"; }
void func3() noexcept {
    std::cout<< "Oops! I encounterd an error\n";
    throw std::runtime_error("Error");
}

int main() {
    std::cout << std::boolalpha;
    std::cout << "func1 is noexcept? " << noexcept(func1()) <<" and program is running...\n";
    std::cout << "func2 is noexcept? " << noexcept(func2()) <<" and program is running...\n";
    std::cout << "func3 is noexcept? " << noexcept(func3()) <<" and program is running...\n"<<std::endl;

    std::cout << "\nNow actually calling functions:\n";
    func1();   // runs fine
    func2();   // runs fine (not marked noexcept, but doesn’t throw)

    // This will crash the program!
    func3();   // marked noexcept, but throws → std::terminate()
    
    std::cout << "Program ended normally\n"; // This line will never execute
}
