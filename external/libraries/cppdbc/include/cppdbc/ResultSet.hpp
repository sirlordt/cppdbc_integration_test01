#pragma once

#include <string>
#include <map>
#include <any>
#include <cstdint>

namespace CPPDBC {

  class ResultSet {
  public:

    virtual bool next() = 0;

    virtual short getAsShort( const char* fieldName ) = 0;
    virtual int getAsInt( const char* fieldName ) = 0;
    virtual long getAsLong( const char* fieldName ) = 0;
    virtual long long getAsLongLong( const char* fieldName ) = 0;
    virtual float getAsFloat( const char* fieldName ) = 0;
    virtual double getAsDouble( const char* fieldName ) = 0;
    virtual std::string getAsString( const char* fieldName ) = 0;

    virtual short getAsShort( uint32_t fieldIndex ) = 0;
    virtual int getAsInt( uint32_t fieldIndex ) = 0;
    virtual long getAsLong( uint32_t fieldIndex ) = 0;
    virtual long long getAsLongLong( uint32_t fieldIndex ) = 0;
    virtual float getAsFloat( uint32_t fieldIndex ) = 0;
    virtual double getAsDouble( uint32_t fieldIndex ) = 0;
    virtual std::string getAsString( uint32_t fieldIndex ) = 0;

    virtual const std::string getLastError() = 0;

    virtual int fieldNameExists( const char *fieldName ) = 0;
    virtual bool fieldIndexExists( uint32_t fieldIndex ) = 0;

    virtual const DBFieldInfoList& getMetaData() = 0;
    virtual const DBFieldNameList& getMetaDataFieldNames() = 0;

  };

}
