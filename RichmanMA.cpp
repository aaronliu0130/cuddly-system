/*
 * RichmanMA.cpp
 * C++11+ support is needed.
 *  Created on: Apr 7, 2019
 *      Author: Aaron
 */
#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "libs/utils.h"
//#define DEBUG
//#define RELEASE
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
using namespace std;
typedef struct card {
	string title, desc;int id(-1);
	card(string a, string b, int c) {
		title = a, desc = b, id = c;
	}
	;
} deck;
/**
 * @struct playe
 * @brief PLayer Information
 *
 */
struct playe {
	int points = -1, money = 0, troops = 0, step = 0;
	vector<deck> mCards, wCards;
	char name[100], current[20] = "Camp";
} player[4];
/**
 * @class gb
 * @brief Global Variables
 *
 */
class gb {
public:
	static string places[30];
	static int players;
	static vector<deck> wDeck, mDeck, bDeck;
};
string gb::places[30] = { "Camp", "Martial Arts", "Recruit", "Martial Arts",
		"Battlefield", "Front-line Message", "Agriculture", "Super PK",
		"Recruit", "Front-line Message", "Martial Arts", "Battlefield",
		"Martial Arts", "Agriculture", "Training", "Agriculture", "Recruit",
		"Martial Arts", "Battlefield", "Front-line Order", "Martial Arts",
		"Super PK", "Martial Arts", "Recruit", "Battlefield", "Agriculture",
		"Martial Arts", "Front-line Message" };
int gb::players;
//Repeating is due to actual repeating cards in the original boxed set
vector<deck> gb::mDeck = {
	{	"Burn-Siegeth(6)", "Act accordying to circumstances(Attack any battlefield but with two additional required troops)", 1},
	{	"Burn-Siegeth(6)", "Act accordying to circumstances(Attack any battlefield but with two additional required troops)", 1},
	{	"Contention(4)", "Tyme dost naught wait(Recruit twice)", 2},
	{	"Espionageth(6)", "Ther ys nobodie closer to the armie than a spie(Super PK against another player with two additional card points for you)", 3},
	{	"Espionageth(6)", "Ther ys nobodie closer to the armie than a spie(Super PK against another player with two additional card points for you)", 3}
	{	"Formation(3)", "Prepareth to protect thyself and wyn(Recruit twice)", 4},
	{	"Formation(3)", "Prepareth to protect thyself and wyn(Recruit twice)", 4},
	{	"Marchyng(2)", "Ten feet by forceth(Move forward two, four or six squares and execute the square's event)", 5},
	{	"Marchyng(2)", "Ten feet by forceth(Move forward two, four or six squares and execute the square's event)", 5},
	{	"Movement(2)", "Surprise attacketh and defend(Move forward one, three or five squares and execute the square's event)", 6},
	{	"Movement(2)", "Surprise attacketh and defend(Move forward one, three or five squares and execute the square's event)", 6},
	{	"Speed(4)", "Speed ys keie, naught combat(Attack any battlefield but with two additional required troops)", 7},
	{	"Strategie(5)", "The man who knows the enemy as wel as himself wyns(Take four cards and keep one of them)", 8},
	{	"Strategie(5)", "The man who knows the enemy as wel as himself wyns(Take four cards and keep one of them)", 8},
	{	"Strategie(5)", "The man who knows the enemy as wel as himself wyns(Take four cards and keep one of them)", 8},
	{	"Strategie(5)", "The man who knows the enemy as wel as himself wyns(Take four cards and keep one of them)", 8},
	{	"Strength and Weaknesse(4)", "Attacketh weaknesses and retreat from strengths(You and the player with the least points gain three)", 9},
	{	"Strength and Weaknesse(4)", "Attacketh weaknesses and retreat from strengths(You and the player with the least points gain three)", 9},
	{	"Tacticks(2)", "War is craftie(Agriculture Once)", 10},
	{	"Terrayn(3)", "The man o' terrayn ys aided(Move forward one, two or three squares and execute the square's event)", 11},
	{	"Terrayn(3)", "The man o' terrayn ys aided(Move forward one, two or three squares and execute the square's event)", 11},
	{	"Terrayn(3)", "The man o' terrayn ys aided(Move forward one, two or three squares and execute the square's event)", 11},
},
gb::wDeck = {
	{	"Citie Full o' Soldiers", "All players receive two troops. Then, return and shuffle all the battle cards.", 1},
	{	"Emperores Reward", "Receive 2000 yuan.", 2},
	{	"Recruitment Driveth", "All players roll dice. The highest one(s) will receive three troops.", 3},
	{	"Reinforcements Arriveth", "Receive 5 troops.", 4},
	{	"Supplie Cut", "You and another player roll dice. The lower one(s) will lose 2000 yuan.", 5},
	{	"Victory", "Receive 3 troops.", 6}};
int pNo = -1;
/**
 * @fn int dice()
 * @brief Dice Roll
 *
 * @return Random number from 1~6
 */
int dice() {
	srand(time(NULL));
	return rand() % 6 + 1;
}
/**
 * @fn void MACard(bool, int)
 * @brief Martial Art Cards
 *
 * @param pNo No. of player
 * @param get Whether or not the player is drawing a card from the deck
 */
void MACard(int pNo, bool get = 0) {
	if (get) {
		int ran(rand() % gb::mDeck.size());
		cout << gb::mDeck[ran].title << "!\n";
		player[pNo].mCards.push_back(gb::mDeck[ran]);
		gb::mDeck.erase(gb::mDeck.begin() + ran);
	} else {
		if (!player[pNo].mCards.size())
			cout
					<< "You have not studied Sun Tzu's Martial Arts yet, you anti-book!"
					<< '\n';
		else {
			//@TODO: Add actual functionality after martial art cards.
			cout << "Martial Cards you have:\n";
			for (auto a : player[pNo].mCards)
				cout << '\t' << a.title << "\tID:" << a.id << '\n';
			cout
					<< "Input ID of the card to view more info, 'x' followed by the ID of the card to execute the card's effects, or 'q' to exit: ";
			string menu;
			cin >> menu;
			if (menu[0] == 'q')
				return;
			if (menu[0] == 'x')
				if (menu.length() == 1)
					switch (menu[1]) {
					case '1':
						battle(pNo, 1);
					}
		}
	}
}
/**
 * @fn void WCard(bool, int)
 * @brief Wildcards
 * Not functional yet.
 * @param pNo No. of player
 * @param get Whether or not the player is drawing a card from the deck
 */
void WCard(int pNo, bool get = 0) {
//@TODO: Add actual functionality after wildcards
}
/**
 * @fn void battle(bool, int, int)
 * @brief Battlefields
 * Not functional yet
 * @param pNo No. of player
 * @param bonus Whether or not there is a bonus from the martial card
 */
void battle(int pNo, bool bonus = 0);
/**
 * @fn void camp(int)
 * @brief Handles camping
 *
 * @param pNo No. of player
 */
void camp(int pNo) {
	player[pNo].money += 3000, player[pNo].troops += 2;
}
/**
 * @fn void event(char[], int)
 * @brief Handles board events
 *
 * @param event String of event name
 * @param pNo No. of player
 */
void event(char event[], int pNo) {
	char e = event[0];
	int die;
	switch (e) {
	case 'C':
		cout
				<< "Actually, you didn't went over the camp... You went straight on it!\n";
		cout
				<< "Great job on that luck! You don't have any rewards though...\n";
		break;
	case 'M':
		cout
				<< "You continue to learn your copy of Sun Tzu's Martial Arts! You learned something new!\n You got a Martial Art Card!\n Its....\n \t\t\tcalled...... ";
		MACard(pNo, 1);
		break;
	case 'R': {
		cout
				<< "Time to recruit some good troops!\n Automatically rolling the die.\n";
		die = dice() * 2;
		cout << "Congratulations! You enlisted " << die << " troops!\n";
	}
		break;
	case 'B':
		cout << "You decide to try and battle!\n";
		printf("Choose a battlefield:");
		//@TODO: Add battlefields
		break;
	case 'F':
		cout
				<< "The frontline gave some help!\n You got a Wildcard!\n Its....\n \t\t\tcalled...... ";
		WCard(pNo, 1);
		break;
	case 'A': {
		printf(
				"You did some agriculture with your fellow citizens. You earned a lot of profit!\n Automatically rolling the die.\n");
		die = dice() * 2000;
		printf("Congratulations! You earned %d money! That's a lot!\n", die);
		player[pNo].money += die;
		break;
	}
	case 'S':
		//TODO: Add super dramatic SUPER PK TTS audio
		printf("ＣＨＯＯＳＥ　ＹＯＵＲ　ＥＮＥＭＹ！");
		for (int i(1); i <= pNo; i++) {
			printf("%d: %s", i, player[i - 1].name);
		}
		break;
	case 'T':

		break;
	}
}
/**
 * @fn void controls()
 * @brief Help for controls
 *
 */
void controls() {
	printf("ＤＩＳＣＬＡＩＭＥＲ：\nPress stands for input and press enter here.\n");
	printf("Press \"d\" to roll the die!\n");
	printf("Press \"m\" to get Martial Card info!\n");
	printf("Press \"w\" to get Wildcard info!\n");
	printf(
			"Also, if you need any help on a specific event, you can press \"help\" followed by a space, then the event you need help on.\n");
	printf(
			"There are other help options. for specifics, you can press \"help help\" or simply \"help\".\n");
	printf(
			"During Super PK, you enter the number of the player you want to PK with, and card selection's the same except the number's under the Card Power!\n");
	printf(
			"The screen will also display how many Battle Power you have. Upon prompted, enter the number of battle power you wish to exert!");
	cout << endl;
	printf("That's it!\n");
	printf("Press any key to continue...");
	cin.get();
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}
/**
 * @fn void help(string)
 * @brief Help
 *
 * @param param What help section to display
 */
void help(string param) {
	bool flag = 0;
	string menu;
	TRIE(param)
	CASE("help")
	flag = 1;
	printf("Usage:	");
	printf("help <parameters> [parameters]\n");
	printf("Parameters:\n");
	printf("list <events/commands>\n");
	printf("	Lists all of a category. Currently can only list commands or events.\n");
	printf("about\n");
	printf("	About this program.\n");
	printf("license <deed/legal>\n");
	printf("	Specific information about the license. \"deed\" is a synopsis, and \"legal\" contains a long list of legal information.");
	CASE("list")
	cin >> menu;
	TRIE(menu)
	CASE("events")
	flag = 1;
	printf("All events(clockwise from start):\n");
	for (auto i : gb::places)
	cout << i << ", ";
	CASE("commands")
	flag = 1;
	controls();
	CASE("cows")
	flag = 1;
	printf("There are no easter eggs in this program.");
	CASE("moo")
	flag = 1;
	printf("There are no easter eggs in this program!");
	ENDTRIE;
	CASE("about")
	flag = 1;
	printf("Richman Sun Tzu's Martial Arts Edition\n\nVersion: 0.1.0 Alpha\nLast Version Hash: f623d78650904f0640cb57e1ec90989026f91717\n\nLiscensed under Creative Commons by-nc-sa. Monopoly is a trademark of Hasbro, Inc., https://www.hasbro.com/..");
	CASE("license")
	printf("Please select: \"legal\" or \"deed\"?");
	cin >> menu;
	TRIE(menu)
	CASE("deed")
	flag = 1;
	printf("ＤＩＳＣＬＡＩＭＥＲ：\nThis deed highlights only some of the key features and terms of the actual license. It is not a license and has no legal value. You should carefully review all of the terms and conditions of the actual license before using the licensed material.\nCreative Commons is not a law firm and does not provide legal services. Distributing, displaying, or linking to this deed or the license that it summarizes does not create a lawyer-client or any other relationship.\n");
	printf("ＹＯＵ　ＡＲＥ　ＦＲＥＥ　ＴＯ：\nShare — copy and redistribute the material in any medium or format\nAdapt — remix, transform, and build upon the material\nThe licensor cannot revoke these freedoms as long as you follow the license terms.\n");
	printf("ＵＮＤＥＲ　ＴＨＥ　ＦＯＬＬＯＷＩＮＧ　ＴＥＲＭＳ：\nAttribution — You must give appropriate credit, provide a link to the license, and indicate if changes were made. You may do so in any reasonable manner, but not in any way that suggests the licensor endorses you or your use.\n\nNonCommercial — You may not use the material for commercial purposes.\n\nShareAlike — If you remix, transform, or build upon the material, you must distribute your contributions under the same license as the original.\n\nNo additional restrictions — You may not apply legal terms or technological measures that legally restrict others from doing anything the license permits.");
	CASE("legal")
	flag = 1;
	printf("WARNING:\n This is lengthy. Are you sure you want to output legals(y/n)?");
	cin >> menu;
	if (menu == "n")
	{
		printf("Okay then. Saved a bit of work for me.");
	}
	else
	{
		printf("Here you go!\n");
#ifdef _WIN32
		system("start Drumrool.mp3");
		Sleep(7000);
#else
		system("open Drumrool.mp3");
		sleep(7);
#endif
		printf("Details in https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode!\n");
#ifdef _WIN32
		Sleep(3000);
#else
		sleep(3);
#endif

		printf("░░░░▄▄▄▄▀▀▀▀▀▀▀▀▄▄▄▄▄▄\n");
		printf("░░░░█░░░░▒▒▒▒▒▒▒▒▒▒▒▒░░▀▀▄\n");
		printf("░░░█░░░▒▒▒▒▒▒░░░░░░░░▒▒▒░░█\n");
		printf("░░█░░░░░░▄██▀▄▄░░░░░▄▄▄░░░█\n");
		printf("░▀▒▄▄▄▒░█▀▀▀▀▄▄█░░░██▄▄█░░░█\n");
		printf("█▒█▒▄░▀▄▄▄▀░░░░░░░░█░░░▒▒▒▒▒█\n");
		printf("█▒█░█▀▄▄░░░░░█▀░░░░▀▄░░▄▀▀▀▄▒█\n");
		printf("░█▀▄░█▄░█▀▄▄░▀░▀▀░▄▄▀░░░░█░░█\n");
		printf("░░█░░▀▄▀█▄▄░█▀▀▀▄▄▄▄▀▀█▀██░█\n");
		printf("░░░█░░██░░▀█▄▄▄█▄▄█▄████░█\n");
		printf("░░░░█░░░▀▀▄░█░░░█░███████░█\n");
		printf("░░░░░▀▄░░░▀▀▄▄▄█▄█▄█▄█▄▀░░█\n");
		printf("░░░░░░░▀▄▄░░░░░░░░░░░░░░░█\n");
		printf("░░░░░░░░░░▀▀▄▄░░░░░░░░░░░░█\n");
		printf("░░░░░░░░░░░░░░▀▄▄▄▄▄░░░░░█\n");
	}
	ENDTRIE;
	ENDTRIE;
	if (!flag) {
		printf("help: %s: invalid option\nexit;", param.c_str());
		return;
	}
	cout << endl;
	printf(
			"Press any key to continue.\nIf you still have other commands, press \"help\" followed by that command");
	cin >> param;
	if (param == "help") {
		cin >> param;
		help(param);
	}
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}
/**
 * @fn int main()
 * @brief Main execution loop
 *
 * @return 0 on successful round, 42 on invalid players, -1 on runtime error
 */
int main() {
	srand(time(NULL));
	printf(
			"Welcome to Richman/Uncle Wang Sun Tzu's Martial Arts Board Game!\n How many players are there? Note that no one can join mid-game and that the maximum number of players is 4!");
	cin >> gb::players;
	if (gb::players <= 1 || gb::players > 4) {
		printf("Invalid Number. exit;");
		return 42;
	}
	for (int i = 0; i < gb::players; i++) {
		printf("Please input player %d's name!", i + 1);
		cin >> player[i].name;
		player[i].points++;
	}
	printf("Do you want to know the controls?(y/n): ");
	char yn;
	do
		cin >> yn;
	while (yn != 'n' && yn != 'y');
	if (yn == 'y')
		controls();
	printf("If you wish to look at the controls, press c!\n");
	printf("Now...\n");
	printf("GAME START!\n");
	printf("Press enter to continue...");
	cin.get();
	do {
		int die;
		char yn;
		if (++pNo > gb::players)
			pNo = 0;
#ifdef release
#ifdef _WIN32
		system("cls");
#else
		system("clear");
#endif
#endif
		printf("%s Points: %d Money: %d Battle Power: %d Current Tile: %s\n",
				player[pNo].name, player[pNo].points, player[pNo].money,
				player[pNo].troops, player[pNo].current);
		string temp;
		restart: printf("What to do... What to do? ");
		cin >> temp;
		if (temp == "help") {
			cin >> temp;
			help(temp);
		}
		yn = temp.c_str()[0];
		switch (yn) {
		case 'c':
			controls();
			goto restart;
		case 'm':
			MACard(pNo);
			break;
		case 'w':
			//@TODO: Finish WCard()

			break;
		case 'd':
			die = dice();
			printf("You rolled a %d!\n", die);
			player[pNo].step += die;
			if (player[pNo].step >= 30) {
				player[pNo].step -= 30;
				printf("You went over the camp!Take some rest!\n");
				printf("You got 3000 money and 2 more troops!\n");
				camp(pNo);
			}
			strcpy(player[pNo].current, gb::places[player[pNo].step].c_str());
			event(player[pNo].current, pNo);
			break;
		default:
			printf("Please enter a valid control!\n");
			goto restart;
		}
		printf("Anyways, now for the next player!\n");
		printf(
				"When you're going to transfer this device to %s, press any key to continue!",
				player[pNo].name);
		cin >> temp;
#ifdef _WIN32
		system("cls");
#else
		system("clear");
#endif
	} while (player[pNo].points < 20);
	printf("So, the winner is...\n"); //TODO: Replace winner text with Shouty TTS
#ifdef _WIN32
	system("start Drumrool.mp3");
	Sleep(7000);
#else
	system("open Drumrool.mp3");
	sleep(7);
#endif
	printf("%s!\n", player[pNo].name);
	printf("Congratulations!\n");
	printf("Wanna play again?(y/n): ");
	return 0;
}
