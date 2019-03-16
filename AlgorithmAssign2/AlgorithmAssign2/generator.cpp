#include<fstream>
using namespace std;

int main() {
	string filePath = "test.txt";
	ofstream writeFile(filePath.data());
	if (writeFile.is_open()) {
		writeFile << "Hello World!\n";
		writeFile << "This is C++ File Contents.\n";
		writeFile.close();
	}
}