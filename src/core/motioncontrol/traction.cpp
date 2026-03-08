#include "traction.h"
#include "../physics/constants.h"

double alpha(double t, std::vector<double> t_points, std::vector<double> alpha_points ){

    // Предполагаем, что t_points и alpha_points имеют одинаковый размер и упорядочены
    if (t <= t_points.front()) return alpha_points.front();
    if (t >= t_points.back()) return alpha_points.back();
    
    for (size_t i = 0; i < t_points.size() - 1; ++i) 
    {
        if (t >= t_points[i] && t <= t_points[i+1]) 
        {
            double alpha = alpha_points[i] + (alpha_points[i+1] - alpha_points[i]) * (t - t_points[i]) / (t_points[i+1] - t_points[i]);
            return alpha;
        }
    }

    return 0.0; 
}


// Рассчет текущей тяги
double Traction(double t, Rocker rocker)
{
    int current_stage = rocket.current_stage;

    Stage stage = rocker.getCurrStage();

    std::ifstream f(settings_path);

    json data = json::parse(f);
    auto t_points = data[current_stage]["t_points"].get<std::vector<double>>();
    auto alpha_points = data[current_stage]["alpha_points"].get<std::vector<double>>();

    double alpha_t = alpha(t, t_points, alpha_points);

    return alpha_t * stage.T_max;
}

// Рассчет текущего потребления топлива.
double mu(double t, Rocker rocker)
{
    return T(t)/(rocker.getCurrStage().I_sp*g_0);
}