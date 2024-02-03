/*Boost Software License - Version 1.0 - August 17th, 2003
Copyright (c) 2024 Alan Uthoff*/

#include <thread>
#include <chrono>
#include "property.h"
#include <iostream>
using namespace std::chrono_literals;
constexpr std::chrono::milliseconds sleepDuration = 500ms;

int main() {
    Property<std::string>myProperty(std::string("bob is here"));
    std::cout<<"Current Value"<<myProperty.getValue()<<"\n";
    fteng::connection onChange = myProperty.valueChanged.connect([](){
        std::cout<<"Value Changed"<<"\n";
    });
    myProperty = std::move(std::string("Now trying to move he is gone"));
    myProperty = std::string("Now he is gone");
    std::cout<<std::endl;
    return 0;
}
