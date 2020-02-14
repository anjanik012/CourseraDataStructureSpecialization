#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <limits>

namespace anjani {

    std::vector<std::string> string_split(std::string s) {
        std:f:string dilimter = " ";
        int pos = 0;
        std::string token;
        std::vector<std::string> split;
        while ((pos = s.find(dilimter)) != std::string::npos) {
            token = s.substr(0, pos);
            split.push_back(token);
            s.erase(0, pos + 1);
        }
        split.push_back(s);
        return split;
    }

    std::vector<std::string> find_numbers(std::vector<std::string> commands) {
        std::vector<std::string> result, temp;
        std::unordered_map<std::string, std::string> phone_book;
        for (auto &command : commands) {
            temp = string_split(command);
            auto it = phone_book.find(temp[1]);
            if (command[0] == 'a') {
                if (it == phone_book.end()){
                    phone_book.insert(std::make_pair(temp[1], temp[2]));
                } else {
                    phone_book.erase(temp[1]);
                    phone_book.insert(std::make_pair(temp[1], temp[2]));
                }
            } else if (command[0] == 'f') {
                if (it != phone_book.end()) {
                    result.push_back((*it).second);
                } else {
                    result.emplace_back("not found");
                }
            } else {
                if (it != phone_book.end())
                    phone_book.erase(temp[1]);
            }
        }
        return result;
    }
};


int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> commands(n);

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for (int i = 0; i < n; i++)
        std::getline(std::cin, commands[i]);

    std::vector<std::string> result = anjani::find_numbers(commands);
    for (auto &i: result)
        std::cout << i << std::endl;
    return 0;
}