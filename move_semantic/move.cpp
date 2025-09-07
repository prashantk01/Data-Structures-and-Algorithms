#include<iostream>
#include<vector>

void display(const std::vector<int>& vec){
    std::cout << "vector starting address: " << &vec <<" and size: " <<vec.size() << std::endl;
    for (auto i : vec)
    {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}
int main(){
    std::vector<int> vec1;
    std::vector<int> vec2;
    int a = 5;
    for(int i=0;i<a;i++){
        vec1.push_back(i+1); 
        vec2.push_back(i+11); 
    }
    display(vec1);
    display(vec2);

    vec2 = std::move(vec1); // move assignment, vec1 is now in a valid but unspecified state
    display(vec1); // vec1 is in a valid but unspecified state, size may be 0
    display(vec2); // vec2 has taken ownership of vec1's data
}