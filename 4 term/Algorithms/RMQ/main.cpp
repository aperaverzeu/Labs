#include <iostream>
#include <vector>

class rmq {
public:
    static const int log_2 = 6;

    int table[log_2][100]{};
    int pow2[log_2]{};
//    std::vector<uint64_t> pow2(log_2);
    std::vector<uint64_t> u;


    void preprocess(const std::vector<uint64_t>& array) {

        // pow in 2
        pow2[0] = 1;
        for (int i = 1; i < log_2; i++) {
            pow2[i] = pow2[i - 1] * 2;
        }

        // power in k
        for (int i = 0; i < array.size(); i++) {
            for (int j = 0; j < 1 << i; j++) {
                u.push_back(i);
            }
        }

        // first row
        for (int i = 0; i < array.size(); i++) {
            table[0][i] = array[i];
        }

        // entering table
        for (int k = 1; k < log_2; k++) {
            for (int i = 0; i < array.size(); i++) {
                table[k][i] = std::min(table[k-1][i], table[k-1][i + pow2[k-1]]);
            }
        }

        // output
        for (int k = 0; k < array.size(); k++) {
            for (int i = 0; i < array.size(); i++) {
                std::cout << table[k][i] << "\t";
            }
            std::cout << std::endl;
        }
    }

    uint64_t query(int left, int right) {
        auto o = std::min(table[u[right - left + 1]][left], table[u[right - left + 1]][right - pow2[u[right - left + 1]] + 1]);
        return o;
    }

    uint64_t min(int left, int right) {
        return query(left, right);
    }
      
};

int main() {
    std::vector<uint64_t> array = {2, 2, 8, 3, 2, 2};

    rmq r;
    r.preprocess(array);
    std::cout << r.min(0, 3) << std::endl;

    return 0;
}
