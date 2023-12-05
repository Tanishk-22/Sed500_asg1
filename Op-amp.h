// OpAmp.h
#ifndef _OPAMP_H_
#define _OPAMP_H_

#include "Component.h"

class OpAmp : public Component {
private:
    double openLoopGain;
    double inputVoltage;
    double outputVoltage;

public:
    // Constructor: Initializes Op-Amp with given gain, RGB values, and name
    OpAmp(double gain, double red, double green, double blue, const std::string& name)
        : openLoopGain(gain), inputVoltage(0.0), outputVoltage(0.0) {
        Red = red;
        Green = green;
        Blue = blue;
        this->name = name;
    }

    // Virtual function to get the name of the Op-Amp
    virtual std::string GetName() const override {
        return name;
    }

    // Virtual function for any update logic specific to Op-Amp
    virtual void Update() override {
        // Additional update logic specific to Op-Amp, if needed
        // For example, consider any internal state changes
    }

    // Virtual function to calculate the voltage across Op-Amp based on input and characteristics
    virtual double GetVoltage(double _current, double timestep) override {
        // Op-Amp voltage calculation logic based on input and characteristics
        // This is a simple example; the actual behavior can be more complex
        // For simplicity, we assume an ideal Op-Amp in this case
        outputVoltage = openLoopGain * inputVoltage;
        return outputVoltage;
    }

    // Virtual function for displaying information about Op-Amp
    virtual void Display() override {
        // Additional display logic specific to Op-Amp, if needed
        std::cout << "Op-Amp: " << GetName() << std::endl;
        std::cout << "Input Voltage: " << inputVoltage << "V" << std::endl;
        std::cout << "Output Voltage: " << outputVoltage << "V" << std::endl;
    }

    // Set the input voltage for the Op-Amp
    void SetInputVoltage(double voltage) {
        inputVoltage = voltage;
        // Additional logic to handle input voltage change, if needed
    }

    // Get the current output voltage of the Op-Amp
    double GetOutputVoltage() const {
        return outputVoltage;
    }

    // Get the red color component for visualization
    virtual float red() override {
        return Red;
    }

    // Get the green color component for visualization
    virtual float green() override {
        return Green;
    }

    // Get the blue color component for visualization
    virtual float blue() override {
        return Blue;
    }
};

#endif // _OPAMP_H_