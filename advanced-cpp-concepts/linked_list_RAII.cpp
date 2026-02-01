#include <iostream>
#include <memory>

class node
{
public:
    int data;
    // node *next;
    std::unique_ptr<node> next;
    node(int val)
    {
        data = val;
        next = nullptr;
    };
};

class list
{
private:
    std::unique_ptr<node> head;

public:
    list() { head = nullptr; }

    // move constructor
    list(list &&other) noexcept
    {
        this->head = std::move(other.head);
    }

    // move assignment
    list &operator=(list &&other)
    {
        if (this != &other)
        {
            this->head = std::move(other.head);
        }
        return *this;
    }

    void insert_at_end(int val)
    {
        // node *newnode = new node(val);
        std::unique_ptr<node> newnode = std::make_unique<node>(val);
        if (!head)
        {
            head = std::move(newnode);
        }
        else
        {
            node *temp = head.get();
            // node *temp = head;
            while (temp->next)
            {
                temp = temp->next.get();
                // temp = temp->next;
            }
            temp->next = std::move(newnode);
        }
    }
    void printlist()
    {
        node *temp = head.get();
        for (; temp != nullptr; temp = temp->next.get())
            std::cout << temp->data << " ";
        std::cout << std::endl;
    }
    void insert_at_start(int val)
    {
        // node* newnode = new node(val);
        std::unique_ptr<node> newnode = std::make_unique<node>(val);
        if (!head)
        {
            head = std::move(newnode);
            return;
        }
        newnode->next = std::move(head);
        head = std::move(newnode);
    }
};

int main()
{
    list obj;
    obj.insert_at_end(10);   // insert(10)
    obj.insert_at_end(20);   // insert(20)
    obj.insert_at_end(30);   // insert(30)
    obj.insert_at_end(40);   // insert(40)
    obj.printlist();         // display
    obj.insert_at_start(50); // insert(50)
    obj.printlist();         // display
    list obj2 = std::move(obj);
    obj2.printlist();
    return 0;
}