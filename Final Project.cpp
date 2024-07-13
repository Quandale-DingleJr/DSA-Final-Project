#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Book{
	private://data
		vector<int> bookID;
		vector<int> nofCopies;
		vector<string> bookTitle;
		vector<string> author;
		vector<string> genre;
	
	public:
		//no constructor
		void insertBook(){
			int id = bookID.size() + 1;
			int copies;
			string title, auth, genr;
			
			cout << "Book ID:\t" << id << endl;
			bookID.push_back(id);
			
			cout << "Book Title:\t";
			cin.ignore();
			getline(cin, title);
			bookTitle.push_back(title);
			
			cout << "Author:\t";
			getline(cin, auth);
			author.push_back(auth);
			
			cout << "Genre:\t";
			getline(cin, genr);
			genre.push_back(genr);
			
			cout << "No. Of Copies:\t";
			cin >> copies;
			nofCopies.push_back(copies);
			cin.ignore();
			}
			
		void rentBook(){
			int id;
			char choice;
			
			do{
				cout << "Book ID:\t";
				cin >> id;
				
				bool found = false;
				
				for(size_t i = 0; i < bookID.size(); i++){
					if(id == bookID[i]){
						cout << "Book Title:\t" << bookTitle[i] << endl;
						cout << "Number of Copies:\t" << nofCopies[i] << endl;
						found = true;
						break;
					}
				}
				if(!found){
					cout << "Book not Found...";
				}
				cout << "Rent another book?(Y/N): ";
				cin >> choice;
			}while(choice == 'Y' || choice == 'y');
		}
		
		void returnBook() {
      	 		 int id;
       			 cout << "Book ID:\t";
        		 cin >> id;

      			  vector<int>::iterator itID = bookID.begin();
      			  vector<int>::iterator itCopies = nofCopies.begin();
        		  bool found = false;

      		 	 while (itID != bookID.end()) {
           	 		if (*itID == id) {
               		 	found = true;
              	 	 	(*itCopies)++;
              		  	cout << "Book returned successfully.\n";
              	 	 	break;
          	  		}
          	 	 ++itID;
         	  	 ++itCopies;
       		 	}
	
      		  if (!found) {
      		      cout << "Book ID not found.\n";
      		  }
   	 	}
			
		void showBookDetails() {
			}
		void displayBooks(){
		}
			int main(){

	
}