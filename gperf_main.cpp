
#include "dict.h"
#include <string>

int main( void )
{
    std::string str[4];
    str[0] = "dd";
    str[1] = "aa";
    str[2] = "cc";
    str[3] = "c";
    for ( int i=0; i<4; i++ ) { 
        const struct dictionaryInfo *ret = dictionary::searchDict( str[i].c_str(), str[i].length() );
        if ( ret ) { 
            printf( "key: %s\tvalue: %s\n", ret->name, ret->value );
        } else {
            printf( "Cannot find key %s\n", str[i].c_str() );
        }   
    }   
    return 0;
}
