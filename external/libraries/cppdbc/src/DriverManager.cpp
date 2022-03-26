
#include <string.h>

#include "cppdbc/DriverManager.hpp"

#include <cppdbc/drivers/mysql/MySQLConnection.hpp>

namespace CPPDBC
{

  void DriverManager::registerDriver( const std::string& driver,
                                      const DriverCreationFunction& creationFunction ) {

    DriverManager::m_driverCreationFunctionList_[ driver ] = creationFunction;

  }

  std::shared_ptr<Connection> DriverManager::getConnection( const char* driver ) {

    std::shared_ptr<Connection> result {};

    if ( DriverManager::m_driverCreationFunctionList_[ driver ] ) {

      result = DriverManager::m_driverCreationFunctionList_[ driver ]();

    }
    else if ( strcmp( driver, "mysql" ) == 0 ) {

      result = std::make_shared<MySQLConnection>();

    }

    return result;

  }

}
