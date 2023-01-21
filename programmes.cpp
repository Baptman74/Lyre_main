//contiens les programmes automatiques

#include "programmes.h"

using namespace programmes;

uint pg1(uint32_t current_time, uint8_t etat_pg, uint32_t dern_exec_fade, sorties_controles * sorties)
{
  //instructions du programme 1 en non bloquant (mise a jour de la struct)
}//pg1

uint pg2(uint32_t current_time, uint8_t etat_pg, uint32_t dern_exec_fade, sorties_controles * sorties)
{
  //instructions du programme 2 en non bloquant (mise a jour de la struct)
}//pg2

void at_pg_change(uint8_t etat_pg){
  //reset toutes les variables des programmes
}
