#ifndef _INDUCTOR_H_
#define _INDUCTOR_H_

#include "Component.h"

class Inductor : public Component {
private:
    double inductance;
    double current;
public:
    Inductor(double _inductance, float _Red, float _Green, float _Blue, const std::string& _name)
        : inductance(_inductance), current(0.0) {
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
        return inductance * (current - _current) / timestep;
    }

    virtual void Display() override {
        std::cout << "Inductor " << name << ": Current = " << current << " A" << std::endl;
    }
};

#endif // _INDUCTOR_H_
