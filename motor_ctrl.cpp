//contiens les fonctions relatives aux calculs de positions des moteurs

#include "motor_ctrl.h"

using namespace motor_ctrl;

//calcul le nombre de pas entre la position actuelle et la position a atteindre
uint16_t nb_step(uint pos_moteur_couleur, uint8_t position_precedente_couleur)
{
  uint16_t abs_dist_couleur = abs(position_precedente_couleur - pos_moteur_couleur);
  if (abs_dist_couleur>100)
  {
    uint16_t dist_plus_courte_couleur = (200 - abs_dist_couleur)*10+1;
  }
  else
  {
    uint16_t dist_plus_courte_couleur = abs_dist_couleur*10;
  }
  return abs_dist_couleur;
} //nb_step

//calcul le demi temps pour 1 pas (pin on, timing, pin low, timing etc)
uint8_t timing_one_step(uint8_t speed)
{
  if (speed == 0){
    speed = 1; //pour eviter les divisions par 0, si on ne veut pas bouger on appelle pas la fct
  }
  uint8_t coeff = 5;
  return 1000/(speed*coef);
}//timing_one_step
