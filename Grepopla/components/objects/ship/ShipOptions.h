#ifndef SHIPOPTIONS_H
#define SHIPOPTIONS_H

struct ShipOptions
{
    double speed;
    int size;
    int HP;

    //constructor
    ShipOptions(double p_speed, int p_size, int p_HP): speed(p_speed), size(p_size), HP(p_HP) {}
};

#endif // SHIPOPTIONS_H
