//
// lib/Ranking.c
//

#include <stdio.h>
#include <string.h>
#include "Ranking.h"
#include "Text.h"

void InitRanking(Ranking *ranking) {
    ranking->size = 0;
}

int LoadRankingFile(char *filename, Ranking *ranking) {
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

int SaveRankingFile(char *filename, Ranking *ranking) {
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

int CanRankIn(Ranking *ranking, int score) {
    if (ranking->size < 10) return ranking->size;
    for (int i = 0; i < ranking->size; i++) {
        if (ranking->ranking[i].score < score) {
            return i;
        }
    }

    return -1;
}

int AddToRanking(Ranking *ranking, int score, char name[10]) {
    int i = CanRankIn(ranking, score);
    if (i != -1) {
        ranking->ranking[i].score = score;
        strcpy(ranking->ranking[i].name, name);

        ranking->size++;

        return 1;
    } else {
        return 0;
    }
}

void SortRanking(Ranking *ranking) {
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

void RenderRanking(Ranking *ranking) {
    SortRanking(ranking);

    for (int i = 0; i < ranking->size ; i++) {
        char rankingText[64];
        sprintf(rankingText, "%s %d", ranking->ranking[i].name, ranking->ranking[i].score);
        RenderText(rankingText, 180, 145 + i * 30);
    }
}

void PrintRanking(Ranking *ranking) {
    for (int i = 0; i < ranking->size; i++) {
        printf("%s: %d\n", ranking->ranking[i].name, ranking->ranking[i].score);
    }
}
