//////////////////////////
// INCLUDE HEADER FILES //
/////////////////////////

#include <cstdio>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include "book.h"
using namespace std;

////////////////////
// METHODS NEEDED //
///////////////////
void delay(double j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

void menu();
void add_Book();
void show_Book();
void check_Book();
void modify_Book();
void delete_Book();
void bey();
void wrong();
//////////
// MAIN //
/////////
int main(){
	menu();
	return 0;
}

// show main menu
void menu(){
	int choice;
	system("cls");
	system("color F0");
	cout << "\n\t\t\t\t\tBOOKSHOP MANAGEMENT SYSTEM\n" << endl;
	cout << "\t\t\t\t\t\xDD\xDD WELCOME TO MAIN MENU \xDD\xDD" << endl;
	cout << "\t\t\t\t\t1- ADD Book Record." << endl;
	cout << "\t\t\t\t\t2- SHOW Book Records." << endl;
	cout << "\t\t\t\t\t3- CHECK Availability." << endl;
	cout << "\t\t\t\t\t4- MODIFY Book Reacords." << endl;
	cout << "\t\t\t\t\t5- DELETE Book Record." << endl;
	cout << "\t\t\t\t\t6- EXIT." << endl;
	cout << "\n\n\t\t\t\t\tEnter your choice : ";
	cin >> choice ;

	switch (choice){
		case 1 : add_Book();
			break;
		case 2 : show_Book();
			break;
		case 3 : check_Book();
			break;
		case 4 : modify_Book();
			break;
		case 5 : delete_Book();
			break;
		case 6 : bey();
			break;
		default : wrong();
			break;
	}
}
void add_Book(){
	string bo ;
	int boo;
	Book addB;
	system("cls");
	system("color F1");
	cout << "\n\t\t\t\t\tBook Name : ";
	cin >> bo;
	addB.setname(bo);
	cout << "\t\t\t\t\tBook Author : ";
	cin >> bo;
	addB.setauthor(bo);
	cout << "\t\t\t\t\tCopies : ";
	cin >> boo;
	addB.setnoc(boo);
	
	ofstream outf;
	outf.open("record.dat" , ios::out | ios::app);
	outf << endl <<addB.getname() << "\t" << addB.getauthor() << "\t" << addB.getnoc();
	outf.close();
	system("cls");
	cout << "\n\t\t\t\t\tBook add successfuly \xFB";
	delay(1000000000);
	return menu();
}

void show_Book(){
	system("cls");
	system("color F2");
	string data;
	int count = 0;
	cout << "\n\t\t\t\t\tName\t\t\tAuthor\t\t\tCopies" <<endl << endl << "\t\t\t\t\t";
	ifstream inf;
	inf.open("record.dat" , ios::in);
	while(!inf.eof()){
	inf >> data;
	cout << data << "\t\t\t" ;
	count++;
	if (count == 3){
		count = 0;
		cout << endl << "\t\t\t\t\t";
	}
	}
	delay (1111111111);
	cout << endl << "\t\t\t\t\t";
	inf.close();
	system("pause");
	return menu();
}

void check_Book(){
	system("cls");
	system("color F3");
	string name,author,check ;
	int noc;
	bool find = false;
	cout << "\n\t\t\t\t\tEnter the name of the Book : ";
	cin >> check ;
	ifstream inf;
	inf.open("record.dat" , ios::in);
	while (!inf.eof()){
		inf >> name >> author >> noc ;
		if (check.compare(name) == 0){
			find = true;
			delay(1212121212);
			cout << "\n\t\t\t\t\tName : " << name <<endl;
			cout << "\t\t\t\t\tAuthor : " << author <<endl;
			cout << "\t\t\t\t\tNo. Of Copies : " << noc << endl;
			break;
		}
	}
	if (!find){
		delay(1212121212);
		cout << "\n\t\t\t\t\tThis book does not exist yet !!";
		
	}
	cout << "\n\t\t\t\t\t";
	system("pause");
	return menu();
}

void modify_Book(){
	system("cls");
	system("color F4");
	string check;
	string name , author;
	int noc;
	bool find = false;
	ifstream inf;
	ofstream outf;
	inf.open("record.dat" , ios::in);
	outf.open("temp.dat" , ios::out);
	cout << "\n\t\t\t\t\tEnter the name of the book : ";
	cin >> check;
	while (!inf.eof()){
		inf >> name >> author >> noc ; 
		if (check.compare(name) == 0){
			find = true;
			delay(1111111111);
			cout << "\n\t\t\t\t\tEnter right name : ";
			cin >> name ;
			cout << "\t\t\t\t\tEnter right author : ";
			cin >> author;
			cout << "\t\t\t\t\tEnter right no. of copies : ";
			cin >> noc;
		}
	outf << endl << name << "\t" << author << "\t" << noc;
	}
	inf.close();
	outf.close();
	inf.open("temp.dat" , ios::in);
	outf.open("record.dat" , ios::out);
	while (!inf.eof()){
		inf >> name >> author >> noc;
		outf << endl << name << "\t" << author << "\t" << noc;
	}
	remove("temp.dat");
	inf.close();
	outf.close();
	if (!find){
		delay(1111111111);
		cout <<"\n\t\t\t\t\tBook not found !!";
	}
	cout << "\n\t\t\t\t\t";
	system("pause");
	return menu();
}

void delete_Book(){
	system("cls");
	system("color F5");
	string check;
	string name , author;
	int noc;
	bool find = false;
	ifstream inf;
	ofstream outf;
	inf.open("record.dat" , ios::in);
	outf.open("temp.dat" , ios::out);
	cout << "\n\t\t\t\t\tEnter the name of the book : ";
	cin >> check;
	while (!inf.eof()){
		inf >> name >> author >> noc ; 
		if (check.compare(name) == 0){
			find = true;
			delay(1111111111);
			cout << "\n\t\t\t\t\tDeleted successfuly ";
			continue;
		}
	outf << endl << name << "\t" << author << "\t" << noc;
	}
	inf.close();
	outf.close();
	inf.open("temp.dat" , ios::in);
	outf.open("record.dat" , ios::out);
	while (!inf.eof()){
		inf >> name >> author >> noc;
		outf << endl << name << "\t" << author << "\t" << noc;
	}
	remove("temp.dat");
	inf.close();
	outf.close();
	if (!find){
		delay(1111111111);
		cout <<"\n\t\t\t\t\tBook not found !!";
	}
	cout << "\n\t\t\t\t\t";
	system("pause");
	return menu();
}

void bey(){
	system("cls");
	system("color F6");
	cout << "\n\n\t\t\t\t\t\xB0\xB0\xB1\xB1\xB2\xB2 This work done by NAEL SALEH \xB2\xB2\xB1\xB1\xB0\xB0";
	delay(1111111111);
	exit(1);
}

void wrong (){
	system("cls");
	system("color F7");
	cout << "\n\t\t\t\t\tWrong choice , try again ^_^";
	delay(1111111111);
	return menu();
}
