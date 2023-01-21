#ifndef MOTOR_CTRL_H
#define MOTOR_CTRL_H

namespace motor_ctrl
{
  //calcul le nombre de pas entre la position actuelle et la position a atteindre
  uint8_t nb_step(uint couleur, uint position_actuelle);

  //calcul le demi temps pour 1 pas (pin on, timing, pin low, timing etc)
  uint8_t timing_one_step(uint8_t speed);
}

#endif
