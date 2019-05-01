#include "stringUtil.h"

std::vector<std::string> splitString(std::string s, std::string separador){
    std::vector<std::string> strings;
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(separador)) != std::string::npos) {
        token = s.substr(0, pos);        
        s.erase(0, pos + separador.length());
        strings.push_back(token);
    }
    strings.push_back(s);   
    return strings;
}

bool isNumber(const std::string& s){  
    try {
        std::stod(s);
    }
    catch(...)
    {
        return false;
    }
    return true;

}