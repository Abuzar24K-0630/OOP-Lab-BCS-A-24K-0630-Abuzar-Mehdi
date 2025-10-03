#include <iostream>
#include <string>
using namespace std;

class MobileDevice {
    string modelName;
    const string IMEINumber;
public:
    MobileDevice(string model, string imei) : IMEINumber(imei) , modelName(model) {}
    void verifyDevice() const {
        cout << "Model Name: " << modelName << endl;
        cout << "IMEI Number: " << IMEINumber << endl;
    }
};

int main() {
    MobileDevice d1("Samsung Galaxy S24", "356789012345678");
    d1.verifyDevice();
    return 0;
}
