#include <iostream>
#include <vector>

// (1) compile
template <typename T> 
struct Foo {
  T Run() { 
    std::cout << "Foo not specialized" << std::endl; 
    return T();
  };
};

// (2) compile
template <typename T> 
struct Foo<std::vector<T>> {
  std::vector<T> Run() { 
    std::cout << "Foo specialized" << std::endl;  
    return std::vector<T>();
   };
};


template <typename T> struct Bar
{
    T Run();
};

// (3) compiles
template<typename T>
T Bar<T>::Run() {
    std::cout << "Bar not specialized" << std::endl;
    return T();
};

// (3) compiles
template<>
std::vector<bool> Bar<std::vector<bool>>::Run() {
    std::cout << "Bar specialized" << std::endl;
    return std::vector<bool>();
};

// (4) wont compile: error: invalid use of incomplete type 'struct Bar<std::vector<T> >
// template<typename T>
// std::vector<T> Bar<std::vector<T>>::Run() {
//     std::cout << "Bar specialized" << std::endl;
//     return std::vector<T>();
// };

int main(int argc, char const *argv[]) {
  Foo<bool> f1;
  bool rf1 = f1.Run();

  Foo<std::vector<int>> f2;
  std::vector<int> rf2 = f2.Run();

  Bar<bool> b1;
  bool rb1 = b1.Run();

  Bar<std::vector<bool>> b2;
  std::vector<bool> rb2 = b2.Run();

  Bar<std::vector<int>> b3;
  std::vector<int> rb3 = b3.Run();

  return 0;
};