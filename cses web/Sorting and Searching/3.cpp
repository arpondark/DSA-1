#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, x;
    std::cin >> n >> x;

    std::vector<int> weights(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> weights[i];
    }

    // Sort the weights
    std::sort(weights.begin(), weights.end());

    int left = 0;
    int right = n - 1;
    int gondolas = 0;

    while (left <= right) {
        if (weights[left] + weights[right] <= x) {
            // Heaviest and lightest can share a gondola
            ++left;
        }
        // Always need one gondola for the heaviest child
        ++gondolas;
        --right;
    }

    std::cout << gondolas << std::endl;

    return 0;
}
