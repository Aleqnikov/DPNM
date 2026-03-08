#ifndef STRUCTURES_H
#define STRUCTURES_H


#include <iostream>

/**
* @brief  В данном файле описываются основные структуры, что описывают текщую
* конфигурацию модели.
*/


struct Stage
{
    double weight;                  // Вес самой ступени
    double field_weight;            // Вес топлива, что расходуется по мере
                                    // полета ракеты.

    double I_sp;                    // Удельный импульс
    double T_max;                   // Тяга

    double getFullWeight()
    {
        return weight + field_weight;
    }
};



/**
 * Структура, описывающяя ракету, имеет как характеристики текщие координаты, 
 * векторы скорости.
 */
struct Rocket
{
    double x, y;                    // Текущие координаты ракеты в простанстве
    double dx_dt, dy_dt;            // Текущие составляющие вектора скорости ракеты
    Stage stage1, stage2;

    int current_stage = 1;

    Stage getCurrStage()
    {
        if(current_stage == 0)
            return stage1;
        return stage2;
    }


    double getWeight()
    {
        return stage1.getFullWeight() + stage2.getFullWeight();
    }


    double getCurrSpeed()
    {
        return std::sqrt(std::pow(dx_dt, 2) + std::pow(dy_dt, 2));
    }
};









#endif //STRUCTURES_H

