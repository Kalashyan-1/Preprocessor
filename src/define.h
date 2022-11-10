#include "include.h"
#include <vector>

std::map<std::string, std::string> map_d;
std::vector<std::string> vec;

void define(dir_name* d) {
        std::fstream f1, f2;
        std::string s1 = "";
        std::string s2 = "";
        std::string s3 = "";
        std::string new_line = "";
        int i = 0;
        bool c = true;
        bool c2 = false;
        f1.open(name, std::ios::in);
        f2.open("chlp.chlp", std::ios::out);
        while (getline(f1, s1)) {
                bool b = true;
                new_line = "";
                if (c && !(c2)) {
                for (int i = 0; s1[i] != '\0'; ++i) {
                        if (s1[i] == 32 || s1[i] == 9){
                        new_line += s1[i];
                        continue;

                        }else {   
  				s2 = "";
                        while (s1[i] != ' ') {
                                s2 += s1[i];
                                ++i;
                                if (s1[i] == '\0') {
                                        break;
                                }
                        }
                       
				--i;
                        switch (d->dir_name_map[s2]) {
                                case enum_directives::DEFINE:
                                                ++i;
                                                for (int k = i; s1[k] != '\0'; ++k) {
                                                        if (s1[k] == ' ') {
                                                                continue;
                                                        } else {
                                                                s3 += s1[k];
                                                                if (s1[k + 1] == ' ' || s1[k + 1] == '\0') {
                                                                        vec.push_back(s3);
                                                                        s3 = "";
                                                                }

                                                        }
                                                }
                                                map_d[vec[0]] = vec[1];
                                                vec.clear();
                                        break;

                                case enum_directives::IFDEF:
                                                ++i;
                                                for (int k = i; s1[k] != '\0'; ++k) {
                                                        if (s1[k] == ' ') {
                                                                continue;
                                                        } else {
                                                                s3 += s1[k];
                                                        }
                                                }

                                                c = contains(s3, map_d);
                                                s3 = "";
                                                break;
                                case enum_directives::ENDIF:

                                        break;
                                case enum_directives::UNDEF:
                                        for (int k = i; s1[k] != '\0'; ++k) {
                                                        if (s1[k] == ' ') {
                                                                continue;
                                                        } else {
                                                                s3 += s1[k];
                                                        }
                                                }

                                                if(contains(s3, map_d)) {
                                                        map_d.erase(s3);
                                                }
                                                s3 = "";
                                        break;
                                case enum_directives::IFNDEF:
                                        for (int k = i; s1[k] != '\0'; ++k) {
                                                        if (s1[k] == ' ') {
                                                                continue;
                                                        } else {
                                                                s3 += s1[k];
                                                        }
                                                }

                                                c2 = contains(s3, map_d);
                                                s3 = "";
                                        break;
                                default:
                                if (contains(s2, map_d)) {
                                       new_line += map_d[s2];
                                } else {
                                new_line += s2;
                                }
                                b = false;
                        }  //end switch
                        s2 = "";
                        }// end else
                         if (b) {
                                 new_line = "";
                        break;
                         }

                }//end for
                                if (!b) {
                                f2 << new_line;
                                f2 << "\n";
                                }
                } else {
                        for (int i = 0; s1[i] != '\0'; ++i) {
                        if (s1[i] == ' ') {
                        continue;
                        } else {
                                s3 += s1[i];
                                if (s3 == "#endif") {
                                        c = true;
                        }
                }
                }
                        s3 = "";


                }

        }
        const char* ch = name.c_str();
        remove(ch);
        rename("chlp.chlp", ch);


}


std::map<enum_directives, void(*)()> func_pointer;

void init_func_pointer(std::map<enum_directives, void(*)()>& func_pointer) {
func_pointer[enum_directives::INCLUDE] = &include;
}


void determin_dir_name(int l_num, std::string& tmp11, dir_name* d, std::map<enum_directives, void(*)()>& func_pointer) {
        func_pointer[d->dir_name_map[tmp11]]();
}

