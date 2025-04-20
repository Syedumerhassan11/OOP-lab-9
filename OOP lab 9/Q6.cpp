#include <iostream>
#include <string>

class Car {
protected:
    std::string model;
    double price;

public:
    Car(const std::string& m) : model(m), price(0.0) {}

    std::string getModel() const {
        return model;
    }

    double getPrice() const {
        return price;
    }

    void setModel(const std::string& m) {
        model = m;
    }

    virtual void setPrice(double p) = 0;

    virtual void display() const {
        std::cout << "Model: " << model << ", Price: $" << price << std::endl;
    }

    virtual ~Car() {}
};

class Color : public Car {
private:
    std::string color;

public:
    Color(const std::string& m, const std::string& c) : Car(m), color(c) {}

    void setPrice(double p) override {
        price = p + 500; // color-based surcharge
    }

    void display() const override {
        std::cout << "Model: " << model << ", Color: " << color << ", Price: $" << price << std::endl;
    }
};

class Company : public Car {
private:
    std::string company;

public:
    Company(const std::string& m, const std::string& c) : Car(m), company(c) {}

    void setPrice(double p) override {
        price = p + 1000; // company-brand value added
    }

    void display() const override {
        std::cout << "Model: " << model << ", Company: " << company << ", Price: $" << price << std::endl;
    }
};

int main() {
    Color car1("Sedan", "Red");
    car1.setPrice(20000);
    car1.display();

    Company car2("SUV", "Toyota");
    car2.setPrice(30000);
    car2.display();

    return 0;
}

