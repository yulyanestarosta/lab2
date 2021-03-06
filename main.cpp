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
        for (int i = 0; i != grid.y_size*grid.x_size; i++) {
            in >> grid.mem[i];
        }
        return in;
    }
    friend ostream& operator<<(ostream& out, Grid const& grid) { //вывод
        for (int i = 1; i != grid.y_size+1; i++) {
            for (int j = 1; j != grid.x_size+1; j++) {
                out << grid.mem[(j - 1) + grid.x_size*(i-1)] << ' ';
            }
            out << endl;
        }

        return out;
    }
};

