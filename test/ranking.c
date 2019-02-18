//
// test/ranking.c
//

#include <stdio.h>
#include "Ranking.h"

int main(void) {
    Ranking ranking;

    initRanking(&ranking);

    puts("====================");
    printf("test: addToRanking()\n\n");
    printf("expect:\n"
           "test1: 100\n\n");
    addToRanking(&ranking, 100, "test1");
    puts("result:");
    printRanking(&ranking);
    puts("====================");

    initRanking(&ranking);

    puts("====================");
    printf("test: saveRankingFile() and loadRankingFile()\n\n");
    printf("expect:\n"
           "test2: 200\n\n");
    addToRanking(&ranking, 200, "test2");
    saveRankingFile("test/ranking_data.csv", &ranking);
    initRanking(&ranking);
    puts("result:");
    loadRankingFile("test/ranking_data.csv", &ranking);
    printRanking(&ranking);
    puts("====================");

    initRanking(&ranking);

    puts("====================");
    printf("test: sortRanking()\n\n");
    printf("expect:\n"
           "1: 100\n"
           "2: 50\n"
           "3: 25\n\n");
    addToRanking(&ranking, 25, "3");
    addToRanking(&ranking, 50, "2");
    addToRanking(&ranking, 100, "1");
    sortRanking(&ranking);
    puts("result:");
    printRanking(&ranking);
    puts("====================");

    return 0;
}
