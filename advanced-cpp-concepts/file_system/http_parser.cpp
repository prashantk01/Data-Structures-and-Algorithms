#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::pair<std::string, std::string> getKeyValue(const std::string &line)
{
    int ind = 0;
    for (const auto &ch : line)
    {
        if (ch == ':')
            break;
        ind++;
    }
    if (ind == line.size())
        return {};
    std::string key = line.substr(0, ind);
    std::string value = line.substr(ind + 1);
    return {key, value};
}

int main()
{
    std::ifstream itr("http_input.txt");
    std::ofstream out("parsed_output.txt");

    if (!itr)
    {
        std::cout << "file does not exist!!" << std::endl;
        return -1;
    }

    // 1. Handling Header 1: first method, path, version
    std::string line;
    getline(itr, line);
    std::string method, path, version;
    std::istringstream iss(line);
    iss >> method >> path >> version;
    std::cout << "Method: " << method << std::endl;
    std::cout << "Path: " << path << std::endl;
    std::cout << "Version: " << version << std::endl;

    out << "Method " << method << " " << "Path " << path << " " << "Version " << version << std::endl;

    // 2. Process Key value headers
    int content_length = 0;
    while (getline(itr, line))
    {
        if (line.empty())
            break;
        if (line == "{" || line == "}")
        {
            out << line << std::endl;
            continue;
        }
        auto [key, value] = getKeyValue(line);
        if (!key.size() || !value.size())
        {
            std::cout << "broken key-value pair" << std::endl;
            return -1;
        }
        std::cout << key << ": " << value << std::endl;
        out << key << ": " << value << std::endl;
        if (key == "Content-Length")
        {
            content_length = stoi(value);
            std::cout << "Content Body: " << std::endl;
        }
    }
    return 0;
}