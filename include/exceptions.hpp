
#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>
#include <string>

namespace fislator {

/**
 *   @brief  Base level exception FislatorException
 *
 *           Should be extended with subclasses
 */
class FislatorException : public std::exception {
public:
  FislatorException(std::string text) : _what(text) {}
  virtual ~FislatorException() throw() {}
  virtual const char *what() const throw() { return _what.c_str(); }

protected:
  std::string _what;
};

/**
 *   @brief  Invalid JSON file exception InvalidJSONFileException
 *
 *           Throw when issues when JSON file is not from F-II.
 */
class InvalidJSONFileException : public FislatorException {
public:
  InvalidJSONFileException(std::string text) : FislatorException(text) {}

  virtual ~InvalidJSONFileException() throw() {}
};

/**
 *   @brief  Key lookup exception JSONKeyNotFoundException
 *
 *           Throw when issues when cannot find a key in the JSON file.
 */
class JSONKeyNotFoundException : public FislatorException {
public:
  JSONKeyNotFoundException(std::string text) : FislatorException(text) {}

  virtual ~JSONKeyNotFoundException() throw() {}
};

/**
 *   @brief  File Format exception FileFormatReadException
 *
 *           Throw when issues with file formatting (reading/writing)
 */
class FileFormatReadException : public FislatorException {
public:
  FileFormatReadException(std::string text) : FislatorException(text) {}

  virtual ~FileFormatReadException() throw() {}
};

} // namespace fislator

#endif // EXCEPTIONS_HPP
