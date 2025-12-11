//Discount Calculator

#include<iostream>
#include<conio.h>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;

class Discount{
    string product;
    float realPrice;
    float discount;
    float rate;
    bool isValid(){
        if (realPrice <= 0 || rate <= 0 || rate > 100) {
        cout << "Invalid input!\nPrice and rate must be positive, and rate <= 100.\n";
        return false;
        }
        else return true;
    }
    
    public:
    void calculateDiscount();
    void calculateRate();
    void compare();
};

void Discount :: calculateDiscount(){
    cout << "Enter product name: ";
    cin >> product;
    cout << "Enter the real price of the product: ";
    cin >> realPrice;
    cout << "Enter the discount rate: ";
    cin >> rate;
    
    if(!isValid())
    return;
    
    discount = (realPrice/100)*rate;
    
    cout << "\nProduct: " << product<< endl;
    cout << "Final price after discount: "  << fixed << setprecision(2) << realPrice-discount << endl;
    cout << "You can Save upto " << fixed << setprecision(2) << discount << endl;
    
    cout << "\nPress any key to continue  ";
    cin.ignore();
    cin.get();
}

void Discount :: calculateRate(){
    int amt;
    cout << "Enter product name: ";
    cin >> product;
    cout << "Enter the real price of the product: ";
    cin >> realPrice;
    cout << "Enter final price after discount: ";
    cin >> amt;
    
    discount = realPrice - amt;

    if(!isValid())
    return;
    
    rate = 100/(realPrice/discount);
    
    cout << "\nProduct: " << product<< endl;
    cout << "The discount rate is " << fixed << setprecision(2) << rate << "%" << endl;
    
    cout << "\nPress any key to continue  ";
    cin.ignore();
    cin.get();
}    

void Discount :: compare() {
    int n;
    cout << "Enter the number of products to compare: ";
    cin >> n;

    vector<Discount> prod(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter product name: ";
        cin >> prod[i].product;
        cout << "Enter the real price of the product: ";
        cin >> prod[i].realPrice;
        cout << "Enter the discount rate: ";
        cin >> prod[i].rate;
        prod[i].discount = (prod[i].realPrice / 100) * prod[i].rate;
    }

    sort(prod.begin(), prod.end(), [](const Discount &a, const Discount &b)
    {return a.discount > b.discount;} );

    cout << left << setw(12) << "Product" << left << setw(10) << "RealPrice" << left << setw(6)  << "Rate" << left << setw(10) << "Discount" << endl;

    for (int i = 0; i < n; i++) {
        cout << left << setw(12) << prod[i].product;
        cout << left <<setw(10) << fixed << setprecision(2) << prod[i].realPrice;
        cout << left << setw(6) << fixed << setprecision(2) << prod[i].rate;
        cout << left << setw(10) << fixed << setprecision(2) << prod[i].discount << endl;
    }
    
    cout << "\nPress any key to continue  ";
    cin.ignore();
    cin.get();
}

int main(){
    cout << "-----DISCOUNT CALCULATOR-----\n" << endl;
    
    int c;
    Discount pdt1,pdt2;
    
    do{
        cout << "Enter the following number to\n1.Calculate discounted price\n2.Calculate dicount rate\n3.Compare discounts\n4.Exit\nChoice: ";
        cin >> c;
        
        switch(c){
        case 1: pdt1.calculateDiscount(); break;
        case 2: pdt1.calculateRate(); break;
        case 3: pdt1.compare(); break;
        case 4: cout << "Exited Successfully" << endl; exit(0);
        default: cout << "Invalid choice\nTry Again" << endl;
        }
    
    }while(c!=0);
    
}