#include "bank_card.h"
#include "Menu_1.h"

int main()
{
	setlocale(LC_ALL, "ru");
	Stats s1;
	s1.add_card(Card("Egor"));
	menu(s1);
}