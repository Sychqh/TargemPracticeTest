#ifndef SYCHKOVSTRING
#define SYCHKOVSTRING

namespace sychkov {
    class String {
    public:
        String();
        explicit String(const char* data);
        String(const String& other);
        String(String&& other) noexcept;
        ~String();

        char* getData() const;
        unsigned int getLength() const;

        String changeToLower() const;

        String& operator = (const String& other);
        String& operator = (String&& other) noexcept;
        String& operator = (const char* other);
        String& operator += (const String& other);
        String& operator += (const char* other);

        friend void swap(String& s1, String& s2) noexcept;

    private:
        char* data_ = nullptr;
        unsigned int length_ = 0;
    };

    bool CompareStrings(const sychkov::String& s1, const sychkov::String& s2);
}

sychkov::String operator + (const sychkov::String& s1, const sychkov::String& s2);
sychkov::String operator + (const sychkov::String& s1, const char* s2);

#endif //SYCHKOVSTRING
