/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P1)
Full Name  :Timothy Lee
Student ID#:177133212
Email      :glee89@myseneca.ca
Section    :NGG
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_PATH_LENGTH 70
#define MIN_PATH_LENGTH 10
#define PATH_LENGTH_MULTIPLE 5
#define MAX_MOVES_PERCENTAGE 0.75

typedef struct {
    int lives;
    char symbol;
    int treasure_count;
    int history[MAX_PATH_LENGTH];
} PlayerInfo;

typedef struct {
    int max_moves;
    int path_length;
    int bombs[MAX_PATH_LENGTH];
    int treasure[MAX_PATH_LENGTH];
} GameInfo;

void configure_player(PlayerInfo* player) {

    int i = 0;
    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");

    printf("PLAYER Configuration\n");
    printf("--------------------\n");

    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player->symbol);
    printf("Set the number of lives: ");

    do {
        scanf("%d", &player->lives);
        if (player->lives < 1 || player->lives > 10) {
            printf("     Must be between 1 and 10!\n");
            printf("Set the number of lives: ");
        }
    } while (player->lives < 1 || player->lives > 10);
    player->treasure_count = 0;

    for (i = 0; i < MAX_PATH_LENGTH; i++) {
        player->history[i] = 0;
    }

    printf("Player configuration set-up is complete\n\n");
}

void configure_game(GameInfo* game, const PlayerInfo* player) {

    int i = 0;
    printf("GAME Configuration\n");
    printf("------------------\n");
    printf("Set the path length (a multiple of %d between %d-%d): ", PATH_LENGTH_MULTIPLE, MIN_PATH_LENGTH, MAX_PATH_LENGTH);
    do {
        scanf("%d", &game->path_length);
        if (game->path_length % PATH_LENGTH_MULTIPLE != 0 || game->path_length < MIN_PATH_LENGTH || game->path_length > MAX_PATH_LENGTH) {
            printf("     Must be a multiple of %d and between %d-%d!!!\n", PATH_LENGTH_MULTIPLE, MIN_PATH_LENGTH, MAX_PATH_LENGTH);
            printf("Set the path length (a multiple of %d between %d-%d): ", PATH_LENGTH_MULTIPLE, MIN_PATH_LENGTH, MAX_PATH_LENGTH);
        }
    } while (game->path_length % PATH_LENGTH_MULTIPLE != 0 || game->path_length < MIN_PATH_LENGTH || game->path_length > MAX_PATH_LENGTH);

    int max_moves = 0;
    do {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &max_moves);
        if (max_moves < 3 || max_moves >(int)(game->path_length * 0.75)) {
            printf("    Value must be between 3 and %d\n", (int)(game->path_length * 0.75));
        }
    } while (max_moves < 3 || max_moves >(int)(game->path_length * 0.75));
    game->max_moves = max_moves;
    
    printf("\nBOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\nof 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game->path_length);
    for (i = 0; i < game->path_length; i += 5) {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d", &game->bombs[i], &game->bombs[i + 1], &game->bombs[i + 2], &game->bombs[i + 3], &game->bombs[i + 4]);
    }
    i = 0;
    printf("BOMB placement set\n\n");

    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\nof 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game->path_length);
    for (i = 0; i < game->path_length; i += 5) {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d", &game->treasure[i], &game->treasure[i + 1], &game->treasure[i + 2], &game->treasure[i + 3], &game->treasure[i + 4]);
    }
    i = 0;
    printf("TREASURE placement set\n\n");

    printf("GAME configuration set-up is complete...\n\n");

    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", player->symbol);
    printf("   Lives      : %d\n", player->lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");

    printf("Game:\n");
    printf("   Path Length: %d\n", game->path_length);
    printf("   Bombs      : ");
    for (i = 0; i < game->path_length; i++) {
        printf("%d", game->bombs[i]);
    }
    i = 0;
    printf("\n");
    printf("   Treasure   : ");
    for (i = 0; i < game->path_length; i++) {
        printf("%d", game->treasure[i]);
    }
    i = 0;

    printf("\n\n====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");
}

int main() {
    PlayerInfo player;
    GameInfo game;
    configure_player(&player);
    configure_game(&game, &player);
    return 0;
}