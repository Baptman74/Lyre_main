#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/pwm.h"

#include "motor_ctrl.h"
#include "programmes.h"
#include "DMX512.h"
#include "sorties_controles.h"

#define LED_OUT 1
#define STEPPER_COLOR_STEP 2
#define STEPPER_COLOR_SENS 3
#define ADC_POM_COULEUR 0
#define LED_POM_COULEUR 16

int gpio_adc_couleur = 26;



int main(){

}

/*

struct controle :
luminosité
pos_moteur_couleur
pos_moteur_formes
pos_moteur_lentilles
pos_moteux_x
pos_moteur_Y

les programmes ou le DMX éditent la struct



structure des executions:
edition:
  programmes OU DMX éditent struct

application:
  pour luminosité: met la luminosité a la bonne valeur
  pour moteurs: fait +1 si consigne != valeur reelle


/!\ tout les appels a des fonctions du pico se font ici dans le main
*/
