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
		vector<int> initialCopies;
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
			initialCopies.push_back(copies);
			cin.ignore();
			cout << endl;
		}
		//function to rent a book
		void rentBook(){
			int id;
			char choice;
			
			system ("cls");
			do{
				cout << "Renting a Book\n";
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
						if(!found){
						cout << "Book not Found...";
					}
				}
				
				}
				cout << "Rent another book?(Y/N): ";
				cin >> choice;
				cout << endl;
				
			}while(choice == 'Y' || choice == 'y');
		}
		void returnBook() {
            int id;
            
            system ("cls");
            cout << "Returning a Book\n";
            cout << "Book ID:\t";
            cin >> id;

            bool found = false;

            for (size_t i = 0; i < bookID.size(); i++) {
                if (id == bookID[i]) {
                    found = true;
                    if (nofCopies[i] < initialCopies[i]){
                        nofCopies[i]++;
                        cout << "Book returned successfully.\n\n";
                    } 
					else {
                        cout << "All copies of this book are already returned.\n\n";
                    }
                    break;
                }
            }
            if (!found) {
                cout << "Book ID not found.\n\n";
            }
        }
   	 	void showBookDetails() {
            int id;
        	bool found = false;
        	
        	system ("cls");
        	cout << "Showing Book Details\n";
            if(bookID.size() == 0){
            	cout << "Library is Empty.\n\n";
			}
			else{
				cout << "Book ID:\t";
            	cin >> id;
            	
            	for (size_t i = 0; i < bookID.size(); i++) {
                	if (id == bookID[i]) {
                		system ("cls");
                		cout << "Showing Book Details\n";
                    	cout << "Book ID:\t\t" << bookID[i] << endl;
                    	cout << "Book Title:\t\t" << bookTitle[i] << endl;
                    	cout << "Author:\t\t\t" << author[i] << endl;
                    	cout << "Genre:\t\t\t" << genre[i] << endl;
                    	cout << "Number of Copies:\t" << nofCopies[i] << endl << endl;
                    	found = true;
                    	break;
                	}
            	}
            	if (!found) {
                	cout << "Book not found.\n\n" << endl;
            	}
			} 
    	}
        void displayBooks() {
        	system ("cls");
            cout << "Books in the library:\n";
            cout << "ID\tTitle\tAuthor\tGenre\tCopies\n";

            for (size_t i = 0; i < bookID.size(); ++i) {
                cout << bookID[i] << "\t" << bookTitle[i] << "\t" << author[i] << "\t" << genre[i] << "\t" << nofCopies[i] << "\n";
            }
            cout << endl;
        }
        void checkAvailability(){
        	int id;
        	bool found = false;
        	
        	system ("cls");
        	cout << "Showing Book Availability\n";
            if(bookID.size() == 0){
            	cout << "Library is Empty.\n\n";
			}
			else{
				cout << "Book ID:\t";
            	cin >> id;
            	
            	for (size_t i = 0; i < bookID.size(); i++) {
                	if (id == bookID[i]) {
                		system ("cls");
                		cout << "Showing Book Details\n";
                    	cout << "Book ID:\t\t" << bookID[i] << endl;
                    	cout << "Book Title:\t\t" << bookTitle[i] << endl;
                    	cout << "Author:\t\t\t" << author[i] << endl;
                    	cout << "Genre:\t\t\t" << genre[i] << endl;
                    	cout << "Number of Copies:\t" << nofCopies[i] << endl;
                    	if(nofCopies[i] == 0){
                    		cout << "Availability:\t\t" << "Available\n\n";
						}
						else{
							cout << "Availability:\t\t" << "Unavailable\n\n";
						}
                    	found = true;
                    	break;
                	}
            	}
            	if (!found) {
                	cout << "Book not found.\n\n" << endl;
            	}
			} 
		}
		void saveToFile(const string& filename) {
            ofstream outFile(filename);
            if (outFile.is_open()) {
                for (size_t i = 0; i < bookID.size(); ++i) {
                    outFile << bookID[i] << "\n"
                            << bookTitle[i] << "\n"
                            << author[i] << "\n"
                            << genre[i] << "\n"
                            << nofCopies[i] << "\n";
                }
                outFile.close();
            } else {
                cout << "Unable to open file for writing." << endl;
            }
        }
        // Function to load data from file
        void loadFromFile(const string& filename) {
            ifstream inFile(filename);
            if (inFile.is_open()) {
                bookID.clear();
                bookTitle.clear();
                author.clear();
                genre.clear();
                nofCopies.clear();
                initialCopies.clear();
                
                int id, copies;
                string title, auth, genr;
                
                while (inFile >> id) {
                    inFile.ignore(); // Ignore newline after id
                    getline(inFile, title);
                    getline(inFile, auth);
                    getline(inFile, genr);
                    inFile >> copies;
                    inFile.ignore(); // Ignore newline after copies
                    
                    bookID.push_back(id);
                    bookTitle.push_back(title);
                    author.push_back(auth);
                    genre.push_back(genr);
                    nofCopies.push_back(copies);
                    initialCopies.push_back(copies);
                }
                inFile.close();
            } else {
                cout << "Unable to open file for reading." << endl;
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
			
			library.loadFromFile("library.txt");
			int choice;
			char answer = 'N';
			
			do{
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
						library.checkAvailability();
						break;
						
					case 8:
						cout << "Exit Program? (Y/N): ";
						cin >> answer;
						cout << endl;
						break;
						
					default:
						cout << "Invalid Input...";
				}
			}while(answer != 'Y' && answer != 'y');
			
			library.saveToFile("library.txt");
			return 0;
		}
		
		
		
		
		
		
		
		