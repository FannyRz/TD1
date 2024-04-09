#include <iostream>
#include <vector>
#include <algorithm>

#include "tri.hpp"
#include "ScopedTimer.hpp"

int main()
{
    std::vector<int> array_int {1,4,6,5,7,9,2};
    std::vector<int> array_int_trie {1, 2, 2, 3, 4, 8, 12};
    std::vector<float> array_float {1.f,4.f,6.f,5.f,7.f,9.f,2.f};
    std::vector<float> array_big {(generate_random_vector(100,50))};

    // if (is_sorted(array)) {
    //     std::cout << "Le tableau est trie" << std::endl;
    // } else {
    //     std::cout << "Le tableau n'est pas trie" << std::endl;
    // }

    // selection_sort(array_int);
    // merge_sort(array_float);
    // display(array_float);

    {
        ScopedTimer timer("nom du chronometre");
            merge_sort(array_big);
    }
    {
        ScopedTimer timer("nom du chronometre");
            std::sort(array_big.begin(), array_big.end());
    }

    //pour tester la dichotomie

    std::cout << search({1, 2, 2, 3, 4, 8, 12}, 8) << std::endl;
    std::cout << search({1, 2, 3, 3, 6, 14, 12, 15}, 15) << std::endl;
    std::cout << search({2, 2, 3, 4, 5, 8, 12, 15, 16}, 16) << std::endl;
    std::cout << search({5, 6, 7, 8, 9, 10, 11, 12, 13}, 6) << std::endl;
    std::cout << search({1, 2, 3, 4, 5, 6, 7, 8, 9}, 10) << std::endl;
}