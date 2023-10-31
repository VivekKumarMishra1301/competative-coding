#include <iostream>
#include <vector>

int main() {
    int i = 0;
    int j = 0;
    std::vector<int> arr = {2, 1, 4, 6, 5, 7, 9, 11, 6};
    int n = arr.size();

    while (i < n) {
        // Search for the next even number
        j = i;
        while (j < n && arr[j] % 2 != 0) {
            j++;
        }

        while (j < n && j > i) {
            std::swap(arr[j], arr[j - 1]);
            j--;
        }
        i++;

        // Search for the next odd number
        j = i;
        while (j < n && arr[j] % 2 == 0) {
            j++;
        }

        while (j < n && j > i) {
            std::swap(arr[j], arr[j - 1]);
            j--;
        }
        i++;
    }

    // Print the sorted array
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
