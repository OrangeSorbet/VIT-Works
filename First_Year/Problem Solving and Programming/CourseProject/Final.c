#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define BOARD_SIZE 10
static const char ALPHABET[] = "ABCDEFGHIJ";

static const int SHIP_SIZES[] = {5, 3, 2, 2, 1};
static const int NUM_SHIPS = sizeof(SHIP_SIZES) / sizeof(SHIP_SIZES[0]);

typedef enum {
    HUNT_MODE,
    TARGET_MODE
} AImode;

typedef struct {
    AImode mode;
    int last_hit_x;
    int last_hit_y;
    int target_candidates[4][2];
    int num_candidates;
} AIState;

void initialize_board(char board[BOARD_SIZE][BOARD_SIZE]);
void print_board(const char board[BOARD_SIZE][BOARD_SIZE], bool reveal_ships);
bool place_ship(char board[BOARD_SIZE][BOARD_SIZE], int size, bool horizontal, int x, int y);
bool place_ships_random(char board[BOARD_SIZE][BOARD_SIZE]);
bool process_attack(char board[BOARD_SIZE][BOARD_SIZE], int x, int y);
bool check_victory(const char board[BOARD_SIZE][BOARD_SIZE]);
void update_board_for_destroyed_ship(char board[BOARD_SIZE][BOARD_SIZE]);
void floodFillShip(char board[BOARD_SIZE][BOARD_SIZE],
                   int i, int j,
                   bool visited[BOARD_SIZE][BOARD_SIZE],
                   int group[][2],
                   int *groupCount,
                   bool *hasIntact);
void manual_place_ships(char board[BOARD_SIZE][BOARD_SIZE], const char *playerName);
void initialize_ai(AIState *state);
void add_target_candidates(AIState *state, int x, int y, char board[BOARD_SIZE][BOARD_SIZE]);
void ai_attack(AIState *state, char player_board[BOARD_SIZE][BOARD_SIZE]);
void display_rules();
void player_attack(char opponent_board[BOARD_SIZE][BOARD_SIZE],
                   char guess_board[BOARD_SIZE][BOARD_SIZE],
                   const char *player_name);

void initialize_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            board[i][j] = '.';
}

void print_board(const char board[BOARD_SIZE][BOARD_SIZE], bool reveal_ships) {
    printf("   A B C D E F G H I J\n");
    printf("  ---------------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%2d| ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            char cell = board[i][j];
            if (reveal_ships) {
                if (cell == '&' || cell == '#' || cell == '0' || cell == 'x')
                    printf("%c ", cell);
                else
                    printf(". ");
            } else {
                if (cell == 'x' || cell == '#' || cell == '0')
                    printf("%c ", cell);
                else
                    printf(". ");
            }
        }
        printf("\n");
    }
}

bool place_ship(char board[BOARD_SIZE][BOARD_SIZE], int size, bool horizontal, int x, int y) {
    if (horizontal) {
        if (y + size > BOARD_SIZE) return false;
        for (int i = 0; i < size; i++) {
            if (board[x][y + i] != '.') return false;
        }
        for (int i = 0; i < size; i++) {
            board[x][y + i] = '&';
        }
    } else {
        if (x + size > BOARD_SIZE) return false;
        for (int i = 0; i < size; i++) {
            if (board[x + i][y] != '.') return false;
        }
        for (int i = 0; i < size; i++) {
            board[x + i][y] = '&';
        }
    }
    return true;
}

bool place_ships_random(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < NUM_SHIPS; i++) {
        bool placed = false;
        int attempts = 0;
        while (!placed && attempts < 1000) {
            int x = rand() % BOARD_SIZE;
            int y = rand() % BOARD_SIZE;
            bool horizontal = (rand() % 2) == 0;
            placed = place_ship(board, SHIP_SIZES[i], horizontal, x, y);
            attempts++;
        }
    }
    return true;
}

bool process_attack(char board[BOARD_SIZE][BOARD_SIZE], int x, int y) {
    if (board[x][y] == '&') {
        board[x][y] = '#';
        update_board_for_destroyed_ship(board);
        return true;
    } else if (board[x][y] == '.') {
        board[x][y] = 'x';
        return false;
    }
    return false;
}

bool check_victory(const char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
            if (board[i][j] == '&')
                return false;
    return true;
}

void floodFillShip(char board[BOARD_SIZE][BOARD_SIZE],
                   int i, int j,
                   bool visited[BOARD_SIZE][BOARD_SIZE],
                   int group[][2],
                   int *groupCount,
                   bool *hasIntact) {
    if (i < 0 || i >= BOARD_SIZE || j < 0 || j >= BOARD_SIZE)
        return;
    if (visited[i][j])
        return;
    if (board[i][j] != '#' && board[i][j] != '&')
        return;

    visited[i][j] = true;
    group[*groupCount][0] = i;
    group[*groupCount][1] = j;
    (*groupCount)++;
    if (board[i][j] == '&')
        *hasIntact = true;

    floodFillShip(board, i - 1, j, visited, group, groupCount, hasIntact);
    floodFillShip(board, i + 1, j, visited, group, groupCount, hasIntact);
    floodFillShip(board, i, j - 1, visited, group, groupCount, hasIntact);
    floodFillShip(board, i, j + 1, visited, group, groupCount, hasIntact);
}

void update_board_for_destroyed_ship(char board[BOARD_SIZE][BOARD_SIZE]) {
    bool visited[BOARD_SIZE][BOARD_SIZE] = { false };
    int group[BOARD_SIZE * BOARD_SIZE][2];
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (!visited[i][j] && (board[i][j] == '#' || board[i][j] == '&')) {
                int groupCount = 0;
                bool hasIntact = false;
                floodFillShip(board, i, j, visited, group, &groupCount, &hasIntact);
                if (!hasIntact && groupCount > 0) {
                    for (int k = 0; k < groupCount; k++) {
                        int gx = group[k][0];
                        int gy = group[k][1];
                        board[gx][gy] = '0';
                    }
                }
            }
        }
    }
}

void manual_place_ships(char board[BOARD_SIZE][BOARD_SIZE], const char *playerName) {
    printf("\n%s, place your ships on the board.\n", playerName);
    for (int i = 0; i < NUM_SHIPS; i++) {
        int size = SHIP_SIZES[i];
        bool placed = false;
        while (!placed) {
            print_board(board, true);
            printf("Place your ship of size %d.\n", size);
            printf("Enter starting coordinate (e.g., A1): ");
            char coord[5];
            scanf("%s", coord);
            char col = coord[0];
            int row = atoi(&coord[1]);
            if (row < 1 || row > BOARD_SIZE || col < 'A' || col > 'A' + BOARD_SIZE - 1) {
                printf("Invalid coordinate. Try again.\n");
                continue;
            }
            int x = row - 1;
            int y = col - 'A';
            printf("Enter orientation (H for horizontal, V for vertical): ");
            char orient;
            scanf(" %c", &orient);
            bool horizontal;
            if (orient == 'H' || orient == 'h')
                horizontal = true;
            else if (orient == 'V' || orient == 'v')
                horizontal = false;
            else {
                printf("Invalid orientation. Use H or V.\n");
                continue;
            }
            if (!place_ship(board, size, horizontal, x, y)) {
                printf("Invalid placement or overlapping ship. Try again.\n");
            } else {
                placed = true;
            }
        }
    }
}

void initialize_ai(AIState *state) {
    state->mode = HUNT_MODE;
    state->last_hit_x = -1;
    state->last_hit_y = -1;
    state->num_candidates = 0;
}

void add_target_candidates(AIState *state, int x, int y, char board[BOARD_SIZE][BOARD_SIZE]) {
    int directions[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
    for (int d = 0; d < 4; d++) {
        int nx = x + directions[d][0];
        int ny = y + directions[d][1];
        if (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE) {
            if (board[nx][ny] == '.' || board[nx][ny] == '&') {
                bool duplicate = false;
                for (int i = 0; i < state->num_candidates; i++) {
                    if (state->target_candidates[i][0] == nx &&
                        state->target_candidates[i][1] == ny) {
                        duplicate = true;
                        break;
                    }
                }
                if (!duplicate && state->num_candidates < 4) {
                    state->target_candidates[state->num_candidates][0] = nx;
                    state->target_candidates[state->num_candidates][1] = ny;
                    state->num_candidates++;
                }
            }
        }
    }
}

void ai_attack(AIState *state, char player_board[BOARD_SIZE][BOARD_SIZE]) {
    int x, y;
    bool hit;
    if (state->mode == HUNT_MODE) {
        do {
            x = rand() % BOARD_SIZE;
            y = rand() % BOARD_SIZE;
        } while (player_board[x][y] == 'x' || player_board[x][y] == '#' || player_board[x][y] == '0');

        hit = process_attack(player_board, x, y);
        if (hit) {
            printf("Computer HIT at %c%d!\n", ALPHABET[y], x + 1);
            state->mode = TARGET_MODE;
            state->last_hit_x = x;
            state->last_hit_y = y;
            state->num_candidates = 0;
            add_target_candidates(state, x, y, player_board);
        } else {
            printf("Computer MISSED at %c%d!\n", ALPHABET[y], x + 1);
        }
    } else {
        if (state->num_candidates > 0) {
            int idx = state->num_candidates - 1;
            x = state->target_candidates[idx][0];
            y = state->target_candidates[idx][1];
            state->num_candidates--;
            hit = process_attack(player_board, x, y);
            if (hit) {
                printf("Computer HIT at %c%d!\n", ALPHABET[y], x + 1);
                state->last_hit_x = x;
                state->last_hit_y = y;
                add_target_candidates(state, x, y, player_board);
            } else {
                printf("Computer MISSED at %c%d!\n", ALPHABET[y], x + 1);
            }
        } else {
            state->mode = HUNT_MODE;
            ai_attack(state, player_board);
        }
        if (state->last_hit_x >= 0 && state->last_hit_y >= 0 &&
            player_board[state->last_hit_x][state->last_hit_y] == '0') {
            state->mode = HUNT_MODE;
            state->num_candidates = 0;
            state->last_hit_x = -1;
            state->last_hit_y = -1;
        }
    }
}

void display_rules() {
    printf("Welcome to Battleship!\n\n");
    printf("Game Rules:\n");
    printf("1. Players take turns attacking each other's ships.\n");
    printf("2. Ships are placed on a 10x10 grid.\n");
    printf("3. The first player to sink all enemy ships wins.\n\n");
    printf("Symbols on the Board:\n");
    printf("  '.' - Water\n");
    printf("  '&' - Intact ship part\n");
    printf("  '#' - Hit ship part\n");
    printf("  '0' - Destroyed ship\n");
    printf("  'x' - Missed attack\n\n");
}

void player_attack(char opponent_board[BOARD_SIZE][BOARD_SIZE],
                   char guess_board[BOARD_SIZE][BOARD_SIZE],
                   const char *player_name) {
    char move[5];
    int x, y;
    while (1) {
        printf("%s, enter attack coordinates (e.g., A1, A10): ", player_name);
        scanf("%s", move);
        char col = move[0];
        int row = atoi(&move[1]);
        if (row < 1 || row > BOARD_SIZE || col < 'A' || col > 'A' + BOARD_SIZE - 1) {
            printf("Invalid coordinates. Try again.\n");
            continue;
        }
        x = row - 1;
        y = col - 'A';
        if (guess_board[x][y] == 'x' || guess_board[x][y] == '#' || guess_board[x][y] == '0') {
            printf("Already attacked this position. Try again.\n");
            continue;
        }
        bool hit = process_attack(opponent_board, x, y);
        if (hit) {
            guess_board[x][y] = '#';
            printf("You HIT at %c%d!\n", col, row);
        } else {
            guess_board[x][y] = 'x';
            printf("You MISSED at %c%d!\n", col, row);
        }
        break;
    }
}

int main() {
    srand(time(NULL));
    display_rules();

    char mode;
    printf("Choose mode: (1) Player vs Player (2) Player vs Computer: ");
    scanf(" %c", &mode);
    while (mode != '1' && mode != '2') {
        printf("Invalid mode. Choose 1 or 2: ");
        scanf(" %c", &mode);
    }

    if (mode == '1') {
        char board1[BOARD_SIZE][BOARD_SIZE];
        char board2[BOARD_SIZE][BOARD_SIZE];
        char guess1[BOARD_SIZE][BOARD_SIZE];
        char guess2[BOARD_SIZE][BOARD_SIZE];

        initialize_board(board1);
        initialize_board(board2);
        initialize_board(guess1);
        initialize_board(guess2);

        manual_place_ships(board1, "Player 1");
        manual_place_ships(board2, "Player 2");

        bool player1_turn = true;
        while (true) {
            if (player1_turn) {
                printf("\nPlayer 1's turn:\n");
                print_board(guess1, false);
                player_attack(board2, guess1, "Player 1");
                if (check_victory(board2)) {
                    printf("Player 1 wins!\n");
                    break;
                }
            } else {
                printf("\nPlayer 2's turn:\n");
                print_board(guess2, false);
                player_attack(board1, guess2, "Player 2");
                if (check_victory(board1)) {
                    printf("Player 2 wins!\n");
                    break;
                }
            }
            player1_turn = !player1_turn;
        }
    } else {
        char player_board[BOARD_SIZE][BOARD_SIZE];
        char ai_board[BOARD_SIZE][BOARD_SIZE];
        char guess_board[BOARD_SIZE][BOARD_SIZE];
        AIState ai_state;

        initialize_board(player_board);
        initialize_board(ai_board);
        initialize_board(guess_board);
        initialize_ai(&ai_state);

        manual_place_ships(player_board, "Player");
        place_ships_random(ai_board);

        while (true) {
            printf("\nYour turn:\n");
            print_board(guess_board, false);
            player_attack(ai_board, guess_board, "Player");
            if (check_victory(ai_board)) {
                printf("You win!\n");
                break;
            }

            printf("\nComputer's turn:\n");
            ai_attack(&ai_state, player_board);
            if (check_victory(player_board)) {
                printf("Computer wins!\n");
                break;
            }
        }
    }

    return 0;
}
