#include <iostream>

using namespace std;

//Функция
template<typename Type>
Type _min(Type a, Type b) {
    return a < b ? a : b;
}

//Класс
template<typename Type1, typename Type2>
class Pair {
private:
    Type1 first;
    Type2 second;
public:
    Pair() {};

    Pair(Type1 a, Type2 b) {
        this->first = a;
        this->second = b;
    }

    Type1 getFirst() {
        return this->first;
    }

    Type2 getSecond() {
        return this->second;
    }

    void setFirst(Type1 a) {
        this->first = a;
    }

    void setSecond(Type2 a) {
        this->second = a;
    }
};


//Специализация
template<>
string _min(string a, string b) {
    return a.size() < b.size() ? a : b;
}

int main(int argc, char** argv) {
    cout << _min<double>(5, 0.22) << endl;

    Pair<int, string> pair(2, "two");

    cout << pair.getFirst() << "\t" << pair.getSecond() << endl;
    
    Pair<int, double> innerPair(9, 0.2);

    Pair<Pair<int, double>, string> pair2;

    pair2.setFirst(innerPair);
    pair2.setSecond("this is pair in pair");

    cout << pair2.getFirst().getFirst() << "\t" << pair2.getFirst().getSecond() << "\t" << pair2.getSecond() << endl;

    cout << _min<>("big", "small") << endl;
    
    cin.get();
    return 0;
}