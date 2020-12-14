#include "path_filter.hpp"

bool cmp(const std:: string& tmpt, const std:: string&path)  //only templates (tmpt) has '*' and '?'
{
	int len_tmpt = tmpt.size();
	int len_path = path.size();
	int i = 0, j = 0;

	for (; i < len_tmpt && j < len_path; ++i, ++j) {
		if (tmpt[i] == '?')
			continue;

		if (tmpt[i] == '*' && i + 1 < len_tmpt && tmpt[i+1] == '*') { //if tmpt[i] is last charecter so 'i+1 < len_tmpt' is false and next condition will not be checked
			i+=2;
			for (; j < len_path; ++j) {
				if (cmp(std::string(tmpt, i), std::string(path, j)))
					return true;
			}
			if (j == len_path && i == len_tmpt) 
				return true;
			if (j == len_path || i == len_tmpt)
				return false;
		}

		if (tmpt[i] == '*') {
			for (++i; path[j] != '/' && j < len_path; ++j) {
				if (cmp(std::string(tmpt, i), std::string(path, j)))
					return true;
			}
			if (j == len_path && i == len_tmpt) 
				return true;
			if (j == len_path || i == len_tmpt)
				return false;
		}
		
		if (tmpt[i] != path[j])
			return false;
	}

	if (j == len_path && i < len_tmpt) {  //in case of remaining asterisks in the end of the template
		while (tmpt[i] == '*' && i < len_tmpt)
			++i;
	}

	if (j == len_path && i == len_tmpt)
		return true;
	return false;
}


void path_string_processing(std::string& path)
{
	int size = path.size();
	for (int i = 0; i < size; ++i) {
		path[i] = tolower(path[i]);
		if (path[i] == '\\')
			path[i] = '/';	
	}
}


Path_filter:: Path_filter(const std::vector<std:: string>& vec):
criterias(vec),
size(vec.size())
{
	#ifdef F_WINDOWS
	for (int i = 0; i < size; ++i) {
		path_string_processing(criterias[i]);
	}
	#endif
}

bool Path_filter:: match(std::string path)
{
	#ifdef F_WINDOWS
	path_string_processing(path);
	#endif
	for (int i = 0; i < size; ++i) {
		if (cmp(criterias[i], path))
			return true;
	}

	return false;
}