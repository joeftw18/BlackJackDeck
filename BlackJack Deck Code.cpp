#include <iostream>
#include <vector>
#include <tuple>
#include <clocale>
#include <string>
#include <algorithm>
#include <io.h>
#include <fcntl.h>

using namespace std;


int main() {
	wchar_t *suits[4] = { L"\u2660", L"\u2663",L"\u2665",L"\u2666" };//{ "HEARTS", "CLUBS", "SPADES", "DIAMONDS" };
	const int values[13] = { 1,2,3,4,5,6,7,8,9,10,10,10,10 };
	const int number_of_decks = 3;
	const int number_of_suits = 4;
	const int number_of_cards = 13;
	
	_setmode(_fileno(stdout), _O_U16TEXT);

	vector<tuple<wchar_t*, int> > deck;
	
	for (int e = 0; e != number_of_decks; e++){
		for (int i = 0; i != number_of_suits; i++) {
			for (int q = 0; q != number_of_cards; q++) {
				deck.push_back(make_tuple(suits[i], values[q]));
			}
		}
	}

	for (tuple<wchar_t*, int> testit : deck) {
		wcout << "CARD: " << get<0>(testit) << " " << get<1>(testit) << endl;
	}

	system("PAUSE");
	random_shuffle(deck.begin(), deck.end());

	for (tuple<wchar_t*, int> testit : deck) {
		wcout << "CARD: " << get<0>(testit) << " " << get<1>(testit) << endl;
	}

	system("PAUSE");
	return 0;
}