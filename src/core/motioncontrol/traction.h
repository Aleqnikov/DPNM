#ifndef TRACTION_H
#define TRACTION_H

#include <iostream>
#include <string>

#include <nlohmann/json.hpp>


#include "../models/structures.h"

using json = nlohmann::json;
/**
 * @brief В данном файле описывается функция контроля тяги двигателя.
 * 
 * Идея - так как у нас условно, данная функция является кусочно-линейной, 
 * такая что она разбивается на отрезки, которые имеют определенные значения на 
 * разных концах, программист задает это в специальном файле. затем программа это считывает
 * и вписывает в программу.
 */

const std::string settings_path = "src/core/motioncontrol/trackingsettings.json"

// Рассчет мощьности
double alpha(double t, std::vector<double> t_points, std::vector<double> alpha_points );


// Рассчет текущей тяги
double Traction(double t, Rocker roker);

// Рассчет текущего потребления топлива.
double mu(double t, Rocker rocker);





    


#endif //TRACTION_H
