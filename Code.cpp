#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct User {
    int id;
    int balance;
};

int main() {
    int n;
    cin >> n;
    
    vector<User> users(n);
    for (int i = 0; i < n; i++) {
        cin >> users[i].id >> users[i].balance;
    }
    
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int fromID, toID, amount;
        cin >> fromID >> toID >> amount;

        int fromIndex = -1, toIndex = -1;
        for (int j = 0; j < n; j++) {
            if (users[j].id == fromID) {
                fromIndex = j;
            }
            if (users[j].id == toID) {
                toIndex = j;
            }
        }

        if (fromIndex != -1 && toIndex != -1 && users[fromIndex].balance >= amount) {
            users[fromIndex].balance -= amount;
            users[toIndex].balance += amount;
            cout << "Success" << endl;
        } else {
            cout << "Failure" << endl;
        }
    }
    cout << endl;

        sort(users.begin(), users.end(), [](const User &a, const User &b) {
        return a.balance < b.balance;
    });

    for (const auto &user : users) {
        cout << user.id << " " << user.balance << endl;
    }

    return 0;
}
