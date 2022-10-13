#include "lab18_class_impl.h"


int main() {

      std::fstream file;
      std::string path = "/Users/denis_adidas/CLionProjects/lab18/test.txt";
      file.open(path);

      std::string str;
      char ch;

      while (file.get(ch)) {
          str.push_back(ch);
      }

      char* cstr = new char[str.length()+1];
      std::strcpy (cstr, str.c_str());

      char* token = strtok(cstr, " \n,'?!;:");
      multiset<std::string> a(" ");

      while (token != NULL)
      {
          a.insert(token);
          token = strtok(NULL, " \n,'?!;:");
      }

      std::cout << a.get_size();
      
    return 0;
}
