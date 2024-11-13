#include<stdio.h>
#include<string.h>

#define numofteams 5
#define pnsize 25
#define tnsize 25
#define squad_size 20
#define size 20

//Init
void display_menu();


struct age_t {
    int day;
    int month;
    int year;
    int age;
};

struct play_t {
    char pname[pnsize];
    int kit_number;
    char club[size];
    struct age_t ageofp;
    char position[size];
};

struct team_t {
    char tname[tnsize];
    struct play_t players[squad_size];
    int activesize;
};

int main() {
    display_menu();

}

void display_menu() {
    int choice;

    printf("Menu:\n");
    printf("1. Enroll Club 1\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice){
        case 1:
         // enroll_club();
          break;
        case 2:
          //  add_player();
            break;
        case 3:
          //  search_update();
            break;
        case 4:
         //   display_club_statistics();
            break;
        case 5:
          //  handle_error();
            break;
        default:
            printf("Choice Invalid. Terminating Program\n");
            break;

    }


}

void enroll_club() {

}

void add_player() {

}

void search_update() {

}

void display_club_statistics() {

}

void handle_error() {

}