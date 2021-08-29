#include <iostream>
using namespace std;

template<class T, class U, template <class V> class K>
class Map{
    K<T> list1;
    K<U> list2;
public:
    Map();
};