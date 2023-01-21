# Lyre_main
code principal pour la lyre polybot. 


normes et specificitées de code:
-fonctions:
//indications sur ce que fait la fonction

type_sortie nom_fonction(parametres)

{

  code
  
}//nom_fonction


-utiliser "using namespace" uniquement dans les fichiers autres que main.cpp 

-tout les appels a des fonctions du raspberry pi pico se fait dans le main.cpp

-les sorties forment une struct avec les valeurs des variables (luminosité, posisiton moteur, etc) 

-pour le mouvement des moteurs: on calcul l'écart entre la position réelle du moteur, et on cherche a réduire cet écart

-la lecture DMX et son(gpio 1) se fera dans le coeur 2 
