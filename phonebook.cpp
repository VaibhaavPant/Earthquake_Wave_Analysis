#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void sort();
class contacts{ //think this is an real phone directory
    public:     //We have an public class here, it got name, mobile number, email address and residential address of one person
    string name;
    int number;
    string email;
    string address;
};
vector <contacts>phonebook; //defined an vector which stores data as the elements in the class
void add(){     //add new contact
        contacts c; //We will make the object of an class here
        cout<<"Enter the name of the person: "<<endl;
        cin.ignore();
        getline(cin, c.name);
        cout<<"Enter the mobile number of the person: "<<endl;
        cin>>c.number;
        cin.ignore();
        cout<<"Enter the email address of the person: "<<endl;
        getline(cin, c.email);
        cout<<"Enter the residential address of the person: "<<endl;
        getline(cin, c.address);
        phonebook.push_back(c);  //push the details into the phone directory, i.e. the class
        sort();
}
void deletecon(){
    string deletename;
    cout<<"Enter the name you want to delete"<<endl;
    cin.ignore();
    getline(cin, deletename);
    for(auto it=phonebook.begin();it!=phonebook.end();it++){
        if(it->name==deletename){
            phonebook.erase(it);
            cout<<"Contact deleted sucessfully"<<endl;
            return;
        }
    }
    sort();
    }
void search() {
    string searchname;
    cout << "Enter the name you want to search: ";
    cin.ignore();
    getline(cin, searchname);

    // Sort the phonebook before performing binary search
    sort(phonebook.begin(), phonebook.end(), [](const contacts &a, const contacts &b) {
        return a.name < b.name;
    });

    int left = 0;
    int right = phonebook.size() - 1;
    bool found = false;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (phonebook[mid].name == searchname) {
            cout << "Contact found:\n";
            cout << "Name: " << phonebook[mid].name << "\n";
            cout << "Mobile number: " << phonebook[mid].number << "\n";
            cout << "Email address: " << phonebook[mid].email << "\n";
            cout << "Residential address: " << phonebook[mid].address << "\n";
            found = true;
            break;
        } else if (phonebook[mid].name < searchname) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (!found) {
        cout << "Contact not found!\n";
    }
    sort();
}
void swap(contacts &a, contacts &b){
    contacts temp=a;
    a=b;
    b=temp;
}
int partition(int low, int high) {
    contacts pivot = phonebook[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (phonebook[j].name < pivot.name) {
            i++;
            swap(phonebook[i], phonebook[j]);
        }
    }
    swap(phonebook[i + 1], phonebook[high]);
    return i + 1;
}

void quicksort(int low, int high) {
    if (low < high) {
        int pi = partition(low, high);
        quicksort(low, pi - 1);
        quicksort(pi + 1, high);
    }
}

void sort() {
    quicksort(0, phonebook.size() - 1);
    cout << "Contacts sorted using QuickSort!\n";
}
void display(){
    if(phonebook.empty()){
        cout<<"Phonebook is empty"<<endl;
        return;
    }
    cout<<"Contacts: "<<endl;
    for(auto &contact : phonebook){
       cout << "Name: " << contact.name << ", Phone: " << contact.number << ", Email: " << contact.email << ", Address: " << contact.address << "\n";
    }
}
int main(){
    int ch;

     cout<<"----Phonebook application----"<<endl;
    
    do{
        cout<<"Press 1.to Add New Contact"<<endl;
        cout<<"Press 2.to Delete the contact"<<endl;
        cout<<"Press 3.to Search for the contact"<<endl;
        cout<<"Press 4.to Sort the contact list"<<endl;
        cout<<"Press 5.to Display the contacts"<<endl;
        cout<<"Press 0.to Exit the program"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>ch;
        switch(ch){
                case 1:
                add();
                break;
                case 2:
                deletecon();
                break;
                case 3:
                search();
                break;
                case 4:
                sort();
                break;
                case 5:
                display();
                break;
                case 0:
                cout<<"Exiting...";
                break;
                default:
                cout<<"Valid choice"<<endl;
                break;
               
        }
    }while(ch!=0);
    return 0;
}
