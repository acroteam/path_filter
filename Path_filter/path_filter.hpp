#include <string>
#include <vector>

/**/



/*this function compares two strings, and consider using wildcards in tmpt (tempplate)*/
bool cmp(const std:: string& tmpt, const std:: string&path);

/* Path string process (used for windows paths):
  1) replace uppercase letter with lowercase  
  2) replace backslash '\' with normal '/'
  */
void path_string_processing(std::string& path);


/*
	Class which conatins path templates */
class Path_filter {
private:
	std:: vector<std:: string> criterias;
	int size;
public:
	Path_filter(const std::vector<std:: string>& vec);
	Path_filter() = delete;
	~Path_filter() = default;
	/*Check whether path match any template*/
	bool match (std:: string path);
}; 





