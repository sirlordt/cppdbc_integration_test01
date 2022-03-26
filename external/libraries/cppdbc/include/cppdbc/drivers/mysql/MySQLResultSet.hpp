#pragma once

#include <mysql/mysql.h>

#include "cppdbc/Common.hpp"

#include "cppdbc/ResultSet.hpp"

namespace CPPDBC {

  class MySQLResultSet : public ResultSet {
  public:

    MySQLResultSet( MYSQL_RES *queryResultSet );
    ~MySQLResultSet();

    bool next() override;

    short getAsShort( const char* fieldName ) override;
    int getAsInt( const char* fieldName ) override;
    long getAsLong( const char* fieldName ) override;
    long long getAsLongLong( const char* fieldName ) override;
    float getAsFloat( const char* fieldName ) override;
    double getAsDouble( const char* fieldName ) override;
    std::string getAsString( const char* fieldName ) override;

    short getAsShort( uint32_t fieldIndex ) override;
    int getAsInt( uint32_t fieldIndex ) override;
    long getAsLong( uint32_t fieldIndex ) override;
    long long getAsLongLong( uint32_t fieldIndex ) override;
    float getAsFloat( uint32_t fieldIndex ) override;
    double getAsDouble( uint32_t fieldIndex ) override;
    std::string getAsString( uint32_t fieldIndex ) override;

    const std::string getLastError() override;

    int fieldNameExists( const char *fieldName ) override;
    bool fieldIndexExists( uint32_t fieldIndex ) override;

    const DBFieldInfoList& getMetaData() override;
    const DBFieldNameList& getMetaDataFieldNames() override;

    void setThrowMode( const bool throwMode );
    bool getThrowMode() const;

  protected:

    MYSQL_RES *m_queryResultSet_ { nullptr };

    MYSQL_ROW m_queryResultSetCurrentRawRow_ { nullptr };

    DBFieldNameList m_queryResultSetFieldNameList_ {};

    DBFieldInfoList m_queryResultSetFieldInfoList_ {};

    bool m_throwMode_ { false };

    std::string m_lastError_ {};

  };

}
