// contient les fonctions pour l'adressage et l'entrée DMX
#include "DMX512.h"
#include <cmath>
#include "sorties_controles.h"

using namespace DMX512;


uint8_t get_adresse(uint8_t * adress)
{
  uint8_t chan_val = 0;
  for (int i = 0; i<=8;i++)
  {
    chan_val = chan_val + std::pow(2,i) * (*adress[i]);
  }
  return chan_val;
}//get_adresse

void set_color(sorties_controles * sorties)
{
  //change la variable de position du moteur couleur
}//set_color

void set_luminosite(sorties_controles * sorties)
{
  //change la variable de luminosite
}//set_luminosite

void set_formes(sorties_controles * sorties)
{
  //change la variable de position du moteur forme
}//set_formes

void set_x(sorties_controles * sorties)
{
  //change la variable de position du moteur x
}//set_x

void set_y(sorties_controles * sorties)
{
  //change la variable de position du moteur y
}//set_y
