
#include "cppdbc/Common.hpp"

namespace CPPDBC {

  bool isInteger( const DBFieldType dbFieldType ) {

    bool result = false;

    if ( dbFieldType == DBFieldType::TYPE_TINY  ||
        dbFieldType == DBFieldType::TYPE_SHORT ) {

      result = true;

    }

    return result;

  }

  bool isLong( const DBFieldType dbFieldType ) {

    bool result = false;

    if ( dbFieldType == DBFieldType::TYPE_LONG  ||
        dbFieldType == DBFieldType::TYPE_LONGLONG ) {

      result = true;

    }

    return result;

  }

  bool isDecimal( const DBFieldType dbFieldType ) {

    bool result = false;

    if ( dbFieldType == DBFieldType::TYPE_DECIMAL ||
        dbFieldType == DBFieldType::TYPE_FLOAT ||
        dbFieldType == DBFieldType::TYPE_DOUBLE ||
        dbFieldType == DBFieldType::TYPE_TIMESTAMP ) {

      result = true;

    }

    return result;

  }

  bool isNumber( const DBFieldType dbFieldType ) {

    bool result = false;

    if ( isInteger( dbFieldType ) ||
        isDecimal( dbFieldType ) ) {

      result = true;

    }

    return result;

  }

  bool isString( const DBFieldType dbFieldType ) {

    bool result = false;

    if ( dbFieldType == DBFieldType::TYPE_JSON ||
        dbFieldType == DBFieldType::TYPE_VAR_STRING ||
        dbFieldType == DBFieldType::TYPE_VARCHAR ||
        dbFieldType == DBFieldType::TYPE_STRING ) {

      result = true;

    }

    return result;

  }

}
