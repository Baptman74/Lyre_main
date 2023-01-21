#ifndef DMX512_H
#define DMX512_H

#include "sorties_controles.h"

namespace DMX512
{
    uint8_t get_adresse(uint2_t * adress);

    void set_color(struct sorties_controles * sorties);
    void set_luminosite(struct sorties_controles * sorties);
    void set_formes(struct sorties_controles * sorties);
    void set_x(struct sorties_controles * sorties);
    void set_y(struct sorties_controles * sorties);

}//DMX512

#endif
