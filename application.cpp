#include "application.h"

Application::Application() : customer(nullptr), currentStore(nullptr) {}

bool Application::init() {
    return GlobalVariable::init();
}

bool Application::login() {
    system("cls");
    cout << "Do you have an account? (0: No, 1: Yes)" << endl;
    int choice;
    cin >> choice;
    if (choice == 0) {
        cout << "Do you want to create an account? (0: No, 1: Yes)" << endl;
        cin >> choice;
        if (choice == 0) return false;
        else {
            string username, password;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            customer = new BuyerAccount(username, password);
            cout << "Enter your name: ";
            string name;
            cin.ignore();
            getline(cin, name);
            customer->setName(name);
            cout << "Enter your email: ";
            string email;
            cin >> email;
            customer->setEmail(email);
            cout << "Enter your gender (0: male, 1: female): ";
            int gender;
            cin >> gender;
            customer->setGender(gender);
            cout << "Enter your date of birth: (day month year): ";
            Date dateOfBirth;
            cin >> dateOfBirth;
            customer->setDateOfBirth(dateOfBirth);
            GlobalVariable::listAccount.addAccount(customer);
            return true;
        }
    }
    else {
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;
        customer = GlobalVariable::listAccount.checkAccount(username, password);
        if (customer == nullptr) return false;
        else return true;
    }
    return true;
}

void Application::showProducts() {
    while (true) {
        system("cls");
        cout << "Welcome to " << currentStore->getName() << endl;
        cout << *currentStore;
        cout << "===========================" << endl;
        cout << "1. Add product to cart" << endl;
        cout << "2. Back" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: {
                cout << "Enter product index to add to cart: ";
                int index;
                cin >> index;
                if (index < 1 || index > currentStore->getNumProduct()) break;
                Product *product = currentStore->getProduct(index - 1);
                cout << "Enter quantity: ";
                int quantity;
                cin >> quantity;
                customer->addProductToCart(product, quantity);
                break;
            }
            case 2:
                return;
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
        system("pause");
    }
}

void Application::showStore() {
    system("cls");
    cout << GlobalVariable::listStore;
    cout << "Enter store index to visit: ";
    int choice;
    cin >> choice;
    if (choice < 1 || choice > GlobalVariable::listStore.getNumStore()) return;
    currentStore = GlobalVariable::listStore.getStore(choice - 1);
    showProducts();
}

void Application::checkOut() {
    system("cls");
    cout << GlobalVariable::listVoucher;
    cout << "You only can use one voucher" << endl;
    cout << "Enter voucher index to use: (0: None)";
    int choice;
    cin >> choice;
    if (choice == 666) {
        GlobalVariable::flashSale.load();
    }
    else if (choice == 999) {
        GlobalVariable::flashSale.reset();
    }
    else if (choice < 0 || choice > GlobalVariable::listVoucher.getNumVoucher()) {
        cout << "Invalid choice" << endl;
        system("pause");
    }
    else if (choice != 0) {
        Voucher *voucher = GlobalVariable::listVoucher.getVoucher(choice - 1);
        ShoppingCart::getInstance()->setVoucher(voucher);
    }
    cout << "Choose shipping method: " << endl;
    cout << "1. Normal shipping" << endl;
    cout << "2. Fast shipping" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    if (choice == 1) {
        ShoppingCart::getInstance()->setShippingMethod(new ShippingMethodStandard());
    }
    else if (choice == 2) {
        ShoppingCart::getInstance()->setShippingMethod(new ShippingMethodExpress());
    }
    else {
        cout << "Invalid choice, default: standard shipping method" << endl;
        ShoppingCart::getInstance()->setShippingMethod(new ShippingMethodStandard());
        system("pause");
    }
    cout << "Choose payment method: " << endl;
    cout << "1. Cash" << endl;
    cout << "2. Credit card" << endl;
    cout << "3. Momo" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    PaymentMethodFactory paymentMethodFactory;
    if (choice == 1) {
        ShoppingCart::getInstance()->setPaymentMethod(paymentMethodFactory.createPaymentMethod("Cash"));
    }
    else if (choice == 2) {
        ShoppingCart::getInstance()->setPaymentMethod(paymentMethodFactory.createPaymentMethod("CreditCard"));
    }
    else if (choice == 3) {
        ShoppingCart::getInstance()->setPaymentMethod(paymentMethodFactory.createPaymentMethod("Momo"));
    }
    else {
        cout << "Invalid choice, default: cash" << endl;
        ShoppingCart::getInstance()->setPaymentMethod(paymentMethodFactory.createPaymentMethod("cash"));
        system("pause");
    }
    cout << *ShoppingCart::getInstance() << endl;
    cout << "Enter to pay" << endl;
    system("pause");
    customer->checkout();
}

void Application::showCart() {
    while (true) {
        system("cls");
        cout << *ShoppingCart::getInstance();
        cout << "1. Check out" << endl;
        cout << "2. Remove product" << endl;
        cout << "3. Back" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: {
                checkOut();
                break;
            }
            case 2: {
                cout << "Enter product index to remove: ";
                int index;
                cin >> index;
                if (index < 1 || index > ShoppingCart::getInstance()->getNumProduct()) break;
                Product *product = ShoppingCart::getInstance()->getProduct(index - 1);
                customer->removeProductFromCart(product);
                break;
            }
            case 3: {
                return;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
        system("pause");
    }
}

void Application::showMenu() {
    while (true) {
        system("cls");
        cout << "Welcome " << customer->getName() << endl;
        cout << "Rank: " << customer->getRanking()->getCustomerRankingName() << endl;
        cout << "1. Visit store" << endl;
        cout << "2. View cart" << endl;
        cout << "3. Logout" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1: {
                showStore();
                break;
            }
            case 2: {
                showCart();
                break;
            }
            case 3: {
                return; //logout
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
        system("pause");
    }
}

void Application::runApp() {
    if (!init()) {
        cout << "Init failed" << endl;
        return;
    }
    do {
        if (!login()) {
            cout << "Login failed, try again" << endl;
            system("pause");
        }
    } while (customer == nullptr);
    customer->setShoppingCart(ShoppingCart::getInstance(customer));
    cout << "Login success, enter to continue" << endl;
    system("pause");
    showMenu();  
    system("pause");
}   