#include <iostream>
#include <string>
#include <vector>

namespace anjani {
    struct triplet {
        int a;
        int b;
        int l;
    };

    std::vector<std::string> find_sub_str(const std::string &input, const std::vector<anjani::triplet> &queries) {
        std::vector<std::string> ans(queries.size());
        auto it = ans.begin();
        for (auto &query:queries) {
            if (input.substr(query.a, query.l) == input.substr(query.b, query.l))
                *it = "Yes";
            else
                *it = "No";
            it++;
        }
        return ans;
    }

};

int main() {
    std::string input;
    std::getline(std::cin, input);
    int n;
    std::cin >> n;
    std::vector<anjani::triplet> queries(n);
    for (int i = 0; i < n; ++i)
        std::cin >> queries[i].a >> queries[i].b >> queries[i].l;

    std::vector<std::string> ans = anjani::find_sub_str(input, queries);
    for (auto &i: ans)
        std::cout << i << std::endl;

    return 0;
}