#pragma once
#include <memory.h>
#include "fteng/signals.hpp"
//fteng/signals.hpp from https://github.com/TheWisp/signals under the MIT License
template<typename T>

class Property{
public:
   explicit Property(T & initalValue){
        m_value = initalValue;
    }

    explicit Property(T && initalValue){
        m_value = std::move(initalValue);
    }

    Property(Property & copy){
        m_value = copy.m_m_value;
    }
    Property(Property && other) noexcept{
        m_value(other.m_value);
    }

    ~Property() = default;

    T & getValue(){
        return m_value;
    }

    void setValue(T newValue)
    {
        T oldValue = m_value;
        m_value = newValue;
        if(oldValue != newValue)
        {
            valueChanged();
        }
    }

    void moveValue(T && newValue)
    {
        T oldValue = std::move(m_value);
        m_value = std::move(newValue);
        if(oldValue != newValue)
        {
            valueChanged();
        }
    }

    Property & operator=(const T & value){
        setValue(value);
        return *this;
    }
    Property & operator=(const Property & copy){
        setValue( copy.m_value);
        return *this;
    }
    Property & operator=(Property && other){
        setValue( std::move(other.m_value));
        return *this;
    }
    Property & operator=(T && other){
        moveValue(std::move(other));
        return *this;
    }

    fteng::signal<void()> valueChanged;

protected:
    T m_value;
};
