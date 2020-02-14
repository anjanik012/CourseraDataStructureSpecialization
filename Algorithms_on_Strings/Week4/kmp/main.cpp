#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;

// Find all occurrences of the pattern in the text and return a
// vector with all positions in the text (starting from 0) where
// the pattern starts in the text.

vector<int> compute_prefix_function(const string &str) {
    vector<int> s(str.size());
    s[0] = 0;
    int border = 0;
    for (int i = 1; i < str.size(); i++) {
        while ((border > 0) && (str[i] != str[border])) {
            border = s[border - 1];
        }
        if (str[i] == str[border]) {
            border++;
        } else {
            border = 0;
        }
        s[i] = border;
    }
    return s;
}


vector<int> find_pattern(const string &pattern, const string &text) {
    vector<int> result;
    string S = pattern + "$" + text;
    auto s = compute_prefix_function(S);
    for (unsigned long i = pattern.size() + 1; i < S.size(); i++) {
        if (s[i] == pattern.size()) {
            result.push_back(i - 2*pattern.size());
        }
    }
    return result;
}

int main() {
    string pattern, text;
    cin >> pattern;
    cin >> text;
    vector<int> result = find_pattern(pattern, text);

    for (auto &i: result) {
        cout << i << " ";
    }

    return 0;
}
