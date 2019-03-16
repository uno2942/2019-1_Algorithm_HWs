/*#include<fstream>
using namespace std;

int main() {
	string filePath = "test.txt";
	ofstream writeFile(filePath.data());
	if (writeFile.is_open()) {
		writeFile << 1 << endl;
		writeFile << 5000 << ' ' << 200000 << ' ' << 39455834 << endl;
		for (int i = 0; i < 5000; i++)
			writeFile << i << ' ';
		writeFile << endl;
		for (int j = 0; j < 200000; j++)
			writeFile << j << ' ';
		writeFile.close();
	}
}

*/