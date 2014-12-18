#ifndef SHIPOPTIONS_H
#define SHIPOPTIONS_H

struct ShipOptions
{
    double speed;
    int size;
    int lifes;

    //constructor
    ShipOptions(double p_speed, int p_size, int p_lives): speed(p_speed), size(p_size), lifes(p_lives) {}
};

#endif // SHIPOPTIONS_H
