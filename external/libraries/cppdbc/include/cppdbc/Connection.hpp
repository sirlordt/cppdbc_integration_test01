#pragma once

// #include <string>
// #include <map>
// #include <any>
// #include <vector>
#include <memory>

#include "Common.hpp"
#include "Statement.hpp"
#include "ResultSet.hpp"

namespace CPPDBC {

  class Connection
  {
  public:

    virtual bool connect( const char* host,
                          const char* user,
                          const char* password,
                          const char* database,
                          int port = 3306 ) = 0;
    virtual bool disconnect() = 0;

    virtual bool isConnected() = 0;

    virtual bool setAutoCommit( bool autoCommit ) = 0;
    virtual bool inTransaction() = 0;
    virtual bool begin() = 0;
    virtual void commit() = 0;
    virtual void rollback() = 0;

    virtual std::shared_ptr<Statement> createStatement() = 0;

    virtual void setThrowMode( bool throwMode ) = 0;
    virtual bool getThrowMode() const = 0;

    virtual const std::string getLastError() = 0;

    virtual void* getNativeConnection() = 0;

  };

}
