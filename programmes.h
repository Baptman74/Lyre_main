#ifndef PROGRAMMES_H
#define PROGRAMMES_H

#include "sorties_controles.h"

namespace programmes
{
  /*
  programme n°1
  effectue un fade in puis fade out de la led, puis change de couleur (couleur random)
  */
  void pg1(uint32_t current_time, uint8_t etat_pg, uint32_t dern_exec_fade, sorties_controles * sorties);

  /*
  programme n°2

  */
  void pg2(uint32_t current_time, uint8_t etat_pg, uint32_t dern_exec_fade,sorties_controles * sorties);

  //reset les variables des programmes
  void at_pg_change(uint8_t etat_pg);

}

#endif
