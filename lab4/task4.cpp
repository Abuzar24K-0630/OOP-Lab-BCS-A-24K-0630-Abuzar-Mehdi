#include <iostream>
using namespace std;

class ServerSession {
private:
    int sessionID;
public:
    ServerSession(int id) {
        sessionID = id;
        cout << "Session " << sessionID << " started. Resource acquired." << endl;
    }
    ~ServerSession() {
        cout << "Session " << sessionID << " ended. Resource released." << endl;
    }
};

int main() {
    {
        ServerSession s1(101);
    }
    cout << "Block ended." << endl;
    return 0;
}