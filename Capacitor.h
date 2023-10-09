#ifndef _CAPACITOR_H_
#define _CAPACITOR_H_

#include "Component.h"

class Capacitor : public Component {
private:
    double capacitance;
    double voltage;
public:
    Capacitor(double _capacitance, float _Red, float _Green, float _Blue, const std::string& _name)
        : capacitance(_capacitance), voltage(0.0) {
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
        voltage += (_current / capacitance) * timestep;
        return voltage;
    }

    virtual void Display() override {
        std::cout << "Capacitor " << name << ": Voltage = " << voltage << " V" << std::endl;
    }
};

#endif // _CAPACITOR_H_
