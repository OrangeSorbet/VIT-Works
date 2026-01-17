#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define BOARD_SIZE 10
#define SHIP_SIZES {5, 3, 2, 2, 1}  // Ship sizes: 1 ship of size 5, 1 ship of size 3, 2 ships of size 2

const char ALPHABET[] = "ABCDEFGHIJ"; // For coordinate system

typedef struct {
    int x, y;
} Coordinate;

// Function prototypes
void print_board(char board[BOARD_SIZE][BOARD_SIZE], bool reveal_ships);
bool is_valid_move(int x, int y);
bool place_ship(char board[BOARD_SIZE][BOARD_SIZE], int size, bool horizontal, int x, int y);
bool check_victory(char board[BOARD_SIZE][BOARD_SIZE]);
void player_attack(char opponent_board[BOARD_SIZE][BOARD_SIZE], char guess_board[BOARD_SIZE][BOARD_SIZE], const char* player_name);
void computer_attack(char player_board[BOARD_SIZE][BOARD_SIZE]);
void initialize_board(char board[BOARD_SIZE][BOARD_SIZE]);
bool place_ships(char board[BOARD_SIZE][BOARD_SIZE]);
bool process_attack(char board[BOARD_SIZE][BOARD_SIZE], int x, int y);
void display_rules();
void swap_turns(char* current_turn);
void update_board_for_destroyed_ship(char board[BOARD_SIZE][BOARD_SIZE]);

int main() {
    srand(time(NULL));

    // Display Menu and Rules
    display_rules();

    char mode;
    printf("Choose mode: (1) Player vs Player (2) Player vs Computer: ");
    scanf(" %c", &mode);

    while (mode != '1' && mode != '2') {
        printf("Invalid choice! Please choose again: ");
        scanf(" %c", &mode);
    }

    char player1_board[BOARD_SIZE][BOARD_SIZE];
    char player2_board[BOARD_SIZE][BOARD_SIZE];
    char player1_guess_board[BOARD_SIZE][BOARD_SIZE];
    char player2_guess_board[BOARD_SIZE][BOARD_SIZE];

    // Initialize boards
    initialize_board(player1_board);
    initialize_board(player2_board);
    initialize_board(player1_guess_board);
    initialize_board(player2_guess_board);

    // Randomly place ships
    place_ships(player1_board);   // Place ships on Player 1's board
    place_ships(player2_board);   // Place ships on Player 2's board

    char current_turn = '1';  // Start with Player 1

    if (mode == '1') {  // Player vs Player
        while (1) {
            if (current_turn == '1') {
                printf("\n--- Player 1's Turn ---\n");
                // Show Player 1's board fully and Player 2's guessed positions
                print_board(player1_board, true);  // Top: Player 1's ships
                print_board(player2_guess_board, false);  // Bottom: Player 1's guesses for Player 2's ships

                player_attack(player2_board, player1_guess_board, "Player 1");
                if (check_victory(player2_board)) {
                    printf("Player 1 wins!\n");
                    break;
                }
                swap_turns(&current_turn);  // Switch to Player 2
            } else {
                printf("\n--- Player 2's Turn ---\n");
                // Show Player 2's board fully and Player 1's guessed positions
                print_board(player2_board, true);  // Top: Player 2's ships
                print_board(player1_guess_board, false);  // Bottom: Player 2's guesses for Player 1's ships

                player_attack(player1_board, player2_guess_board, "Player 2");
                if (check_victory(player1_board)) {
                    printf("Player 2 wins!\n");
                    break;
                }
                swap_turns(&current_turn);  // Switch to Player 1
            }
        }
    } else {  // Player vs Computer
        while (1) {
            printf("\n--- Player 1's Turn ---\n");
            print_board(player1_board, true);  // Top: Player 1's ships
            print_board(player2_guess_board, false);  // Bottom: Player 1's guesses for Computer's ships

            player_attack(player2_board, player1_guess_board, "Player 1");
            if (check_victory(player2_board)) {
                printf("Player 1 wins!\n");
                break;
            }

            printf("\n--- Computer's Turn ---\n");
            computer_attack(player1_board);  // Computer attacks Player 1
            if (check_victory(player1_board)) {
                printf("Computer wins!\n");
                break;
            }
        }
    }

    return 0;
}

void print_board(char board[BOARD_SIZE][BOARD_SIZE], bool reveal_ships) {
    printf("   A B C D E F G H I J\n");
    printf("  ---------------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%2d| ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (reveal_ships) {
                // Show ships and destroyed ships
                if (board[i][j] == '&') {
                    printf("& ");
                } else if (board[i][j] == '#') {
                    printf("# ");
                } else if (board[i][j] == '0') {
                    printf("0 ");
                } else {
                    printf(". ");
                }
            } else {
                // Show guesses (for Player 2 or Computer)
                if (board[i][j] == 'x') {
                    printf("x ");
                } else if (board[i][j] == '#') {
                    printf("# ");
                } else if (board[i][j] == '0') {
                    printf("0 ");
                } else {
                    printf(". ");
                }
            }
        }
        printf("\n");
    }
}

bool is_valid_move(int x, int y) {
    return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
}

bool place_ship(char board[BOARD_SIZE][BOARD_SIZE], int size, bool horizontal, int x, int y) {
    if (horizontal) {
        if (y + size > BOARD_SIZE) return false;
        for (int i = 0; i < size; i++) {
            if (board[x][y + i] != '.') return false;
        }
        for (int i = 0; i < size; i++) {
            board[x][y + i] = '&';  // Place ship parts on the board
        }
    } else {
        if (x + size > BOARD_SIZE) return false;
        for (int i = 0; i < size; i++) {
            if (board[x + i][y] != '.') return false;
        }
        for (int i = 0; i < size; i++) {
            board[x + i][y] = '&';  // Place ship parts on the board
        }
    }
    return true;
}

void initialize_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '.';  // Set all positions to water initially
        }
    }
}

bool place_ships(char board[BOARD_SIZE][BOARD_SIZE]) {
    int ship_sizes[] = SHIP_SIZES;
    int num_ships = sizeof(ship_sizes) / sizeof(ship_sizes[0]);

    for (int i = 0; i < num_ships; i++) {
        bool placed = false;
        while (!placed) {
            int x = rand() % BOARD_SIZE;
            int y = rand() % BOARD_SIZE;
            bool horizontal = rand() % 2;
            placed = place_ship(board, ship_sizes[i], horizontal, x, y);
        }
    }
    return true;
}

bool check_victory(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == '&') {  // If there are still parts of ships left
                return false;
            }
        }
    }
    return true;
}

bool process_attack(char board[BOARD_SIZE][BOARD_SIZE], int x, int y) {
    if (board[x][y] == '&') {  // If it's a ship part
        board[x][y] = '#';  // Mark the ship part as hit with '#'
        printf("IT'S A HIT!\n");
        update_board_for_destroyed_ship(board);
        return true;
    } else if (board[x][y] == '.') {  // If it's water
        board[x][y] = 'x';  // Mark as miss
        printf("Miss!\n");
        return false;
    }
    printf("Already attacked this spot.\n");  // If the spot has been already attacked
    return false;
}

void update_board_for_destroyed_ship(char board[BOARD_SIZE][BOARD_SIZE]) {
    // Check each ship and see if it is fully destroyed
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == '#') {
                // Check if this part is part of a destroyed ship (no '&' left in the ship)
                bool is_destroyed = true;
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        int nx = i + dx;
                        int ny = j + dy;
                        if (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE && board[nx][ny] == '&') {
                            is_destroyed = false;
                        }
                    }
                }
                if (is_destroyed) {
                    board[i][j] = '0';  // Mark it as destroyed ship part
                }
            }
        }
    }
}

void player_attack(char opponent_board[BOARD_SIZE][BOARD_SIZE], char guess_board[BOARD_SIZE][BOARD_SIZE], const char* player_name) {
    char move[5];  // Allow for up to 4 characters (e.g., A10)
    int x, y;
    while (1) {
        printf("%s, enter attack coordinates (e.g., A1, A10, etc.): ", player_name);
        scanf("%s", move);

        // Parse the input (handle cases like A10)
        char col_char = move[0];  // First character is the column letter (A-J)
        int row_num = atoi(&move[1]);  // Convert the rest of the string to the row number

        if (row_num < 1 || row_num > 10 || col_char < 'A' || col_char > 'J') {
            printf("Invalid coordinates. Try again.\n");
            continue;
        }

        x = row_num - 1;  // Convert row to 0-based index
        y = col_char - 'A';  // Convert column to 0-based index

        if (!is_valid_move(x, y)) {
            printf("Invalid coordinates. Try again.\n");
        } else {
            // If the position has already been attacked, prompt the user to try again
            if (guess_board[x][y] == 'x' || guess_board[x][y] == '#') {
                printf("Already attacked this position. Try again.\n");
                continue;
            }
            process_attack(opponent_board, x, y);
            guess_board[x][y] = 'x';  // Mark it as attacked on the guess board
            break;
        }
    }
}

void computer_attack(char player_board[BOARD_SIZE][BOARD_SIZE]) {
    int x, y;
    while (1) {
        x = rand() % BOARD_SIZE;
        y = rand() % BOARD_SIZE;

        if (player_board[x][y] == '.' || player_board[x][y] == '#') {
            break;
        }
    }

    printf("Computer attacks %c%d\n", ALPHABET[y], x + 1);
    process_attack(player_board, x, y);
}

void swap_turns(char* current_turn) {
    if (*current_turn == '1') {
        *current_turn = '2';
    } else {
        *current_turn = '1';
    }
}

void display_rules() {
    printf("Welcome to Battleship!\n\n");
    printf("Game Rules:\n");
    printf("1. Players take turns attacking each other's ships.\n");
    printf("2. Ships are placed randomly on a 10x10 grid.\n");
    printf("3. The first player to sink all the opponent's ships wins.\n\n");

    printf("Symbols Used on the Board:\n");
    printf("  '.' - Water (empty space)\n");
    printf("  '&' - Ship part\n");
    printf("  '#' - Hit ship part\n");
    printf("  '0' - Entire ship destroyed\n");
    printf("  'x' - Missed attack\n\n");

    printf("Your goal is to sink all the enemy ships before they sink yours.\n\n");
    printf("Good luck!\n\n");
}
