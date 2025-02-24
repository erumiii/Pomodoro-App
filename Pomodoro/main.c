#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#define pomodoro 1500
#define shortbreak 300

void menu();


int main(){
    
    int choice;
    do{
        system("cls");
        menu();
        printf("Choice : "); scanf("%d", &choice);
        switch (choice)
        {
        case 1:{
            system("cls");
            int seconds = pomodoro;
            while (seconds >= 0)
            {
                int min = (seconds % 3600) / 60;
                int sec = seconds % 60;
                printf("\r\e[1m%02d:%02d\e[m", min, sec);
                
                fflush(stdout);

                clock_t stop = clock() + CLOCKS_PER_SEC;
                while (clock() < stop) { }
                
                seconds--;
            }
            printf("\r\e[1mTime's up!\e[m\n");
            printf("\nPress enter to continue...\n");
            getch();
            break;
        }
        case 2:{
            system("cls");
            int seconds = shortbreak;
            while (seconds >= 0)
            {
                int min = (seconds % 3600) / 60;
                int sec = seconds % 60;
                printf("\r\e[1m%02d:%02d\e[m", min, sec);
                
                fflush(stdout);

                clock_t stop = clock() + CLOCKS_PER_SEC;
                while (clock() < stop) { }

                seconds--;
            }
            printf("\r\e[1mTime's up!\e[m\n");
            printf("\nPress enter to continue...\n");
            getch();
            break;
        }            
        case 3:{
            system("cls");
            int minutes;
            do{
                system("cls");
                printf("Enter the number of minutes for the long break[15-30 min]: ");
                scanf("%d", &minutes);
                if(minutes < 15 || minutes > 30){
                    printf("Invalid input. Please enter a number between 15 and 30.\n");
                    printf("\nPress enter to continue...\n");
                    getch();
                }
            }while (minutes < 15 || minutes > 30);
            system("cls");
            int seconds = minutes * 60;
            while (seconds >= 0)
            {
                int min = (seconds % 3600) / 60;
                int sec = seconds % 60;
                printf("\r\e[1m%02d:%02d\e[m", min, sec);
                
                fflush(stdout);

                clock_t stop = clock() + CLOCKS_PER_SEC;
                while (clock() < stop) { }

                seconds--;
            }
            printf("\r\e[1mTime's up!\e[m\n");
            printf("\nPress enter to continue...\n");
            getch();
            break;
        }        
        case 4:
            
            break;
        case 5:
            
            break;
        case 6:{
            return 0;
            getch();
            break;
            }   
        default:
            break;
        }
    }while(choice != 6);

    return 0;
}

void menu(){
    printf(" ================================\n");
    printf(" ||       POMODORO TIMER       ||\n");
    printf("==================================\n");
    printf("|| 1. Pomodoro Timer [25 min]   ||\n");
    printf("|| 2. Short Break [5 min]       ||\n");
    printf("|| 3. Long Break [15-30 min]    ||\n");
    printf("|| 4. Add Task                  ||\n");
    printf("|| 5. Clear Task                ||\n");
    printf("|| 6. Exit                      ||\n");
    printf("==================================\n");
}