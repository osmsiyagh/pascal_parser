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

void verification_des_token_lus(){

  int i=0;
  int k;
  switch (etat) {

    case 0:
      etat = 1;
      break;

    case 1:
      if (isalpha(mot[i++])!=0) etat = 2; //si tous les caracteres sont des lettres
      else etat = 3; //digit ?
      break;

    case 2
      if (est_mot_cle(mot) == 1) {
        for (size_t i = 0; i < taille_tab_mot_cles; i++) {
          if (strcmp(mot, tab_mot_cle[i].CODE)) {
            Sym_COUR.CODE = tab_mot_cle[i].CODE;
            strcpy(Sym_COUR.NOM, mot);
            break;
          }
        }
      }else etat = 4;//identificateur
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
      }else etat = 6; // symbole special
      break;

    case 4:
      Sym_COUR.CODE = ID_TOKEN;
      strcpy(Sym_COUR.NOM, mot);
      break;

    case 5:
      Sym_COUR.CODE = NUM_TOKEN;
      strcpy(Sym_COUR.NOM, mot);
      break;

    case 6:
      if (strcmp(mot, tab_car_spe[i].CODE)) {
        Sym_COUR.CODE = tab_car_spe[i].CODE;
        strcpy(Sym_COUR.NOM, mot);
        break;
      }
      break;
  }
}
