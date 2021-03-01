#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

class complex {
    public:
        complex() : real(0), imagine(0) { }
        complex(double r) : real(r), imagine(0) { }
        complex(double r, double i) : real(r), imagine(i) { }
        // ...

        double getReal() { return real; }
        double getI() { return imagine; }
        complex& operator+=(const complex& a)
            { real+=a.real; imagine+=a.imagine; return *this; }
        friend complex operator+(const complex &a, const complex &b);
        // ...
    private:
        double real, imagine;
}; 

inline complex operator+(const complex &a, const complex &b) {
    return complex(a.real + b.real, a.imagine+b.imagine);
}

inline double niceRand() {
 return rand() / (RAND_MAX+1.0);
}

inline double nicerRand(double min, double max) {
 return min + (max-min)*niceRand();
}

bool compareReals(shared_ptr<complex> l, shared_ptr<complex> r) {
			return l->getReal() < r->getReal();
}

int main(int argc, char *argv[]) {
	vector<complex *> someNums;

	for (int i=0; i < 20; i++) {
		someNums.push_back(new complex(nicerRand(-20, 20), nicerRand(-20, 20)));
	}
    
	for (auto c : someNums) {
		cout << "real: " << c->getReal() << " imaginary: " << c->getI() << endl;
	}

}
