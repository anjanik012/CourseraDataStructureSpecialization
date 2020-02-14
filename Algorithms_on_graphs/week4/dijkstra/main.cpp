#include <iostream>

namespace anjani {
    class min_priority_queue {
    private:
        int max_size;
        int size;
        int *H;

        int parent(int i) {
            return (i - 1) / 2;
        }

        int left_child(int i) {
            return 2 * i + 1;
        }

        int right_child(int i) {
            return 2 * i + 2;
        }

        void sift_up(int i) {
            while (i > 0 && H[parent(i)] > H[i]) {
                int temp = H[parent(i)];
                H[parent(i)] = H[i];
                H[i] = temp;
                i = parent(i);
            }
        }

        void sift_down(int i) {
            int min_index = i;
            int l = left_child(i);
            int r = right_child(i);
            if (l <= size && H[l] < H[min_index])
                min_index = l;
            if (r <= size && H[r] < H[min_index])
                min_index = r;
            if (i != min_index) {
                int temp = H[i];
                H[i] = H[min_index];
                H[min_index] = temp;
                sift_down(min_index);
            }
        }

    public:
        explicit min_priority_queue(int max_size) : max_size(max_size) {
            size = -1;
            H = new int[max_size];
        }

        int insert(int p) {
            if (size == max_size)
                return -1;
            size++;
            H[size] = p;
            sift_up(size);
            return 1;
        }

        int get_min() {
            return H[0];
        }

        int extract_min() {
            int result = H[0];
            H[0] = H[size];
            size--;
            sift_down(0);
            return result;
        }

        int remove(int i) {
            H[i] = INT32_MAX;
            sift_up(i);
            return extract_min();
        }

        void change_priority(int i, int p) {
            int oldp = H[i];
            H[i] = p;
            if (p < oldp)
                sift_up(i);
            else
                sift_down(i);
        }
    };
}

int main() {
    anjani::min_priority_queue queue(100);
    queue.insert(60);
    queue.insert(441);
    queue.insert(40);
    std::cout << queue.get_min() << std::endl;
    queue.change_priority(2, 65);

    std::cout << queue.get_min() << std::endl;
}