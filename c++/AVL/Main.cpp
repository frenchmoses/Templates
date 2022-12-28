

#include "AVL.h"
#include <iostream>
#include <string>
#include <time.h>
#include <math.h>
using namespace std;
using std::string;


struct stuff{
    int num;
};
ostream& operator<<(ostream& out, const stuff& S){
    out << S.num;
    return out;
}
int main(){
    AVLTree<int> list;
    srand(time(0));
	int s = 1;
	int e = 17;
	for(int i = s; i <= e; i++){
		list.push(i);
	}
	cout << "Height: " << list.height() << endl;
	list.printLevels();

	int i = 8;
	cout << "Removing " << i << endl;
	list.pop(i);
	list.printLevels();
	cout << endl;
/*
	i = 10;
	cout << "Removing " << i << endl;
	list.pop(i);
	list.printLevels();
	cout << endl;

	i = 6;
	cout << "Removing " << i << endl;
	list.pop(i);
	list.printLevels();
	cout << endl;

	i = 7;
	cout << "Removing " << i << endl;
	list.pop(i);
	list.printLevels();
	cout << endl;

	i = 68;
	cout << "Removing " << i << endl;
	list.pop(i);
	list.printLevels();
	cout << endl;
*/
    return 0;
}
