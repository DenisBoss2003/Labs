#include "calculationdewpoint.h"
#include <cmath> // для std::log

void DewPoint::Calculation()
{
    constexpr float a = 17.27f;
    constexpr float b = 237.7f;
    
    
    auto humidity = mdataH.GetData(); // в процентах (например, 50%)
    auto temperature = mdataT.GetData(); // в градусах Цельсия
    
   
    float humidityFraction = humidity / 100.0f;
    
   
    float gamma = (a * temperature) / (b + temperature) + std::log(humidityFraction);
    
    
    value = (b * gamma) / (a - gamma);
    
   
}

float DewPoint::GetData()
{
    return value;
}