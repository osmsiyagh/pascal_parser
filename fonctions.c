#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>



#define  taille_tab_mot_cles 12
#define  taille_tab_sym_spe 16


#include "prototypes.h"



extern TSym_Cour tab_car_spe[taille_tab_sym_spe];
extern TSym_Cour tab_mot_cle[taille_tab_mot_cles];



void Lire_Car(){
  Car_Cour=fgetc(Fichier);
}

int est_mot_cle(char nom[20]){
  for (size_t i = 0; i < taille_tab_mot_cles; i++) {
    if (strcmp(nom, tab_mot_cle[i].NOM) == 0) return 1;
  }
  return 0;
}

int est_car_spe(char nom[20]){
  for (size_t i = 0; i < taille_tab_sym_spe; i++) {
    if (strcmp(nom, tab_car_spe[i].NOM) == 0) return 1;
  }
  return 0;
}

char* char_to_string(char c){
    char* string = (char*)malloc(2* sizeof(char));
    string[0] = c;
    string[1] = '\0';
    return string;
}

int checkString(char str1[])
{
    int i, x=0, p;
    p=strlen(str1);
    for (i = 0; i < p ; i++)
    {
        if ((str1[i] >= 'a' && str1[i] <= 'z') || (str1[i] >= 'A' && str1[i] <= 'Z') )
        {
            continue;
        }
        else{ return 0; }
    }
    return 1;
}


void Affichage_Token(CODES_LEX code)
{
    switch(code)
    {
        case PROGRAM_TOKEN :
            printf("PROGRAM_TOKEN") ;
            break ;
        case IF_TOKEN :
            printf("IF_TOKEN") ;
            break ;
        case ELSE_TOKEN :
            printf("ELSE_TOKEN") ;
            break ;
        case END_TOKEN :
            printf("END_TOKEN") ;
            break ;
        case WHILE_TOKEN :
            printf("WHILE_TOKEN") ;
            break ;
        case BEGIN_TOKEN:
            printf("BEGIN_TOKEN") ;
            break ;
        case CONST_TOKEN :
            printf("CONST_TOKEN") ;
            break ;
        case VAR_TOKEN :
            printf("VAR_TOKEN") ;
            break ;
        case DO_TOKEN :
            printf("DO_TOKEN") ;
            break ;
        case READ_TOKEN :
            printf("READ_TOKEN") ;
            break ;
        case WRITE_TOKEN :
            printf("WRITE_TOKEN") ;
            break ;
        case PV_TOKEN :
            printf("PV_TOKEN") ;
            break ;
        case PT_TOKEN :
            printf("PT_TOKEN") ;
            break ;
        case PLUS_TOKEN :
            printf("PLUS_TOKEN") ;
            break ;
        case MOINS_TOKEN :
            printf("MOINS_TOKEN") ;
            break ;
        case MULTI_TOKEN :
            printf("MULTI_TOKEN") ;
            break ;
        case DIV_TOKEN :
            printf("DIV_TOKEN") ;
            break ;
        case VIR_TOKEN :
            printf("VIR_TOKEN") ;
            break ;
        case AFF_TOKEN :
            printf("AFF_TOKEN") ;
            break ;
        case INF_TOKEN :
            printf("INF_TOKEN") ;
            break ;
        case INFEG_TOKEN :
            printf("INFEG_TOKEN") ;
            break ;
        case SUP_TOKEN :
            printf("SUP_TOKEN") ;
            break ;
        case SUPEG_TOKEN :
            printf("SUPEG_TOKEN") ;
            break ;
        case DIFF_TOKEN :
            printf("DIFF_TOKEN") ;
            break ;
        case PO_TOKEN :
            printf("PO_TOKEN") ;
            break ;
        case PF_TOKEN :
            printf("PF_TOKEN") ;
            break ;
        case FIN_TOKEN :
            printf("FIN_TOKEN") ;
            break ;
        case ID_TOKEN :
            printf("ID_TOKEN") ;
            break ;
        case NUM_TOKEN :
            printf("NUM_TOKEN") ;
            break ;
        case ERREUR_TOKEN :
            printf("ERREUR_TOKEN") ;
            break ;
    }
}

void verification_des_token_lus(){

    int n;

  int k;

  switch (etat) {

      case 1:
          //printf("\n fine in switch case");
      if (checkString(mot) != 0) {
          //printf("\n it's an alpha");
          etat = 2;
      }//si tous les caracteres sont des lettres
      else {
          etat = 3;
          printf("on est là");
      } //digit ? identificateur ?
      break;

    case 2 :
      //printf("Am here now");
      if (est_mot_cle(mot) == 1) {
        for (size_t i = 0; i < taille_tab_mot_cles; i++) {
          if (strcmp(mot, tab_mot_cle[i].NOM) == 0) {
            Sym_COUR.CODE = tab_mot_cle[i].CODE;
            strcpy(Sym_COUR.NOM, mot);
            etat_checked = 1;
          }
        }
      }else {
          etat = 3;// digit or id
          //printf("we are here \n");
      }
      break;

    case 3:
      if (isdigit(mot[0]) != 0) {
        k=1;
        if((isdigit(mot[k++])!= 0)) etat = 5;//NUM_TOKEN
        else{
          while ((isdigit(mot[k] != 0) && mot[k+1]!= '.')) {
            k++;
          }
          if ((mot[k+1]=='.' && isdigit(mot[k++]!=0)) || mot[k]=='.') etat = 5;
        }
      }else etat = 6; //caractère spe ou identificateur
      break;

    case 4:

      Sym_COUR.CODE = ID_TOKEN;
      strcpy(Sym_COUR.NOM, mot);
      //printf("on est là");
      etat_checked = 1;
      //printf("%s\n", Sym_COUR.CODE);
      //etat = 0;
      break;

    case 5:
      Sym_COUR.CODE = NUM_TOKEN;
      strcpy(Sym_COUR.NOM, mot);
      etat_checked = 1;
      //printf("%s\n", Sym_COUR.CODE);
      //etat =0;
      break;

    case 6:
        if (est_car_spe(mot) == 1){
            if (strcmp(mot, tab_car_spe[n].CODE)) {
                Sym_COUR.CODE = tab_car_spe[n].CODE;
                strcpy(Sym_COUR.NOM, mot);
                etat_checked = 1;
                //printf("%s\n", Sym_COUR.CODE);
                //etat = 0;
                break;
            }
        }else etat = 4;

      break;

    default :
      Sym_COUR.CODE = ERREUR_TOKEN;
      //printf("%s\n", Sym_COUR.CODE);

      break;
  }
}
