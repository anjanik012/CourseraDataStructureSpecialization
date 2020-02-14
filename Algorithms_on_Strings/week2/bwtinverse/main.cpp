#include <iostream>
#include <vector>
#include <map>
#include <string>

using std::vector;
using std::map;
using std::cout;
using std::cin;
using std::string;
using std::pair;

typedef map<pair<char, int>, int> Map;
typedef vector<pair<char, int>> Pairs;

int char_to_index(char c) {
    switch (c) {
        case '$':
            return 0;
        case 'A':
            return 1;
        case 'C':
            return 2;
        case 'G':
            return 3;
        case 'T':
            return 4;
        default:
            return -1;
    }
}

char index_to_char(int i) {
    switch (i) {
        case 0:
            return '$';
        case 1:
            return 'A';
        case 2:
            return 'C';
        case 3:
            return 'G';
        case 4:
            return 'T';
        default:
            return -1;
    }
}

Map create_map(const string &str) {
    Map m;
    int count[5] = {0, 0, 0, 0, 0};
    for (int i = 0; i < str.size(); i++) {
        char c = str[i];
        count[char_to_index(c)]++;
        m.insert({{c, count[char_to_index(c)]}, i});
    }
    return m;
}

Pairs create_sorted_pairs(const string &str) {
    Pairs p;
    int count[5] = {0, 0, 0, 0, 0};
    for (const auto &c: str) {
        count[char_to_index(c)]++;
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < count[i]; ++j) {
            p.push_back({index_to_char(i), j + 1});
        }
    }
    return p;
}


string reverse_bwt(const string &bwt) {
    string result = "";
    Map m = create_map(bwt);            // O(n) time
    Pairs pairs = create_sorted_pairs(bwt); // O(n) time
    auto n_pair = pairs[0];
    do{
        auto i = m.find(n_pair);
        int j = i->second;
        n_pair = pairs[j];
        result += n_pair.first;
    } while (n_pair != pairs[0]);
    return result;
}


int main() {
    string str;
    cin >> str;
    cout << reverse_bwt(str);
    return 0;
}