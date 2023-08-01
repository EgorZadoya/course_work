#include "bank_card.h"
#include "Menu_1.h"

int main()
{
	setlocale(LC_ALL, "ru");
	Stats s1;
	s1.add_card(Card("egor"));
	s1.add_transaction(Transaction(-300, "food", "30-07-2023"), 0);
	s1.add_transaction(Transaction(-400, "kvartira", "30-07-2023"), 0);
	s1.add_transaction(Transaction(-100, "transport", "30-07-2023"), 0);
	s1.add_transaction(Transaction(200, "kalivan", "30-07-2023"), 0);
	menu(s1);

}