#include <iostream>
#include <vector>
#include <locale>

using namespace std;


class Clothing {
public:
    int id;
    string name;
    string size;
    double price;

    Clothing(int id, string name, string size, double price) {
        this->id = id;
        this->name = name;
        this->size = size;
        this->price = price;
    }

    void display() {
        cout << id << ". " << name << " (Size: " << size << ") - $" << price << endl;
    }
};


class ClothingStore {
public:
    vector<Clothing> products;
    vector<Clothing> cart;

    ClothingStore() {

        products.push_back(Clothing(1, "👕 T-shirt", "M", 19.99));
        products.push_back(Clothing(2, "👖 Jeans", "L", 49.99));
        products.push_back(Clothing(3, "👗 Dress", "S", 59.99));
        products.push_back(Clothing(4, "🧥 Jacket", "XL", 79.99));
        products.push_back(Clothing(5, "👞 Shoes", "42", 89.99));
    }

    void showProducts() {
        cout << "\n🛍️ Do‘kondagi kiyimlar:\n";
        for (Clothing p : products) {
            p.display();
        }
    }

    void addToCart(int productId) {
        for (Clothing p : products) {
            if (p.id == productId) {
                cart.push_back(p);
                cout << "✅ " << p.name << " savatchaga qo‘shildi!\n";
                return;
            }
        }
        cout << "❌ Mahsulot topilmadi!\n";
    }

    void viewCart() {
        cout << "\n🛒 Savatchangiz:\n";
        double total = 0;
        if (cart.empty()) {
            cout << "❌ Savatcha bo‘sh!\n";
            return;
        }

        for (Clothing p : cart) {
            p.display();
            total += p.price;
        }
        cout << "💰 Umumiy summa: $" << total << endl;
    }

    void checkout() {
        if (cart.empty()) {
            cout << "❌ Savatcha bo‘sh! Xarid qilish uchun kiyim qo‘shing.\n";
            return;
        }
        viewCart();
        cout << "✅ Xaridingiz muvaffaqiyatli amalga oshirildi! Rahmat!\n";
        cart.clear(); // Savatchani tozalash
    }
};


int main() {
    setlocale(LC_ALL,"");
    ClothingStore store;
    int choice;

    do {
        cout << "\n===  ONLINE KIYIM DO'KONI ===\n";
        cout << "1. Kiyimlarni ko‘rish\n";
        cout << "2. Savatchaga qo‘shish\n";
        cout << "3. Savatchani ko‘rish\n";
        cout << "4. Xarid qilish\n";
        cout << "5. Chiqish\n";
        cout << "Tanlovingiz: ";
        cin >> choice;

        switch (choice) {
            case 1:
                store.showProducts();
                break;
            case 2:
                int productId;
                cout << "🛍️ Qaysi kiyimni savatchaga qo‘shmoqchisiz? ID kiriting: ";
                cin >> productId;
                store.addToCart(productId);
                break;
            case 3:
                store.viewCart();
                break;
            case 4:
                store.checkout();
                break;
            case 5:
                cout << "🚪 Dasturdan chiqilmoqda...\n";
                break;
            default:
                cout << "❌ Noto‘g‘ri tanlov! Qaytadan urinib ko‘ring.\n";
        }
    } while (choice != 5);

    return 0;
}
