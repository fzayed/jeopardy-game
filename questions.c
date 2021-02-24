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
#include "questions.h"

// Initializes the array of questions for the game
void initialize_game(void)
{
    // initialize each question struct and assign it to the questions array
    strcpy(questions[0].category, "programming");
    strcpy(questions[0].question, "A programming language that starts with c and ends with ++");
    strcpy(questions[0].answer, "what is c++");
    questions[0].value = 200;
    questions[0].answered = false;
    
    strcpy(questions[1].category, "programming");
    strcpy(questions[1].question, "A programming language that starts with py");
    strcpy(questions[1].answer, "what is python");
    questions[1].value = 500;
    questions[1].answered = false;
    
    strcpy(questions[2].category, "programming");
    strcpy(questions[2].question, "The best programming language for web");
    strcpy(questions[2].answer, "what is javascript");
    questions[2].value= 1000;
    questions[2].answered= false;
    
    strcpy(questions[3].category , "programming");
    strcpy(questions[3].question , "A programming language that uses system.out.println()");
    strcpy(questions[3].answer , "what is java");
    questions[3].value = 2000;
    questions[3].answered = false;
    
    strcpy(questions[4].category , "algorithms");
    strcpy(questions[4].question , "The running time of a linear function");
    strcpy(questions[4].answer , "what is n");
    questions[4].value = 200;
    questions[4].answered = false;
    
    strcpy(questions[5].category , "algorithms");
    strcpy(questions[5].question , "The greek letter for worst case running time");
    strcpy(questions[5].answer , "what is bigo");
    questions[5].value = 500;
    questions[5].answered = false;
    
    strcpy(questions[6].category , "algorithms");
    strcpy(questions[6].question , "The best sorting algorithm");
    strcpy(questions[6].answer , "what is quicksort");
    questions[6].value = 1000;
    questions[6].answered = false;
    
    strcpy(questions[7].category , "algorithms");
    strcpy(questions[7].question , "The average running time of quicksort");
    strcpy(questions[7].answer , "what is nlogn");
    questions[7].value = 2000;
    questions[7].answered = false;
    
    strcpy(questions[8].category , "databases");
    strcpy(questions[8].question , "The language used to query databases");
    strcpy(questions[8].answer , "what is sql");
    questions[8].value = 200;
    questions[8].answered = false;
    
    strcpy(questions[9].category , "databases");
    strcpy(questions[9].question , "The sql statement used to update records in a table");
    strcpy(questions[9].answer , "what is update");
    questions[9].value = 500;
    questions[9].answered = false;
    
    strcpy(questions[10].category , "databases");
    strcpy(questions[10].question , "The programming language used to connect a web form to a database");
    strcpy(questions[10].answer , "what is php");
    questions[10].value = 1000;
    questions[10].answered = false;
    
    strcpy(questions[11].category , "databases");
    strcpy(questions[11].question , "The diagram used to design databases");
    strcpy(questions[11].answer , "what is er");
    questions[11].value = 2000;
    questions[11].answered = false;
    
}

// Displays each of the remaining categories and question dollar values that have not been answered
void display_categories(void)
{
    // print categories and dollar values for each unanswered question in questions array
    int count = 0;
    printf("programming | algorithms | databases |\n");
    for(int i = 0; i < 4; i++){
    	for (int j = 0; j < 3; j++) {
	    	int index = i + count;
	    	if(questions[index].answered){
	    		printf("x|");
	    	}else{
	    		printf("%d|", questions[index].value);
	    	}
	    	count += 4;
	    	count %= 12;
    	}
    	printf("\n");
    	/*if(i%4 == 3){
    		printf("\n");
    	}*/
    }
}

// Displays the question for the category and dollar value
void display_question(char *category, int value)
{
	printf("Question: ");
	// lookup the question and see if it's already been marked as answered
	for(int i = 0; i < NUM_QUESTIONS; ++i)
	{
	    if(!strcmp(questions[i].category, category) && questions[i].value == value)
	    {
		printf("%s\n", questions[i].question);
	    }
	}
	
}

// Returns true if the answer is correct for the question for that category and dollar value
bool valid_answer(char *category, int value, char *answer)
{
    // Look into string comparison functions
    for(int i = 0; i < NUM_QUESTIONS; ++i)
	{
	    if(!strcmp(questions[i].category, category) && questions[i].value == value)
	    {
	    	if (!strcmp(questions[i].answer, answer)) {
			printf("Correct! Player awarded with $%d\n", questions[i].value);
	    		questions[i].answered = true;
			return true;
	    	} else {
	    		printf("Incorrect! The correct answer is %s\n", questions[i].answer);
	    		questions[i].answered = true;
	    		return false;
	    	}
	    }
	}
    return false;
}

// Returns true if the question has already been answered
bool already_answered(char *category, int value)
{
    // lookup the question and see if it's already been marked as answered
    for(int i = 0; i < NUM_QUESTIONS; ++i)
	{
	    if(!strcmp(questions[i].category, category) && questions[i].value == value && questions[i].answered)
	    {
		return true;
	    }
	}
    return false;
}
