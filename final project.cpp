#include <iostream>
#include <fstream> 
#include <string>
using namespace std;

// Book class
struct node {
    double book_id, cost;
    string b_name, b_status, b_author, publisher;
    node* next, * pre;
};

class BookLinkedList {
private:
    node* start;

public:
    BookLinkedList() {
        start = nullptr;
    }
    
    void inputNode(node* newNode)
   {
        cout << "Enter Book's Name : ";
        cin >> newNode->b_name;
        cout << "Enter Book's ID : ";
        cin >> newNode->book_id;
        cout << "Enter Cost of Book : ";
        cin >> newNode->cost;
        cout << "Enter Author's Name : ";
        cin >> newNode->b_author;
        cout << "Enter Publisher's Name : ";
        cin >> newNode->publisher;
        newNode->b_status = "Available";
        newNode->next = nullptr;
   }

    
    	void input()
   {
        node* temp = new node;
        inputNode(temp);
        temp->pre = nullptr;

        if (start == nullptr) {
            start = temp;
        }
        else {
            node* ptr = start;
            while (ptr->next != nullptr)
                ptr = ptr->next;
            ptr->next = temp;
            temp->pre = ptr;
        }

        cout << "\n****************************************";
        cout << "\nBook has been added successfully...\n";
        cout << "****************************************\n";
    }

    void insert_first(){
    node* a = new node;
    inputNode(a);

    if (start == NULL) {
        a->next = NULL;
        a->pre = NULL;
        start = a;
    } else {
        a->next = start;
        a->pre = NULL;
        start->pre = a;
        start = a;
    }

    cout << "\n****************************************";
    cout << "\nBook has been inserted at first\n";
    cout << "****************************************\n";
   }
	void insert_any() {
        int pos;
        cout << "Enter position you want to insert : ";
        cin >> pos;

        node* temp = new node;
        inputNode(temp);

        if (pos == 1) {
            temp->next = start;
            temp->pre = nullptr;
            if (start != nullptr) {
                start->pre = temp;
            }
            start = temp;
        }
        else {
            node* cur = start;
            for (int i = 1; i < pos - 1 && cur != nullptr; i++) {
                cur = cur->next;
            }

            if (cur == nullptr) {
                cout << "Invalid position\n";
                delete temp;
                return;
            }

            temp->next = cur->next;
            temp->pre = cur;
            if (cur->next != nullptr) {
                cur->next->pre = temp;
            }
            cur->next = temp;
        }

        cout << "\n****************************************";
        cout << "\nBook has been inserted successfully...\n";
        cout << "****************************************\n";
    }

	void search()
	{
		int id;
		cout << "Enter Book ID you want to search : ";
		cin >> id;
		node *i;
		i = start;
		while (i != NULL)
		{
			if (i->book_id == id)
			{
				cout << "****************************************\n";
				cout << "****************************************\n";
				cout << "Your Requested Book has  been Found !\n";
				cout << "****************************************\n";
				cout << " Book Name : " << i->b_name << endl;
				cout << " Book's id : " << i->book_id << endl;
				cout << " Book's Author : " << i->b_author << endl;
				cout << " Book's Publisher : " << i->publisher << endl;
				cout << " Book Cost : " << i->cost << endl;
				cout << "****************************************\n";
			}
			i = i->next;
		}
	}
	
	
	void dispBook()
	{
		node *i;
		i = start;
		while (i != NULL)
		{
			cout << "****************************************\n";
			cout << "Book Name : " << i->b_name << endl;
			cout << "Book Cost : " << i->cost << endl;
			cout << "Book ID : " << i->book_id << endl;
			cout << "Book's Author : " << i->b_author << endl;
			cout << "Book Publisher : " << i->publisher << endl;
			cout << "****************************************\n";
			i = i->next;
		}
	}
	void delbook() //delete book by id//
	{
		int id;
		cout << "Enter Book's Id you want to delete : ";
		cin >> id;
		node *temp, *ptr;
		if (start->book_id == id)
		{
			temp = start;
			start = start->next;
			start->pre = NULL;
			delete temp;
			cout << "\n****************************************";
			cout << "\nBook's Details has been deleted...\n";
			cout << "****************************************\n";
			return;
		}
		ptr = start;
		while (ptr->next->next != NULL)
		{
			if (ptr->next->book_id == id)
			{
				temp = ptr->next;
				ptr->next = temp->next;
				temp->next->pre = ptr;
				delete temp;
				cout << "\n****************************************";
				cout << "\nBook's Details has been deleted...\n";
				cout << "****************************************\n";
				return;
			}
			ptr = ptr->next;
		}
		if (ptr->next->book_id == id)
		{
			temp = ptr->next;
			delete temp;
			ptr->next = NULL;
			cout << "\n****************************************";
			cout << "\nBook's Details has been deleted...\n";
			cout << "****************************************\n";
			return;
		}
	}
	void del_first()	//delete book at first//
	{
		node *ptr = new node;
		ptr = start;
		start = start->next;
		start->pre = NULL;
		delete ptr;
		cout << "\n****************************************\n";
		cout << "Book has been deleted at first\n";
		cout << "****************************************\n";
	}
	void del_any(){
    int pos;
    cout << "Enter position you want to delete book : ";
    cin >> pos;

    if (start == nullptr)
    {
        cout << "List is empty. Cannot delete from an empty list.\n";
        return;
    }

    node *prev = nullptr;
    node *cur = start;

    // Traverse 
    for (int i = 1; i < pos && cur != nullptr; i++)
    {
        prev = cur;
        cur = cur->next;
    }

    if (cur == nullptr)
    {
        cout << "Invalid position. Cannot delete.\n";
        return;
    }

    
    if (prev != nullptr)
    {
        prev->next = cur->next;
    }
    else
    {
        
        start = cur->next;
    }

    if (cur->next != nullptr)
    {
        cur->next->pre = prev;
    }

    
    delete cur;

    cout << "\n****************************************\n";
    cout << "Book has been deleted successfully...\n";
    cout << "****************************************\n";
}

	void del_last(){
    if (start == NULL)
    {
        cout << "List is empty. Cannot delete from an empty list.\n";
        return;
    }

    if (start->next == NULL)
    {
        
        delete start;
        start = NULL;
    }
    else
    {
        node *prev = NULL;
        node *cur = start;

        while (cur->next != NULL)
        {
            prev = cur;
            cur = cur->next;
        }

        prev->next = NULL;
        delete cur;
    }

    cout << "\n****************************************\n";
    cout << "Book has been deleted at last\n";
    cout << "****************************************\n";
}
	void count()
	{
		node *ptr;
		int count = 0;
		ptr = start;
		while (ptr != NULL)
		{
			count++;
			ptr = ptr->next;
		}
		cout << "\n*************************************\n";
		cout << "There are " << count << " books";
		cout << "\n*************************************\n";
	}
	void update()
	{
		int id;
		cout << "Enter Book id you want to update : ";
		cin >> id;
		node *i;
		i = start;
		while (i != NULL)
		{
			if (i->book_id == id)
			{
				cout << "\n****************************************\n";
				cout << "Book has been found you can update now..\n";
				cout << "****************************************\n";
				cout << "Update Book's Name : ";
				cin >> i->b_name;
				cout << "Update Book's ID : ";
				cin >> i->book_id;
				cout << "Update Cost of Book : ";
				cin >> i->cost;
				cout << "Update Author's Name : ";
				cin >> i->b_author;
				cout << "Update Publisher's Name : ";
				cin >> i->publisher;
				cout << "\n**************************************\n";
			}
			i = i->next;
		}
		cout << "\n****************************************************\n";
		cout << "Your requested book has been updated successfully...\n";
		cout << "****************************************************\n";
	}
	void sort()
	{
		node *i;
		i = start;
		while (i != NULL)
		{
			node *j;
			j = i->next;
			while (j != NULL)
			{
				if (i->book_id > j->book_id)
				{
					swap(i->book_id,j->book_id);
					swap(i->b_author, j->b_author);
					swap(i->b_name, j->b_name);
					swap(i->cost, j->cost);
					swap(i->publisher, j->publisher);
				}
				j = j->next;
			}
			i = i->next;
		}
		cout << "\n*************************************\n";
		cout << " Books has been sorted successfully...\n";
		cout << "\n*************************************\n";
	}
	void traverse()
	{
		node *s1, *s2;
		s1 = start;
		s2 = s1->next;
		s1->next = NULL;
		s1->pre = s2;
		while (s2 != NULL)
		{
			s2->pre = s2->next;
			s2->next = s1;
			s1 = s2;
			s2 = s2->pre;
		}
		start = s1;
		cout << "\n*************************************\n";
		cout << " Books has been Reversed successfully...";
		cout << "\n*************************************\n";
	}
	
	void saveToFile(const string& filename) {
        ofstream outFile(filename);

        if (!outFile.is_open()) {
            cout << "Error opening file for writing." << endl;
            return;
        }

        node* current = start;
        while (current != nullptr) {
            outFile << current->b_name << " "
                    << current->book_id << " "
                    << current->cost << " "
                    << current->b_author << " "
                    << current->publisher << " "
                    << current->b_status << endl;

            current = current->next;
        }

        outFile.close();
        cout << "Data saved to file successfully." << endl;
    }

    
    void loadFromFile(const string& filename) {
    ifstream inFile(filename);

    if (!inFile.is_open()) {
        cout << "Error opening file for reading." << endl;
        return;
    }

    while (start != nullptr) {
        node* temp = start;
        start = start->next;
        delete temp;
    }

    while (inFile >> ws, !inFile.eof()) { 
        node* temp = new node;
        inFile >> temp->b_name >> temp->book_id >> temp->cost >> temp->b_author >> temp->publisher >> temp->b_status;

        temp->next = nullptr;
        temp->pre = nullptr;

        if (start == nullptr) {
            start = temp;
        } else {
            node* ptr = start;
            while (ptr->next != nullptr)
                ptr = ptr->next;
            ptr->next = temp;
            temp->pre = ptr;
        }
    }

    inFile.close();
    
}

};

int main() {
	
	
	system("color 0b");
	re:

    BookLinkedList  l;
    int flag = 1;
	int choice;
	string filename = "book_data.txt";
	system("cls");
   
    
    while (flag == 1) {
    	
    	cout << "\n***********************************\n";
		cout << "\tLIBRARY MANAGMENT SYSTEM";
		cout << "\n***********************************\n";
		
        cout << "1.Add Book\n";
        cout << "2.Display Books\n";
        cout << "3.Update Books\n";
        cout << "4.Delete Books\n";
        cout << "5.Search Book\n";
        cout << "6.Sort by Book id\n";
        cout << "7.Reverse Books\n";
        cout << "8.Count Books\n";
        cout << "9.Save data to file\n";
        cout << "10.Load Data from File\n";
        cout << "11.Exit the Program\n";
		cout << "***********************************\n";
		
		cin >> choice;
		switch (choice)
		{
            case 1:
			system("cls");
			cout << "\n************************************\n";
			cout << "1. Add Book\n";
			cout << "2. Add Book at first\n";
			cout << "3. Add Book b/w any position\n";
			cout << "4. Add Book at last\n";
			cout << "************************************\n";
			int a;
			cin >> a;
			if (a == 1)
				l.input();
			else if (a == 2)
				l.insert_first();
			else if (a == 3)
				l.insert_any();
			else if (a == 4)
				l.input();
            break;
            
        case 2:
			system("cls");
			l.dispBook();
			break;
        
        case 3:
            system("cls");
			l.update();
			break;
        case 4:
            system("cls");
			cout << "\n************************************\n";
			cout << "1. Delete Books by ID\n";
			cout << "2. Delete b/w any position\n";
			cout << "3. Delete first\n";
			cout << "4. Delete last\n";
			cout << "************************************\n";
			int b;
			cin >> b;
			if (b == 1)
				l.delbook();
			else if (b == 2)
				l.del_any();
			else if (b == 3)
				l.del_first();
			else if (b == 4)
				l.del_last();
			break;
        case 5:
            system("cls");
			l.search();
			break;
        case 6:
            system("cls");
			l.sort();
			break;
        case 7:
            system("cls");
			l.traverse();
			break;
        case 8:
            system("cls");
			l.count();
			break;
		case 9:
			system("cls");
            l.saveToFile("book_data.txt");
            cout << "\n****************************************\n";
            cout << "    Data saved to the file... \n";
            cout << "****************************************\n";
            break;

        case 10:
        	system("cls");
            l.loadFromFile("book_data.txt");
            cout << "\n****************************************\n";
            cout << "    Data loaded from the file... \n";
            cout << "****************************************\n";
            break;

        case 11:
        	system("cls");
            cout << "\n****************************************\n";
            cout << "    Thanks for using LMS Program... \n";
            cout << "****************************************\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
	
		
	}
	system("pause");
	return 0;
}
