#include<iostream>
#include<set>
#include<new>
using namespace std;

template<typename T>
class Grid {

private:
    T* mem; //memory
    size_t x_size, y_size;

public:
    Grid(size_t x_size, size_t y_size):
            x_size(x_size),
            y_size(y_size),
            mem(new T[x_size*y_size]){ };

    Grid(Grid const& copy) : Grid(copy.x_size, copy.y_size){  //скопировать
        for (size_t pos = 0; pos != x_size * y_size; ++pos) {
            mem[pos] = copy.mem[pos];
        }
    }

    ~Grid() {
        delete[] mem;
    }

    T operator()(size_t x_idx, size_t y_idx) const {
        return mem[(x_idx - 1) + x_size*(y_idx - 1)];
    }

    T& operator()(size_t x_idx, size_t y_idx) {
        return mem[(x_idx - 1) + x_size * (y_idx - 1)];
    }

    Grid& operator=(T inp) {  //замена
        for (size_t pos = 0; pos != x_size * y_size; ++pos) {
            mem[pos] = inp;
        }
        return *this;
    }

    friend istream& operator>>(istream& in, Grid& grid) { //ввод
        for (T i = 0; i != grid.y_size*grid.x_size; i++) {
            in >> grid.mem[i];
        }
        return in;
    }
    friend ostream& operator<<(ostream& out, Grid const& grid) { //вывод
        for (T i = 1; i != grid.y_size+1; i++) {
            for (T j = 1; j != grid.x_size+1; j++) {
                out << grid.mem[(j - 1) + grid.x_size*(i-1)] << ' ';
            }
            out << std::endl;
        }

        return out;
    }
};
// // протестируем
//int main() {
//    Grid<int> g1(3, 2);
//    g1 = 1;
//    cout << g1;
//    cout << endl;
//    cout << g1(1, 1);
//    cout << endl;
//    g1(3, 1) = 0;
//    cout << endl;
//    cout << g1;
//    cout << endl;
//
//    Grid<int> g_in(2, 3);
//    cout << "Введите элементы";
//    cout << endl;
//    cin >> g_in;
//    cout << endl;
//    cout << g_in;
//    cout << endl;
//
//    Grid<int> copy1(g1);
//    cout << copy1;
//    copy1(2, 2) = 0;
//    cout << endl;
//    cout << copy1;
//    cout << endl;
//    cout << g1;
//}