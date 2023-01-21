//contiens les fonctions relatives aux calculs de positions des moteurs

#include "motor_ctrl.h"

using namespace motor_ctrl;

//calcul le nombre de pas entre la position actuelle et la position a atteindre
uint8_t nb_step(uint couleur, uint position_actuelle)
{
  //couleur entre 0 et 7 en entrée

  uint8_t nb_step_sens[2] = {0,0};
  int dist = couleur - position_actuelle;

  if (dist<0)
  {
    nb_step_sens[0] = 0;
    nb_step_sens[1] = -dist*24;
  }
  else if(dist > 0)
  {
    nb_step_sens[0] = 1;
    nb_step_sens[1] = dist*24;
  }
  return nb_step_sens;
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
