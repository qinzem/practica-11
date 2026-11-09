#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K, L;
    cin >> N >> K >> L;

    // Создаём массив для цен всех цветов
    vector<int> prices(N);
    for (int i = 0; i < N; i++) {
        cin >> prices[i];
    }

    sort(prices.begin(), prices.end(), greater<int>());

    int taken[101] = {0};
    int total_sum = 0;
    int count = 0;

    for (int i = 0; i < N; i++) {
        if (count == K) break;

        // В этом массиве индексы — это цены (до 100).
        // Если такой цветок уже брали L раз — пропускаем
        if (taken[prices[i]] < L) {
            total_sum += prices[i];
            taken[prices[i]]++;
            count++;
        }
    }

    cout << total_sum << endl;
    return 0;
}
