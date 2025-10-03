#include <iostream>
#include <cstring>   
using namespace std;
class User {
private:
    int ID;
    char name[50];
    char password[50];
    char role[20];

public:
   
    User(int id, const char* uname, const char* pass) {
        ID = id;
        strcpy(name, uname);
        strcpy(password, pass);
        strcpy(role, "Guest");
    }

   
    User(int id, const char* uname, const char* pass, const char* r) {
        ID = id;
        strcpy(name, uname);
        strcpy(password, pass);
        strcpy(role, r);
    }

    int getID() { return ID; }
    const char* getName() { return name; }
    const char* getRole() { return role; }

    void setRole(const char* newRole) {
        strcpy(role, newRole);
    }

    void display() {
        cout << "ID: " << ID
             << " | Name: " << name
             << " | Role: " << role << endl;
    }

  
    static bool validatePassword(const char* pass) {
        int len = strlen(pass);
        if (len < 6) return false;

        const char* specials = "!@#$%^&*()-_=+[]{};:'\",.<>/?\\|";
        for (int i = 0; i < len; i++) {
            for (int j = 0; specials[j] != '\0'; j++) {
                if (pass[i] == specials[j])
                    return true;
            }
        }
        return false;
    }
};


class Admin {
private:
    User** users;   
    int capacity;  
    int count;     
    int nextID;    

public:
    Admin(int cap = 100) {
        capacity = cap;
        users = new User*[capacity];
        count = 0;
        nextID = 1;
    }

    ~Admin() {
        for (int i = 0; i < count; i++) {
            delete users[i];
        }
        delete[] users;
    }

    void addUser(const char* name, const char* pass, const char* role = "") {
        if (count >= capacity) {
            cout << "User capacity full!\n";
            return;
        }

        if (!User::validatePassword(pass)) {
            cout << "Password invalid! Must be >=6 chars & contain special character.\n";
            return;
        }

        if (role == 0) {
            users[count] = new User(nextID++, name, pass);
        } else {
            users[count] = new User(nextID++, name, pass, role);
        }

        cout << "User added successfully with ID: " << users[count]->getID() << endl;
        count++;
    }

    void removeUser(int id) {
        int index = -1;
        for (int i = 0; i < count; i++) {
            if (users[i]->getID() == id) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            cout << "User not found!\n";
            return;
        }

        delete users[index];
        for (int i = index; i < count - 1; i++) {
            users[i] = users[i + 1];
        }
        count--;
        cout << "User with ID " << id << " removed successfully.\n";
    }

    void searchUser(int id) {
        for (int i = 0; i < count; i++) {
            if (users[i]->getID() == id) {
                cout << "User Found: ";
                users[i]->display();
                return;
            }
        }
        cout << "User not found!\n";
    }

    void displayUsers() {
        if (count == 0) {
            cout << "No users available.\n";
            return;
        }
        cout << "All Users:\n";
        for (int i = 0; i < count; i++) {
            users[i]->display();
        }
    }

    void assignRole(int id, const char* newRole) {
        for (int i = 0; i < count; i++) {
            if (users[i]->getID() == id) {
                users[i]->setRole(newRole);
                cout << "Role updated successfully.\n";
                return;
            }
        }
        cout << "User not found!\n";
    }
};

int main() {
    Admin admin(10);
    admin.addUser("Ali", "pass@123", "Admin");
    admin.addUser("Sara", "hello#12");
    admin.addUser("Ahmed", "strong*pw", "User");
    cout << endl;
    admin.displayUsers();
    cout << endl;
    admin.searchUser(2);
    admin.assignRole(2, "User");
    admin.displayUsers();
    admin.removeUser(1);
    cout << endl;
    admin.displayUsers();
    return 0;
}
