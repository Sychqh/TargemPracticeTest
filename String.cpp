#include <cstring>
#include <string>
#include "String.h"

sychkov::String::String() {
    data_ = new char[0];
    length_ = 0;
}

sychkov::String::String(const char* data) {
    length_ = strlen(data);
    data_ = new char[length_ + 1];
    strcpy(data_, data);
}

sychkov::String::String(const sychkov::String &other) {
    length_ = other.length_;
    data_ = new char[length_ + 1];
    strcpy(data_, other.data_);
}

sychkov::String::String(sychkov::String&& other) noexcept {
    length_ = other.length_;
    data_ = other.data_;

    other.length_ = 0;
    other.data_ = nullptr;
}

sychkov::String::~String() {
    delete[] data_;
}

char* sychkov::String::getData() const {
    return data_;
}

unsigned int sychkov::String::getLength() const {
    return length_;
}

sychkov::String sychkov::String::changeToLower() const {
    char* newData = data_;
    int dataLength = strlen(newData);

    for (int i = 0; i < dataLength; i++) {
        newData[i] = std::tolower(newData[i]);
    }

    return String(newData);
}

sychkov::String &sychkov::String::operator=(const sychkov::String& other) {
    sychkov::String temp(other);
    swap(*this, temp);
    return *this;
}

sychkov::String &sychkov::String::operator=(sychkov::String&& other) noexcept {
    String temp(std::move(other));
    swap(*this, temp);
    return *this;
}

sychkov::String &sychkov::String::operator=(const char *other) {
    String temp(other);
    swap(*this, temp);
    return *this;
}

sychkov::String &sychkov::String::operator+=(const sychkov::String &other) {
    strcat(data_, other.data_);
    length_ += other.length_;

    return *this;
}

sychkov::String &sychkov::String::operator+=(const char *other) {
    strcat(data_, other);
    length_ += strlen(other);

    return *this;
}

void sychkov::swap(sychkov::String &s1, sychkov::String &s2) noexcept {
    std::swap(s1.data_, s2.data_);
    std::swap(s1.length_, s2.length_);
}

bool sychkov::CompareStrings(const sychkov::String& s1, const sychkov::String& s2) {
    return strcmp(s1.changeToLower().getData(), s2.changeToLower().getData()) < 0;
}

sychkov::String operator + (const sychkov::String& s1, const sychkov::String& s2) {
    char* newData = new char[s1.getLength() + s2.getLength() + 1];
    strcpy(newData, s1.getData());
    strcat(newData, s2.getData());
    return sychkov::String(newData);
}

sychkov::String operator + (const sychkov::String& s1, const char* s2) {
    char* newData = new char[s1.getLength() + strlen(s2) + 1];
    strcpy(newData, s1.getData());
    strcat(newData, s2);
    return sychkov::String(newData);
}
