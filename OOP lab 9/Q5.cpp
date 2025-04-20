#include <iostream>

class Shape {
public:
    virtual double getArea() const = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape {
private:
    double width;
    double height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double getArea() const override {
        return width * height;
    }
};

class Triangle : public Shape {
private:
    double base;
    double height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    double getArea() const override {
        return 0.5 * base * height;
    }
};

int main() {
    Rectangle rect(5.0, 3.0);
    Triangle tri(4.0, 6.0);

    std::cout << "Area of Rectangle: " << rect.getArea() << std::endl;
    std::cout << "Area of Triangle: " << tri.getArea() << std::endl;

    return 0;
}

