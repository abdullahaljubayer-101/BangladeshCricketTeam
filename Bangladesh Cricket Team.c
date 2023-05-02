#include <stdio.h>
#include <string.h>

struct Player
{
    char fullName[50];
    int age;
    char playerRole[50];
    int ODIMatch;
    int totalRuns;
    int highestRun;
}player[50];

int numberOfPlayers;

void showAllPlayer();
void particularPlayerInformation();
void mostExperiencedPlayer();
void newCommerPlayer();
void topScorerPlayer();
void hardHitterPlayer();
void highestRunTakerPlayer();
void mostValuablePlayer();
void showTheAllRounders();

int main() {
    char fileName[100];
    printf("Enter Input File Name: ");
    scanf(" %[^\n]s", fileName);

    FILE *file = fopen(fileName, "r");

    fscanf(file, "%d", &numberOfPlayers);

    for (int i = 0; i < numberOfPlayers; i++) {
        fscanf(file, " %[^\n]s", player[i].fullName);
        fscanf(file, "%d", &player[i].age);
        fscanf(file, " %[^\n]s", player[i].playerRole);
        fscanf(file, "%d", &player[i].ODIMatch);
        fscanf(file, "%d", &player[i].totalRuns);
        fscanf(file, "%d", &player[i].highestRun);
    }

    fclose(file);

    int choice;
    while (1) {
        printf("\n"
               "1. Show All Players\n"
               "2. Show A Particular player information (Provide Player Name)\n"
               "3. Show the MOST Experienced Player (MEP)\n"
               "4. Show the New Commer Player (NCP)\n"
               "5. Show the Top Scorer Player (TSP)\n"
               "6. Show the Hard Hitter Player (HHP)\n"
               "7. Show the Highest Run Taker Player (HRTP)\n"
               "8. Show the MOST Valuable Player (MVP)\n"
               "9. Show the All-rounders\n"
               "10. Exit/Quit\n"
               "\n"
               "Enter Your Choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            showAllPlayer();
        } else if (choice == 2) {
            particularPlayerInformation();
        } else if (choice == 3) {
            mostExperiencedPlayer();
        } else if (choice == 4) {
            newCommerPlayer();
        } else if (choice == 5) {
            topScorerPlayer();
        } else if (choice == 6) {
            hardHitterPlayer();
        } else if (choice == 7) {
            highestRunTakerPlayer();
        } else if (choice == 8) {
            mostValuablePlayer();
        } else if (choice == 9) {
            showTheAllRounders();
        } else if (choice == 10) {
            break;
        }
    }
}

void showAllPlayer() {
    for (int i = 0; i < numberOfPlayers; i++) {
        printf("\n");
        printf("Full Name: %s\n", player[i].fullName);
        printf("Age: %d\n", player[i].age);
        printf("Player Role: %s\n", player[i].playerRole);
        printf("ODI Match: %d\n", player[i].ODIMatch);
        printf("Total Runs: %d\n", player[i].totalRuns);
        printf("Highest Run: %d\n", player[i].highestRun);
        printf("\n");
    }
}

void particularPlayerInformation() {
    printf("\n");

    char name[50];
    printf("Enter Player Name: ");
    scanf(" %[^\n]s", name);

    for (int i = 0; i < numberOfPlayers; i++) {
        if (strncmp(name, player[i].fullName, strlen(name)) == 0) {
            printf("\n");
            printf("Full Name: %s\n", player[i].fullName);
            printf("Age: %d\n", player[i].age);
            printf("Player Role: %s\n", player[i].playerRole);
            printf("ODI Match: %d\n", player[i].ODIMatch);
            printf("Total Runs: %d\n", player[i].totalRuns);
            printf("Highest Run: %d\n", player[i].highestRun);
            printf("\n");

            break;
        }
    }
}

void mostExperiencedPlayer() {
    int maxMatch = 0;
    int maxMatchIndex = 0;

    for (int i = 0; i < numberOfPlayers; i++) {
        if (maxMatch < player[i].ODIMatch) {
            maxMatch = player[i].ODIMatch;
            maxMatchIndex = i;
        }
    }

    printf("\nMOST Experienced Player (MEP): %s\n", player[maxMatchIndex].fullName);
}

void newCommerPlayer() {
    int minAge = 9999;
    int minAgeIndex = 0;

    for (int i = 0; i < numberOfPlayers; i++) {
        if (minAge > player[i].age) {
            minAge = player[i].age;
            minAgeIndex = i;
        }
    }

    printf("\nNew Commer Player (NCP): %s\n", player[minAgeIndex].fullName);
}

void topScorerPlayer() {
    int maxTotalRuns = 0;
    int maxTotalRunsIndex = 0;

    for (int i = 0; i < numberOfPlayers; i++) {
        if (maxTotalRuns < player[i].totalRuns) {
            maxTotalRuns = player[i].totalRuns;
            maxTotalRunsIndex = i;
        }
    }

    printf("\nTop Scorer Player (TSP): %s\n", player[maxTotalRunsIndex].fullName);
}

void hardHitterPlayer() {
    float maxAverageRunPerMatch = 0;
    int maxAverageRunPerMatchIndex = 0;

    for (int i = 0; i < numberOfPlayers; i++) {
        float averageRunPerMatch = (float) player[i].totalRuns / player[i].ODIMatch;
        if (maxAverageRunPerMatch < averageRunPerMatch) {
            maxAverageRunPerMatch = averageRunPerMatch;
            maxAverageRunPerMatchIndex = i;
        }
    }

    printf("\nHard Hitter Player (HHP): %s\n", player[maxAverageRunPerMatchIndex].fullName);
}

void highestRunTakerPlayer() {
    int maxHighestRun = 0;
    int maxHighestRunIndex = 0;

    for (int i = 0; i < numberOfPlayers; i++) {
        if (maxHighestRun < player[i].highestRun) {
            maxHighestRun = player[i].highestRun;
            maxHighestRunIndex = i;
        }
    }

    printf("\nHighest Run Taker Player (HRTP): %s\n", player[maxHighestRunIndex].fullName);
}

void mostValuablePlayer() {
    float maxValue = 0;
    int maxValueIndex = 0;

    for (int i = 0; i < numberOfPlayers; i++) {
        if (strncmp(player[i].playerRole, "Allrounder", 10) == 0) {
            float value = player[i].age + player[i].ODIMatch + player[i].totalRuns + player[i].highestRun + ((float) player[i].totalRuns / player[i].ODIMatch) + ((float ) player[i].highestRun / player[i].age);
            if (maxValue < value) {
                maxValue = value;
                maxValueIndex = i;
            }
        }
    }

    printf("\nMOST Valuable Player (MVP): %s\n", player[maxValueIndex].fullName);
}

void showTheAllRounders() {
    for (int i = 0; i < numberOfPlayers; i++) {
        if (strncmp(player[i].playerRole, "Allrounder", 10) == 0) {
            printf("\n");
            printf("Full Name: %s\n", player[i].fullName);
            printf("Age: %d\n", player[i].age);
            printf("Player Role: %s\n", player[i].playerRole);
            printf("ODI Match: %d\n", player[i].ODIMatch);
            printf("Total Runs: %d\n", player[i].totalRuns);
            printf("Highest Run: %d\n", player[i].highestRun);
            printf("\n");
        }
    }
}