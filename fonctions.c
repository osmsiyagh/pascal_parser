#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>



#define  taille_tab_mot_cles 12
#define  taille_tab_sym_spe 19


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
    char* stringi = (char*)malloc(2* sizeof(char));
    stringi[0] = c;
    stringi[1] = '\0';
    return stringi;
}

char* LastcharDel(char* name)
{
    int i = 0;
    while(name[i] != '\0')
    {
        i++;

    }
    name[i-1] = '\0';
    return name;
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

int checkAlphaNum(char mot[]){
    for (int i = 0; i < strlen(mot); i++) {
        if (isalnum(mot[i]) == 0){
            return 0;
        }
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
        case EG_TOKEN:
            printf("EG_TOKEN") ;
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

int Car_Cour_Car_Spe(char c){
    char premier_cara = c;
    if(est_car_spe(char_to_string(premier_cara)) || premier_cara == ':' ){
        Lire_Car();
        string = (char*)malloc(3* sizeof(char));
        string[0] = premier_cara;
        string[1] = Car_Cour;
        string[2] = '\0';
        if (est_car_spe(string)){
            return 2;
        }else if ( est_car_spe(LastcharDel(string))){
            fseek(Fichier, -1, SEEK_CUR);
            return 1;
        }
    }
    return 0;

}

void verification_des_token_lus(){
    int k = 0;
    if (checkString(mot) != 0) //si tous les caracteres sont des lettres
        {
            if (est_mot_cle(mot) == 1) {
                for (size_t i = 0; i < taille_tab_mot_cles; i++) {
                    if (strcmp(mot, tab_mot_cle[i].NOM) == 0) {
                        Sym_COUR.CODE = tab_mot_cle[i].CODE;
                        strcpy(Sym_COUR.NOM, mot);
                    }
                }
            }else // ID
             {
                Sym_COUR.CODE = ID_TOKEN;
                strcpy(Sym_COUR.NOM, mot);
            }
    }
    else //digit ? identificateur ? car_spe ?
        {
            if (isdigit(mot[0]) != 0) {
                k = 1;
                if ((isdigit(mot[k++]) != 0)) //NUM_TOKEN
                {
                    Sym_COUR.CODE = NUM_TOKEN;
                    strcpy(Sym_COUR.NOM, mot);
                } else {
                    while ((isdigit(mot[k] != 0) && mot[k + 1] != '.')) {
                        k++;
                    }
                    if ((mot[k + 1] == '.' && isdigit(mot[k++] != 0)) || mot[k] == '.')//NUM_TOKEN
                    {
                        Sym_COUR.CODE = NUM_TOKEN;
                        strcpy(Sym_COUR.NOM, mot);
                    }
                }
            }else // ID
            {
                if (est_car_spe(mot) == 1){
                    for (int i = 0; i < taille_tab_sym_spe; i++) {
                        if (strcmp(mot, tab_car_spe[i].NOM) == 0) {
                            Sym_COUR.CODE = tab_car_spe[i].CODE;
                            strcpy(Sym_COUR.NOM, mot);
                        }
                    }
                } else if (checkAlphaNum(mot) == 0){
                    strcpy(Sym_COUR.NOM, mot);
                    Sym_COUR.CODE = ERREUR_TOKEN;
                }else
                {
                    Sym_COUR.CODE = ID_TOKEN;
                    strcpy(Sym_COUR.NOM, mot);
                }
            }
    }
/*
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
      } //digit ? identificateur ? car_spe ?
      break;

    case 2 :
      //printf("Am here now");
      if (est_mot_cle(mot) == 1) {
        for (size_t i = 0; i < taille_tab_mot_cles; i++) {
          if (strcmp(mot, tab_mot_cle[i].NOM) == 0) {
            Sym_COUR.CODE = tab_mot_cle[i].CODE;
            strcpy(Sym_COUR.NOM, mot);
              printf("I did it");
            etat_checked = 1;
            //etat = 1;
          }
        }
      }else {
          etat = 3;// digit or id
          //printf("we are here \n");
      }
      break;

    case 3:
      if (isdigit(mot[0]) != 0) {
        //  printf("on est là");
        k=1;
        if((isdigit(mot[k++])!= 0)) etat = 5;//NUM_TOKEN
        else{
          while ((isdigit(mot[k] != 0) && mot[k+1]!= '.')) {
            k++;
          }
          if ((mot[k+1]=='.' && isdigit(mot[k++]!=0)) || mot[k]=='.') etat = 5;
        }
      }else{
          printf("on est là");
          //etat = 6;
      }  //car_spe ou identificateur
      break;

    case 4:

      Sym_COUR.CODE = ID_TOKEN;
      strcpy(Sym_COUR.NOM, mot);
      printf("on est là");
      etat_checked = 1;
      //printf("%s\n", Sym_COUR.CODE);
      //etat = 1;
      break;

    case 5:
      Sym_COUR.CODE = NUM_TOKEN;
      strcpy(Sym_COUR.NOM, mot);
      etat_checked = 1;
      //printf("%s\n", Sym_COUR.CODE);
      //etat = 1;
      break;

    case 6:
        if (est_car_spe(mot) == 1){
            if (strcmp(mot, tab_car_spe[n].CODE)) {
                Sym_COUR.CODE = tab_car_spe[n].CODE;
                strcpy(Sym_COUR.NOM, mot);
                etat_checked = 1;
                //printf("%s\n", Sym_COUR.CODE);
                //etat = 1;
                break;
            }
        }else etat = 4;

      break;

    default :
      Sym_COUR.CODE = ERREUR_TOKEN;
      //printf("%s\n", Sym_COUR.CODE);

      break;
  }
  */
}
