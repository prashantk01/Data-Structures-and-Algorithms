#include <iostream>

// no except specifier is used to indicate that a function does not throw any exceptions.
// If a function is marked as noexcept and it does throw an exception, the program will call std::terminate() and crash.
// This is useful for optimization, as the compiler can make certain assumptions about the function's behavior and generate more efficient code.
// compiler does not create exception handling code for functions marked as noexcept, which can lead to faster execution and smaller binary size.
void func1() noexcept { std::cout << "No exception\n"; }
void func2() { std::cout << "May throw\n"; }
void func3() noexcept
{
    std::cout << "Oops! I encounterd an error\n";
    throw std::runtime_error("Error");
    std::cout << "print!!!!!!!!!!!!!!!!\n";
}

int main()
{
    std::cout << std::boolalpha;
    std::cout << "func1 is noexcept? " << noexcept(func1()) << " and program is running...\n";
    std::cout << "func2 is noexcept? " << noexcept(func2()) << " and program is running...\n";
    std::cout << "func3 is noexcept? " << noexcept(func3()) << " and program is running...\n"
              << std::endl;

    std::cout << "\nNow actually calling functions:\n";
    func1(); // runs fine
    func2(); // runs fine (not marked noexcept, but doesn’t throw)

    // This will crash the program!
    func3(); // marked noexcept, but throws → std::terminate()

    std::cout << "Program ended normally\n"; // This line will never execute
}
