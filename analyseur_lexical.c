#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define  taille_tab_mot_cles 12
#define  taille_tab_sym_spe 16



#include "prototypes.h"




TSym_Cour tab_mot_cle[taille_tab_mot_cles]={
        {"if",IF_TOKEN},
        {"then", THEN_TOKEN},
        {"else",ELSE_TOKEN},
        {"begin",BEGIN_TOKEN},
        {"end",END_TOKEN},
        {"program",PROGRAM_TOKEN},
        {"const", CONST_TOKEN},
        {"var", VAR_TOKEN},
        {"while", WHILE_TOKEN},
        {"Do", DO_TOKEN},
        {"read", READ_TOKEN},
        {"write", WRITE_TOKEN},
};


//tableau des caracteres speciaux
TSym_Cour tab_car_spe[taille_tab_sym_spe]={
        {";",PV_TOKEN},
        {"/",DIV_TOKEN},
        {".",PT_TOKEN},
        {"+",PLUS_TOKEN},
        {"*",MULTI_TOKEN},
        {"-",MOINS_TOKEN},
        {"<", INF_TOKEN},
        {"<=",INFEG_TOKEN},
        {">",SUP_TOKEN},
        {"<=",SUPEG_TOKEN},
        {"<>",DIFF_TOKEN},
        {"(",PO_TOKEN},
        {")",PF_TOKEN},
        {"EOF",FIN_TOKEN},
        {":=",AFF_TOKEN},
        {",",VIR_TOKEN},
};

int etat = 1;
int etat_checked = 0;
int etat_trouve = 0;
int main(int argc, char const *argv[]) {


  Fichier = fopen("/Users/macbook/CLionProjects/untitled/test.p", "r");

  int premiere_rencontre_espace = 1;
  int premiere_rencontre_car_spe = 1;


  do{
      Lire_Car();

      if (Car_Cour_Car_Spe(Car_Cour) != 0){
          if ( premiere_rencontre_car_spe == 1 ){
              printf("%s", mot);

              while (!etat_checked){
                  verification_des_token_lus();
                  if (etat_checked){
                      break;
                  }
              }

              printf("\n-----------------------");
              Affichage_Token(Sym_COUR.CODE);
              printf("\n");
              premiere_rencontre_car_spe = 0;

          }
          strcpy(mot, string);
          printf("\n------%s--------", mot);
          if( mot != " "){
              while (!etat_checked){
                  verification_des_token_lus();
                  if (etat_checked){
                      break;
                  }
              }
              //etat_checked = 0;
              printf("\n-----------------------");
              Affichage_Token(Sym_COUR.CODE);
              printf("\n");
          }
          strcpy(mot, "");// on reinitialise la variable mot pour qu'elle puisse contenir un autre mot;

          Lire_Car();
      }
      while (Car_Cour == ' ' || Car_Cour == '\n' || Car_Cour == '\t') {
     //     printf("\n****here we go again*****");
              // verification des mots lus :
              if (premiere_rencontre_espace == 1){
                  printf("%s", mot);

                  while (!etat_checked){
                      verification_des_token_lus();
                      if (etat_checked){
                          break;
                      }
                  }

                  etat_checked = 0;
                  printf("\n-----------------------");
                  Affichage_Token(Sym_COUR.CODE);
                  printf("\n");
                  premiere_rencontre_espace = 0;
              }
              strcpy(mot, "");// on reinitialise la variable mot pour qu'elle puisse contenir un autre mot.
              Lire_Car();
      }
      premiere_rencontre_espace = 1;
      strcat(mot,char_to_string(Car_Cour));

  }while(Car_Cour != EOF);

  fclose(Fichier);
  return 0;
}
