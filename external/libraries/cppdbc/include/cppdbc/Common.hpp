#pragma once

#include <string>
#include <map>
#include <any>
#include <vector>

namespace CPPDBC {

  enum class DBFieldType {

    //Number
    TYPE_TINY        = 0,
    TYPE_SHORT       = 1,
    TYPE_LONG        = 2,
    TYPE_LONGLONG    = 3,

    //Decimal
    TYPE_DECIMAL     = 4,
    TYPE_FLOAT       = 5,
    TYPE_DOUBLE      = 6,
    TYPE_TIMESTAMP   = 7,

    //Date time
    TYPE_DATE        = 8,
    TYPE_TIME        = 9,
    TYPE_DATETIME    = 10,

    //Boolean
    TYPE_BOOL        = 11,

    //Blob
    TYPE_TINY_BLOB   = 14,
    TYPE_MEDIUM_BLOB = 15,
    TYPE_LONG_BLOB   = 16,
    TYPE_BLOB        = 17,

    //String
    TYPE_JSON        = 18,
    TYPE_VAR_STRING  = 19,
    TYPE_VARCHAR     = 20,
    TYPE_STRING      = 21

  };

  struct DBFieldInfo {

    int index;
    std::string name;
    DBFieldType type;

  };

  using DBFieldNameList = std::vector<std::string>;
  using DBFieldInfoList = std::vector<DBFieldInfo>;

  bool isInteger( const DBFieldType dbFieldType );
  bool isLong( const DBFieldType dbFieldType );
  bool isDecimal( const DBFieldType dbFieldType );
  bool isNumber( const DBFieldType dbFieldType );
  bool isString( const DBFieldType dbFieldType );

}
