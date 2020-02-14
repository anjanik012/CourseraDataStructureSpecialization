#include<iostream>
#include<vector>
#include<queue>
#include <array>

namespace anjani {

    struct pair {
        int thread;
        uint64_t t_begin;
    };

    std::vector<pair> schedule(const int n, std::vector<uint64_t> job_list) {
        std::priority_queue<int, std::vector<int>, std::greater<>> job_priority;
        uint64_t t_f[n];
        for (int i = 0; i < n; i++) {
//            job_priority.push(i);
            t_f[i] = 0;
        }
        std::vector<pair> pairs;
        pair p;
        uint64_t time_elapsed = 0;
        int i;
        auto job = job_list.begin();
        while (job != job_list.end()) {
            for (int j = 0; j < n && job != job_list.end(); j++) {
                if (time_elapsed == t_f[j])
                    job_priority.push(j);
            }

            while (!job_priority.empty() && job != job_list.end()) {
                i = job_priority.top();
                t_f[i] = time_elapsed + *job;
                p.thread = i;
                p.t_begin = time_elapsed;
                pairs.push_back(p);
                job_priority.pop();
                job++;
            }
            time_elapsed++;

        }
        return pairs;
    }

};


int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<uint64_t> job_list(m);
    for (size_t i = 0; i < m; i++)
        std::cin >> job_list[i];

    std::vector<anjani::pair> pairs = anjani::schedule(n, job_list);
    for (auto p : pairs) {
        std::cout << p.thread << ' ' << p.t_begin << std::endl;
    }

    return 0;
}