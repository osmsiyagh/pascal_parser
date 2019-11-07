#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define  taille_tab_mot_cles 12
#define  taille_tab_sym_spe 19

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
        {",",VIR_TOKEN},
        {"=", EG_TOKEN},
        {";",PV_TOKEN},
        {"/",DIV_TOKEN},
        {".",PT_TOKEN},
        {"+",PLUS_TOKEN},
        {"*",MULTI_TOKEN},
        {"-",MOINS_TOKEN},
        {"<", INF_TOKEN},
        {"<=",INFEG_TOKEN},
        {":=", AFF_TOKEN},
        {">",SUP_TOKEN},
        {"<=",SUPEG_TOKEN},
        {"<>",DIFF_TOKEN},
        {"EOF", FIN_TOKEN},
        {"(",PO_TOKEN},
        {")",PF_TOKEN},
        {"{", AO_TOKEN},
        {"}", AF_TOKEN},

};

int main(int argc, char const *argv[]) {
  Fichier = fopen("/Users/macbook/CLionProjects/untitled/test.p", "r");
  do{
      Lire_Car();
      switch (Car_Cour){
          case '\t' :
              break;
          case '\n':
              break;
          case '{' :
              //Traitement des commentaires:
              if (strcmp(mot, "") == 0){
                  strcpy(mot, char_to_string('{'));
                  printf("\n%s", mot);
                  printf("\n");
                  Affichage_Token(AO_TOKEN);
              }
              while(Car_Cour != '}'){
                  Lire_Car();
              }
              strcpy(mot, char_to_string('}'));
              printf("\n%s", mot);
              printf("\n");
              Affichage_Token(AF_TOKEN);
              strcpy(mot,"");
              break;
          case ' ':
              while (Car_Cour == ' '){
                  Lire_Car();
              }
              fseek(Fichier, -1, SEEK_CUR);
              if (strcmp(mot, "") != 0){
                  printf("\n%s", mot);
                  verification_des_token_lus();
                  printf("\n");
                  Affichage_Token(Sym_COUR.CODE);
                  strcpy(mot, "");
              }
              break;
          default:
              if (Car_Cour_Car_Spe(Car_Cour)){
                  if (strcmp(mot, "") != 0){
                      printf("\n%s", mot);
                      verification_des_token_lus();
                      printf("\n");
                      Affichage_Token(Sym_COUR.CODE);
                  }
                  strcpy(mot, string);
                  printf("\n%s", mot);
                  verification_des_token_lus();
                  printf("\n");
                  Affichage_Token(Sym_COUR.CODE);
                  strcpy(mot, "");
              } else{
                  strcat(mot, char_to_string(Car_Cour));
              }
              break;
      }
  }while(Car_Cour != EOF);
  printf("\n");
  Affichage_Token(FIN_TOKEN);
  fclose(Fichier);
  return 0;
}
