#include <string>
#include <map>

        std::string tmp1 = "";
        std::string tmp2 = "";
        int include_line_num = 0;
        std::string name = "";


enum class enum_directives {

        INCLUDE,
        IFDEF,
        DEFINE,
        UNDEF,
        ENDIF,
        IFNDEF,
};

struct dir_name {

        std::map<std::string, enum_directives> dir_name_map;
};

void dir_name_init(dir_name* d) {

        d -> dir_name_map["#include"] = enum_directives::INCLUDE;
        d -> dir_name_map["#ifdef"] = enum_directives::IFDEF;
        d -> dir_name_map["#define"] = enum_directives::DEFINE;
        d -> dir_name_map["#undef"] = enum_directives::UNDEF;
        d -> dir_name_map["#endif"] = enum_directives::ENDIF;
        d -> dir_name_map["#ifndef"] = enum_directives::IFNDEF;

}

