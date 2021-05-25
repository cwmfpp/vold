#ifndef LOGGING_H
#define LOGGING_H


#include <string.h>

#include <iostream>
#include <sstream>

// Simple error logging macro to avoid dependencies in other base libraries.
#define LOG(severity) LogMessage(__FILE__, __LINE__, #severity).stream()

// A variant of LOG that also logs the current errno value.
#define PLOG(severity) LogMessage(__FILE__, __LINE__, #severity, errno).stream()

// A temporarily scoped object used by LOG & PLOG.
class LogMessage {
 public:
  LogMessage(const char* file, unsigned int line, const char* severity);

  LogMessage(const char* file,
             unsigned int line,
             const char* severity,
             int error);

  ~LogMessage();

  // Returns the stream associated with the message, the LogMessage performs
  // output when it goes out of scope.
  std::ostream& stream() { return stream_; }

 private:
  std::ostringstream stream_;
  int error_;  // The saved errno value.
};

#endif // LOGGING_H
