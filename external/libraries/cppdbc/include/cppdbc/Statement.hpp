#pragma once

#include <memory>

#include "ResultSet.hpp"

namespace CPPDBC {

  class Statement {
  public:

    virtual int64_t execute( const char* command ) = 0;

    virtual std::shared_ptr<ResultSet> executeQuery( const char* query ) = 0;

    virtual const std::string getLastError() = 0;

  };

}
