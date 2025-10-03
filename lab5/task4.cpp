#include <iostream>
#include <string>
using namespace std;

class CallRecord {
    string callerID;
    int durationMinutes;
    static int totalCalls;
public:
    CallRecord() {
        callerID = "";
        durationMinutes = 0;
    }
    CallRecord(string id, int duration) {
        callerID = id;
        durationMinutes = duration;
        totalCalls++;
    }
    void display() {
        cout << "Caller ID: " << callerID << ", Duration: " << durationMinutes << " minutes" << endl;
    }
    static void getTotalCalls() {
        cout << "Total Calls Logged: " << totalCalls << endl;
    }
};

int CallRecord::totalCalls = 0;

int main() {
    CallRecord calls[20] = {
        CallRecord("03001234567", 5),
        CallRecord("03019876543", 10),
        CallRecord("03121234567", 8)
    };

    for (int i = 0; i < 3; i++) {
        calls[i].display();
    }

    CallRecord::getTotalCalls();
    return 0;
}
