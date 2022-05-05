#include <iostream>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N, M;

    std::cin >> N;
    std::set<int> A;
    std::copy_n(std::istream_iterator<int>(std::cin), N, std::inserter(A, A.begin()));

    std::cin >> M;
    std::vector<int> res(M);
    for (auto i = 0; i < M; ++i) {
        auto val = 0;
        std::cin >> val;
        res[i] = A.find(val) != std::end(A) ? 1 : 0;
    }

    for (const auto& val : res) {
        std::cout << val << std::endl;
    }

    return 0;
}