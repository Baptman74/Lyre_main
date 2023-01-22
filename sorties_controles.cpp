//structure sorties

#include "sorties_controles.h"

struct sorties_controles
{
  uint8_t luminosite; //luminosité (0-255)
  uint8_t pos_moteur_couleur; //position en pas (0-200)
  uint8_t pos_moteur_formes; //position en pas (0-200)
  uint8_t pos_moteur_lentilles; //position en pas (0-?)
  uint8_t pos_moteux_x; //position en pas (0-?)
  uint8_t pos_moteur_Y; //position en pas (0-?)
  uint8_t vitesse_x_y; //vitesse (0-255)
}
