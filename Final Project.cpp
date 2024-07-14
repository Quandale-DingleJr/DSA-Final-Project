#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Book{
	private://data
		vector<int> bookID;
		vector<int> nofCopies;
		vector<int> initialCopies; //vector to monitor the initial number of copies of a book
		vector<string> bookTitle;
		vector<string> author;
		vector<string> genre;
		int id;
		
	public:
		//constructor
		Book(){
			loadFromFile("library.txt");
			if(bookID.empty()) {
				id = 0;
			}
			else {
				id = bookID.back();
			}
		}
		//function to add a book
		void insertBook(){
			int copies;
			string title, auth, genr;
			
			//clear screen
			system("cls");
			cout << "Adding a Book\n";
			
			cout << "Book ID:\t" << ++id;
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
			if(copies <= 0){		//makes sure that the number of copies is not less than or equal to zero
				while(copies <= 0){
					cout << "Number of Copies must be Greater than 0.\n";
					cout << "No. Of Copies:\t";
					cin >> copies;
				}
			}
			nofCopies.push_back(copies);
			initialCopies.push_back(copies);
			cin.ignore();
			cout << endl;
		}
		//function to rent a book
		void rentBook(){
			char choice;
			bool found = false;
			
			system ("cls");
			cout << "Renting a Book\n";
			//checks if the library is empty
			if(bookID.empty()){
				cout << "Library is Empty.\n\n";
			}
			else{
				//loop to allow multiple instances of renting
				do{
				cout << "Book ID:\t\t";		//prompt the user to input a book ID
				cin >> id;
				
				for(int i = 0; i < bookID.size(); i++){
					if(id == bookID[i]){		//loops and finds the matching bookID
						found = true;		//a mark to tell that the bookID has been found
						if(nofCopies[i] == 0){		//checks if the number of copies of the book is zero
							cout << "No more Copies Remaining of Book: " << bookTitle[i] << endl;
						}
						else{
							cout << "Book Title:\t\t" << bookTitle[i] << endl;
							cout << "Copies Remaining:\t" << --nofCopies[i] << endl;
						}
						break;		//to break out of the loop once the id matches with bookID
					}
				}
				if(!found){		//if the inputed id did not match bookID
					cout << "Book not Found...\n";
				}
				cout << "Rent another book?(Y/N): ";
				cin >> choice;
				cout << endl;
				}while(choice == 'Y' || choice == 'y');
			}
		}
		//function to return a book
		//////////
		////////// DI PA TAPOS RETURNBOOK
		//////////
		void returnBook() {
			bool found = false;
			
            system ("cls");
            cout << "Returning a Book\n";
            if(bookID.empty()){
            	cout << "Library is Empty.\n\n";
			}
			else{
            	cout << "Book ID:\t";
            	cin >> id;

            	for(int i = 0; i < bookID.size(); i++){
                	if(id == bookID[i]){
                    	found = true;
                    	if(nofCopies[i] < initialCopies[i]){		//if the current number of copies is less than the initial number of copies 
                        	nofCopies[i]++;
                        	cout << "Book returned successfully.\n\n";
                    	} 
						else{		//if the current number of copies is equal to initial number of copies
                        	cout << "All copies of this book are already returned.\n\n";
                    	}
                    	break;
                	}
           		}
            	if (!found) {
                	cout << "Book ID not found.\n\n";
            	}
			} 
        }
        //function to show the selected book its details
   	 	void showBookDetails(){
   	 		bool found = false;
   	 		
        	system ("cls");
        	cout << "Showing Book Details\n";
            if(bookID.empty()){
            	cout << "Library is Empty.\n\n";
			}
			else{
				cout << "Book ID:\t";
            	cin >> id;
            	
            	for(int i = 0; i < bookID.size(); i++){
                	if (id == bookID[i]){
                		found = true;
                		system ("cls");
                		cout << "Showing Book Details\n";
                    	cout << "Book ID:\t\t" << bookID[i] << endl;
                    	cout << "Book Title:\t\t" << bookTitle[i] << endl;
                    	cout << "Author:\t\t\t" << author[i] << endl;
                    	cout << "Genre:\t\t\t" << genre[i] << endl;
                    	cout << "Number of Copies:\t" << nofCopies[i] << endl << endl;
                    	break;
                	}
            	}
            	if(!found){
                	cout << "Book not found.\n\n" << endl;
            	}
			} 
    	}
    	//function to display all books
        void displayBooks(){
        	system ("cls");
        	cout << "Books in the library:\n";
        	
        	if(bookID.empty()){
        		cout << "Library is Empty.\n\n";
			}
			else{
				cout << "ID\tTitle\t\t\tAuthor\t\tGenre\t\tCopies\n";
            	for(int i = 0; i < bookID.size(); i++){
                	cout << bookID[i] << "\t" << bookTitle[i] << "\t\t" << author[i] << "\t" << genre[i] << "\t\t" << nofCopies[i] << endl;
            }
            cout << endl;
			}
        }
        //function to check a book's availability
        void checkAvailability(){
        	bool found = false;
        	
        	system ("cls");
        	cout << "Showing Book Availability\n";
            if(bookID.empty()){
            	cout << "Library is Empty.\n\n";
			}
			else{
				cout << "Book ID:\t";
            	cin >> id;
            	
            	for(int i = 0; i < bookID.size(); i++){
                	if(id == bookID[i]){
                		found = true;
                		system ("cls");
                		cout << "Showing Book Details\n";
                    	cout << "Book ID:\t\t" << bookID[i] << endl;
                    	cout << "Book Title:\t\t" << bookTitle[i] << endl;
                    	cout << "Author:\t\t\t" << author[i] << endl;
                    	cout << "Genre:\t\t\t" << genre[i] << endl;
                    	cout << "Number of Copies:\t" << nofCopies[i] << endl;
                    	cout << "Availability:\t\t";
                    	if(nofCopies[i] == 0){
                    		cout << "Unavailable\n\n";
						}
						else{
							cout << "Available\n\n";
						}
                    	break;
                	}
            	}
            	if(!found){
                	cout << "Book not found.\n\n" << endl;
            	}
			} 
		}
		//function to save data to a text file
		void saveToFile(const string& filename){
            ofstream outFile(filename);
            if(outFile.is_open()){
                for (int i = 0; i < bookID.size(); i++) {
                    outFile << bookID[i] << "\n"
                            << bookTitle[i] << "\n"
                            << author[i] << "\n"
                            << genre[i] << "\n"
                            << nofCopies[i] << "\n";
                }
                outFile.close();
            }
			else{
                cout << "Unable to open file for writing." << endl;
            }
        }
        // Function to load data from file
        void loadFromFile(const string& filename){
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
                
                while(inFile >> id){
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
            }
			else{
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
						cout << "Invalid Input...\n";
				}
			}while(answer != 'Y' && answer != 'y');
			
			library.saveToFile("library.txt");
			cout << "Saving Data...\n";
			cout << "Exiting Program...";
			return 0;
		}