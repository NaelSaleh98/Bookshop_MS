//////////////////////////
// INCLUDE HEADER FILES //
/////////////////////////
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

///////////////////////
// CLASS DECLARATION //
///////////////////////
class Book {
	private : 
		string name , author;
		int noc;
	public :
		Book(string name = "" , string author = "" , int noc = 0){
			this->name = name;
			this->author = author;
			this->noc = noc;
		}
		void setname (string name){
			this->name = name;
		}
		void setauthor (string author){
			this->author = author;
		}
		void setnoc (int noc){
			this->noc = noc;
		}
		string getname (){
			return this->name;
		}
		string getauthor (){
			return this->author;
		}
		int getnoc (){
			return this->noc;
		}
};

