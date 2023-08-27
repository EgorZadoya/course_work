#pragma once
#include "bank_card.h"

void top_stats(int choice, Stats& s1) {
	int number = 0;
	string date;
	switch (choice) {
	case 1:
		cout << "Выберите номер карты для которой хотите посмотреть статистику: " << endl;
		s1.show_name_card();
		cin >> number;
		cout << "Напишите дату за которую хотите посмотреть данные(например 27-07-2023): " << endl;
		cin >> date;
		system("cls");
		s1.all_date(date, number - 1);
		break;
	case 2:
		cout << "Выберите номер карты для которой хотите посмотреть статистику: " << endl;
		s1.show_name_card();
		cin >> number;
		system("cls");
		s1.top_amount(number - 1);
		break;
	case 3:
		cout << "Выберите номер карты для которой хотите посмотреть статистику: " << endl;
		s1.show_name_card();
		cin >> number;
		system("cls");
		s1.top_category(number - 1);
		break;
	default:
		cout << endl << "выбрана неправильная цифра" << endl << endl;
	}
}

void menu(Stats& s1) {
	int menu = 0;
	int sum_transaction = 0;
	int number = 0;
	int choice = 0;
	string name;
	string category;
	string date;
	do {
		cout << "\tЗадоя Егор ПВ-211" << endl
			<< "________________________________" << endl
			<< "1 - посмотреть текущие карты" << endl
			<< "2 - добавить новую карту " << endl
			<< "3 - добавить транзакцию " << endl
			<< "4 - посмотреть отчеты" << endl
			<< "5 - посмотреть все транзакции" << endl	
			<< "6 - выход" << endl;
		cin >> menu;
		system("cls");
		switch (menu) {
		case 1:
			s1.card_info();
			break;
		case 2:
			cout << "Введите имя новой карты(на английском) : " << endl;
			cin >> name;
			s1.add_card(Card{ name });
			system("cls");
			cout << endl << "Новая карта создана" << endl << endl;
			break;
		case 3:
			cout << "Выберите номер карты для транзакции: " << endl;
			s1.show_name_card();
			cin >> number;
			cout << "Введите сумму транзакции: " << endl;
			cin >> sum_transaction;
			cout << "Введите категорию транзакции(на английском): " << endl;
			cin >> category;
			cout << "Введите дату создания транзакции(например 27-07-2023): ";
			cin >> date;
			s1.add_transaction(Transaction(sum_transaction, category, date), number - 1);
			system("cls");
			cout << "Транзакция создана" << endl << endl;
			break;
		case 4:
			cout << "Выберите отчет который хотите посмотреть: " << endl
				<< "1 - отчет за выбранную дату" << endl
				<< "2 - ТОП-3 затрат" << endl
				<< "3 -  ТОП-3 категории в которых были сделаны самые большие траты" << endl;
			cin >> choice;
			system("cls");
			top_stats(choice, s1);
			break;
		case 5:
			cout << "Выберите номер карты для просмотра транзакций: " << endl;
			s1.show_name_card();
			cin >> number;
			system("cls");
			s1.show_all_transactions(number - 1);
			break;
		case 6:
			cout << "Выход";
			break;
		default:
			cout << endl << "выбрана неправильная цифра" << endl << endl;
		}
	} while (menu != 6);
}
