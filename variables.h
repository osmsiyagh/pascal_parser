



              //les variables globales



                char Car_Cour;
                FILE * Fichier;

                char mot[20];

                int etat=0;

                //le type �num�r� des token
                typedef enum{
                          IF_TOKEN,
                          THEN_TOKEN,
                          BEGIN_TOKEN,
                          END_TOKEN,
                          PROGRAM_TOKEN,
                          CONST_TOKEN,
                          VAR_TOKEN,
                          WHILE_TOKEN,
                          DO_TOKEN,
                          READ_TOKEN,
                          WRITE_TOKEN,
                          PV_TOKEN,
                          PT_TOKEN,
                          PLUS_TOKEN,
                          MOINS_TOKEN,
                          MULTI_TOKEN,
                          DIV_TOKEN,
                          VIR_TOKEN,
                          AFF_TOKEN,
                          INF_TOKEN,
                          INFEG_TOKEN,
                          SUP_TOKEN,
                          SUPEG_TOKEN,
                          DIFF_TOKEN,
                          PO_TOKEN,
                          PF_TOKEN,
                          FIN_TOKEN,
                          ID_TOKEN,
                          NUM_TOKEN,
                          CAR_SPE_TOKEN,
                          ERREUR_TOKEN,
                  }CODES_LEX;

                //******************************

                  typedef struct{
                          char NOM[20];
                          CODES_LEX CODE;
                  }TSym_Cour;
                //*******************************

                TSym_Cour Sym_COUR;
                //*******************************
                //tableau des mots clés:

                TUNITE_LEXICALE tab_mot_cle[taille_tab_mot_cles]={
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
                TUNITE_LEXICALE tab_car_spe[taille_tab_sym_spe]={
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
