#include <iostream>
#include <cmath>
#include <locale>

using namespace std;

class Progression {
public:
    Progression(double first, double step) : firstElement(first), commonProgression(step) {}

    virtual double sum(int n) = 0;

protected:
    double firstElement;
    double commonProgression;
};

class ArithmeticProgression : public Progression {
public:
    ArithmeticProgression(double first, double difference) : Progression(first, difference) {}

    double sum(int n) override {
        return static_cast<double>(n + 1) * (firstElement + (firstElement + static_cast<double>(n) * commonProgression)) / 2.0;
    }
};

class GeometricProgression : public Progression {
public:
    GeometricProgression(double first, double difference) : Progression(first, difference) {}

    double sum(int n) override {
        return (firstElement - commonProgression * std::pow(commonProgression, n)) / (1 - commonProgression);
    }
};

int main() {
    setlocale(LC_ALL, "ukr");
    double start, step, n;
    cout << "Введіть початкове значення:" << endl;
    cin >> start;
    cout << "Введіть крок:" << endl;
    cin >> step;
    ArithmeticProgression arithmeticProgression(start, step);
    GeometricProgression geometricProgression(start, step);
    
    cout << "Введіть кількість повторювань:" << endl;
    cin >> n;

    double sumArithmetic = arithmeticProgression.sum(n);
    double sumGeometric = geometricProgression.sum(n);

    cout << "Сума арифметичної прогресії: " << sumArithmetic << std::endl;
    cout << "Сума геометричної прогресії: " << sumGeometric << std::endl;

    return 0;
}
