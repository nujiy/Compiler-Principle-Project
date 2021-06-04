#include "../include/util.h"
std::map<int,std::string> typeMap;
std::map<int,std::string> opMap;
void setMap()
{
    typeMap[VALUEBOOL] = "Bool";
    typeMap[VALUEINT] = "Int";
    typeMap[VALUEFLOAT] = "Float";
    typeMap[VALUEVOID] = "Void";
    opMap[OPADD] = "+";
    opMap[OPSUB] = "-";
    opMap[OPDIV] = "/";
    opMap[OPMUL] = "*";
    opMap[OPMOD] = "%";
    opMap[OPPOW] = "^";
    opMap[OPEQ] = "==";
    opMap[OPGT] = ">";
    opMap[OPLT] = "<";
    opMap[OPELT] = "<=";
    opMap[OPEGT] = ">=";
    opMap[OPNEQ] = "<>";
     opMap[OPAND] = "&&";
    opMap[OPOR] = "|";
}

std::string& getTypeMap(int index)
{
    return typeMap[index];
}

std::string& getOpMap(int index){
    return opMap[index];
}