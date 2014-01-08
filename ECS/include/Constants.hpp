#ifndef CONSTANTS_HPP_INCLUDED
#define CONSTANTS_HPP_INCLUDED

namespace constant
{
    enum Comp
    {
        Base = 0, Health, Movement, Display, Flags
    };

    enum Flag
    {
        Player = 0, Collidable, Tile, Solid
    };

    const double pi = 3.141592653;

    const int windowWidth = 1440;
    const int windowHeight = 900;

    const int maxComps = 128;
    const int maxFlags = 32;
}


#endif
