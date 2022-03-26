
#include <algorithm>
#include <stdexcept>
#include <sstream>

#include "cppdbc/Common.hpp"

//#include "cppdbc/drivers/mysql/MySQLStatement.hpp"
#include "cppdbc/drivers/mysql/MySQLResultSet.hpp"
#include "cppdbc/drivers/mysql/MySQLCommon.hpp"

namespace CPPDBC {

  MySQLResultSet::MySQLResultSet( MYSQL_RES *queryResultSet ): m_queryResultSet_( queryResultSet )
  {

    int fieldIndex = 0;

    MYSQL_FIELD *field { nullptr };

    while ( field = mysql_fetch_field( this->m_queryResultSet_ ) )
    {

      DBFieldInfo dbFieldInfo { fieldIndex, field->name, convert_MySQL_Type_To_SQL_Type( field->type ) };

      m_queryResultSetFieldInfoList_.push_back( dbFieldInfo );

      m_queryResultSetFieldNameList_.push_back( dbFieldInfo.name );

      fieldIndex += 1;

    }

  }

  MySQLResultSet::~MySQLResultSet()
  {

    if ( this->m_queryResultSet_ )
    {

      mysql_free_result( this->m_queryResultSet_ );
      this->m_queryResultSet_ = nullptr;

    }

  }

  bool MySQLResultSet::next()
  {

    bool result = false;

    if ( this->m_queryResultSet_ )
    {

      this->m_queryResultSetCurrentRawRow_ = mysql_fetch_row( this->m_queryResultSet_ );

      if ( this->m_queryResultSetCurrentRawRow_ )
      {

        result = true;

        /*
        for ( auto fieldInfo: this->m_queryResultFieldInfoList )
        {

          result[ fieldInfo.name ] = convertToType( fieldInfo.type, row[ fieldInfo.index ] );

        }
        */

      }
      else
      {

        this->m_lastError_ = "EOF";

        if ( this->m_throwMode_ )
        {

          throw std::runtime_error( this->m_lastError_ );

        }

      }

    }
    else
    {

      this->m_lastError_ = "No result to fetch";

      if ( this->m_throwMode_ )
      {

        throw std::runtime_error( this->m_lastError_ );

      }

    }

    return result;

  }

  short MySQLResultSet::getAsShort( const char* fieldName )
  {

    short result = 0;

    int fieldIndex = this->fieldNameExists( fieldName );

    if ( fieldIndex >= 0 )
    {

      if ( CPPDBC::isInteger( this->m_queryResultSetFieldInfoList_[ fieldIndex ].type ) )
      {

        result = std::stoi( this->m_queryResultSetCurrentRawRow_[ fieldIndex ] );

      }
      else
      {

        std::stringstream ss;
        ss << "The field with name [" << fieldName << "]. Not contains a short number value";

        this->m_lastError_ = ss.str();

        if ( this->m_throwMode_ )
        {

          throw std::runtime_error( this->m_lastError_ );

        }

      }

    }
    else
    {

      std::stringstream ss;
      ss << "Field with name [" << fieldName << "] not found";

      this->m_lastError_ = ss.str();

      if ( this->m_throwMode_ )
      {

        throw std::runtime_error( this->m_lastError_ );

      }

    }

    return result;

  }

  int MySQLResultSet::getAsInt( const char* fieldName )
  {

    int result = 0;

    int fieldIndex = this->fieldNameExists( fieldName );

    if ( fieldIndex >= 0 )
    {

      if ( CPPDBC::isInteger( this->m_queryResultSetFieldInfoList_[ fieldIndex ].type ) )
      {

        result = std::stoi( this->m_queryResultSetCurrentRawRow_[ fieldIndex ] );

      }
      else
      {

        std::stringstream ss;
        ss << "The field with name [" << fieldName << "]. Not contains a int number value";

        this->m_lastError_ = ss.str();

        if ( this->m_throwMode_ )
        {

          throw std::runtime_error( this->m_lastError_ );

        }

      }

    }
    else
    {

      std::stringstream ss;
      ss << "Field with name [" << fieldName << "] not found";

      this->m_lastError_ = ss.str();

      if ( this->m_throwMode_ )
      {

        throw std::runtime_error( this->m_lastError_ );

      }

    }

    return result;

  }

  long MySQLResultSet::getAsLong( const char* fieldName )
  {

    long result = 0;

    int fieldIndex = this->fieldNameExists( fieldName );

    if ( fieldIndex >= 0 )
    {

      if ( CPPDBC::isLong( this->m_queryResultSetFieldInfoList_[ fieldIndex ].type ) )
      {

        result = std::stol( this->m_queryResultSetCurrentRawRow_[ fieldIndex ] );

      }
      else
      {

        std::stringstream ss;
        ss << "The field with name [" << fieldName << "]. Not contains a long number value";

        this->m_lastError_ = ss.str();

        if ( this->m_throwMode_ )
        {

          throw std::runtime_error( this->m_lastError_ );

        }

      }

    }
    else
    {

      std::stringstream ss;
      ss << "Field with name [" << fieldName << "] not found";

      this->m_lastError_ = ss.str();

      if ( this->m_throwMode_ )
      {

        throw std::runtime_error( this->m_lastError_ );

      }

    }

    return result;

  }

  long long MySQLResultSet::getAsLongLong( const char* fieldName )
  {

    long long result = 0;

    int fieldIndex = this->fieldNameExists( fieldName );

    if ( fieldIndex >= 0 )
    {

      if ( CPPDBC::isLong( this->m_queryResultSetFieldInfoList_[ fieldIndex ].type ) )
      {

        result = std::stoll( this->m_queryResultSetCurrentRawRow_[ fieldIndex ] );

      }
      else
      {

        std::stringstream ss;
        ss << "The field with name [" << fieldName << "]. Not contains a long long number value";

        this->m_lastError_ = ss.str();

        if ( this->m_throwMode_ )
        {

          throw std::runtime_error( this->m_lastError_ );

        }

      }

    }
    else
    {

      std::stringstream ss;
      ss << "Field with name [" << fieldName << "] not found";

      this->m_lastError_ = ss.str();

      if ( this->m_throwMode_ )
      {

        throw std::runtime_error( this->m_lastError_ );

      }

    }

    return result;

  }

  float MySQLResultSet::getAsFloat( const char* fieldName )
  {

    return 0.0f;

  }

  double MySQLResultSet::getAsDouble( const char* fieldName )
  {

    return 0.0;

  }

  std::string MySQLResultSet::getAsString( const char* fieldName )
  {

    std::string result = "";

    int fieldIndex = this->fieldNameExists( fieldName );

    if ( fieldIndex >= 0 )
    {

      if ( CPPDBC::isString( this->m_queryResultSetFieldInfoList_[ fieldIndex ].type ) )
      {

        result = this->m_queryResultSetCurrentRawRow_[ fieldIndex ];

      }
      else
      {

        std::stringstream ss;
        ss << "The field with name [" << fieldName << "]. Not contains a string value";

        this->m_lastError_ = ss.str();

        if ( this->m_throwMode_ )
        {

          throw std::runtime_error( this->m_lastError_ );

        }

      }

    }
    else
    {

      std::stringstream ss;
      ss << "Field with name [" << fieldName << "] not found";

      this->m_lastError_ = ss.str();

      if ( this->m_throwMode_ )
      {

        throw std::runtime_error( this->m_lastError_ );

      }

    }

    return result;

  }

  short MySQLResultSet::getAsShort( uint32_t fieldIndex )
  {

    short result = 0;

    if ( fieldIndex >= 0 )
    {

      if ( CPPDBC::isInteger( this->m_queryResultSetFieldInfoList_[ fieldIndex ].type ) )
      {

        result = std::stoi( this->m_queryResultSetCurrentRawRow_[ fieldIndex ] );

      }
      else
      {

        std::stringstream ss;
        ss << "The field with index [" << fieldIndex << "]. Not contains a short number value";

        this->m_lastError_ = ss.str();

        if ( this->m_throwMode_ )
        {

          throw std::runtime_error( this->m_lastError_ );

        }

      }

    }
    else
    {

      std::stringstream ss;
      ss << "Field with with index [" << fieldIndex << "] not found";

      this->m_lastError_ = ss.str();

      if ( this->m_throwMode_ )
      {

        throw std::runtime_error( this->m_lastError_ );

      }

    };

    return result;

  }

  int MySQLResultSet::getAsInt( uint32_t fieldIndex )
  {

    return 0;

  }

  long MySQLResultSet::getAsLong( uint32_t fieldIndex )
  {

    return 0;

  }

  long long MySQLResultSet::getAsLongLong( uint32_t fieldIndex )
  {

    return 0;

  }

  float MySQLResultSet::getAsFloat( uint32_t fieldIndex )
  {

    return 0.0f;

  }

  double MySQLResultSet::getAsDouble( uint32_t fieldIndex )
  {

    return 0.0;

  }

  std::string MySQLResultSet::getAsString( uint32_t fieldIndex )
  {

    return "";

  }

  const std::string MySQLResultSet::getLastError()
  {

    return this->m_lastError_;

  }

  int MySQLResultSet::fieldNameExists( const char *fieldName )
  {

    //auto it = find( v.begin(), v.end(), K);

    int result = -1;

    auto it = std::find( m_queryResultSetFieldNameList_.begin(),
                        m_queryResultSetFieldNameList_.end(),
                        fieldName ); // != m_queryResultSetFieldNameList_.end();

    if ( it !=  m_queryResultSetFieldNameList_.end() ) {

      result = it - m_queryResultSetFieldNameList_.begin();

    }

    return result;

  }

  bool MySQLResultSet::fieldIndexExists( uint32_t fieldIndex )
  {

    return fieldIndex < m_queryResultSetFieldNameList_.size();

  }

  const DBFieldInfoList& MySQLResultSet::getMetaData()
  {

    return this->m_queryResultSetFieldInfoList_;

  }

  const DBFieldNameList& MySQLResultSet::getMetaDataFieldNames()
  {

    return this->m_queryResultSetFieldNameList_;

  }

  void MySQLResultSet::setThrowMode( const bool throwMode )
  {

    this->m_throwMode_ = throwMode;

  }

  bool MySQLResultSet::getThrowMode() const
  {

    return this->m_throwMode_;

  }

}
