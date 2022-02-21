#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
	unordered_map<string, int> ourmap;
	
	// insert
	pair<string, int> p("abc", 1);
	ourmap.insert(p);
  //or
	ourmap["def"] = 2;

	// find or access
	cout << ourmap["abc"] << endl;    //not good
	cout << ourmap.at("abc") << endl;
  
  //size of map
	cout << "size : " << ourmap.size() << endl;

	// check Presense
	if (ourmap.count("ghi") > 0) {
		cout << "ghi is present" << endl;
	}

	// erase
	ourmap.erase("ghi");
	cout << "size : " << ourmap.size() << endl;
	if (ourmap.count("ghi") > 0) {
		cout << "ghi is present" << endl;
	}

}
