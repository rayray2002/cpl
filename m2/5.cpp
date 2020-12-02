//PREPEND BEGIN
#include <iostream>

using namespace std;

struct Card {
	int value;
	char *name;
	Card *next;
};

struct Player {
	char name;
	Card *FirstCard;
};

void show(Player p) {

	cout << "Player " << p.name << " : ";
	Card *cur;
	cur = p.FirstCard;
	while (cur) {
		cout << cur->name << " ";
		cur = cur->next;
	}
	cout << "\n";
}

void deal(Player &p);

void draw(Player &p1, Player &p2, int c);
//PREPEND END

//TEMPLATE BEGIN

//Todo1 : deal function
void deal(Player &p) {
	Card *cards = new Card[10];
	cin >> p.name;
	for (int i = 0; i < 10; i++) {
		cards[i].name = new char[3];
		cin >> cards[i].name;
		switch (cards[i].name[0]) {
			case 'A':
				cards[i].value = 0;
				break;
			case 'K':
				cards[i].value = 12;
				break;
			case 'Q':
				cards[i].value = 11;
				break;
			case 'J':
				cards[i].value = 10;
				break;
			case '1':
				cards[i].value = 9;
				break;
			case '9':
				cards[i].value = 8;
				break;
			case '8':
				cards[i].value = 7;
				break;
			case '7':
				cards[i].value = 6;
				break;
			case '6':
				cards[i].value = 5;
				break;
			case '5':
				cards[i].value = 4;
				break;
			case '4':
				cards[i].value = 3;
				break;
			case '3':
				cards[i].value = 2;
				break;
			case '2':
				cards[i].value = 1;
				break;
		}
	}
	for (int j = 0; j < 10; j++) {
		for (int i = 0; i < 9; i++) {
			if (cards[i].value > cards[i + 1].value) {
				Card temp = cards[i];
				cards[i] = cards[i + 1];
				cards[i + 1] = temp;
			}
		}
	}
	p.FirstCard = &cards[0];
	for (int i = 0; i < 9; i++) {
		cards[i].next = &cards[i + 1];
	}
	cards[9].next = nullptr;
}

//Todo2 : draw function
void draw(Player &p1, Player &p2, int c) {
	Card *card = p2.FirstCard;
	if (c == 1) {
		p2.FirstCard = card->next;
	} else {
		for (int i = 0; i < c - 2; i++) {
			card = card->next;
		}
		Card *temp = card->next;
		card->next = card->next->next;
		card = temp;
	}
//    cout << "tar:" << card->name << endl;

	Card *index = p1.FirstCard;
	int i = 1;
	while (index != nullptr) {
//        cout << index->name;
		if (index->value == card->value) {
//            cout << "find!!!" << i << endl;
			Card *rm = p1.FirstCard;
			if (i == 1) {
				p1.FirstCard = rm->next;
			} else {
				for (int j = 0; j < i - 2; j++) {
					rm = rm->next;
				}
				rm->next = rm->next->next;
			}
			return;
		}
		index = index->next;
		i++;
	}
//    cout << endl;

	index = p1.FirstCard;
	i = 1;
	if (index->value > card->value) {
		p1.FirstCard = card;
		card->next = index;
		return;
	}
	while (index->next != nullptr) {
//        cout << index->next->value<< card->value;
		if (index->next->value > card->value) {
//            cout << "app" << i << endl;
//            cout << index->name;
			Card *next = index->next;
			index->next = card;
			card->next = next;
			return;
		}
		index = index->next;
		i++;
	}
//    cout << index->name;
	index->next = card;
	card->next = nullptr;
}
//TEMPLATE END

//APPEND BEGIN
int main() {

	auto *players = new Player[4];
	for (int i = 0; i < 4; i++) {
		deal(players[i]);
	}
//    for (int i = 0; i < 4; i++) {
//        show(players[i]);
//    }

	int N, card_i, p1, p2;
	char p_name_1, p_name_2;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> p_name_1 >> p_name_2 >> card_i;
		p1 = p_name_1 - 97;
		p2 = p_name_2 - 97;
		draw(players[p1], players[p2], card_i);
//        for (int i = 0; i < 4; i++) {
//            show(players[i]);
//        }
	}

	for (int i = 0; i < 4; i++) {
		show(players[i]);
	}
}
//APPEND END
