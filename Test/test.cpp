#include <iostream>
#include <string>
#include <vector>
#include "path_filter.hpp"



int main(int argc, char* argv[])
{
	std::vector<std::string> vec_tmpt;
	std::vector<std::string> vec_path;
	std::string tmpt;
	std::string path;
	int n = 0;
	std:: cin >> n;
	for (int i = 0; i < n; ++i) {
		std:: cin >> tmpt;
		vec_tmpt.push_back(tmpt);
	}
	
	std:: cin >> n;
	for (int i = 0; i < n; ++i) {
		std:: cin >> path;
		vec_path.push_back(path);
	}

	Path_filter pf(vec_tmpt);




	for (int i = 0; i < n; ++i) {
		if (pf.match(vec_path[i])) std::cout << "Match: " << vec_path[i] << std:: endl;
		else std::cout << "Mismatch: " << vec_path[i] << std:: endl;
	}
	return 0;
}