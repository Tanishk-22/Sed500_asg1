#ifndef _RESISTOR_H_
#define _RESISTOR_H_

#include "Component.h"

class Resistor : public Component {
private:
    double resistance;
    double current;
public:
    Resistor(double _resistance, float _Red, float _Green, float _Blue, const std::string& _name)
        : resistance(_resistance), current(0.0) {
        Red = _Red;
        Blue = _Blue;
        Green = _Green;
        name = _name;
    }

    virtual std::string GetName() const override {
        return name;
    }

    virtual void Update() override {
    }

    virtual double GetVoltage(double _current, double timestep) override {
        current = _current;
        return current * resistance;
    }

    virtual void Display() override {
        std::cout << "Resistor " << name << ": Current = " << current << " A" << std::endl;
    }
};

#endif // _RESISTOR_H_
