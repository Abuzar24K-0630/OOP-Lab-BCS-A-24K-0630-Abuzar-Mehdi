#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    int id;
    string name;
    double price;
    int stockQuantity;
public:
    Product(int i = 0, string n = "", double p = 0.0, int s = 0) {
        id = i;
        name = n;
        price = p;
        stockQuantity = s;
    }
    int getId() const { return id; }
    string getName() const { return name; }
    double getPrice() const { return price; }
    int getStock() const { return stockQuantity; }

    void reduceStock(int q) {
        if (q <= stockQuantity) stockQuantity -= q;
    }
};

class ShoppingCart {
private:
    Product** items;
    int* quantities;
    int capacity;
    int count;
public:
    ShoppingCart(int cap = 10) {
        capacity = cap;
        count = 0;
        items = new Product*[capacity];
        quantities = new int[capacity];
    }
    ShoppingCart(Product* products[], int qty[], int size) {
        capacity = size + 5;
        count = size;
        items = new Product*[capacity];
        quantities = new int[capacity];
        for (int i = 0; i < size; i++) {
            items[i] = products[i];
            quantities[i] = qty[i];
        }
    }
    ~ShoppingCart() {
        delete[] items;
        delete[] quantities;
    }
    void addProduct(Product* p, int q) {
        if (p->getStock() < q) {
            cout << "Not enough stock for " << p->getName() << endl;
            return;
        }
        for (int i = 0; i < count; i++) {
            if (items[i]->getId() == p->getId()) {
                quantities[i] += q;
                p->reduceStock(q);
                return;
            }
        }
        if (count < capacity) {
            items[count] = p;
            quantities[count] = q;
            count++;
            p->reduceStock(q);
        }
    }
    void removeProduct(int id) {
        for (int i = 0; i < count; i++) {
            if (items[i]->getId() == id) {
                for (int j = i; j < count - 1; j++) {
                    items[j] = items[j + 1];
                    quantities[j] = quantities[j + 1];
                }
                count--;
                cout << "Product removed from cart." << endl;
                return;
            }
        }
        cout << "Product not found in cart." << endl;
    }
    void displayCart() const {
        if (count == 0) {
            cout << "Cart is empty." << endl;
            return;
        }
        cout << "Cart Contents:" << endl;
        for (int i = 0; i < count; i++) {
            cout << "- " << items[i]->getName()
                 << " (x" << quantities[i] << ") = "
                 << items[i]->getPrice() * quantities[i] << endl;
        }
    }
    double calculateTotal() const {
        double total = 0;
        for (int i = 0; i < count; i++) {
            total += items[i]->getPrice() * quantities[i];
        }
        return total;
    }
};

int main() {
    Product p1(1, "Laptop", 2000, 5);
    Product p2(2, "Mouse", 20, 10);
    Product p3(3, "Keyboard", 50, 8);

    ShoppingCart cart;
    cart.addProduct(&p1, 1);
    cart.addProduct(&p2, 2);
    cart.addProduct(&p3, 1);

    cart.displayCart();
    cout << "Total Price: $ " << cart.calculateTotal() << endl;

    cart.removeProduct(2);
    cart.displayCart();
    cout << "Total Price: $ " << cart.calculateTotal() << endl;

    return 0;
}
