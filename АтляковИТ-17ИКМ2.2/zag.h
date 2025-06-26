#include <iostream>
#include <string>
#include <limits>
#include <sstream>

using namespace std;

// Узел списка бочек
class BarrelNode {
public:
    int fuel;          // Количество топлива в бочке
    BarrelNode* next;   // Указатель на следующую бочку

    BarrelNode(int f);
};

// Класс для представления отсека баржи
class BarrelCompartment {
private:
    BarrelNode* top;    // Вершина стека (последняя добавленная бочка)

public:
    BarrelCompartment();
    ~BarrelCompartment();

    void addBarrel(int fuel);
    int removeBarrel();
    bool isEmpty() const;
    int getTopFuel() const;
};

// Вспомогательные функции
int SafeInputInt(const string& prompt, int min_val, int max_val);
bool ParseOperation(const string& input, char& op, int& A, int& B, int K);

