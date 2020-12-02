//PREPEND BEGIN
#include <iostream>
#include <cstring>

using namespace std;
enum Suit {
	CLUB, DIAMOND, HEART, SPADE
};
enum Point {
	TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK,
	QUEEN, KING, ACE
};
struct Card {
	Suit s;
	Point p;
};
struct Hand {
	Card cards[5];
};

//PREPEND END
//TEMPLATE BEGIN
char smapc[4][8] = {"Club", "Diamond", "Heart", "Spade"};
int smapi[4] = {0, 1, 2, 3};
char pmapc[13][3] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "1"};
int pmapi[13] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

void set_hand(Hand &hand) {
	for (int i = 0; i < 5; i++) {
		char suit[10], point[10];
		cin >> suit >> point;
//		cout << suit[0] << point[0] << endl;
		if (suit[0] == 'C') hand.cards[i].s = CLUB;
		if (suit[0] == 'S') hand.cards[i].s = SPADE;
		if (suit[0] == 'H') hand.cards[i].s = HEART;
		if (suit[0] == 'D') hand.cards[i].s = DIAMOND;

		if (point[0] == '2') hand.cards[i].p = TWO;
		if (point[0] == '3') hand.cards[i].p = THREE;
		if (point[0] == '4') hand.cards[i].p = FOUR;
		if (point[0] == '5') hand.cards[i].p = FIVE;
		if (point[0] == '6') hand.cards[i].p = SIX;
		if (point[0] == '7') hand.cards[i].p = SEVEN;
		if (point[0] == '8') hand.cards[i].p = EIGHT;
		if (point[0] == '9') hand.cards[i].p = NINE;
		if (point[0] == '1') hand.cards[i].p = TEN;
		if (point[0] == 'J') hand.cards[i].p = JACK;
		if (point[0] == 'Q') hand.cards[i].p = QUEEN;
		if (point[0] == 'K') hand.cards[i].p = KING;
		if (point[0] == 'A') hand.cards[i].p = ACE;
	}
}

void show_hand(Hand &hand) {
	bool sort = true;
	while (sort) {
		sort = false;
		for (int j = 0; j < 4; j++) {
			if (pmapi[hand.cards[j + 1].p] > pmapi[hand.cards[j].p]) {
				Card temp = hand.cards[j + 1];
				hand.cards[j + 1] = hand.cards[j];
				hand.cards[j] = temp;
				sort = true;
			} else if (pmapi[hand.cards[j + 1].p] == pmapi[hand.cards[j].p] &&
			           smapi[hand.cards[j + 1].s] > smapi[hand.cards[j].s]) {
				Card temp = hand.cards[j + 1];
				hand.cards[j + 1] = hand.cards[j];
				hand.cards[j] = temp;
				sort = true;
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		Suit suit = hand.cards[i].s;
		Point point = hand.cards[i].p;
		cout << smapc[suit] << ' ' << pmapc[point] << endl;
	}
}

int compare_hand(Hand hand) {
	bool sort = true;
	while (sort) {
		sort = false;
		for (int j = 0; j < 4; j++) {
			if (pmapi[hand.cards[j + 1].p] > pmapi[hand.cards[j].p]) {
				Card temp = hand.cards[j + 1];
				hand.cards[j + 1] = hand.cards[j];
				hand.cards[j] = temp;
				sort = true;
			} else if (pmapi[hand.cards[j + 1].p] == pmapi[hand.cards[j].p] &&
			           smapi[hand.cards[j + 1].s] > smapi[hand.cards[j].s]) {
				Card temp = hand.cards[j + 1];
				hand.cards[j + 1] = hand.cards[j];
				hand.cards[j] = temp;
				sort = true;
			}
		}
	}

	int rank = 1;
	bool check = true;
	for (int i = 0; i < 4; i++) {
		if (hand.cards[i].s != hand.cards[i + 1].s || pmapi[hand.cards[i].p] - pmapi[hand.cards[i + 1].p] != 1)
			check = false;
	}
	if (check) return rank;

	rank = 2;
	check = false;
	if (pmapi[hand.cards[1].p] == pmapi[hand.cards[2].p] && pmapi[hand.cards[2].p] == pmapi[hand.cards[3].p]) {
		if (pmapi[hand.cards[1].p] == pmapi[hand.cards[0].p]) {
			check = true;
		}
		if (pmapi[hand.cards[3].p] == pmapi[hand.cards[4].p]) {
			check = true;
		}
	}
	if (check) return rank;

	rank = 3;
	check = false;
	if (pmapi[hand.cards[4].p] == pmapi[hand.cards[3].p] && pmapi[hand.cards[3].p] == pmapi[hand.cards[2].p] &&
	    pmapi[hand.cards[0].p] == pmapi[hand.cards[1].p]) {
		check = true;
	}
	if (pmapi[hand.cards[0].p] == pmapi[hand.cards[1].p] && pmapi[hand.cards[1].p] == pmapi[hand.cards[2].p] &&
	    pmapi[hand.cards[3].p] == pmapi[hand.cards[4].p]) {
		check = true;
	}
	if (check) return rank;

	rank = 4;
	check = false;
}

//TEMPLATE END
//APPEND BEGIN
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		Hand hand;
		set_hand(hand);
		char op[5];
		cin >> op;
		if (!strcmp(op, "Show")) {
			cout << "Show" << endl;
			show_hand(hand);
		} else cout << "Rank\n" << compare_hand(hand) << endl;
	}
	return 0;
}
//APPEND END