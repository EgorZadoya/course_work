#include "bank_card.h"

Transaction::Transaction(double _amount, const string& _category, const string& _date) : amount{ _amount }, category{ _category }, date{ _date } {}

Transaction::Transaction() : Transaction(0, "@", "@") {}

double Transaction::get_amount() const { return amount; }

const string& Transaction::get_category() const { return category; }

const string& Transaction::get_date() const { return date; }

Transaction& Transaction::operator=(Transaction& t) {
	amount = t.amount;
	category = t.category;
	date = t.date;
	return *this;
}

const Transaction& Transaction::operator+=(const Transaction& t) {
	amount += t.amount;
	return *this;
}

vector<Transaction> Transaction::sort(vector <Transaction> tran) {
	for (int i = 0; i < tran.size() - 1; i++) {
		for (int j = 0; j < tran.size() - i - 1; j++) {
			if (tran[j].get_amount() > tran[j + 1].get_amount()) {
				Transaction tmp = tran[j];
				tran[j] = tran[j + 1];
				tran[j + 1] = tmp;
			}
		}
	}
	return tran;
}

Card::Card(const string& _name) : card_name{ _name }, all_money{ 0 } {}

vector<Transaction> Card::get_transactions() { return transactions; };

vector<Transaction> Card::transactions_date(const std::string& date) const {
	vector<Transaction> sort;
	for (int i = 0; i < transactions.size(); i++) {
		if (transactions[i].get_date() == date) {
			sort.push_back(transactions[i]);
		}
	}
	return sort;
}

void Card::set_name(string& _name) {
	card_name = _name;
}

void Card::plus_money(const Transaction& transaction) {
	all_money += transaction.get_amount();
	transactions.push_back(transaction);
}

const string& Card::get_name()const  { return card_name; }

double Card::get_money() const { return all_money; }

void Stats::add_transaction(const Transaction& transaction, int number) {
	cards[number].plus_money(transaction);
}

void Stats::add_card(const Card& card) {
	cards.push_back(card);
}

void Stats::card_info()const {
	cout << "________________________________" << endl;
	for (int i = 0; i < cards.size(); i++) {
		cout << i + 1 << " - " << " ��������: " << cards[i].get_name() << endl;
		cout << "������: " << cards[i].get_money() << endl;
	}
	cout << "________________________________" << endl;
}

void Stats::show_name_card() const {
	cout << "________________________________" << endl;
	for (int i = 0; i < cards.size(); i++) {
		cout << i + 1 << " - " << " ��������: " << cards[i].get_name() << endl;
	}
	cout << "________________________________" << endl;
}

void Stats::all_date(const string& date, int number) const {//������������ ������� �� �������� � ����������
	vector<Transaction> transactions_for_date = cards[number].transactions_date(date);// �������� ������ ���������� �� ��������� ����.
	if (transactions_for_date.empty()) {
		cout << "����������� ������ �� ��� ���� " << endl;
		return;
	}
	double max_transaction = 0;
	double min_transaction = 0;
	cout << "����� �� ������ �� " << date << endl;
	cout << "________________________________" << endl;
	for (int i = 0; i < transactions_for_date.size(); i++) {//������� ���������� ������� �������� �� ����
		const Transaction& transaction = transactions_for_date[i];//������� ���������� �� �������
		cout << "���������: " << transaction.get_category() << endl << "�����: " << transaction.get_amount() << endl;
		if (transaction.get_amount() > 0) {
			max_transaction += transaction.get_amount();
		}
		else {
			min_transaction += transaction.get_amount();
		}
	}
	cout << "________________________________" << endl;
	cout << "����� ����������� ����� �� ���� ����: " << max_transaction << endl;
	cout << "����� ����������� ����� �� ���� ����: " << min_transaction << endl;
	cout << "����� � ����� ���: " << max_transaction + min_transaction << endl;
	cout << "________________________________" << endl;
}

void Stats::top_amount(int number) {
	vector<Transaction> transactions_for_amount = cards[number].get_transactions();
	vector<Transaction>transactions_sort;
	transactions_sort = transactions_for_amount[0].sort(transactions_for_amount);
	if (transactions_sort.empty()) {
		cout << "����������� ���������� " << endl;
		return;
	}
	cout << endl;
	cout << "��� ��� �������:  " << endl;
	for (int i = 0; i < 3; i++) {
		if (i < transactions_sort.size()) {
			cout << "________________________________" << endl;
			cout << i + 1 << " - " << transactions_sort[i].get_amount() << endl << " � ���������:  " << transactions_sort[i].get_category() << endl << "�� ����: " << transactions_sort[i].get_date() << endl;
		}
		else {
			break;
		}
	}
	cout << "________________________________" << endl;
	cout << endl;
}

void Stats::top_category(int number) {
	vector<Transaction> transactions_for_date = cards[number].get_transactions();
	vector<Transaction> categories;
	//for (int i = 0; i < transactions_for_date.size(); i++) {
		/*vector<Transaction> transactions_for_date = cards[number].get_transactions();
		vector<Transaction> categories;*/

		if (transactions_for_date.empty()) {
			cout << "����������� ��������� " << endl;
			return;
		}

		for (int i = 0; i < transactions_for_date.size(); i++) {
			const Transaction& transaction = transactions_for_date[i];
			if (transaction.get_amount() < 0) {
				bool search = false;
				for (int j = 0; j < categories.size(); j++) {
					if (categories[j].get_category() == transaction.get_category()) {
						categories[j] += transaction;
						search = true;
						break;
					}
				}
				if (!search) {
					categories.emplace_back(transaction);
				}
			}
		}

		vector<Transaction>transactions_sort;
		transactions_sort = categories[0].sort(categories);


		cout << "��� ��� ��������� �� ��������:  " << endl;
		for (int i = 0; i < 3; i++) {
			if (i < transactions_sort.size()) {
				cout << "________________________________" << endl;
				cout << i + 1 << " - " << transactions_sort[i].get_category() << endl
					<< "����� ���������: " << transactions_sort[i].get_amount() << endl;
			}
			else {
				break;
			}
		}
		cout << endl << endl;
}