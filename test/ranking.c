//
// test/ranking.c
//

#include <stdio.h>
#include "Ranking.h"

int main(void) {
    Ranking ranking;

    InitRanking(&ranking);

    puts("====================");
    printf("test: AddToRanking()\n\n");
    printf("expect:\n"
           "test1: 100\n\n");
    AddToRanking(&ranking, 100, "test1");
    puts("result:");
    PrintRanking(&ranking);
    puts("====================");

    InitRanking(&ranking);

    puts("====================");
    printf("test: SaveRankingFile() and LoadRankingFile()\n\n");
    printf("expect:\n"
           "test2: 200\n\n");
    AddToRanking(&ranking, 200, "test2");
    SaveRankingFile("test/ranking_data.csv", &ranking);
    InitRanking(&ranking);
    puts("result:");
    LoadRankingFile("test/ranking_data.csv", &ranking);
    PrintRanking(&ranking);
    puts("====================");

    InitRanking(&ranking);

    puts("====================");
    printf("test: SortRanking()\n\n");
    printf("expect:\n"
           "1: 100\n"
           "2: 50\n"
           "3: 25\n\n");
    AddToRanking(&ranking, 25, "3");
    AddToRanking(&ranking, 50, "2");
    AddToRanking(&ranking, 100, "1");
    SortRanking(&ranking);
    puts("result:");
    PrintRanking(&ranking);
    puts("====================");

    return 0;
}
