#ifndef COMPILER_UTIL_H
#define COMPILER_UTIL_H
#include <map>
using namespace std;

#define OPADD 0
#define OPSUB 1
#define OPMUL 2
#define OPDIV 3
#define OPMOD 4
#define OPPOW 5
#define OPGT 6    // larger than
#define OPLT 7    // less than
#define OPEQ 8    // equal

#define VALUEBOOL 0     // determine the type of expression value
#define VALUEINT 1
#define VALUEFLOAT 2
#define VALUECHAR 3
#define VALUEVOID 4

#define EXPRID 0    // determine the expr type variable | literal | binary-expression to be calculate
#define EXPRVALUE 1
#define EXPRBINARY 2
#define EXPRFUNCCALL 2

#define DECLVARIABLE 10
#define DECLPROTO 11
#define DECLPARAM 12

#define STMTEXPR 0
#define STMTASSIGN 1
#define STMTDECL 2
#define STMTRETURN 3

void setMap();
string& getTypeMap(int index);
string& getOpMap(int index);
#endif //COMPILER_UTIL_H
