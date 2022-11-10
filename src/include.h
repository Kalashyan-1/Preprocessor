#include "helpers.h"


void pars_1(std::string& tmp1, std::string& tmp2, int& include_line_num) {

        std::fstream f;

        f.open(name, std::ios::in);
        std::string s;
        int line_num = 0;
        bool b = false;

        while (getline(f,s)) {
                        int times = 1;
                        ++line_num;

                for (int i = 0; s[i] != '\0'; ++i) {
                        if (s[i] == 32) {
                                continue;
                        }
                                if (times == 1) {
                                while (s[i] != 32) {
                                        tmp1 += s[i];
                                        ++i;

                                }
                                }
                                        if (tmp1 == "#include"){
                                        include_line_num = get_line_num(line_num, tmp1);
                                        ++times;
                                        } else {
                                                tmp1 = "";
                                                break;
                                        }

                                if (times == 2) {
                                        i = i + 2;
                                while (s[i] != 34) {
                                   tmp2 += s[i];
                                        ++i;
                                }
                                b = true;
                                break;
                                }
                }
                if (b) {
                        break;
                }
        }
        f.close();

}


void include() {




        del_copy(include_line_num, tmp2);
        tmp1 = "";
        tmp2 = "";
        include_line_num = 0;
        pars_1(tmp1, tmp2, include_line_num);
        if (tmp1 == "#include")
        {
                include();

        }

}

