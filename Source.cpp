#include <iostream>
using namespace std;
 
struct Node {
public:
    int data;
    Node* next;
 
    Node(int data) {
        data = this->data;
        next = NULL;
    }
};
 
struct Queue {
 
    Node* head = NULL;
    Node* tail = NULL;
    int size = 0;
 
    int getSize() { // funkcija patikrina elementu kieki eileje
        return size;
    }
 
    bool isEmpty() { // funkcija patikrina ar eile yra tuscia
        if (size > 0)
            return true;
        else
            return false;
    }
 
    void add(int data) { // funkcija prideda elementa i eile
 
        if (head == NULL) {
            head = new Node(data);
            size++;
        }
        else {
            if (getSize() == 1)
                tail = new Node(data);
            else
                tail->next = new Node(data);
 
            size++;
        }
    }
 
    void remove() { //funkcija istrina elementa is eiles
       
        if (getSize() == 1) {
            head = NULL;
            size--;
            return;
        }
        if (getSize() == 2) {
            head = tail;
            tail = head;
            size--;
            return;
        }
        head->next = head;
        size--;
    }
};
 
 
 
int main() {
 
    Queue eile;
    int n;
    std::cout << "Iveskite kiek norite irasyti skaiciu i eile\n";
    std::cin >> n;
    cout << "Iveskite pasirinktus skaicius\n";
    int data;
    for (int i = 0; i < n; i++) {
      cin >> data;
      eile.add(data);
    }
 
    int pasirinkimas = 0;
 
    while (pasirinkimas != 5) {
 
      cout << "1. Patikrinti eile yra tuscia." << endl;
      cout << "2. Prideti nauja elementa i eile" << endl;
      cout << "3. Pasalinti elementa is eiles. " << endl;
      cout << "4. Isspausdinti elementu kieki sarase." << endl;
      cout << "5. Iseiti." << endl;
      cin >> pasirinkimas;
 
      if (pasirinkimas == 1) {
        if (eile.getSize() == 0)
          cout << "eile yra tuscia" << endl;
        else
          cout << "eile nera tuscia" << endl;
      }
      if (pasirinkimas == 2) {
 
        int elementas;
        cout << "Iveskite elementa kuri norite prideti" << endl;
        cin >> elementas;
        eile.add(elementas);
      }
      if (pasirinkimas == 3)
        eile.remove();
      if (pasirinkimas == 4)
        cout << eile.getSize() << endl;
 
    }
}

