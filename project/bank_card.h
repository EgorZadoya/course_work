#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;

class Transaction {
protected:
	double amount;
	string category;
	string date;
public:
    Transaction(double _amount, const string& _category, const string& _date);
    Transaction();
    double get_amount()const;
    const string& get_category() const;
    const string& get_date() const;
    void set_amount(double value);
    void set_category(string value);
    void set_date(string value);
    Transaction& operator=(Transaction& t);
    const Transaction& operator+=(const Transaction& t);
    vector<Transaction> sort(vector <Transaction> tran);
};

class Card
{
    vector<Transaction> transactions;
    string card_name;
    double all_money;
public:
    Card(const string& _name);
    void in_file(const Transaction& transaction);
    void set_name(string& _name);
    void plus_money(const Transaction& transaction);
    const string& get_name()const;
    double get_money() const;
    vector<Transaction> get_transactions();
    vector<Transaction> transactions_date(const std::string& date) const;
};

class Stats {
private: 
    vector<Card> cards;
public:
    void add_transaction(const Transaction& transaction, int number);
    void add_card(const Card& card);
    void card_info()const;
    void show_name_card() const;
    void show_all_transactions(int number);
    void all_date(const string& date, int number) const;
    void top_amount(int number);
    void top_category(int number);
};
