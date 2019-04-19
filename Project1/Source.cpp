#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std;

struct Date {
	int day, month, year;
};

struct project {
	int ID;
	Date startDate, endDate;
	string title, brief;
}pro[100];

struct news {
	int ID;
	Date publishDate;
	string title, brief, pro_Title;
}ns[100];

//Main functions
void add_project();
void display_project();
void add_news();
void display_news();
void filter_startDate();
void filter_endDate();
void filter_ID();
void filter_title();
//View functions
void Logo_display();
void main_view();
void project_options();
void news_options();
void filter_projects();
void filter_news();
//Bugs functions
int choice_three(int);
int choice_four(int);
void hold_chars();
//Save & Read data functions
void files_pro();
void files_news();
void pro_save();
void news_save();

int counter = 0, counter2 = 0;
int cho, choice;

int main() {
	files_pro();
	files_news();
	string new_operation;
	bool back_main_view = false, back_project_options = false, back_news_options = false;
	do {
		main_view();
		back_main_view = false;
		if (!back_main_view && !back_project_options && !back_news_options) { choice = choice_three(cho); }
		if (back_project_options) {
			choice = 1;
			back_project_options = false;
		}
		if (back_news_options) {
			choice = 2;
			back_news_options = false;
		}
		if (choice == 1) {
			project_options();
			if (!back_main_view && !back_project_options && !back_news_options) { choice = choice_four(cho); }
			if (choice == 1) { add_project(); }
			else if (choice == 2) { display_project(); }
			else if (choice == 3) {
				filter_projects();
				if (counter != 0) { choice = choice_three(cho); }
				if (choice == 1) { filter_startDate(); }
				else if (choice == 2) { filter_endDate(); }
				else if (choice == 3) {
					new_operation = "Y";
					back_project_options = true;
				}
			}
			else if (choice == 4) {
				new_operation = "Y";
				back_main_view = true;
			}
		}
		else if (choice == 2) {
			news_options();
			if (!back_main_view && !back_project_options && !back_news_options) { choice = choice_four(cho); }
			if (choice == 1) { add_news(); }
			else if (choice == 2) { display_news(); }
			else if (choice == 3) {
				filter_news();
				if (counter != 0 && counter2 != 0) { choice = choice_three(cho); }
				if (choice == 1) { filter_ID(); }
				else if (choice == 2) { filter_title(); }
				else if (choice == 3) {
					new_operation = "Y";
					back_news_options = true;
				}
			}
			else if (choice == 4) {
				new_operation = "Y";
				back_main_view = true;
			}
		}
		else if (choice == 3) { exit(0); }
		if (!back_main_view && !back_project_options && !back_news_options) {
			cout << "Do you want to do another operation  (Y/N)" << endl;
			cin >> new_operation;
			while (new_operation != "Y"&&new_operation != "y"&&new_operation != "N"&&new_operation != "n") {
				cout << "please enter Y / N: ";
				cin >> new_operation;
			}
		}
	} while (new_operation == "Y" || new_operation == "y");
	return 0;
}
//Project
void add_project() {
	system("CLS");
	Logo_display();
	cout << "\n\nEnter Title \n";
	cin.ignore(1000, '\n');
	getline(cin, pro[counter].title);
	cout << "Enter Brief \n";
	getline(cin, pro[counter].brief);
	pro[counter].ID = counter + 1;
	cout << "Enter start date \n";
	cout << "Enter day ";
	cin >> pro[counter].startDate.day;
	while (pro[counter].startDate.day > 31 || pro[counter].startDate.day < 1) {
		cout << "Invalid Value..please enter again" << endl;
		cin >> pro[counter].startDate.day;
		hold_chars();
	}
	cout << "Enter month ";
	cin >> pro[counter].startDate.month;
	while (pro[counter].startDate.month > 12 || pro[counter].startDate.month < 1) {
		cout << "Invalid Value..please enter again" << endl;
		cin >> pro[counter].startDate.month;
		hold_chars();
	}
	cout << "Enter year ";
	cin >> pro[counter].startDate.year;
	while (pro[counter].startDate.year < 1) {
		cout << "Invalid Value..please enter again" << endl;
		cin >> pro[counter].startDate.year;
		hold_chars();
	}
	cout << "End date" << endl;
	bool S_E = true;
	while (S_E) {
		cout << "Enter day ";
		cin >> pro[counter].endDate.day;
		while (pro[counter].endDate.day > 31 || pro[counter].endDate.day < 1) {
			cout << "Invalid Value..please enter again" << endl;
			cin >> pro[counter].endDate.day;
			hold_chars();
		}
		cout << "Enter month ";
		cin >> pro[counter].endDate.month;
		while (pro[counter].endDate.month > 12 || pro[counter].endDate.month < 1) {
			cout << "Invalid Value..please enter again" << endl;
			cin >> pro[counter].endDate.month;
			hold_chars();
		}
		cout << "Enter year ";
		cin >> pro[counter].endDate.year;
		while (pro[counter].endDate.year < 1) {
			cout << "Invalid Value..please enter again" << endl;
			cin >> pro[counter].endDate.year;
			hold_chars();
		}
		if (pro[counter].startDate.year < pro[counter].endDate.year) { S_E = false; }
		else if (pro[counter].startDate.year == pro[counter].endDate.year) {
			if (pro[counter].startDate.month < pro[counter].endDate.month) { S_E = false; }
			else if (pro[counter].startDate.month == pro[counter].endDate.month) {
				if (pro[counter].startDate.day <= pro[counter].endDate.day) { S_E = false; }
			}
		}
		if (S_E) { cout << "\nstart date can't be bigger than end date..please enter End date again\n\n"; }
	}
	pro_save();
	counter++;
}

void display_project() {
	system("CLS");
	Logo_display();
	cout << "\n\n";
	if (counter == 0) { cout << "There is no projects yet \n\n"; }
	else {
		for (int i = 0; i < counter; i++) {
			cout << "ID : " << pro[i].ID << endl;
			cout << "Title : " << pro[i].title << endl;
			cout << "Start Date : " << pro[i].startDate.day << "/" << pro[i].startDate.month << "/" << pro[i].startDate.year << endl;
			cout << "End Date : " << pro[i].endDate.day << "/" << pro[i].endDate.month << "/" << pro[i].endDate.year << endl;
			cout << "Brief : " << pro[i].brief << endl;
			cout << "______________________________________________________________\n";
		}
	}
}
//News
void add_news() {
	system("CLS");
	Logo_display();
	if (counter == 0) { cout << "\n\nThere is no projects to Add news to \n" << endl; }
	else {
		cout << "\n\nEnter Title \n";
		cin.ignore(1000, '\n');
		getline(cin, ns[counter2].title);
		cout << "Enter Brief \n";
		getline(cin, ns[counter2].brief);
		cout << "Enter Publishing Date \n";
		bool S_pub_E;
		do {
			S_pub_E = false;
			cout << "Enter day: ";
			cin >> ns[counter2].publishDate.day;
			while (ns[counter2].publishDate.day > 31 || ns[counter2].publishDate.day < 1) {
				cout << "Invalid Value..please enter again" << endl;
				cin >> ns[counter2].publishDate.day;
				hold_chars();
			}
			cout << "Enter month: ";
			cin >> ns[counter2].publishDate.month;
			while (ns[counter2].publishDate.month > 12 || ns[counter2].publishDate.month < 1) {
				cout << "Invalid Value..please enter again" << endl;
				cin >> ns[counter2].publishDate.month;
				hold_chars();
			}
			cout << "Enter year: ";
			cin >> ns[counter2].publishDate.year;
			while (ns[counter2].publishDate.year < 1) {
				cout << " Invalid Value..please enter again" << endl;
				cin >> ns[counter2].publishDate.year;
				hold_chars();
			}
			cout << "______________________________________________________________\n";
			cout << "Projects IDs:" << endl;
			for (int i = 0; i < counter; i++) { cout << "ID: " << pro[i].ID << endl; }
			cout << "______________________________________________________________\n";
			int choiceID;
			cout << "Enter ID number to add to project: ";
			cin >> choiceID;
			while (choiceID > counter || choiceID < 1) {
				cout << "This ID doesn't exist..please enter another ID: ";
				cin >> choiceID;
				hold_chars();
			}
			if (ns[counter2].publishDate.year < pro[choiceID - 1].startDate.year) { S_pub_E = true; }
			else if (ns[counter2].publishDate.year == pro[choiceID - 1].startDate.year) {
				if (ns[counter2].publishDate.month < pro[choiceID - 1].startDate.month) { S_pub_E = true; }
				else if (ns[counter2].publishDate.month == pro[choiceID - 1].startDate.month) {
					if (ns[counter2].publishDate.day < pro[choiceID - 1].startDate.day) { S_pub_E = true; }
				}
			}
			if (ns[counter2].publishDate.year > pro[choiceID - 1].endDate.year) { S_pub_E = true; }
			else if (ns[counter2].publishDate.year == pro[choiceID - 1].endDate.year) {
				if (ns[counter2].publishDate.month > pro[choiceID - 1].endDate.month) { S_pub_E = true; }
				else if (ns[counter2].publishDate.month == pro[choiceID - 1].endDate.month) {
					if (ns[counter2].publishDate.day > pro[choiceID - 1].endDate.day) { S_pub_E = true; }
				}
			}
			if (S_pub_E) {
				cout << "\nPublishing date must be between Start date and End date as..\n";
				cout << "Start Date is " << pro[choiceID - 1].startDate.day << "/" << pro[choiceID - 1].startDate.month << "/" << pro[choiceID - 1].startDate.year << endl;
				cout << "End Date is " << pro[choiceID - 1].endDate.day << "/" << pro[choiceID - 1].endDate.month << "/" << pro[choiceID - 1].endDate.year << endl;
				cout << "Please enter another publishing date\n\n";
			}
			else {
				ns[counter2].ID = pro[choiceID - 1].ID;
				ns[counter2].pro_Title = pro[choiceID - 1].title;
				news_save();
			}
		} while (S_pub_E);
		counter2++;
	}
}

void display_news() {
	system("CLS");
	Logo_display();
	cout << "\n\n";
	if (counter == 0) { cout << "There is no projects yet \n\n"; }
	else if (counter2 == 0) { cout << "There is no news yet \n\n"; }
	else {
		for (int i = 0; i < counter2; i++) {
			bool repeated_projects = true;
			for (int j = 0; j < counter2; j++) {
				if (pro[i].ID == ns[j].ID) {
					if (repeated_projects) {
						cout << "Project ID: " << ns[j].ID << endl;
						cout << "Project Title: " << ns[j].pro_Title << "\n\n";
					}
					cout << "title: " << ns[j].title << endl;
					cout << "publishing date: " << ns[j].publishDate.day << "/" << ns[j].publishDate.month << "/" << ns[j].publishDate.year << endl;
					cout << "brief: " << ns[j].brief << endl << endl;
					repeated_projects = false;
				}
			}
			if (!repeated_projects) { cout << "______________________________________________________________\n"; }
		}
	}
}
//Filters
void filter_startDate() {
	system("CLS");
	Logo_display();
	cout << "\n\n";
	if (counter == 0) { cout << "\n\nThere is no projects yet \n\n"; }
	else {
		Date Filteration;
		bool no_project = true;
		cout << "Enter Start Date For Projects That you want to display" << endl;
		cout << "\nEnter day\n";
		cin >> Filteration.day;
		while (Filteration.day > 31 || Filteration.day < 1) {
			cout << " Invalid Value..please enter again" << endl;
			cin >> Filteration.day;
			hold_chars();
		}
		cout << "\nEnter month\n";
		cin >> Filteration.month;
		while (Filteration.month > 12 || Filteration.month < 1) {
			cout << " Invalid Value..please enter again" << endl;
			cin >> Filteration.month;
			hold_chars();
		}
		cout << "\nEnter Year\n";
		cin >> Filteration.year;
		while (Filteration.year < 1) {
			cout << " Invalid Value..please enter again" << endl;
			cin >> Filteration.year;
			hold_chars();
		}
		for (int i = 0; i < counter; i++) {
			bool view = true;
			if (pro[i].startDate.year < Filteration.year) { view = false; }
			else if (pro[i].startDate.year == Filteration.year) {
				if (pro[i].startDate.month < Filteration.month) { view = false; }
				else if (pro[i].startDate.month == Filteration.month) {
					if (pro[i].startDate.day < Filteration.day) { view = false; }
				}
			}
			cout << endl;
			if (view) {
				cout << "Id : " << pro[i].ID << endl;
				cout << "Title is : " << pro[i].title << endl;
				cout << "start Date : " << pro[i].startDate.day << "/" << pro[i].startDate.month << "/" << pro[i].startDate.year << endl;
				cout << "End Date : " << pro[i].endDate.day << "/" << pro[i].endDate.month << "/" << pro[i].endDate.year << endl;
				cout << "Brief : " << pro[i].brief << endl;
				cout << "______________________________________________________________\n";
				no_project = false;
			}
		}
		if (no_project) { cout << "Sorry There Is NO Projects Start From Date You Entered" << endl; }
	}
}

void filter_endDate() {
	system("CLS");
	Logo_display();
	cout << "\n\n";
	if (counter == 0) { cout << "There is no projects yet \n\n"; }
	else {
		Date Filteration;
		bool no_project = true;
		cout << "Enter End Date For Projects That you want to display" << endl;
		cout << "\nEnter day\n";
		cin >> Filteration.day;
		while (Filteration.day > 31 || Filteration.day < 1) {
			cout << " Invalid Value..please enter again" << endl;
			cin >> Filteration.day;
			hold_chars();
		}
		cout << "\nEnter month\n";
		cin >> Filteration.month;
		while (Filteration.month > 12 || Filteration.month < 1) {
			cout << " Invalid Value..please enter again" << endl;
			cin >> Filteration.month;
			hold_chars();
		}
		cout << "\nEnter year\n";
		cin >> Filteration.year;
		while (Filteration.year < 1) {
			cout << " Invalid Value..please enter again" << endl;
			cin >> Filteration.year;
			hold_chars();
		}
		for (int i = 0; i < counter; i++) {
			bool view = true;
			if (pro[i].endDate.year > Filteration.year) { view = false; }
			else if (pro[i].endDate.year == Filteration.year) {
				if (pro[i].endDate.month > Filteration.month) { view = false; }
				else if (pro[i].endDate.month == Filteration.month) {
					if (pro[i].endDate.day > Filteration.day) { view = false; }
				}
			}
			cout << endl;
			if (view) {
				cout << "Id : " << pro[i].ID << endl;
				cout << "Title is : " << pro[i].title << endl;
				cout << "start Date : " << pro[i].startDate.day << "/" << pro[i].startDate.month << "/" << pro[i].startDate.year << endl;
				cout << "End Date : " << pro[i].endDate.day << "/" << pro[i].endDate.month << "/" << pro[i].endDate.year << endl;
				cout << "Brief : " << pro[i].brief << endl;
				cout << "______________________________________________________________\n";
				no_project = false;
			}
		}
		if (no_project) { cout << "Sorry There Is NO Projects Start From Date You Entered" << endl; }
	}
}

void filter_ID() {
	system("CLS");
	Logo_display();
	cout << "\n\n";
	int find_ID;
	if (counter == 0) { cout << "There is no projects yet\n" << endl; }
	else if (counter2 == 0) { cout << "There is no news yet\n" << endl; }
	else {
		for (int i = 0; i < counter2; i++) {
			bool repeated_projects = true;
			for (int j = 0; j < counter2; j++) {
				if (pro[i].ID == ns[j].ID && repeated_projects) {
					cout << "ID: " << ns[j].ID << endl;
					cout << "Title: " << ns[j].pro_Title << endl;
					cout << "______________________________________________________________\n";
					repeated_projects = false;
				}
			}
		}
		cout << "Enter project ID ";
		cin >> find_ID;
		while (find_ID < 1) {
			cout << "Invalid Value..please enter again" << endl;
			cin >> find_ID;
			hold_chars();
		}
		system("CLS");
		Logo_display();
		cout << "\n\n";
		bool no_news = true;
		for (int i = 0; i < counter2; i++) {
			if (find_ID == ns[i].ID) {
				if (no_news) {
					cout << "Project ID: " << ns[i].ID << endl << endl;
				}
				cout << "News Title: " << ns[i].title << endl;
				cout << "Publishing Date: " << ns[i].publishDate.day << "/" << ns[i].publishDate.month << "/" << ns[i].publishDate.year << endl;
				cout << "News Brief :" << ns[i].brief << endl << endl;
				no_news = false;
			}
		}
		if (find_ID > counter + 1) { cout << "There is no projects with that ID \n\n"; }
		else if (no_news) { cout << "There is no news for this project \n\n"; }
	}
}

void filter_title() {
	system("CLS");
	Logo_display();
	cout << "\n\n";
	if (counter == 0) { cout << "There is no projects yet\n\n" << endl; }
	else if (counter2 == 0) { cout << "There is no news yet\n\n" << endl; }
	else {
		bool no_news = true;
		cout << "Enter project title: ";
		string find_word;
		cin.ignore(1000, '\n');
		getline(cin, find_word);
		cout << endl;
		for (int i = 0; i < counter2; i++) {
			bool repeated_pros = true;
			for (int j = 0; j < counter2; j++) {
				if (ns[j].pro_Title.find(find_word) != -1 && ns[j].ID == i + 1) {
					if (repeated_pros) {
						cout << "Project ID: " << ns[j].ID << endl;
						cout << "Project title: " << ns[j].pro_Title << "\n\n";
					}
					cout << "News Title: " << ns[j].title << endl;
					cout << "Publishing Date: " << ns[j].publishDate.day << "/" << ns[j].publishDate.month << "/" << ns[j].publishDate.year << endl;
					cout << "Brief :" << ns[j].brief << "\n\n";
					no_news = false;
					repeated_pros = false;
				}
			}
			if (!repeated_pros) { cout << "______________________________________________________________\n"; }
		}
		if (no_news) { cout << "There is no projects with that title" << endl; }
	}
}
//View functions
void main_view() {
	system("CLS");
	Logo_display();
	cout << endl << endl;
	cout << "1 - Project options" << endl;
	cout << "2 - News options" << endl;
	cout << "3 - Close" << endl;
}

void project_options() {
	system("CLS");
	Logo_display();
	cout << "\n\n";
	cout << "1 - Add project" << endl;
	cout << "2 - Display all projects" << endl;
	cout << "3 - Filter projects" << endl;
	cout << "4 - Back" << endl;
}

void news_options() {
	system("CLS");
	Logo_display();
	cout << "\n\n";
	cout << "1 - Add news" << endl;
	cout << "2 - Display all news" << endl;
	cout << "3 - Filter news" << endl;
	cout << "4 - Back" << endl;
}

void filter_projects() {
	system("CLS");
	Logo_display();
	cout << "\n\n";
	if (counter == 0) { ; choice = 1; }
	else {
		cout << "1 - Filter with start date" << endl;
		cout << "2 - Filter with end date" << endl;
		cout << "3 - Back" << endl;
	}
}

void filter_news() {
	system("CLS");
	Logo_display();
	cout << "\n\n";
	if (counter == 0 || counter2 == 0) { choice = 1; }
	else {
		cout << "1 - Filter with project ID" << endl;
		cout << "2 - Filter with project title" << endl;
		cout << "3 - Back" << endl;
	}
}

void Logo_display() {
	system("CLS");
	for (int i = 0; i < 62; i++) {
		if (i == 0) { cout << "\t"; }
		if (i == 30) { cout << "\n\n\t\t\tCompany Profile Project\n\n"; }
		else if (i == 31) { cout << "\t"; }
		else { cout << " " << char(4); }
	}
}
//Bugs functions
void hold_chars() {
	if (cin.fail()) {
		string choice_char;
		cin.clear();
		cin >> choice_char;
	}
}

int choice_three(int choice) {
	cin >> choice;
	while (choice != 1 && choice != 2 && choice != 3) {
		cout << "please enter 1, 2 or 3: " << endl;
		cin >> choice;
		hold_chars();
	}
	return choice;
}

int choice_four(int choice) {
	cin >> choice;
	while (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
		cout << "please enter 1, 2, 3 or 4: " << endl;
		cin >> choice;
		hold_chars();
	}
	return choice;
}

//Read data functions
void files_pro() {
	ifstream data_project;
	data_project.open("projects data.txt");
	while (!data_project.eof()) {
		getline(data_project, pro[counter].title);
		getline(data_project, pro[counter].brief);
		data_project >> pro[counter].ID;
		data_project >> pro[counter].startDate.day;
		data_project >> pro[counter].startDate.month;
		data_project >> pro[counter].startDate.year;
		data_project >> pro[counter].endDate.day;
		data_project >> pro[counter].endDate.month;
		data_project >> pro[counter].endDate.year;
		if (pro[counter].endDate.year == 0) { break; }
		counter++;
		getline(data_project, pro[counter].title);
	}
};

void files_news() {
	ifstream data_news;
	data_news.open("news data.txt");
	while (!data_news.eof()) {
		getline(data_news, ns[counter2].title);
		getline(data_news, ns[counter2].brief);
		data_news >> ns[counter2].publishDate.day;
		data_news >> ns[counter2].publishDate.month;
		data_news >> ns[counter2].publishDate.year;
		data_news >> ns[counter2].ID;
		getline(data_news, ns[counter2].pro_Title);
		getline(data_news, ns[counter2].pro_Title);
		if (ns[counter2].publishDate.year == 0) { break; }
		counter2++;
	}
};

//Save data
void pro_save() {
	ofstream data_project;
	data_project.open("projects data.txt", ios::in | ios::out | ios::app);
	data_project << pro[counter].title << endl;
	data_project << pro[counter].brief << endl;
	data_project << pro[counter].ID << endl;
	data_project << pro[counter].startDate.day << endl;
	data_project << pro[counter].startDate.month << endl;
	data_project << pro[counter].startDate.year << endl;
	data_project << pro[counter].endDate.day << endl;
	data_project << pro[counter].endDate.month << endl;
	data_project << pro[counter].endDate.year << endl;
	data_project.close();
}

void news_save() {
	ofstream data_news;
	data_news.open("news data.txt", ios::in | ios::out | ios::app);
	data_news << ns[counter2].title << endl;
	data_news << ns[counter2].brief << endl;
	data_news << ns[counter2].publishDate.day << endl;
	data_news << ns[counter2].publishDate.month << endl;
	data_news << ns[counter2].publishDate.year << endl;
	data_news << ns[counter2].ID << endl;
	data_news << ns[counter2].pro_Title << endl;
	data_news.close();
}
