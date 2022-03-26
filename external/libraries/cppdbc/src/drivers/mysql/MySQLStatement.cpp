
#include <stdexcept>

#include "cppdbc/drivers/mysql/MySQLStatement.hpp"
#include "cppdbc/drivers/mysql/MySQLResultSet.hpp"

namespace CPPDBC {

  MySQLStatement::MySQLStatement( MySQLConnection* connection ): m_connection_( connection )
  {

    //

  }

  int64_t MySQLStatement::execute( const char* command )
  {

    int64_t result = 0;

    if ( this->m_connection_ && this->m_connection_->isConnected() )
    {

      if ( !mysql_query( (MYSQL*) this->m_connection_->getNativeConnection(), command ) )
      {

        result = mysql_affected_rows( (MYSQL*) this->m_connection_->getNativeConnection() );

      }
      else
      {

        this->m_lastError_ = mysql_error( (MYSQL*) this->m_connection_->getNativeConnection() );

        if ( this->m_throwMode_ )
        {

          throw std::runtime_error( this->m_lastError_ );

        }

      }

    }
    else
    {

      this->m_lastError_ = "No connection open";

      if ( this->m_throwMode_ )
      {

        throw std::runtime_error( this->m_lastError_ );

      }

    }

    return result;

  }

  std::shared_ptr<ResultSet> MySQLStatement::executeQuery( const char* query )
  {

    std::shared_ptr<MySQLResultSet> result {};
    //MySQlResultSet* result {};

    if ( this->m_connection_ &&
        this->m_connection_->isConnected() )
    {

      if ( !mysql_query( (MYSQL*) m_connection_->getNativeConnection(), query ) )
      {

        result = std::make_shared<MySQLResultSet>( mysql_store_result( (MYSQL*) m_connection_->getNativeConnection() ) );

      }
      else
      {

        this->m_lastError_ = mysql_error( (MYSQL*) m_connection_->getNativeConnection() );

        if ( this->m_throwMode_ )
        {

          throw std::runtime_error( this->m_lastError_ );

        }

      }

    }
    else
    {

      this->m_lastError_ = "No connection open";

      if ( this->m_throwMode_ )
      {

        throw std::runtime_error( this->m_lastError_ );

      }

    }

    return result;

  }

  const std::string MySQLStatement::getLastError()
  {

    return this->m_lastError_;

  }

}
