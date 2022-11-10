#include "initialization.h"

#include <iostream>
#include <fstream>

bool contains(std::string s1, std::map<std::string, std::string> map_d) {

        std::map<std::string, std::string>::iterator it;
        for (it = map_d.begin(); it != map_d.end(); ++it) {

                if (s1 == it->first) {
                return true;
                }
        }

        return false;
}
int get_line_num(int i, std::string& s) {

        if (s == "#include") {
                return i;
        }
        return 0;
}

void del_copy(int i, std::string header) {
        std::cout << name;
        std::cout << header;
        std::fstream f, f2, f3;
        std::string s;
        f.open(name, std::ios::in);
        f2.open("foo.cpp", std::ios::out);
        f3.open(header, std::ios::in);
        f2 << f3.rdbuf();
        int l = 0;
        while (getline(f, s)) {

                ++l;
        if (l == i) {
        continue;
        }
        f2 << s << "\n";
        }

        f.close();
        f2.close();
        f3.close();
        const char* ch = name.c_str();
        remove(ch);
        rename("foo.cpp", ch);

}

