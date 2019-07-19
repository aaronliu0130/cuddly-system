/*
 * RichmanMA.cpp
 *
 *  Created on: Apr 7, 2019
 *      Author: Aaron
 */
#include<bits/stdc++.h>
using namespace std;
typedef struct player {
	int points = -1, money = 0, troops = 0, step = 0;
	char name[100], current[20] = "Camp";
} playe;
playe player[4];
int dice() {
	srand(time(NULL));
	return rand() % 6 + 1;
}
void MACard() {
	//25 cards
}
void JCard() {

}
void camp(int pNo) {
	player[pNo].money += 3000, player[pNo].troops += 2;
}
void event(char event[], int pNo) {
	char e = event[0];
	int die;
	switch (e) {
	case 'C':
		printf("Actually, you didn't went over the camp... You went straight on it!\n");
		printf("Great job on that luck! You don't have any rewards though...\n");
		break;
	case 'M':

		break;
	case 'R':{
		printf("Time to recruit some good troops!\n Automatically rolling the die.\n");
		die=dice()*2;
		printf("Congratulations! You enlisted %d troops!\n",die);
	}
		break;
	case 'B':

		break;
	case 'F':

		break;
	case 'A':{
		printf("You did some agriculture with your fellow citizens. You earned a lot of profit!\n Automatically rolling the die.\n");
		die=dice()*2000;
		printf("Congratulations! You earned %d money! That's a lot!\n",die);
		player[pNo].money+=die;
		break;
	}
	case 'S':

		break;
	case 'T':

		break;

	}
}
void controls() {
	printf("Press stands for input and press enter here.\n");
	printf("Press d to roll the die!\n");
	printf("Press m to use a Martial Card!\n");
	printf(
			"If you want to use a card, press the number you see under the card you want!\n");
	printf(
			"During Super PK, you enter the number of the player you want to PK with, and card selection's the same except the number's under the Card Power!\n");
	printf(
			"The screen will also display how many Battle Power you have. Upon prompted, enter the number of battle power you wish to exert!");
	printf("That's it! ");
}
int main() {
	int players,die;
	string places[30] = { "Camp", "Martial Arts", "Recruit", "Martial Arts",
			"Battlefield", "Front-line Message", "Agriculture", "Super PK",
			"Recruit", "Front-line Message", "Martial Arts", "Battlefield",
			"Martial Arts", "Agriculture", "Training", "Agriculture", "Recruit",
			"Martial Arts", "Battlefield", "Front-line Order", "Martial Arts",
			"Super PK", "Martial Arts", "Recruit", "Battlefield", "Agriculture",
			"Martial Arts", "Front-line Message" };
	printf(
			"Welcome to Richman/Uncle Wang™ Sun Tzu's Martial Arts® Board Game!\n How many players are there?Note that no one can join mid-game and that the maximum number of players is 4!");
	scanf("%d", &players);
	for (int i = 0; i < players; i++) {
		printf("Please input player %d's name!", i + 1);
		scanf("%s", player[i].name);
		cout<<player[i].name<<endl;
		player[i].points++;
	}
	printf("Do you want to know the controls?(y/n): ");
	char yn;
	do{
		scanf("%c", &yn);
	}while(yn!='n'&&yn!='y');
	if (yn == 'y')
		controls();
	printf("If you wish to look at the controls, press c!\n");
	printf("Now...\n");
	printf("GAME START!\n");
	printf("(press any key and then enter to continue)");
	scanf(" ");
	int pNo = -1;
	do {
		if (++pNo > players)
			pNo = 0;
		cout << "\033[2J\033[1;1H";
		printf("%s Points: %d Money: %d Battle Power: %d Current Tile: %s\n",
				player[pNo].name,player[pNo].points, player[pNo].money, player[pNo].troops,
				player[pNo].current);
		invalid: printf("What to do... What to do? ");
		scanf("%c", &yn);
		switch (yn) {
		case 'c':
			controls();
			break;
		case 'm':

			break;
		case 'd':
			die=dice();
			printf("You rolled a %d!\n",die);
			player[pNo].step+=die;
			if(player[pNo].step>=30){
				player[pNo].step-=30;
				printf("You went over the camp!Take some rest!\n");
				printf("You got 3000 money and 2 more troops!\n");
				camp(pNo);
			}
			strcpy(player[pNo].current,places[player[pNo].step].c_str());
			event(player[pNo].current,pNo);
			printf("Anyways, now for the next player!");
			break;
		default:
			printf("Please enter a valid control!\n");
			goto invalid;
		}
		printf("Press any key to continue!");
		scanf(" ");
	} while (player[pNo].points < 20);
	printf("So, the winner is...\n");
	system("Drumrool.mp3");
	printf("%s!\n", player[pNo].name);
	printf("Congratulations!\n");
	printf("Wanna play again?(y/n): ");
	return 0;
}

