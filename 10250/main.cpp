#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using namespace std::string_literals;
using HWN = std::tuple<int, int, int>;

inline auto read_HWN() -> HWN{
    int H, W, N;
    std::cin >> H >> W >>N;

    return std::make_tuple(H, W, N);
}

inline auto pad_zero(const std::string& num) -> std::string {
    return num.length() == 1 ? "0"s + num : num;
}

inline auto count_X(const HWN& hwn){
    const auto& [H, W, N] = hwn;

    return pad_zero(std::to_string((N -1) / H + 1));
}

inline auto count_Y(const HWN& hwn) {
    const auto& [H, W, N] = hwn;

    return std::to_string((N-1) % H +1);
}

int main(void) {
    size_t T;
    std:: cin >> T;
    std::vector<HWN> customers;

    for (auto i = 0; i < T; ++i) {
        customers.push_back(read_HWN());
    }

    for (const auto& customer : customers) {
        std::cout << count_Y(customer) + count_X(customer) << std::endl;
    }

    return 0;
} 