              //les variables globales

                char Car_Cour;
                FILE * Fichier;

                char mot[20];
                char* string;

                typedef enum{
                          IF_TOKEN,
                          ELSE_TOKEN,
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
                          EG_TOKEN,
                          SUP_TOKEN,
                          SUPEG_TOKEN,
                          DIFF_TOKEN,
                          PO_TOKEN,
                          PF_TOKEN,
                          AO_TOKEN,
                          AF_TOKEN,
                          FIN_TOKEN,
                          ID_TOKEN,
                          NUM_TOKEN,
                          ERREUR_TOKEN,
                  }CODES_LEX;

                //******************************

                  typedef struct{
                          char NOM[20];
                          CODES_LEX CODE;
                  }TSym_Cour;
                //*******************************

                TSym_Cour Sym_COUR;
