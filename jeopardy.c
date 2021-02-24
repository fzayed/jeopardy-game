/*
 * Tutorial 4 Jeopardy Project for SOFE 3950U / CSCI 3020U: Operating Systems
 *
 * Copyright (C) 2015, <GROUP MEMBERS>
 * All rights reserved.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "questions.h"
#include "players.h"
#include "jeopardy.h"

// Put macros or constants here using #define
#define BUFFER_LEN 256
#define NUM_PLAYERS 4

// Put global environment variables here

// Processes the answer from the user containing what is or who is and tokenizes it to retrieve the answer.
void tokenize(char *input, char **tokens);

// Displays the game results for each player, their name and final score, ranked from first to last place
void show_results(player *players, int num_players) {
	printf("Game Over! Here are the results: \n");
	int max = 0;
	int index = 0;
	for(int i = 0; i < num_players; i++)
	{
	    for(int j = 0; j < num_players; j++)
		{
		    if(players[j].score > max)
		    {
			max = players[j].score;
			index = j;
		    }
		}
		players[index].score = 0;
		printf("Place %d: %s, Score: %d", (i+1), players[index].name, max); 
		printf((i == 0 ? ", Winner!\n" : "\n"));
		max = 0;
	}
}


int main()
{
    // An array of 4 players, may need to be a pointer if you want it set dynamically
    player players[NUM_PLAYERS];
    
    
    // Input buffer and and commands
    char buffer[BUFFER_LEN] = { 0 };

    // Display the game introduction and initialize the questions
    initialize_game();

    // Prompt for players names
    // initialize each of the players in the array
    for(int i = 0; i < 4; i++){
    	printf("Enter your name: ");
    	scanf("%s", players[i].name);
    	players[i].score = 0;
    }
    
    int counter = 0;

    // Perform an infinite loop getting command input from users until game ends
    while (fgets(buffer, BUFFER_LEN, stdin) != NULL)
    {
    	char player_name[MAX_LEN];
    	char player_category[MAX_LEN];
    	int player_value;
        // Call functions from the questions and players source files
        printf("Please enter the name of the player: ");
        scanf("%s", player_name);
        while (!player_exists(players, NUM_PLAYERS, player_name)) {
		printf("Invalid name entered. Please try again: ");
		scanf("%s", player_name);
        }
    	display_categories();
        printf("\nPlease choose a category and dollar amount question: ");
        scanf("%s %d", player_category, &player_value);
        while(already_answered(player_category, player_value)) {
		printf("That question has already been answered. Please choose another question: ");
		scanf("%s %d", player_category, &player_value);
        }
        display_question(player_category, player_value);
        
    	char answer[MAX_LEN];
	printf("Please enter the answer: ");
	fgets (answer, MAX_LEN, stdin);
	scanf("%[^\n]%*c", answer);
	if(valid_answer(player_category, player_value, answer)){
		update_score(players, NUM_PLAYERS, player_name, player_value);
	}
	counter++;
	if (counter == 12) {
		show_results(players, NUM_PLAYERS);
		break; // stop the game after its done
	}
        printf("Press Enter to continue...\n");
        // Execute the game until all questions are answered

        // Display the final results and exit
    }
    return EXIT_SUCCESS;
}
