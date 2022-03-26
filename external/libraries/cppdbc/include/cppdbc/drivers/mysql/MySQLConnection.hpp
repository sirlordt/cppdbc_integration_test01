#pragma once

#include "cppdbc/Connection.hpp"
#include "cppdbc/Statement.hpp"

//#include "cppdbc/drivers/mysql/MySQLStatement.hpp"

#include <string>

#include <mysql/mysql.h>

namespace CPPDBC {

  class MySQLConnection : public Connection
  {
  public:

    MySQLConnection();
    virtual ~MySQLConnection();

    bool connect( const char* host,
                  const char* user,
                  const char* password,
                  const char* database,
                  int port = 3306 ) override;
    bool disconnect() override;

    bool isConnected() override;

    bool setAutoCommit( bool autoCommit ) override;
    bool inTransaction() override;
    bool begin() override;
    void commit() override;
    void rollback() override;

    std::shared_ptr<Statement> createStatement() override;

    void setThrowMode( bool throwMode );
    bool getThrowMode() const;

    // bool query( const char* command ) override;
    // uint64_t execute( const char* command ) override;

    //const DBFieldNameList& fetchRowFieldName() const override;
    //const DBFieldTypeList& fetchRowFieldType() const override;
    //const DBFieldInfoList& fetchRowFieldInfo() const override;

    // DBRecord fetchRow() override;
    // DBRecordList fetchAllRow() override;

    const std::string getLastError() override;

    void* getNativeConnection() override;

  protected:

    friend class MySQLStatement;

    MYSQL *m_connection_ { nullptr };

    bool m_throwMode_ { false };

    bool m_inTransaction_ { false };

    //MYSQL_RES *m_queryResult_ { nullptr };

    //int m_query_resultFieldCount { 0 };

    //DBFieldNameList m_queryResultFieldNameList {};

    //DBFieldTypeList m_queryResultFieldTypeList {};

    //DBFieldInfoList m_queryResultFieldInfoList {};

    std::string m_lastError_ {};

  };

}
