#include <iostream>
#include <algorithm>
using namespace std;

struct Product {
    float weight, price;

    float getRatio() const {
        return price / weight;
    }
};

void bubbleSort(Product arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j].getRatio() < arr[j + 1].getRatio())
                swap(arr[j], arr[j + 1]);
}

int main() {
    Product products[5];

    for (auto &p : products) {
        cout << "Enter weight and price: ";
        cin >> p.weight >> p.price;
    }

    bubbleSort(products, 5);

    cout << "\nSorted Products (Descending Order by Price/Weight Ratio):\n";
    for (const auto &p : products)
        cout << p.weight << " " << p.price << " " << p.getRatio() << endl;

    return 0;
}
