# StringUTF8
对utf-8编码数据的切分，以及更容易化操作 <br>
构造函数：
  StringUTF8()
  StringUTF8(const char* ch)
插入字符串：
  char* insert(int val, char *str)
  char* insert(int val, StringUTF8 &str)
运算符重载：
  char* operator[](const int val)
  StringUTF8* operator+=(const char* str)
  StringUTF8* operator+=(const StringUTF8 &str)
  bool operator==(const StringUTF8 &str)
  bool operator==(const char * str)
  StringUTF8 operator+(StringUTF8 & const str1, StringUTF8 & const str2)
  ostream& operator<<(ostream& cout,StringUTF8& const str)
  ostream& operator<<(ostream& cout,StringUTF8* const str)
其他函数：
  1、判断是否包含传入的字符串
    bool contains(const char* str) 
    bool contains(const StringUTF8 &str_utf8)
  2、比较传入的字符串是否与当前相同
    bool equal(const StringUTF8 &str)
    bool equal(const char* str)
  3、往当前对象追加字符串
    void append(const char* str)
  4、返回char指针
    char* tochars()
  6、返回字数
    int length() 
