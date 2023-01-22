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

#define LED_PRINCIPALE 1
#define PAP_COULEUR_STEP 2
#define PAP_COULEUR_SENS 3
#define PAP_FORMES_STEP 5
#define PAP_FORMES_SENS 6
#define CAN_POM_COULEUR 0
#define LED_POM_COULEUR 16

int gpio_can_couleur = 26;

uint8_t position_precedente_couleur = 0;

static uint32_t temps_d_execution_actuel = to_ms_since_boot(get_absolute_time());

//dernier passages
//couleur
uint8_t dernier_passage_moteur_couleur = temps_d_execution_actuel;

//etats
//couleurs
uint8_t gpio_moteur_couleur_haut_bas = 0;

//tableau position absolue en pas en fonction de la couleur

//def fonctions
int pom();

int init_gpio();

int main(){
  sorties_controles sorties;

  //lancement initialisation gpio, arrête l'execution du programme en cas de problème
  if (init_gpio())
  {
    return EXIT_FAILURE;
  }

  //lancement pom, blink builtin led en cas de problème
  if (pom())
  {
    while (1)
    {
      gpio_put(PICO_DEFAULT_LED_PIN,1);
      sleep_ms(1000);
      gpio_put(PICO_DEFAULT_LED_PIN,0);
      sleep_ms(1000);
    }
  }

  //initialisation des variables
  sorties.luminosite = 0;
  sorties.pos_moteur_Y = 0;
  sorties.pos_moteux_x = 0;
  sorties.pos_moteur_lentilles = 0;
  sorties.pos_moteur_formes = 0;
  sorties.pos_moteur_couleur = 0;
  sorties.vitesse_x_y = 0;

  //boucle d'execution principale
  while (1)
  {
    //mise a jour du temps d'execution actuel
    temps_d_execution_actuel = to_ms_since_boot(get_absolute_time());

    //mise a jour struct sortie


    //application valeurs struct sortie

    //luminosite
    pwm_set_gpio_level(LED_PRINCIPALE,sorties.luminosite);

    //couleurs
    uint16_t steps = motor_ctrl::nb_step(sorties.pos_moteur_couleur,position_precedente_couleur);
    gpio_put(PAP_COULEUR_SENS,steps%2);
    if (steps/10)
    {
      if (temps_d_execution_actuel - dernier_passage_moteur_couleur > motor_ctrl::timing_one_step(100))
      {
        if(gpio_moteur_couleur_haut_bas)
        {
          gpio_put(PAP_COULEUR_STEP,1)
          gpio_moteur_couleur_haut_bas = 0;
        }
        else
        {
          gpio_put(PAP_COULEUR_STEP,0)
          gpio_moteur_couleur_haut_bas = 1;
        }
      }
    }

    //formes

    //lentille

    //x

    //y
  }


}

//initialisation des gpio
int init_gpio(){
  stdio_init_all();

  //initialisation du CAN
  adc_init();
  adc_gpio_init(gpio_can_couleur);
  adc_set_clkdiv(2400);
  adc_select_input(CAN_POM_COULEUR);

  //initialisation des leds de POM
  gpio_set_dir(LED_POM_COULEUR,GPIO_OUT);

  //initialisation moteurs pas a pas
  //couleur
  gpio_init(PAP_COULEUR_STEP,GPIO_OUT);
  gpio_init(PAP_COULEUR_SENS, GPIO_OUT);

  //initialisation led failure
  gpio_init(PICO_DEFAULT_LED_PIN, GPIO_OUT);


  //initialisation pwm
  gpio_set_function(LED_PRINCIPALE, GPIO_FUNC_PWM);

  uint slice_num = pwm_gpio_to_slice_num(LED_PRINCIPALE);

  pwm_config config = pwm_get_default_config();
  // Set divider, reduces counter clock to sysclock/this value
  pwm_config_set_clkdiv(&config, 4.f);
  // Load the configuration into our PWM slice, and set it running.
  pwm_init(slice_num, &config, true);
  pwm_set_wrap(slice_num, 255);
  //mise a 0 pour éviter les soucis
  pwm_set_gpio_level(LED_PRINCIPALE,0);

}

//fonction de prise d'origine machine
int pom()
{
  int sortie = 1;
  gpio_put(LED_POM_COULEUR,1);
  gpio_put(PAP_COULEUR_SENS,1);
  int read = adc_read();
  i = 0;
  while (read<=3750)
  {

    gpio_put(PAP_COULEUR_STEP,1);
    sleep_ms(2);
    gpio_put(PAP_COULEUR_STEP,0);
    sleep_ms(2);
    read = adc_read();
    i++
    if (i >= 1000)
    {
      return EXIT_FAILURE;
    }
  }
  for (int i = 0; i<=1;i++)
  {
    gpio_put(PAP_COULEUR_STEP,1);
    sleep_ms(2);
    gpio_put(PAP_COULEUR_STEP,0);
    sleep_ms(2);
  }

  //pom formes

  //pom moteur x

  //pom moteur y

  return EXIT_SUCCES;
}//pom

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


/!\ tout les appels a des fonctions du pico se font ici dans le main.cpp
*/
