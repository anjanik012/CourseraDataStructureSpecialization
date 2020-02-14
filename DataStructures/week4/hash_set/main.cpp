#include <iostream>
#include <vector>
#include <string>
#include <forward_list>
#include <limits>

namespace anjani {

    class hash_set {
    private:
        int number_of_buckets;
        std::vector<std::forward_list<std::string>> buckets;
        static uint64_t mod_power(int x, int i, int p){
            uint64_t ans = 1;
            if (i <= 0)
                return 1;
            else {
                for(int y = 1; y <= i; y++){
                    ans = (ans * x) % p;
                }
                ans %= p;
            }
            return ans;
        }
    public:
        explicit hash_set(int n) {
            number_of_buckets = n;
            buckets.resize(n);
        }

        static uint64_t hasher(const std::string &s, const int &m) {
            uint64_t h = 0;
            const int p = 1000000007;
            const int x = 263;
            const int l = s.length();
            for (int i = 0; i < l; i++) {
                uint64_t s_i = s[i];
                uint64_t mul = mod_power(x, i, p);
                uint64_t y = (s_i * mul)%p;
                h = (h + y)%p;
            }
            h = h % m;
            return h;
        }

        bool find(const std::string &key) {
            uint64_t hash_key = hasher(key, number_of_buckets);
            auto item = buckets[hash_key];
            bool ans = false;
            for (auto &i: item) {
                if (i == key) {
                    ans = true;
                    break;
                }
            }
            return ans;
        }

        void add(const std::string &key) {
            uint64_t hash_key = hasher(key, number_of_buckets);
            if (!find(key))
                buckets[hash_key].push_front(key);
        }

        void del(const std::string &key) {
            uint64_t hash_key = hasher(key, number_of_buckets);
            if (find(key))
                buckets[hash_key].remove(key);
        }

        std::string check(int i) {
            auto item = buckets[i];
            std::string r;
            for (auto &a: item) {
                r.append(a);
                r.append(" ");
            }
            if (item.empty())
                r = "\n";
            return r;
        }
    };

    std::vector<std::string> string_split(std::string s) {
        std::string dilimter = " ";
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

    std::vector<std::string> execute_commands(hash_set &set, const std::vector<std::string> &commands) {
        std::vector<std::string> ans, split;
        for (auto &command : commands) {
            split = string_split(command);
            if (command[0] == 'a') {
                set.add(split[1]);
            } else if (command[0] == 'f') {
                if (set.find(split[1]))
                    ans.emplace_back("yes");
                else
                    ans.emplace_back("no");
            } else if (command[0] == 'd') {
                set.del(split[1]);
            } else if (command[0] == 'c') {
                std::string x = set.check(std::stoi(split[1]));
                ans.push_back(x);
            }
        }
        return ans;
    }

}

int main() {
    int m, n;
    std::cin >> m >> n;
    std::vector<std::string> commands(n);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for (int i = 0; i < n; ++i)
        std::getline(std::cin, commands[i]);

    anjani::hash_set set(m);
    std::vector<std::string> ans = anjani::execute_commands(set, commands);
    for (auto &i : ans) {
        if (i == "\n")
            std::cout << i;
        else
            std::cout << i << std::endl;
    }
//    std::cout<<anjani::hash_set::hasher("abcdefghijklmgytuygrw", 101);
    return 0;

}

