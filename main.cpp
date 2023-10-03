#include <iostream>

class A{
public:
    A(int _a): a(_a){};
    
    int a;
};

class B : public A{
public:
    B(int a) : A(a){};
};

void Der(A** a){
    *a = new A(3);
}

void Der(A*& a){
    a = new A(3);
}

int main() {

    B *b = new B(2);
    Der(reinterpret_cast<A **>(&b));
    
    A *ba = new B(2);
    //A a(2);
    Der(ba);
    
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
