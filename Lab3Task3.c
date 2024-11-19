#include <stdio.h>      // Include standard I/O library for input-output functions
#include <stdbool.h>     // Include library for using boolean data types
#include <string.h>      // Include library for string manipulation functions

// Define constants
#define numofteams 5     // Maximum number of teams
#define pnsize 25        // Maximum player name size
#define tnsize 25        // Maximum team name size
#define squad_size 20    // Maximum number of players per team
#define size 20          // General size for other string fields

// Function prototypes
void display_menu();             // Display menu options
void enroll_club();              // Enroll a new club
void add_player();               // Add a player to a club
void search_update();            // Search and update a player's information
void display_club_statistics();  // Display statistics of all clubs
void handle_error();             // Handle errors

struct age_t {
    int day;         // Day of birth
    int month;       // Month of birth
    int year;        // Year of birth
    int age;         // Calculated age of the player
};

struct play_t {
    char pname[pnsize];      // Player's name
    int kit_number;          // Player's kit number
    char club[size];         // Club name
    struct age_t ageofp;     // Age structure of the player
    char position[size];     // Player's field position
};

struct team_t {
    char tname[tnsize];              // Team name
    struct play_t players[squad_size];  // Array to hold team players
    int activesize;                  // Number of active players in the team
};

struct team_t teams[numofteams];     // Array to store multiple teams
int num_teams = 0;                   // Counter for the number of enrolled teams

int main() {
    int choice;// Variable to store user's menu choice

    while (true) {// Infinite loop for continuous menu display
        display_menu();// Call function to display menu options
        scanf("%d", &choice); // Read user choice

        // Execute corresponding function based on user's choice
        switch (choice) {
            case 1:
                enroll_club();// Enroll a new club
                break;
            case 2:
                add_player();// Add a new player
                break;
            case 3:
                search_update();// Search and update a player
                break;
            case 4:
                display_club_statistics(); // Display club statistics
                break;
            case 5:
                handle_error();// Handle any errors
                break;
            default:
                printf("Choice Invalid. Terminating Program\n");// Invalid input, exit program
                return 0;// Exit the program
        }
    }
}

// Function to display the menu options
void display_menu() {
    printf("Menu:\n");
    printf("1. Enroll Club\n");
    printf("2. Add Player\n");
    printf("3. Search and Update Player\n");
    printf("4. Display Club Statistics\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

// Function to enroll a new club
void enroll_club() {
    if (num_teams >= numofteams) {// Check if max team limit reached
        printf("Maximum number of teams reached!\n");
        return;
    }
    printf("Enter team name: ");// Prompt for team name
    scanf("%s", teams[num_teams].tname);// Read and store team name
    teams[num_teams].activesize = 0;// Initialize active player count for team
    num_teams++;// Increment total team count
    printf("Team enrolled successfully!\n");
}

// Function to add a player to a specified team
void add_player() {
    char team_name[tnsize];// Temporary variable to store team name

    printf("Enter team name to add player: ");
    scanf("%s", team_name);// Read input for team name

    // Search for the specified team
    for (int i = 0; i < num_teams; i++) {
        if (strcmp(teams[i].tname, team_name) == 0) {// If team name matches
            if (teams[i].activesize >= squad_size) {// Check if team is full
                printf("Team is full!\n");
                return;
            }

            struct play_t *player = &teams[i].players[teams[i].activesize]; // Pointer to new player
            printf("Enter player name: ");
            scanf("%s", player->pname);         // Read and store player name
            printf("Enter kit number: ");
            scanf("%d", &player->kit_number);   // Read and store kit number
            printf("Enter club: ");
            scanf("%s", player->club);          // Read and store club name
            printf("Enter birth day: ");
            scanf("%d", &player->ageofp.day);   // Read and store birth day
            printf("Enter birth month: ");
            scanf("%d", &player->ageofp.month); // Read and store birth month
            printf("Enter birth year: ");
            scanf("%d", &player->ageofp.year);  // Read and store birth year
            printf("Enter position: ");
            scanf("%s", player->position);      // Read and store position

            player->ageofp.age = 2024 - player->ageofp.year;// Calculate approximate age

            teams[i].activesize++;// Increment player count for the team
            printf("Player added successfully!\n");
            return;
        }
    }
    printf("Team not found!\n");// Message if team not found
}

// Function to search and update a player's information
void search_update() {
    char player_name[pnsize];// Variable to hold player name

    printf("Enter player name to search/update: ");
    scanf("%s", player_name);// Read player name

    // Search for player across all teams
    for (int i = 0; i < num_teams; i++) {
        for (int j = 0; j < teams[i].activesize; j++) {
            if (strcmp(teams[i].players[j].pname, player_name) == 0) {// Check if name matches
                struct play_t *player = &teams[i].players[j];// Pointer to matched player

                // Display current player info
                printf("Player found in team %s\n", teams[i].tname);
                printf("Current player info:\n");
                printf("Name: %s\n", player->pname);
                printf("Kit Number: %d\n", player->kit_number);
                printf("Club: %s\n", player->club);
                printf("Age: %d\n", player->ageofp.age);
                printf("Position: %s\n", player->position);

                // Update player info
                printf("Enter new kit number: ");
                scanf("%d", &player->kit_number); // Update kit number
                printf("Enter new club: ");
                scanf("%s", player->club);        // Update club name
                printf("Enter new position: ");
                scanf("%s", player->position);    // Update position
                printf("Player updated successfully!\n");
                return;
            }
        }
    }
    printf("Player not found!\n");  // Message if player not found
}

// Function to display statistics for all clubs
void display_club_statistics() {
    printf("Club Statistics:\n");

    // Loop through all enrolled teams
    for (int i = 0; i < num_teams; i++) {
        printf("Team: %s\n", teams[i].tname);// Display team name
        printf("Number of players: %d\n", teams[i].activesize);// Display active players

        // Display information for each player in the team
        for (int j = 0; j < teams[i].activesize; j++) {
            struct play_t *player = &teams[i].players[j];// Pointer to player
            printf("\tPlayer: %s, Kit Number: %d, Club: %s, Age: %d, Position: %s\n",
                   player->pname, player->kit_number, player->club, player->ageofp.age, player->position);
        }
    }
}

// Function to handle errors and exit program
void handle_error() {
    printf("An error occurred.\n");  // Display error message
}