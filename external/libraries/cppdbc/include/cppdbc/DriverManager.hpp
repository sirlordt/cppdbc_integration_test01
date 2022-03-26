#pragma once

#include <memory>
#include <functional>

#include "cppdbc/Connection.hpp"

namespace CPPDBC
{

  class DriverManager {
  public:

    using DriverCreationFunction     = std::function<std::shared_ptr<Connection>()>;
    using DriverCreationFunctionList = std::map<std::string,DriverCreationFunction>;

    static void registerDriver( const std::string& driver,
                                const DriverCreationFunction& creationFunction );

    static std::shared_ptr<Connection> getConnection( const char* driver );

  private:

    DriverManager() = default;

    inline static DriverCreationFunctionList m_driverCreationFunctionList_ {  };

  };

} // namespace CPPDBC


