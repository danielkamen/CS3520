
#include <iostream>
#include <memory>
#include <vector>
using namespace std;
//Templates are used at compile time based on what compiler sees as the
//usage of the code (i.e, specific types). They are helpful in
//Optimization/efficiency
//Most template based code is written in a HEADER-ONLY LIBRARY.
struct Point2D {
int x, y;
bool operator==(Point2D pt) const {
return pt.x == x && pt.y == y;
}
};
//These go in header file (typically)
template <typename T>
bool contains(const vector<T> &vec, T value);
//These go in cpp file but you will need to include the cpp file in your
//code.
bool contains(const int *arr, size_t size, int value){
cout<<"int version"<<endl;
for(size_t ii=0;ii<size;++ii){
if(arr[ii] == value)
return true;
}
return false;
}
bool contains(const double *arr, size_t size, double value){
cout<<"double version"<<endl;
for(size_t ii=0;ii<size;++ii){
if(arr[ii] == value)
return true;
}
return false;
}
template <typename T, typename R>
bool contains(const T *arr, size_t size, R value){
cout<<"template version"<<endl;
for(size_t ii=0;ii<size;++ii){
if(arr[ii] == value)
return true;
}
return false;
}
template <typename T>
bool contains(const vector<T> &vec, T value){
cout<<"vector template version"<<endl;
for(const auto &e : vec){
if(e == value)
return true;
}
return false;
}
int main(void) {
cout << "Start!" << endl;
cout<<boolalpha;
const size_t size = 5;
int arri[size] = {11,22,34,56,101};
cout<<contains(arri,size,33.0)<<endl;
double arrd[size] = {11.1,22.2,34.4,56.6,101.1};
cout<<contains(arrd,size,34.4)<<endl;
float arrf[size] = {11.1f,22.2f,34.4f,56.6f,101.1f};
cout<<contains(arrf,size,34.4f)<<endl;
vector<int> vi = {1,2,3,4,5};
cout<<contains(vi,2)<<endl;
vector<string> vs = {"hey", "hi", "howdi", "bye"};
cout<<contains(vs,string("bye"))<<endl;
vector<Point2D> v2d = {{1,1},{1,2},{2,4},{2,3}};
cout<<contains(v2d,{1,4})<<endl;
cout << "Bye" << endl;
}
