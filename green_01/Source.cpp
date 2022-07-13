#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<chrono>
#include<random>
#include<stdlib.h>
/*
* конструкторы по умолчанию
* оператор == < = 
*/
class Beast {
public:
	Beast() :Beast(0, "", false, 0.0) {}
	Beast(int id, std::string name,bool solidate,double weight):id(id),name(name),solidity(solidate),weight(weight){}

	int id;
	std::string name;
	bool solidity;
	double weight;
};
std::string rand_name() {
	std::vector<std::string>data_name{"Барсик","Мурзик","Пушок","Кот 1","Кот 2" ,"Кот 3" ,"Кот 4" ,"Кот 5" ,"Кот 6" ,"Кот 7"};
	int r_name = rand() % 10;
	return data_name[r_name];
}
double rand_weight() {
	//std::vector<int>data_weight;
	//data_weight.reserve(10);
	double tmp = 0.0 + (double)rand() / RAND_MAX * (10.0 - 0.0);
	//data_weight.emplace_back(tmp);

	return tmp;
}

void sort_fat(std::vector<Beast>&other) {
	 
	auto result = max_element(other.begin(), other.end());
	return result;

}

int main() {
	using namespace std;
	srand(time(NULL));
	system("chcp 1251>nul");
	std::vector<Beast>circus;
	circus.reserve(11);
	for (size_t i = 1; i < circus.capacity(); i++)
	{
		circus.emplace_back(i,rand_name(),false,rand_weight());
	}
	std::for_each(circus.begin(), circus.end(), [](Beast& arg) {std::cout << arg.id << "\t" << arg.name << "\t" << arg.solidity << "\t" << arg.weight << '\n'; });
		std::shuffle(circus.begin()+1, circus.end()-1,random_device()); //рандом в целом уникальный 

	/*for (auto&& a :circus) {
		std::cout << a <<'\n';
	}*/
		auto res = std::find_if(circus.begin(), circus.end(), [](const Beast& arg)->bool {
			if (arg.id == 19) {
				return true;
			}
			return false;

			}); //нахождение элемента в коллекции "7"
	if (res == circus.end()) {
		std::cout << "число не нашли\n";
	}
	/*else {
		std::cout << "число найдено\n" << *res<<"\n" << res._Ptr << "\n";
	}*/
	
	

	std::cout << "Time: " << clock() << "\n";
	system("pause>nul");
	return 0;
}