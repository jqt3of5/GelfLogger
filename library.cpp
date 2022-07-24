#include "library.h"

GelfUDPLogger::GelfUDPLogger(const char * serverUrl, const char * host, int port, bool compress) {
    _serverUrl = serverUrl;
    _host = host;
    _port = port;
    _compress = compress;

    _fieldCount = 0;
}

void GelfUDPLogger::begin() {
    //TODO: Connect to the Gelf server

}

void GelfUDPLogger::printf(int level, const char *format, ...) {
    //TODO: Send a message to the GelfServer
    //TODO: format string
    //TODO: Generate JSON for additional params

}
void GelfUDPLogger::addAdditionalField(const char *fieldName, const char *value) {
    if (_additionalFields == 0)
    {
        _maxfields = 5;
        _additionalFields = new std::tuple<const char *, const char*>*[_maxfields]();
    }

    if (_fieldCount >= _maxfields)
    {
        auto maxfields = _maxfields + 5;
        auto additionalFields = new std::tuple<const char *, const char*>*[_maxfields]();

        for (int i = 0; i < _fieldCount; ++i)
        {
            additionalFields[i] = _additionalFields[i];
        }

        delete _additionalFields;
        _additionalFields = additionalFields;
        _maxfields = maxfields;
    }

    //TODO: Should update if field already exists
    _additionalFields[_fieldCount] = new std::tuple<const char *, const char *>(fieldName, value);

}

void Log::printf(const char *format, ...) {

}
void Log::begin() {

}
void Log::addAdditionalField(const char *fieldName, const char *value) {

}
void Log::addHandler(Logger *logger) {

}
