//
// Created by Administrator on 2022/12/21 0021.
//

#ifndef MY_LIBFM_CMDLINE_H
#define MY_LIBFM_CMDLINE_H
#include <map>
#include <vector>
#include <string>

class CMDLine{
public:
    CMDLine(int argc, char **argv);

    std::string delimiter;

//protected:
    bool parse_name(std::string& s);
    std::map<std::string, std::string> help;
    std::map<std::string, std::string> value;

};


bool CMDLine::parse_name(std::string &s) {
    if ( ( s.length() > 0 ) && ( s[0] == '-' ) ){
        if ( ( s.length() > 1 ) && ( s[1] == '-' ) ){
            s = s.substr(2);
        }else{
            s = s.substr(1);
        }
        return true;
    } else{
        return false;
    }
}


CMDLine::CMDLine(int argc, char **argv) {
    delimiter = ";,";
    int i = 1;
    while (i < argc){
        std::string s(argv[i]);
        if ( parse_name(s) ){
            if ( value.find(s) != value.end() ){
                throw "the parameter " + s + " is already specified";
            }
            if ( (i + 1) < argc ){
                std::string s_next(argv[i + 1]);
                if (!parse_name(s_next)){
                    value[s] = s_next;
                    i++;
                } else {
                    value[s] = "";
                }
            } else {
                value[s] = "";
            }
        } else {
            throw "cannot parse " + s;
        }
        i++;
    }
}


#endif //MY_LIBFM_CMDLINE_H