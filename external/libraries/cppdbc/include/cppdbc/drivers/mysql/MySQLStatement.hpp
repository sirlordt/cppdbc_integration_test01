#pragma once

#include "MySQLConnection.hpp"

#include "cppdbc/Statement.hpp"

namespace CPPDBC {

  class MySQLStatement: public Statement {
  public:

    MySQLStatement( MySQLConnection *connection );

    int64_t execute( const char* command ) override;

    std::shared_ptr<ResultSet> executeQuery( const char* query ) override;

    const std::string getLastError() override;

  protected:

    MySQLConnection* m_connection_ { nullptr };

    bool m_throwMode_ { false };

    std::string m_lastError_ {};

  };

}
