# StringUTF8
对utf-8编码数据的切分，以及更容易化操作 <br>
构造函数：<br>
  StringUTF8()<br>
  StringUTF8(const char* ch)<br>
插入字符串：<br>
  char* insert(int val, char *str)<br>
  char* insert(int val, StringUTF8 &str)<br>
运算符重载：<br>
  char* operator[](const int val)<br>
  StringUTF8* operator+=(const char* str)<br>
  StringUTF8* operator+=(const StringUTF8 &str)<br>
  bool operator==(const StringUTF8 &str)<br>
  bool operator==(const char * str)<br>
  StringUTF8 operator+(StringUTF8 & const str1, StringUTF8 & const str2)<br>
  ostream& operator<<(ostream& cout,StringUTF8& const str)<br>
  ostream& operator<<(ostream& cout,StringUTF8* const str)<br>
其他函数：<br>
  1、判断是否包含传入的字符串<br>
    bool contains(const char* str) <br>
    bool contains(const StringUTF8 &str_utf8)<br>
  2、比较传入的字符串是否与当前相同<br>
    bool equal(const StringUTF8 &str)<br>
    bool equal(const char* str)<br>
  3、往当前对象追加字符串<br>
    void append(const char* str)<br>
  4、返回char指针<br>
    char* tochars()<br>
  6、返回字数<br>
    int length() <br>
