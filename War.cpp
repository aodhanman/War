// War.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <time.h>

int main()
{

	int numOfPlayers;
	int players[10][13];
	int cards[52];
	int finished = 0;

	//char Card[] = { 2,3,4,5,6,7,8,9,10,'J','Q','K','A' };
	//char Suit[] = { 'D','H','C','S' };

	int Player1[13];
	

	//cards[(rand() % 52)];
	//creates deck
	for (int i = 1; i < 53; i++) {
		cards[i] = i + 1;
		//printf("%i \n", cards[i]);
	}

	srand(time(NULL));
	//pseudorandom seed for random card

	//welome message
	printf("Welcome to War \n");
	printf("How many players?\n");

	//get number of players
	scanf_s("%i", &numOfPlayers);
	
	//gives each player 13 random cards
	for (int j = 0; j < numOfPlayers; j++) {
		for (int i = 0; i < 13; i++) {
			players[j][i] = cards[rand() % 52];
		
		}
	}

	int playerPoints[10] = { 0 };
	//creates array element for each players points

	//while loop that lets game run until finished
	while (finished < 13)
	{
		int score[10];
		int win[10];
		int winner = 0;

		//iterates through for loop for each players go
		for (int j = 0; j < numOfPlayers; j++) {
			int played;
			char card;
			int select;

			//there's some mistake i'm making
			//here with the input from cmd line

			
			printf("Player %i press any key to continue ('x' to exit) \n", j + 1);

			if (getchar() == 'x') {
				break;
			}
			else {
				card = getchar();
			}


			for (int i = 1; i < 14; i++) {


				printf("Card %i: ", i);
				if (players[j][i] < 54) {

					switch ((players[j][i]) % 13) {
					case 0:
						printf("K \n");
						break;
					case 1:
						printf("A \n");
						break;
					case 11:
						printf("J \n");
						break;
					case 12:
						printf("Q \n");
						break;
					case 13:
						printf("K \n");
						break;

					default:
						printf("%i \n", players[j][i] % 13);

					}
				}
				else {
					printf("USED \n");
				}

			}
			printf("Enter number of card you would like to play?\n");
			scanf("%i", &select);

			// select card from cmd line
			if (players[j][select] % 13 > 1) {
				printf("Player %i played %i points \n", j + 1, players[j][select] % 13);

				score[j]=(players[j][select] % 13);
				win[j] = players[j][select] % 13;
				//displays how many points the card the player is choosing to play is worth
			}
			else {
				printf("Player %i played 14 points \n", j);
				score[j] = 14;
				win[j] = 14;
				//if player plays an ace this gives 14 points
			}
			players[j][select] = 55;



		}
		int topScore = 0;
		int secScore = 0;
		int sumPoints = 0;

		for (int l = 0; l < numOfPlayers; l++) {
			printf("Player %i   ", l + 1);
			printf("%i \n", score[l]);

			sumPoints = sumPoints + score[l];
			//running total of sum points in round

			if (score[l] > secScore && score[l] < topScore) {
				secScore = score[l];
			}
			if (score[l] > topScore) {
				topScore = score[l];
				winner = l + 1 ;
			}
			//if a score matches the current top score the second highest score will be the winner
			else if (score[l] == topScore) {
				topScore = secScore;
				winner = l + 1;

			}
			
		
		}
		printf("\n");
		printf("Winner = Player %i with %i\n", winner, topScore);
		printf("They get %i points\n", sumPoints);
		playerPoints[(winner -1)] = sumPoints + playerPoints[(winner - 1)];
		printf("They have %i points in total\n", playerPoints[(winner - 1)]);
		printf("\n");
		
		winner = 0;
		//increments until 13 goes have passed
		finished++;
	}

	

	

   // return 0;
}

