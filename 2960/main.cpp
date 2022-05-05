#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>

int main(void) {
    int N, K;
    std::cin >> N >> K;

    constexpr size_t max_N = 1000;
    std::vector<int> net(N-1);

    std::iota(std::begin(net), std::end(net), 2);

    auto prime = 0, cnt = 0, tar_val = 0;

    while (true) {
        prime = *std::begin(net);

        auto tar_it = std::begin(net);
        while (tar_it != std::end(net)) {

            tar_it = std::find_if(std::begin(net), std::end(net),
                [&prime = std::as_const(prime)](const auto& val){
                    return val % prime == 0;
                }
            );

            if (tar_it != std::end(net)) {
                cnt++;
                tar_val = *tar_it;
                if (cnt == K) {
                    goto end_label;
                }
                net.erase(tar_it);
            }
        }
    }

end_label:
    std::cout << tar_val << std::endl;

    return 0;
} 