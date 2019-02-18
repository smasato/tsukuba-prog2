//
// include/Ranking.h
//

#ifndef __INCLUDE_RANKING_H__
#define __INCLUDE_RANKING_H__

typedef struct {
    int score;
    char name[20];
} User;

typedef struct {
    int size;
    User ranking[10];
} Ranking;

void initRanking(Ranking *ranking);

int loadRankingFile(char *filename, Ranking *ranking);

int saveRankingFile(char *filename, Ranking *ranking);

int canRankIn(Ranking *ranking, int score);

int addToRanking(Ranking *ranking, int score, char *name);

void sortRanking(Ranking *ranking);

void renderRanking(Ranking *ranking);

void printRanking(Ranking *ranking);

#endif // __INCLUDE_RANKING_H__
