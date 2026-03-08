#ifndef THETA_H
#define THETA_H

#include "../models/structures.h"

/**
 * @brief В данном файле описан функция поворота ракеты от времени.
 */

//  Сначала опишем подбираемые парамеетры( константы)

const double PI = 3.1415926535;
const double dot_theta_k = 0.5;              // град/с

const double t_1 = 100;                      // c         
const double t_2 = 67;                       // c 
const double t_off = 67;                      // c             


double theta(double t, const Rocket roket);

#endif //THETA_H
