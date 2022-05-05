#include <iostream>

inline auto blanks_and_stars(size_t num_blanks, size_t num_stars) {
    return std::string(num_blanks, ' ') + std::string(num_stars, '*');
}

int main(void) {
    size_t n;
    std::cin >> n;

    for (size_t i = 0; i < n; ++i) {
        std::cout << blanks_and_stars(i, n-i) << std::endl;
    }

    return 0;
}