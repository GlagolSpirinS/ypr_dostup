#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

class Animal {
protected:
    string name;
public:
    Animal(string animalName) : name(animalName) {}
};

class Pet {
public:
    virtual void feed(int foodAmount) = 0;
};

class Dog : public Animal, public Pet {
private:
    int hungerLevel;
public:
    Dog(string dogName, int randomNum, int hunger) : Animal(dogName), hungerLevel(hunger) {
        cout << "Создан новый пёс по имени " << name << " с рандомным числом " << randomNum << endl;
    }
    void feed(int foodAmount) override {
        if (foodAmount >= hungerLevel - 10 && foodAmount <= hungerLevel + 10) {
            cout << name << " радостно съел " << foodAmount << " еды." << endl;
        }
        else {
            cout << name << " не признал эту еду и остался голоден." << endl;
        }
    }
};

class Cat : public Animal, public Pet {
private:
    int hungerLevel;
public:
    Cat(string catName, int randomNum, int hunger) : Animal(catName), hungerLevel(hunger) {
        cout << "Создан новый кот по имени " << name << " с рандомным числом " << randomNum << endl;
    }
    void feed(int foodAmount) override {
        if (foodAmount >= hungerLevel - 10 && foodAmount <= hungerLevel + 10) {
            cout << name << " съел еду, но, кажется, не очень доволен. Он всё еще хочет есть." << endl;
        }
        else {
            cout << name << " наелся и больше не хочет есть." << endl;
        }
    }
};

int main() {

    system("chcp 1251");
    system("cls");
    setlocale(LC_ALL, "Russian_Russian.1251");
    srand(time(0));

    int randomNum1 = rand() % 100;
    int randomNum2 = rand() % 100;

    int dogFoodAmount, catFoodAmount;
    string dogName, catName;

    cout << "Введите количество еды для пса (от 0 до 100): ";
    cin >> dogFoodAmount;
    cout << "Введите имя для пса: ";
    cin >> dogName;

    cout << "Введите количество еды для кота (от 0 до 100): ";
    cin >> catFoodAmount;
    cout << "Введите имя для кота: ";
    cin >> catName;

    Dog dog(dogName, randomNum1, randomNum1 - dogFoodAmount);
    Cat cat(catName, randomNum2, randomNum2 - catFoodAmount);

    cout << endl << "--- Время кормления! ---" << endl;
    dog.feed(dogFoodAmount);
    cat.feed(catFoodAmount);

    return 0;
}
