#pragma once

#include <mysql/mysql.h>

#include "cppdbc/Common.hpp"

namespace CPPDBC {

  DBFieldType convert_MySQL_Type_To_SQL_Type( enum_field_types MySQLType );

}
