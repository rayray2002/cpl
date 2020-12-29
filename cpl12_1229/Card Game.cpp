//PREPEND BEGIN
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

struct card {
	enum suit {
		clubs, diamonds, hearts, spades
	};
	suit card_suit;
	int card_face;

	int compare(card that);

	void print();
};

int card::compare(card that) {
	if (card_face > that.card_face) return 1;
	if (card_face < that.card_face) return 0;
	if (card_suit > that.card_suit) return 1;
	else return 0;
}

void card::print() {
	if (card_suit == clubs) cout << setw(11) << "clubs";
	if (card_suit == diamonds) cout << setw(11) << "diamonds";
	if (card_suit == hearts) cout << setw(11) << "hearts";
	if (card_suit == spades) cout << setw(11) << "spades";
	if (card_face == 14) cout << setw(3) << 'A'; // define A as 14, since A is the largest.
	else if (card_face == 11) cout << setw(3) << 'J';
	else if (card_face == 12) cout << setw(3) << 'Q';
	else if (card_face == 13) cout << setw(3) << 'K';
	else cout << setw(3) << card_face;
}

class Player {
public:
	struct hand_type {
		enum type {
			full_house = 6, flush = 5, straight = 4, two_pair = 3, one_pair = 2, high_card = 1
		} Type;
		card dominate_card;
	};

	void set_card(card _cards[5]);//Set five card to the player
	void sort_cards(); //sort the cards, small to large
	void print_cards();

	void judge_hand();//judge hand type
	int compare(Player that);

	// if this play handtype is larger than the other return +1, smaller return -1
	void ProccessingCard() {
		cout << "Cards:" << endl;
		print_cards();
		sort_cards();
		cout << "Sorted Cards:" << endl;
		print_cards();
		judge_hand();
	}

private:
	card cards[5];
	hand_type Hand_type;
	bool type_judged;
};

void Player::set_card(card _cards[5]) {
	for (int i = 0; i < 5; i++) cards[i] = _cards[i];
}

void Player::sort_cards() {
	card temp;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			if (cards[j].compare(cards[j + 1])) {
				temp = cards[j];
				cards[j] = cards[j + 1];
				cards[j + 1] = temp;
			}
		}
	}
}

void Player::print_cards() {
	for (int i = 0; i < 5; i++)cards[i].print();
	cout << endl;
}

/*full_house=6,flush=5,straight=4,two_pair=3,one_pair=2,high_card=1*/
void Player::judge_hand() {
	type_judged = true;
	/*full_house 3+2*/
	if (cards[0].card_face == cards[1].card_face && cards[1].card_face == cards[2].card_face && \
       cards[3].card_face == cards[4].card_face) {
		Hand_type.Type = Hand_type.full_house;
		Hand_type.dominate_card = cards[2];
	}
		/*full_house 2+3*/
	else if (cards[0].card_face == cards[1].card_face && \
       cards[2].card_face == cards[3].card_face && cards[3].card_face == cards[4].card_face) {
		Hand_type.Type = Hand_type.full_house;
		Hand_type.dominate_card = cards[4];
	}
		/*flush*/
	else if (cards[0].card_suit == cards[1].card_suit && cards[1].card_suit == cards[2].card_suit && \
       cards[2].card_suit == cards[3].card_suit && cards[3].card_suit == cards[4].card_suit) {
		Hand_type.Type = Hand_type.flush;
		Hand_type.dominate_card = cards[4];
	}

		/*straight*/
	else if (cards[0].card_face == (cards[1].card_face - 1) && cards[1].card_face == (cards[2].card_face - 1) && \
       cards[2].card_face == (cards[3].card_face - 1) && cards[3].card_face == (cards[4].card_face - 1)) {
		Hand_type.Type = Hand_type.flush;
		Hand_type.dominate_card = cards[4];
	}
		/*one_pair*/
	else if (cards[3].card_face == cards[4].card_face) {
		Hand_type.Type = Hand_type.one_pair;
		Hand_type.dominate_card = cards[4];
	} else if (cards[2].card_face == cards[4].card_face) {
		Hand_type.Type = Hand_type.one_pair;
		Hand_type.dominate_card = cards[4];
	} else if (cards[1].card_face == cards[4].card_face) {
		Hand_type.Type = Hand_type.one_pair;
		Hand_type.dominate_card = cards[4];
	} else if (cards[0].card_face == cards[4].card_face) {
		Hand_type.Type = Hand_type.one_pair;
		Hand_type.dominate_card = cards[4];
	} else if (cards[2].card_face == cards[3].card_face) {
		Hand_type.Type = Hand_type.one_pair;
		Hand_type.dominate_card = cards[3];
	} else if (cards[1].card_face == cards[3].card_face) {
		Hand_type.Type = Hand_type.one_pair;
		Hand_type.dominate_card = cards[3];
	} else if (cards[0].card_face == cards[3].card_face) {
		Hand_type.Type = Hand_type.one_pair;
		Hand_type.dominate_card = cards[3];
	} else if (cards[1].card_face == cards[2].card_face) {
		Hand_type.Type = Hand_type.one_pair;
		Hand_type.dominate_card = cards[2];
	} else if (cards[0].card_face == cards[2].card_face) {
		Hand_type.Type = Hand_type.one_pair;
		Hand_type.dominate_card = cards[2];
	} else if (cards[0].card_face == cards[1].card_face) {
		Hand_type.Type = Hand_type.one_pair;
		Hand_type.dominate_card = cards[1];
	}
		/*high_card*/
	else {
		Hand_type.Type = Hand_type.high_card;
		Hand_type.dominate_card = cards[4];
	}
	/*two_pair*/
	for (int n1; n1 < 5; n1++)
		for (int n2; n2 < 5; n2++)
			for (int n3; n3 < 5; n3++)
				for (int n4; n4 < 5; n4++) {
					if (n1 != n2 && n1 != n3 && n1 != n4 && n2 != n3 && n2 != n4 && n3 != n4) {
						if (cards[n1].card_face == cards[n2].card_face && cards[n3].card_face == cards[n4].card_face) {
							Hand_type.Type = Hand_type.two_pair;
							if (cards[n2].compare(cards[n4]))Hand_type.dominate_card = cards[n2];
							else Hand_type.dominate_card = cards[n4];
							break;
						}
					}
				}
	if (Hand_type.Type == Hand_type.full_house)cout << "Hand type : Full house" << endl;
	else if (Hand_type.Type == Hand_type.flush)cout << "Hand type : Flush" << endl;
	else if (Hand_type.Type == Hand_type.straight)cout << "Hand type : Straight" << endl;
	else if (Hand_type.Type == Hand_type.two_pair)cout << "Hand type : Two pair" << endl;
	else if (Hand_type.Type == Hand_type.one_pair)cout << "Hand type : One pair" << endl;
	else if (Hand_type.Type == Hand_type.high_card)cout << "Hand type : High card" << endl;
	cout << "Dominant card:" << endl;
	Hand_type.dominate_card.print();
	cout << endl << endl;
	return;
}

int Player::compare(Player that) {
	if (Hand_type.Type > ((that.Hand_type).Type))return 1;
	if (Hand_type.Type < ((that.Hand_type).Type))return -1;
	if ((Hand_type.dominate_card).compare((that.Hand_type).dominate_card))return 1;
	else return -1;
}
//PREPEND END

//TEMPLATE BEGIN
class RatedPlayer : public Player {
public:
	void setRate(const int r) { rate = r; }

	void setName(const string s) { name = s; }

	void show_Name_Rate() {
		cout << "Name:" << name + " Rate:" << rate << "\n\n";
	}

private:
	int rate;
	string name;
};
//TEMPLATE END

//APPEND BEGIN
int main() {
	int player_num = 0;
	cout << "How many players?" << endl;
	cin >> player_num;
	if (player_num < 1 || player_num > 10) {
		cout << "Wrong input";
		return 0;
	}

	RatedPlayer *players = new RatedPlayer[player_num];
	for (int i = 0; i < player_num; i++) {
		stringstream ss;
		ss << i + 1;
		players[i].setName("Player No." + ss.str());
		//Please create player's name Player No.1
	}
	card Game_card[52];
	for (int i = 0; i < 13; i++) {
		Game_card[i].card_suit = Game_card[i].clubs;
		Game_card[i].card_face = i + 1;
	}
	for (int i = 0; i < 13; i++) {
		Game_card[13 + i].card_suit = Game_card[13 + i].diamonds;
		Game_card[13 + i].card_face = i + 1;
	}
	for (int i = 0; i < 13; i++) {
		Game_card[26 + i].card_suit = Game_card[26 + i].hearts;
		Game_card[26 + i].card_face = i + 1;
	}
	for (int i = 0; i < 13; i++) {
		Game_card[39 + i].card_suit = Game_card[39 + i].spades;
		Game_card[39 + i].card_face = i + 1;
	}
	Game_card[0].card_face = 14;
	Game_card[13].card_face = 14;
	Game_card[26].card_face = 14;
	Game_card[39].card_face = 14;

	srand(time(0));
	for (int j = 0; j < 5; j++) {
		for (int i = 0; i < 52; i++) {
			int r;
			cin >> r;
			card temp = Game_card[i];
			Game_card[i] = Game_card[r];
			Game_card[r] = temp;
		}
	}

	for (int i = 0; i < player_num; i++) {
		cout << "Player " << i + 1 << ':' << endl;
		//Please print Player 1, Player 2

		card cards[5];
		for (int j = 0; j < 5; j++)cards[j] = Game_card[5 * i + j];
		players[i].set_card(cards);
		players[i].ProccessingCard();
	}

	for (int i = 0; i < player_num; i++) {
		for (int j = 0; j < player_num - 1; j++) {
			if (players[j].compare(players[j + 1]) < 0) {
				RatedPlayer templ = players[j];
				players[j] = players[j + 1];
				players[j + 1] = templ;
			}
		}
	}
	for (int i = 0; i < player_num; i++) {
		players[i].setRate(i + 1);
	}
	//Please Add your own Code, Sort players
	cout << "Rate Players:" << endl;
	for (int i = 0; i < player_num; i++) {
		players[i].show_Name_Rate();
		//Note that the players here is sorted
	}
	return 0;
}
//APPEND END
