#include "theta.h"


double theta(double t, const Rocket roket)
{
    if ( t < t_1)
        return PI/2;
    
    if (t < t_2)
        return PI / 2.0 - dot_theta_k * (t - t_1);

    if (t < t_off) {
        return atan2(roket.dy_dt, roket.dx_dt);
    }

    return 0;
}