#include "zag.h"

int main() {
    setlocale(LC_ALL, "rus");
    cout << "=== Симулятор погрузки/выгрузки бочек на баржу ===\n\n";

    // Ввод параметров баржи
    int N = SafeInputInt("Введите количество операций (N, 1-100000): ", 1, 100000);
    int K = SafeInputInt("Введите количество отсеков (K, 1-100000): ", 1, 100000);
    int P = SafeInputInt("Введите максимальную вместимость баржи (P, 1-100000): ", 1, 100000);

    // Инициализация отсеков
    BarrelCompartment* compartments = new BarrelCompartment[K + 1];  // Отсеки с 1 до K
    int current_bottles = 0;
    int max_bottles = 0;
    bool error = false;

    cout << "\nВведите " << N << " операций в формате \"+ A B\" или \"- A B\":\n";

    for (int i = 0; i < N; ++i) {
        string input_line;
        char op;
        int A, B;

        while (true) {
            cout << "Операция " << (i + 1) << ": ";
            getline(cin, input_line);

            if (ParseOperation(input_line, op, A, B, K)) {
                break;
            }
            cout << "Некорректный формат! Используйте \"+ A B\" или \"- A B\" (1 <= B <= 10 000)\n";
        }

        if (error) continue;

        if (op == '+') {
            // Погрузка бочки
            if (A < 1 || A > K) {
                cout << "  Ошибка: неверный номер отсека (должен быть 1-" << K << ")!\n";
                error = true;
            }
            else if (current_bottles >= P) {
                cout << "  Ошибка: баржа переполнена (максимум " << P << ")!\n";
                error = true;
            }
            else {
                compartments[A].addBarrel(B);
                current_bottles++;
                if (current_bottles > max_bottles)
                    max_bottles = current_bottles;

                cout << "  Бочка " << B << " добавлена в отсек " << A << "\n";
            }
        }
        else if (op == '-') {
            // Выгрузка бочки
            if (A < 1 || A > K) {
                cout << "  Ошибка: неверный номер отсека (должен быть 1-" << K << ")!\n";
                error = true;
            }
            else if (compartments[A].isEmpty()) {
                cout << "  Ошибка: отсек " << A << " пуст!\n";
                error = true;
            }
            else if (compartments[A].getTopFuel() != B) {
                cout << "  Ошибка: в отсеке " << A << " нет бочки с топливом " << B << "!\n";
                error = true;
            }
            else {
                compartments[A].removeBarrel();
                current_bottles--;
                cout << "  Бочка " << B << " выгружена из отсека " << A << "\n";
            }
        }
    }

    // Итоговый вывод результата
    cout << "\n=== Результат ===\n";
    if (error || current_bottles != 0) {
        cout << "Error\n";
    }
    else {
        cout << "Максимальное количество бочек: " << max_bottles << "\n";
    }

    // Освобождение памяти
    delete[] compartments;

    return 0;
}