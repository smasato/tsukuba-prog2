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

void InitRanking(Ranking *ranking);

int LoadRankingFile(char *filename, Ranking *ranking);

int SaveRankingFile(char *filename, Ranking *ranking);

int CanRankIn(Ranking *ranking, int score);

int AddToRanking(Ranking *ranking, int score, char name[20]);

void SortRanking(Ranking *ranking);

void RenderRanking(Ranking *ranking);

void PrintRanking(Ranking *ranking);

#endif // __INCLUDE_RANKING_H__
