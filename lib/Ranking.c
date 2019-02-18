//
// lib/Ranking.c
//

#include <stdio.h>
#include <string.h>
#include "Ranking.h"
#include "Text.h"

void initRanking(Ranking *ranking) {
    ranking->size = 0;
}

int loadRankingFile(char *filename, Ranking *ranking) {
    FILE *fp = fopen(filename, "r");
    if (fp != NULL) {
        int i;
        for (i = 0; i < 10; i++) {
            if (fscanf(fp, "%[^,],%d\n", ranking->ranking[i].name, &(ranking->ranking[i].score)) == EOF) {
                break;
            }
        }
        ranking->size = i;
        fclose(fp);

        return 1;
    } else {
        return 0;
    }
}

int saveRankingFile(char *filename, Ranking *ranking) {
    FILE *fp = fopen(filename, "w");
    if (fp != NULL) {
        for (int i = 0; i < ranking->size; i++) {
            fprintf(fp, "%s,%d\n", ranking->ranking[i].name, ranking->ranking[i].score);
        }

        fclose(fp);

        return 1;
    } else {
        return 0;
    }
}

int canRankIn(Ranking *ranking, int score) {
    if (ranking->size < 10) return ranking->size;
    for (int i = 0; i < ranking->size; i++) {
        if (ranking->ranking[i].score < score) {
            return i;
        }
    }

    return -1;
}

int addToRanking(Ranking *ranking, int score, char *name) {
    int i = canRankIn(ranking, score);
    if (i != -1) {
        ranking->ranking[i].score = score;
        strcpy(ranking->ranking[i].name, name);

        ranking->size++;

        return 1;
    } else {
        return 0;
    }
}

void sortRanking(Ranking *ranking) {
    User tmp;
    for (int i = 0; i < (ranking->size - 1); ++i) {
        for (int j = (ranking->size - 1); j > i; j--) {
            if (ranking->ranking[j - 1].score < ranking->ranking[j].score) {
                tmp = ranking->ranking[j - 1];
                ranking->ranking[j - 1] = ranking->ranking[j];
                ranking->ranking[j] = tmp;
            }
        }
    }
}

void renderRanking(Ranking *ranking) {
    sortRanking(ranking);

    for (int i = 0; i < ranking->size ; i++) {
        char rankingText[64];
        sprintf(rankingText, "%s %d", ranking->ranking[i].name, ranking->ranking[i].score);
        renderText(rankingText, 180, 145 + i * 30);
    }
}

void printRanking(Ranking *ranking) {
    for (int i = 0; i < ranking->size; i++) {
        printf("%s: %d\n", ranking->ranking[i].name, ranking->ranking[i].score);
    }
}
