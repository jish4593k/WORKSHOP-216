#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent the JSON data
typedef struct {
    char uuid[37];
    int mine_locations[25];
    int clicked_spots[25];
} GameData;

// Simulate the cloudscraper API request
void simulate_api_request(GameData *game_data) {
    // Simulate API response
    strcpy(game_data->uuid, "123456789012345678901234567890123456");
    for (int i = 0; i < 25; i++) {
        game_data->mine_locations[i] = rand() % 2; // 0 or 1
        game_data->clicked_spots[i] = rand() % 2; // 0 or 1
    }
}

// Simulate the main function
void simulate_main() {
    GameData game_data;

    // Simulate API request
    simulate_api_request(&game_data);

    // Print the simulated data
    printf("Most Recent uuid: %s\n", game_data.uuid);
    printf("Most Recent mine locations: ");
    for (int i = 0; i < 25; i++) {
        printf("%d ", game_data.mine_locations[i]);
    }
    printf("\nMost Recent clicked spots: ");
    for (int i = 0; i < 25; i++) {
        printf("%d ", game_data.clicked_spots[i]);
    }
    printf("\n");

    // Simulate grid generation
    char grid[25];
    for (int i = 0; i < 25; i++) {
        if (game_data.mine_locations[i]) {
            grid[i] = 'X';
        } else if (game_data.clicked_spots[i]) {
            grid[i] = 'O';
        } else {
            grid[i] = '-';
        }
    }

    // Print the simulated grid
    printf("\nLast game played\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c ", grid[i * 5 + j]);
        }
        printf("\n");
    }

    // Simulate prediction
    for (int i = 0; i < 25; i++) {
        grid[i] = '-';
    }

    int roundId = atoi(game_data.uuid);
    int roundNum = atoi(game_data.uuid) / 1000000000; // Simplified logic for demonstration

    grid[roundNum / 4] = 'O';
    grid[roundNum / 5] = 'O';
    grid[roundNum / 7] = 'O';

    // Print the simulated prediction
    printf("\nPrediction (use the same mine amount as your last game)\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c ", grid[i * 5 + j]);
        }
        printf("\n");
    }
}

int main() {
    simulate_main();
    return 0;
}
