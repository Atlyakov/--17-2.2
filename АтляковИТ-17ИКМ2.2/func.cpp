#include "zag.h"

// ���������� ������� BarrelNode
BarrelNode::BarrelNode(int f) : fuel(f), next(nullptr) {}

// ���������� ������� BarrelCompartment
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
        return -1;  // ������: ����� ����
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

// ��������������� ������� ��� ����������� ����� �����
int SafeInputInt(const string& prompt, int min_val, int max_val) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cout << "������";
            exit(1);
        }
        else if (value < min_val || value > max_val) {
            cout << "������";
            exit(1);
        }
        else {
            cout << "������";
            exit(1);
        }
    }
}

// ��������������� ������� ��� �������� ��������
bool ParseOperation(const string& input, char& op, int& A, int& B, int K) {
    istringstream iss(input);
    if (!(iss >> op >> A >> B)) {
        return false;
    }
    return (op == '+' || op == '-') &&
        (A >= 1 && A <= K) &&
        (B >= 1 && B <= 10000);
}