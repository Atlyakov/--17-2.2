#include "zag.h"

// Реализация методов BarrelNode
BarrelNode::BarrelNode(int f) : fuel(f), next(nullptr) {}

// Реализация методов BarrelCompartment
BarrelCompartment::BarrelCompartment() : top(nullptr) {}

BarrelCompartment::~BarrelCompartment() {
    while (top != nullptr) {
        BarrelNode* temp = top;
        top = top->next;
        delete temp;
    }
}

void BarrelCompartment::addBarrel(int fuel) {
    BarrelNode* newNode = new BarrelNode(fuel);
    newNode->next = top;
    top = newNode;
}

int BarrelCompartment::removeBarrel() {
    if (top == nullptr) {
        return -1;  // Ошибка: отсек пуст
    }
    int fuel = top->fuel;
    BarrelNode* temp = top;
    top = top->next;
    delete temp;
    return fuel;
}

bool BarrelCompartment::isEmpty() const {
    return top == nullptr;
}

int BarrelCompartment::getTopFuel() const {
    if (top == nullptr) {
        return -1;
    }
    return top->fuel;
}

// Вспомогательная функция для безопасного ввода числа
int SafeInputInt(const string& prompt, int min_val, int max_val) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cout << "Ошибка";
            exit(1);
        }
        else if (value < min_val || value > max_val) {
            cout << "Ошибка";
            exit(1);
        }
        else {
            cout << "Ошибка";
            exit(1);
        }
    }
}

// Вспомогательная функция для парсинга операции
bool ParseOperation(const string& input, char& op, int& A, int& B, int K) {
    istringstream iss(input);
    if (!(iss >> op >> A >> B)) {
        return false;
    }
    return (op == '+' || op == '-') &&
        (A >= 1 && A <= K) &&
        (B >= 1 && B <= 10000);
}