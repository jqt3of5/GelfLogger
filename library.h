#ifndef GELFLOGGER_LIBRARY_H
#define GELFLOGGER_LIBRARY_H
#include <tuple>

class Logger {
public:
    virtual void printf(int level, const char * format, ...) = 0;
    virtual void addAdditionalField(const char * fieldName, const char * value) = 0;
    virtual void begin() = 0;
};

class GelfUDPLogger : Logger
{
public:
    GelfUDPLogger(const char * serverUrl, const char * host, int port = 122012, bool compress = true);
    void addAdditionalField(const char * fieldName, const char * value);
    void printf(int level, const char *format, ...);
    void begin();
private:
    bool _compress;
    const char * _serverUrl;
    int _port;
    const char * _host;

    int _fieldCount = 0;
    int _maxfields = 0;
    std::tuple <const char *, const char*> ** _additionalFields = NULL;
};
//
//class GelfTCPLogger : Logger
//{
//public:
//    GelfTCPLogger();
//    void printf(const char *format, ...);
//    void addAdditionalField(const char * fieldName, const char * value);
//    void begin();
//private:
//    const char * _serverUrl;
//    int _port;
//    const char * _host;
//
//    int _fieldCount = 0;
//    std::tuple <const char *, const char*> * _additionalFields;
//};

class Log
{
public:
    static void printf(const char * format, ...);
    static void addAdditionalField(const char * fieldName, const char * value);
    static void begin();

    static void addHandler(Logger * logger);
private:
    Logger * _handlers;

};

#endif //GELFLOGGER_LIBRARY_H
