#include <stdio.h>
#define SEATS 24

//creating the structure for seat
struct seat {
    int seat_id;
    int assignment;
    char last_name[50];
    char first_name[50];
};

//making arrays
struct seat outbound[SEATS]; 
struct seat inbound[SEATS];

//clear leftover characters
void clear_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//giving each seat a number
void initailize(void) {
    for (int i = 0; i < SEATS; i++) {
        outbound[i].seat_id = i + 1;
        outbound[i].assignment = 0;

        inbound[i].seat_id = i + 1;
        inbound[i].assignment = 0;
    }
}

//showing empty seats
void empty_seats(struct seat flight[]) {
    int count = 0; 
    for (int i = 0; i < SEATS; i++) 
        if (!flight[i].assignment) 
            count++; 
    printf("Number of empty seats: %d\n", count);
}

//showing list of empty seat
void empty_seats_listed(struct seat flight[]) {
    printf("empty seats: ");
    for (int i = 0; i < SEATS; i++)
        if (!flight[i].assignment)
            printf("%d ", flight[i].seat_id); 
    printf("\n");
}

//assigning a passenger to a seat
void add_passenger(struct seat flight[]) {
    char first_name[50];
    char last_name[50];
    int seat;
    printf("Please enter a seat number you would like, or enter 25 to cancel: ");
    if (scanf("%d", &seat) != 1) {
        printf("Not a number.\n");
        clear_buffer();
        return;
    }

    if (seat == 25) {
        clear_buffer();
        return;
    }

    if (seat < 1 || seat > 24) { 
        printf("Invalid seat.\n");
        clear_buffer();
        return;
    }

    if (flight[seat - 1].assignment == 1) {
        printf("That seat is taken.\n");
        return;
    }

    printf("Enter your first name: ");
    scanf(" %49[^\n]", flight[seat - 1].first_name);
    if (getchar() != '\n') {
        printf("name is too long. Shorten it down to below 50 characters");
        clear_buffer();
    }

    if (flight[seat - 1].first_name[0] == '-' && 
        flight[seat - 1].first_name[1] == '1' && 
        flight[seat - 1].first_name[2] == '\0') { 
            printf("Entry aborted.\n"); 
            return;
    }

    printf("Enter your last name: ");
    scanf(" %49[^\n]", flight[seat - 1].last_name);
    if (getchar() != '\n') {
        printf("name is too long. Shorten it down to below 50 characters");
        clear_buffer();
    }

    if (flight[seat - 1].last_name[0] == '-' && 
        flight[seat - 1].last_name[1] == '1' && 
        flight[seat - 1].last_name[2] == '\0') { 
            printf("Entry aborted.\n"); 
            return;
    }

    flight[seat - 1].assignment = 1;
    printf("the seat has been assigned to you!\n");
    
}

//removing a passenger from the list
void remove_passenger(struct seat flight[]) {
    int seat;
    printf("Please enter a seat number you would like, or enter 25 to cancel: ");
    if (scanf("%d", &seat) != 1){
        printf("Invalid selection.\n"); 
        clear_buffer(); 
        return;
    }

    if (seat == 25) {
        clear_buffer();
        return;
    }

    if (seat < 1 || seat > 24) {
        printf("Invalid seat.\n");
        clear_buffer();
        return;
    }

    if (!flight[seat - 1].assignment) {
        printf("That seat is empty");
        return;
    }

    flight[seat - 1].assignment = 0; 
    flight[seat - 1].first_name[0] = '\0'; 
    flight[seat - 1].last_name[0] = '\0'; 
    printf("Seat assignment deleted.\n"); 
}

//alphabetical list of names
void names_listed(struct seat flight[]) {
    int i, j, y, temp;
    int order[SEATS];
    for (i = 0; i < SEATS; i++) 
        order[i] = i;
    for (i = 0; i < SEATS - 1; i++) {
        for (j = i + 1; j < SEATS; j++) {
            if (flight[order[i]].last_name[0] > flight[order[j]].last_name[0]) {
                temp = order[i];
                order[i] = order[j];
                order[j] = temp;
            }   
        }
    }

    printf("Alphabetical list of names:\n");
    for (i = 0; i < SEATS; i++) {
        int y = order[i];
        if (flight[y].assignment)
            printf("%s, %s - Seat %d\n",
                flight[y].last_name,
                flight[y].first_name,
                flight[y].seat_id);
            }
}   

//making outbound menu
void O_menu(void) {
    char choice;

    while (1) {
        printf(" A) Show number of seats that are empty \n");
        printf(" B) Show list of the seats that are empty \n");
        printf(" C) Show list of seats in alphabetical order \n");
        printf(" D) Assign a passenger to a seat \n");
        printf(" E) Remove an assigned seat \n");
        printf(" F) Return to the main menu \n");

        printf("Please select an option: ");
        if (scanf(" %c", &choice) != 1) 
            return;
        

        switch(choice) {
            case 'a':
                empty_seats(outbound);
                break;
            
            case 'b':
                empty_seats_listed(outbound);
                break;

            case 'c':
                names_listed(outbound);
                break;
            
            case 'd':
                add_passenger(outbound);
                break;

            case 'e':
                remove_passenger(outbound);
                break;

            case 'f':
                return;

            default: 
                printf("Error: you can only choose a-f.");
                break;
            
        }
    }
}

//making inbound menu
void I_menu(void) {
    char choice;

    while (1) {
        printf(" A) Show number of seats that are empty \n");
        printf(" B) Show list of the seats that are empty \n");
        printf(" C) Show list of seats in alphabetical order \n");
        printf(" D) Assign a passenger to a seat \n");
        printf(" E) Remove an assigned seat \n");
        printf(" F) Return to the main menu \n");

        printf("Please select an option: ");
        if (scanf(" %c", &choice) != 1) 
            return;
        

        switch(choice) {
            case 'a':
                empty_seats(inbound);
                break;

            case 'b':
                empty_seats_listed(inbound);
                break;

            case 'c':
                names_listed(inbound);
                break;

            case 'd':
                add_passenger(inbound);
                break;

            case 'e':
                remove_passenger(inbound);
                break;

            case 'f':
                return;

            default: 
                printf("Error: you can only choose a-f.");
                break;
            
        }
    }
}

//making the first menu
void first_menu(void) {
    char choice;

    while (1) {

        printf("First-Level Menu: \n");
        printf(" A) Outbound Flight \n");
        printf(" B) Inbound Flight \n");
        printf(" C) Quit \n");

        printf("Please select an option: ");
        if (scanf(" %c", &choice) != 1) {
            return;
        }

        switch(choice) {
            case 'a':
                O_menu();
                break;

            case 'b':
                I_menu();
                break;

            case 'c':
                printf("Quiting!\n");
                return;

            default: {
                printf("Error: you can only choose a, b, or c.\n");
                break;
            }
        }
    }
}

//running the program
int main() {
    initailize();
    first_menu();
    return 0;
}
