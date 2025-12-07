#include<iostream>
#include<string>

class Person{
    private:
    int size;
    std::string data;

    public:
    Person() = default;

    Person(std::string name) noexcept{
        std::cout<<" Normal constructor\n";
        this->data = name;
        size = name.size();
    }
    
    // copy sonstructor
    Person(const Person& source) noexcept{
        std::cout<<" Copy constructor\n";
        this->data = source.data;
        this->size = source.size;
    }

    // move constructor
    Person(Person&& source) noexcept{
        std::cout<<" Move constructor\n";
        this->data = std::move(source.data);
        this->size = source.size;
        source.data = "";
        source.size = 0;
    }

    Person& operator =(const Person& source) noexcept{
        std::cout<<" Copy assignmnet\n";
        this->data = source.data;
        this->size = source.size;
        return *this;
    }

    Person& operator =(Person&& source) noexcept{
        std::cout<<" Move assignment\n";
        this->data = std::move(source.data);
        this->size = source.size;
        source.data = "";
        source.size = 0;
        return *this;
    }
};

void process(const Person& p) noexcept{
    std::cout<<" Processing lvalue\n";
}

void process(Person&& p) noexcept{
    std::cout<<" Processing rvalue\n";
}

template<typename T>
void wrapper(T&& obj){
    process(std::forward<T>(obj));
}

template<typename T, typename... Args>
T make(Args&&... args){
    return T(std::forward<Args>(args)...);
}

int main(){
    Person p1("John");  // normal construction

    process(p1);                 // lvalue
    process(Person("Temp"));     // rvalue
    process(std::move(p1));      // forced rvalue

    wrapper(p1);                 // lvalue through forward
    wrapper(Person("Temp2"));    // rvalue
    wrapper(std::move(p1));      // rvalue

    Person p2 = make<Person>("Factory");   // rvalue internally
    Person p3 = make<Person>(p2);          // lvalue perfect forwarded
    Person p4 = make<Person>(std::move(p2)); // rvalue forwarded
}