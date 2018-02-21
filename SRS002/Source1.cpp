#include <fstream>
#include <iostream>
#include <iomanip>

int main() {
	size_t allo = 4;
	char name[257];
	auto list = new chart*[allo];//check for delete.
	auto next;
	auto count;
	int check;
	
	std::cout << "What would you like to do?" << endl; << "0 = Manualy enter data." << endl; << "1= Pull data from test.txt" << endl; "2= Read data from test.txt" << endl; << "3= End program." << endl;
		std::cin >> check;
		if (check = 0) {
			while (check == 0) {
				std::cin >> std::setw(256) >> name;
				const auto len = strlen(name);
				auto newname = new char[len + 1];//check for delete.
				list[next] = newname;
				count++;
				if (allo < count++)
					allo = 2 * allo;
				std::cout << "What would you like to do?" << endl; << "0 = Manualy enter data again." << endl; << "1= write data to test.txt" << endl; "2= Read data from test.txt" << endl; << "3= End program." << endl;
				std::cin >> check;
			}

		}
		if (check == 1) {
			//todo
			std::cout << std::endl; < std::endl;
		}
		if (check == 2) {
			//todo
			std::cout << std::endl; << std::endl;
		}
		if (check == 3) {
			return 0;
		}



	return 0;
}