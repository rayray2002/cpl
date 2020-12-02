//PREPEND BEGIN
#include <iostream>
using namespace std;

int N =0;

struct CARD{
	char name[100];
	int attack;
	int blood;
};

template <typename X>
void show(X card){
	cout<<"name : "<<card.name<<"\n";
	cout<<"blood : "<<card.blood<<"\n";
	cout<<"attack : "<<card.attack<<"\n";
	cout<<"----------------------------\n";
}
//PREPEND END

//TEMPLATE BEGIN
template <typename X>
void fight(X cards[],int card1,int card2){
	cards[card1].blood -= cards[card2].attack;
	cards[card2].blood -= cards[card1].attack;
	if (cards[card1].blood <= 0) {
		N -= 1;
		for (int i = card1; i < N; i++) {
			cards[i] = cards[i+1];
		}
		if (card2 > card1) card2--;
	}
	if (cards[card2].blood <= 0) {
		N -= 1;
		for (int i = card2; i < N; i++) {
			cards[i] = cards[i+1];
		}
	}
}
//TEMPLATE END

//APPEND BEGIN
int main() {
	CARD cards[1000];
	int card1=0,card2=0;

	cin>>N;

	for(int i=0;i<N;++i)
		cin>>cards[i].name>>cards[i].blood>>cards[i].attack;

	while(cin>>card1>>card2)
		fight(cards,card1,card2);

	for(int i =0 ; i<N;++i)
		show(cards[i]);

	return 0;
}

//APPEND END