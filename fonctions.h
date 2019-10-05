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

  int i;
  switch (etat) {

    case 0:
      etat = 1;
      break;

    case 1:
      if (isalpha(mot[i++])!=0) etat = 2; //si tous les caracteres sont des lettres
      else etat = 3; //ID

    case 2:
      int i,c;
      if (est_mot_cle(mot) == 1) {
        Sym_COUR.CODE = tab
      }
    case 3:


  }
}
