
#include <stdexcept>

#include "cppdbc/drivers/mysql/MySQLConnection.hpp"

#include "cppdbc/drivers/mysql/MySQLStatement.hpp"

//#include <stdexcept>

namespace CPPDBC {

  MySQLConnection::MySQLConnection()
  {

    //

  }

  MySQLConnection::~MySQLConnection()
  {

    if ( this->m_connection_ )
    {

      mysql_close( this->m_connection_ );
      this->m_connection_ = nullptr;

    }

    // if ( this->m_queryResult_ )
    // {

    //   mysql_free_result( this->m_queryResult_ );
    //   this->m_queryResult_ = nullptr;

    // }

    m_lastError_ = "";

  }

  bool MySQLConnection::connect( const char* host,
                                const char* user,
                                const char* password,
                                const char* database,
                                int port )
  {

    bool result = false;

    if ( this->m_connection_ == nullptr )
    {

      this->m_connection_ = mysql_init( nullptr );

      if ( mysql_real_connect( this->m_connection_,
                              host,
                              user,
                              password,
                              database,
                              port,
                              NULL,
                              0 ) != nullptr )
      {

        result = true;

      }
      else
      {

        this->m_lastError_ = mysql_error( this->m_connection_ );

        mysql_close( this->m_connection_ );

        this->m_connection_ = nullptr;

        if ( this->m_throwMode_ )
        {

          throw std::runtime_error( this->m_lastError_ );

        }

      }

    }
    else
    {

      this->m_lastError_ = "Connection already open";

      if ( this->m_throwMode_ )
      {

        throw std::runtime_error( this->m_lastError_ );

      }

    }

    return result;

  }

  bool MySQLConnection::disconnect()
  {

    bool result = false;

    if ( this->m_connection_ )
    {

      mysql_close( this->m_connection_ );

      this->m_connection_ = nullptr;

      result = true;

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

  bool MySQLConnection::isConnected()
  {

    return this->m_connection_ != nullptr &&
           mysql_ping( this->m_connection_ ) == 0;

  };

  bool MySQLConnection::setAutoCommit( bool autoCommit )
  {

    bool result = false;

    if ( this->m_connection_ )
    {

      if ( !mysql_autocommit( this->m_connection_, autoCommit ) )
      {

        this->m_lastError_ = mysql_error( this->m_connection_ );

        if ( this->m_throwMode_ )
        {

          throw std::runtime_error( this->m_lastError_ );

        }

      }

      result = true;

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

  bool MySQLConnection::inTransaction()
  {

    return this->m_inTransaction_;

  }

  bool MySQLConnection::begin()
  {

    bool result = false;

    if ( !this->m_inTransaction_ )
    {

      this->m_inTransaction_ = true;

      result = true;

    }

    return result;

  }

  void MySQLConnection::commit()
  {

    if ( this->m_inTransaction_ && this->isConnected() )
    {

      if ( !mysql_commit( this->m_connection_ ) )
      {

        this->m_lastError_ = mysql_error( this->m_connection_ );

        if ( this->m_throwMode_ )
        {

          throw std::runtime_error( this->m_lastError_ );

        }

      }
      else
      {

        this->m_inTransaction_ = false;

      }

    }

  }

  void MySQLConnection::rollback()
  {

    if ( this->m_inTransaction_ && this->isConnected() )
    {

      if ( !mysql_rollback( this->m_connection_ ) )
      {

        this->m_lastError_ = mysql_error( this->m_connection_ );

        if ( this->m_throwMode_ )
        {

          throw std::runtime_error( this->m_lastError_ );

        }

      }
      else
      {

        this->m_inTransaction_ = false;

      }

    }

  }

  std::shared_ptr<Statement> MySQLConnection::createStatement()
  {

    return std::make_shared<MySQLStatement>( this );

  }

  void MySQLConnection::setThrowMode( bool throwMode )
  {

    this->m_throwMode_ = throwMode;

  }

  bool MySQLConnection::getThrowMode() const
  {

    return this->m_throwMode_;

  }

  const std::string MySQLConnection::getLastError()
  {

    return this->m_lastError_;

  }

  void* MySQLConnection::getNativeConnection()
  {

    return this->m_connection_;

  };

}
