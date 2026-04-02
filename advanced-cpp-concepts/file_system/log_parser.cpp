#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

int main()
{
    std::ifstream itrIn("server.log");
    std::ofstream itrOut("summary.txt");

    if (!itrIn || !itrOut)
    {
        std::cout << "can not access file!!";
        return -1;
    }
    int total_log = 0;
    std::unordered_map<std::string, int> logtype;
    std::string line;
    itrOut << "Error Message:" << std::endl;
    while (getline(itrIn, line))
    {
        total_log++;
        if (!line.size())
            break;
        std::string date, time, type;
        std::istringstream iss(line);
        iss >> date >> time >> type;
        if (type == "ERROR")
        {
            itrOut << date << " " << time << " " << "- ";
            std::string word;
            while (iss >> word)
            {
                itrOut << word << " ";
            }
            itrOut << std::endl;
        }
        logtype[type]++;
    }
    itrOut << std::endl;
    itrOut << "Summary:" << std::endl;
    itrOut << "Total Logs: " << total_log << std::endl;
    for (const auto &[key, val] : logtype)
    {
        itrOut << key << ": " << val << std::endl;
    }
    return 0;
}