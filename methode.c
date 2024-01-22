
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <mariadb/mysql.h>

#include "propriete.c"


void mot_cachee(char* mot, char* lettre_saisi) {
    for (int i = 0; i < strlen(mot); i++) {
        if (strchr(lettre_saisi, mot[i]) != NULL) {
            printf("%c ", mot[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

char choix_utilisateur() {
    char choix;
    printf("Entrez une lettre >>>\t");
    scanf(" %c", &choix);
    return choix;
}

int verifie_choix(char* mot, char choix, char* lettre_saisi) {
    if (strchr(lettre_saisi, choix) != NULL) {
        printf("Lettre deja trouver !\n");
        return 0;
    } else if (strchr(mot, choix) != NULL) {
        printf("Lettre correcte !\n");
        return 1;
    } else {
        printf("Lettre incorrecte !\n");
        return -1;
    }
}

void score_write(char *name, int score){
    FILE *fichier = fopen("score", "a");
    fprintf(fichier, "[ %s ] score of %d\n", name, score);
    fclose(fichier);
}

void score_print(){

    char line[100];

    FILE *fichier = fopen("score", "r");

    printf("\n--------[ Scores ]--------\n");
    for (int i = 0; i < 10; ++i) {
        if(fgets(line, sizeof(line), fichier) != NULL) {
                printf("%s", line);
        }
        else{
            break ;
        }
    }
    fclose(fichier);
    printf("\n----------------------------\n\n");

}

/*
void score_print(){

    MYSQL *conn;
    MYSQL_RES *result;
    MYSQL_ROW row;

    conn = mysql_init(NULL);
    mysql_real_connect(conn, "localhost", "applepie", "applepie", "applepie", 0, NULL, 0) ;

    mysql_query(conn, "SELECT * FROM Score order by score desc limit 10") ;
    result = mysql_store_result(conn);

    system("clear");
    printf("\n------------[ Scores ]------------\n");
    while ( (row = mysql_fetch_row(result)) ) {
        printf("\t[ %s ] score of %s\n", row[1], row[2]);
    }
    printf("----------------------------------\n");


    mysql_close(conn);

}

void score_write(){

    FILE *fichier = fopen("exemple.txt", "a");
    fprintf(fichier, "");

    MYSQL *conn;
    MYSQL_RES *result;
    MYSQL_ROW row;

    conn = mysql_init(NULL);
    mysql_real_connect(conn, "localhost", "applepie", "applepie", "applepie", 0, NULL, 0) ;

    char *requete = "insert into Score(username, score) value('YYYYY', XXXXX)" ;

    mysql_query(conn, requete) ;

    mysql_close(conn);

}
*/