# Path_filter

Small class, which can compare path with set of templates and take into account wildcards.

# Wildcads:
  You can use wildcard character in templates. Here is all types:
1) '?' - substitutes only for one character including slash character.
2) '*' - substitutes for zero or more characters in a file name except slash character.
3) '\**' - substitutes for zero or more characters in a file name, including slash character.

# Path_filter class:
1) const std::vector<std:: string>& is passed to the constructor, this vecotr contains all templates you need for checking.
2) use method match(std:: string path) it returns true if path is matched with one of your templates oterwise false is returned.
