#pragma once
#include "bank_card.h"

void top_stats(int choice, Stats& s1) {
	int number = 0;
	string date;
	switch (choice) {
	case 1:
		cout << "�������� ����� ����� ��� ������� ������ ���������� ����������: " << endl;
		s1.show_name_card();
		cin >> number;
		cout << "�������� ���� �� ������� ������ ���������� ������(�������� 27-07-2023): " << endl;
		cin >> date;
		system("cls");
		s1.all_date(date, number - 1);
		break;
	case 2:
		cout << "�������� ����� ����� ��� ������� ������ ���������� ����������: " << endl;
		s1.show_name_card();
		cin >> number;
		system("cls");
		s1.top_amount(number - 1);
		break;
	case 3:
		cout << "�������� ����� ����� ��� ������� ������ ���������� ����������: " << endl;
		s1.show_name_card();
		cin >> number;
		system("cls");
		s1.top_category(number - 1);
		break;
	default:
		cout << endl << "������� ������������ �����" << endl << endl;
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
		cout << "\t����� ���� ��-211" << endl
			<< "________________________________" << endl
			<< "1 - ���������� ������� �����" << endl
			<< "2 - �������� ����� ����� " << endl
			<< "3 - �������� ���������� " << endl
			<< "4 - ���������� ������" << endl
			<< "5 - ���������� ��� ����������" << endl	
			<< "6 - �����" << endl;
		cin >> menu;
		system("cls");
		switch (menu) {
		case 1:
			s1.card_info();
			break;
		case 2:
			cout << "������� ��� ����� �����(�� ����������) : " << endl;
			cin >> name;
			s1.add_card(Card{ name });
			system("cls");
			cout << endl << "����� ����� �������" << endl << endl;
			break;
		case 3:
			cout << "�������� ����� ����� ��� ����������: " << endl;
			s1.show_name_card();
			cin >> number;
			cout << "������� ����� ����������: " << endl;
			cin >> sum_transaction;
			cout << "������� ��������� ����������(�� ����������): " << endl;
			cin >> category;
			cout << "������� ���� �������� ����������(�������� 27-07-2023): ";
			cin >> date;
			s1.add_transaction(Transaction(sum_transaction, category, date), number - 1);
			system("cls");
			cout << "���������� �������" << endl << endl;
			break;
		case 4:
			cout << "�������� ����� ������� ������ ����������: " << endl
				<< "1 - ����� �� ��������� ����" << endl
				<< "2 - ���-3 ������" << endl
				<< "3 -  ���-3 ��������� � ������� ���� ������� ����� ������� �����" << endl;
			cin >> choice;
			system("cls");
			top_stats(choice, s1);
			break;
		case 5:
			cout << "�������� ����� ����� ��� ��������� ����������: " << endl;
			s1.show_name_card();
			cin >> number;
			system("cls");
			s1.show_all_transactions(number - 1);
			break;
		case 6:
			cout << "�����";
			break;
		default:
			cout << endl << "������� ������������ �����" << endl << endl;
		}
	} while (menu != 6);
}
