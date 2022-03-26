
#include "cppdbc/drivers/mysql/MySQLCommon.hpp"

namespace CPPDBC {

  DBFieldType convert_MySQL_Type_To_SQL_Type( enum_field_types MySQLType ) {

    DBFieldType result {};

    if ( MySQLType == enum_field_types::MYSQL_TYPE_TINY ) {

      result = DBFieldType::TYPE_TINY;

    }
    else if ( MySQLType == enum_field_types::MYSQL_TYPE_SHORT ) {

      result = DBFieldType::TYPE_SHORT;

    }
    else if ( MySQLType == enum_field_types::MYSQL_TYPE_LONG ) {

      result = DBFieldType::TYPE_LONG;

    }
    else if ( MySQLType == enum_field_types::MYSQL_TYPE_LONGLONG ) {

      result = DBFieldType::TYPE_LONGLONG;

    }
    else if ( MySQLType == enum_field_types::MYSQL_TYPE_DECIMAL ) {

      result = DBFieldType::TYPE_DECIMAL;

    }
    else if ( MySQLType == enum_field_types::MYSQL_TYPE_FLOAT ) {

      result = DBFieldType::TYPE_FLOAT;

    }
    else if ( MySQLType == enum_field_types::MYSQL_TYPE_DOUBLE ) {

      result = DBFieldType::TYPE_DOUBLE;

    }
    else if ( MySQLType == enum_field_types::MYSQL_TYPE_TIMESTAMP ) {

      result = DBFieldType::TYPE_TIMESTAMP;

    }
    else if ( MySQLType == enum_field_types::MYSQL_TYPE_DATETIME ) {

      result = DBFieldType::TYPE_DATETIME;

    }
    else if ( MySQLType == enum_field_types::MYSQL_TYPE_DATE ) {

      result = DBFieldType::TYPE_DATE;

    }
    else if ( MySQLType == enum_field_types::MYSQL_TYPE_TIME ) {

      result = DBFieldType::TYPE_TIME;

    }
    else if ( MySQLType == enum_field_types::MYSQL_TYPE_JSON ) {

      result = DBFieldType::TYPE_JSON;

    }
    else if ( MySQLType == enum_field_types::MYSQL_TYPE_VAR_STRING ) {

      result = DBFieldType::TYPE_VAR_STRING;

    }
    else if ( MySQLType == enum_field_types::MYSQL_TYPE_STRING ) {

      result = DBFieldType::TYPE_STRING;

    }
    else if ( MySQLType == enum_field_types::MYSQL_TYPE_VARCHAR ) {

      result = DBFieldType::TYPE_VARCHAR;

    }

    return result;

  }

}
