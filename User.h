#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
private:
    string name;
    string email;
    string phone;

public:
    User() {}
    User(string n, string e, string p) : name(n), email(e), phone(p) {}

    void setName(string n) { name = n; }
    void setEmail(string e) { email = e; }
    void setPhone(string p) { phone = p; }

    string getName() const { return name; }
    string getEmail() const { return email; }
    string getPhone() const { return phone; }
};

#endif
