#include <iostream>
#include <memory>
#include "Array.h"
#include "Triangle.h"
#include "Square.h"
#include "Octagon.h"

int main()
{
    Array<std::shared_ptr<Figure<double>>> figures;

    std::cout << "=== Создание фигур ===" << std::endl;

    std::cout << "\n--- Треугольник ---" << std::endl;
    auto triangle = std::make_shared<Triangle<double>>();
    std::cin >> *triangle;
    figures.add(triangle);

    std::cout << "\n--- Квадрат ---" << std::endl;
    auto square = std::make_shared<Square<double>>();
    std::cin >> *square;
    figures.add(square);

    std::cout << "\n--- Восьмиугольник ---" << std::endl;
    auto octagon = std::make_shared<Octagon<double>>();
    std::cin >> *octagon;
    figures.add(octagon);

    std::cout << "\n=== Информация о фигурах ===" << std::endl;
    for (size_t i = 0; i < figures.size(); ++i)
    {
        std::cout << "Фигура " << i + 1 << ": " << *figures[i] << std::endl;
        std::cout << "Центр: " << figures[i]->center() << std::endl;
        std::cout << "Площадь: " << static_cast<double>(*figures[i]) << std::endl;
        std::cout << "---" << std::endl;
    }

    std::cout << "\n=== Общая площадь ===" << std::endl;
    double totalArea = 0.0;
    for (size_t i = 0; i < figures.size(); ++i)
    {
        totalArea += static_cast<double>(*figures[i]);
    }
    std::cout << "Общая площадь всех фигур: " << totalArea << std::endl;

    return 0;
}