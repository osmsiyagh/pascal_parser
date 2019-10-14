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
int main(int argc, char const *argv[]) {
    printf("%s \n", char_to_string('a'));
  /* code */
  Fichier = fopen("/Users/macbook/CLionProjects/untitled/test.p", "r");
  int j = 1;
  //int iteration = 0;

  int premiere_rencontre_espace = 1;

  caractere[0]=' ';
  caractere[1]='\0';
  do{
      //printf("%d", tab_mot_cle[2].CODE);
      if (j == 1) Lire_Car();
      caractere[0]= Car_Cour;
      j=1;
        //printf("%s", mot);


      while (Car_Cour == ' ' || Car_Cour == '\n' || Car_Cour == '\t'  ) {
              //verification_des_token_lus();



              if (premiere_rencontre_espace == 1){
                  printf("Le mot est %s ", mot);
                  while (!etat_checked){
                      verification_des_token_lus();
                  }
                  //etat_checked = 0;
                  printf("-----------------------\n");
                  Affichage_Token(Sym_COUR.CODE);
                  printf("\n");
                  premiere_rencontre_espace = 0;
              }

              //reintialiser mot pour qu'il puisse contenir un autre mot;
              strcpy(mot, "");//reintialiser mot pour qu'il puisse contenir un autre mot;

              Lire_Car();
              caractere[0] = Car_Cour;


              /*if (isspace(Car_Cour) == 0){
                  j=0;
                  strcpy(nouveau_mot, "");
              }*/

          //verification_des_token_lus();
      }

      //strcpy(mot, nouveau_mot);
      premiere_rencontre_espace = 1;
      strcat(mot,caractere);

  }while(Car_Cour != EOF);


  return 0;
}
