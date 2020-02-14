#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

string BWT(const string& text) {
    string result, temp_text = text;
    const int size = text.size();

    vector<string> M;
    do {
        M.push_back(temp_text);
        char last_char = temp_text.back();
        temp_text = temp_text.substr(0, size - 1);
        temp_text = last_char + temp_text;
    } while (temp_text != text);

    sort(M.begin(), M.end());

    result = "";
    for (const auto &str : M) {
        result += str.back();
    }

    return result;
}

int main() {
    string text;
    cin >> text;
    cout << BWT(text) << endl;
    return 0;
}