# IneptLogger
IneptLogger is a lightweight logging library for C++. It provides support for logging messages with different colors and levels, making it easy to differentiate between different types of messages.

## Purpose
The purpose of IneptLogger is to make logging in C++ projects more efficient and convenient. By providing support for different logging levels and colors, IneptLogger makes it easy to quickly identify and locate important messages in your logs. Additionally, IneptLogger allows you to redirect your log output to a different stream, such as a file or a stringstream, making it easy to save logs or analyze them programmatically.

## Installation
To install IneptLogger, you will need to have CMake installed on your system. Once CMake is installed, you can use the following commands to build and install the library:
```
git clone https://github.com/username/IneptLogger.git
cd IneptLogger
mkdir build
cd build
cmake ..
make
make install
```

## Usage
To use IneptLogger, you need to include the Log.h header file and link to the IneptLogger library.
Here is an example of how to use IneptLogger in your code:

```
#include "Log.h"

int main() {
    Inept::Logging::Log::Init(); // initialize the log
    Inept::Logging::Log::logMessage(Inept::Logging::LogLevel::LOGERROR, "This is an error message.");
    Inept::Logging::Log::logMessage(Inept::Logging::LogLevel::LOGWARNING, "This is a warning message.");
    Inept::Logging::Log::logMessage(Inept::Logging::LogLevel::LOGINFO, "This is an info message.");
    Inept::Logging::Log::logMessage(Inept::Logging::LogLevel::LOGDEBUG, "This is a debug message.");
    Inept::Logging::Log::logMessage(Inept::Logging::LogLevel::LOGTRACE, "This is a trace message.");
    return 0;
}
```

This will output log messages with different colors depending on the log level specified.

You can also redirect your log output to a different stream, such as a file or a stringstream, using the setOutput function :

```
std::stringstream outputStream;
Inept::Logging::Log::Init(&outputStream);
Inept::Logging::Log::logMessage(Inept::Logging::LogLevel::LOGERROR, "This is an error message.");

std::string output = outputStream.str();
```
## Troubleshooting
- If you are getting unresolved external symbol error when building the project, make sure that the library is properly installed and that the linker is able to find the library.
- If you are not seeing any color output, make sure that your terminal or ostream output supports ANSI escape codes.
- If you are not seeing any output at all, make sure that you have called the Init() function before calling any other logging functions.
- If you are not able to build the library, make sure that you have CMake installed on your system and that your system meets the other requirements for building the library.

## References
- CMake - The Build system used
- google test - The testing framework used

## Authors
Johnathan van Tonder - <www.github.com/JohnathanRvT>

## License
This project is licensed under the MIT License - see the LICENSE.md file for details
