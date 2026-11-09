#include <iostream>
using namespace std;

char maze[100][100]; // Лабиринт (максимум 100x100)
int N, M;            // Размеры
int answer = -1;     // (-1 = выхода нет)

// Функция обхода
// x, y - где мы сейчас
// pdf - сколько файлов уже собрали
void go(int x, int y, int pdf) {
    
    // Если вышли за границы или это стена — выходим
    if (x < 0 || x >= N || y < 0 || y >= M) return;
    if (maze[x][y] == '1') return;

    // Если дошли до выхода — обновляем ответ
    if (maze[x][y] == 'E') {
        if (pdf > answer) answer = pdf;
        return;
    }

    // Если тут pdf — плюс один к счёту
    if (maze[x][y] == 'P') pdf++;

    // Запоминаем клетку и делаем её стеной, чтобы не ходить по кругу
    char old = maze[x][y];
    maze[x][y] = '1';

    // Пробуем все 4 стороны
    go(x + 1, y, pdf); // вниз
    go(x - 1, y, pdf); // вверх
    go(x, y + 1, pdf); // вправо
    go(x, y - 1, pdf); // влево

    // Возвращаем клетку как было (для других путей)
    maze[x][y] = old;
}

int main() {
    cin >> N >> M;

    int sx = 0, sy = 0; // Где стартуем

    // Читаем лабиринт и ищем старт
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 'P') {
                sx = i;
                sy = j;
            }
        }
    }

    // Запускаем поиск
    go(sx, sy, 0);

    // Выводим ответ
    cout << answer << endl;

    return 0;
}