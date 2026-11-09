#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, D;
    cin >> N >> D;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    // 1. Сортируем калорийности
    sort(a.begin(), a.end());

    // 2. Массивы для хранения мин и макс калорийности в каждом дне
    // Инициализируем минимумы очень большими числами, а максимумы - нулями
    vector<int> min_cal(D, 1000000000); 
    vector<int> max_cal(D, 0);

    // 3. Раскидываем пирожки по дням по кругу
    for (int i = 0; i < N; i++) {
        int day = i % D; // Определяем номер дня (0, 1, ..., D-1, 0, 1...)
        
        // Обновляем минимум и максимум для этого дня
        if (a[i] < min_cal[day]) min_cal[day] = a[i];
        if (a[i] > max_cal[day]) max_cal[day] = a[i];
    }

    // 4. Ищем максимальную разницу среди всех дней
    int ans = 0;
    for (int i = 0; i < D; i++) {
        int diff = max_cal[i] - min_cal[i];
        if (diff > ans) {
            ans = diff;
        }
    }

    cout << ans << endl;

    return 0;
}