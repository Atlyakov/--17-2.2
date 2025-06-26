#include <iostream>
#include <string>
#include <limits>
#include <sstream>

using namespace std;

// ���� ������ �����
class BarrelNode {
public:
    int fuel;          // ���������� ������� � �����
    BarrelNode* next;   // ��������� �� ��������� �����

    BarrelNode(int f);
};

// ����� ��� ������������� ������ �����
class BarrelCompartment {
private:
    BarrelNode* top;    // ������� ����� (��������� ����������� �����)

public:
    BarrelCompartment();
    ~BarrelCompartment();

    void addBarrel(int fuel);
    int removeBarrel();
    bool isEmpty() const;
    int getTopFuel() const;
};

// ��������������� �������
int SafeInputInt(const string& prompt, int min_val, int max_val);
bool ParseOperation(const string& input, char& op, int& A, int& B, int K);

