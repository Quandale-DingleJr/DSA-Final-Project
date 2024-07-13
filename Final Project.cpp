#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>

using namespace std;

class Book{
	private://data
		vector<int> bookID;
		vector<int> nofCopies;
		vector<string> bookTitle;
		vector<string> author;
		vector<string> genre;
	
	public:
			int id = bookID.size() + 1;
			int copies;
			string title, auth, genr;
		
		//function to add a book
		void insertBook(){
			int id = bookID.size() + 1;
			int copies;
			string title, auth, genr;
			
			//clear screen
			system("cls");
			cout << "Adding a Book\n";
			
			cout << "Book ID:\t" << id;
			bookID.push_back(id);
			cin.ignore();
			
			cout << "\nBook Title:\t";
			getline(cin, title);
			bookTitle.push_back(title);
			
			cout << "Author:\t\t";
			getline(cin, auth);
			author.push_back(auth);
			
			cout << "Genre:\t\t";
			getline(cin, genr);
			genre.push_back(genr);
			
			cout << "No. Of Copies:\t";
			cin >> copies;
			nofCopies.push_back(copies);
			cin.ignore();
		}
		//function to rent a book
		void rentBook(){
			int id;
			char choice;
			
			system ("cls");
			do{
				cout << "Rent a Book\n";
				cout << "Book ID:\t\t";
				cin >> id;
				
				bool found = false;
				
				for(size_t i = 0; i < bookID.size(); i++){
					if(id == bookID[i]){
						if(nofCopies[i] <= 0){
							cout << "No more Copies Remaining of Book: " << bookTitle[i] << endl;
							break;
						}
						else{
							cout << "Book Title:\t\t" << bookTitle[i] << endl;
							cout << "Copies Remaining:\t" << --nofCopies[i] << endl;
						
							found = true;
							break;
						}
					}
				}
				if(!found){
					cout << "Book not Found...";
				}
				cout << "Rent another book?(Y/N): ";
				cin >> choice;
				cout << endl;
				
			}while(choice == 'Y' || choice == 'y');
		}
		void returnBook() {
            int id;
            cout << "Book ID:\t";
            cin >> id;

            bool found = false;
            system ("cls");

            for (size_t i = 0; i < bookID.size(); i++) {
                if (id == bookID[i]) {
                    found = true;
                    if (nofCopies[i] > 0) {
                        nofCopies[i]++;
                        cout << "Book returned successfully.\n";
                    } else {
                        cout << "All copies of this book are already returned.\n";
                    }
                    break;
                }
            }

            if (!found) {
                cout << "Book ID not found.\n";
            }
        }
   	 	void showBookDetails() {
   	 		system ("cls");
            int id;
            cout << "Book ID:\t";
            cin >> id;

            bool found = false;

            for (size_t i = 0; i < bookID.size(); i++) {
                if (id == bookID[i]) {
                    cout << "Book ID:\t" << bookID[i] << endl;
                    cout << "Book Title:\t" << bookTitle[i] << endl;
                    cout << "Author:\t" << author[i] << endl;
                    cout << "Genre:\t" << genre[i] << endl;
                    cout << "Number of Copies:\t" << nofCopies[i] << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Book not found." << endl;
            }
        }
        void displayBooks() {
        	system ("cls");
            cout << "\nBooks in the library:\n";
            cout << "ID\tTitle\tAuthor\tGenre\tCopies\n";

            for (size_t i = 0; i < bookID.size(); ++i) {
                cout << bookID[i] << "\t" << bookTitle[i] << "\t" << author[i] << "\t" << genre[i] << "\t" << nofCopies[i] << "\n";
            }
        }
   	 	void menu(){
   	 		cout  << "[1] New Book\n";
   	 		cout  << "[2] Rent a Book\n";
   	 		cout  << "[3] Return a Book\n";
   	 		cout  << "[4] Show Book Details\n";
   	 		cout  << "[5] Display all Books\n";
   	 		cout  << "[6] Check Book Availability\n";
   	 		cout  << "[7] Customer Maintenance\n";
   	 		cout  << "\t[1] Add New Customer\n";
   	 		cout  << "\t[2] Show Customer Details\n";
   	 		cout  << "\t[3] List of Videos Rented by a Customer\n";
   	 		cout  << "[8] Exit Program\n";
   	 		cout  << "Enter Your Choice: ";
			}
};
		
		int main(){
			Book library;
			int choice;
			char answer;
			do{
				system ("cls");
				library.menu();
				cin >> choice;
				
				switch (choice){
					case 1: 
						library.insertBook();
						break;
						
					case 2: 
						library.rentBook();
						break;
					
					case 3:
						library.returnBook();
						break;
					
					case 4:
						library.showBookDetails();
						break;
					
					case 5:
						library.displayBooks();
						break;
					
					case 6:
						
						
						
					case 8:
						cout << "Exit Program? (Y/N): ";
						cin >> answer;
						return 0;
						
					default:
						cout << "Invalid Input...";
				}
			}while(answer != 'N' || answer != 'n');
		}
		
		
		
		
		
		
		
		