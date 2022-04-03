# StringUTF8
对utf-8编码数据的切分，以及更容易化操作 <br>
#### 使用方法：<br>
  ```
  #include"StringUTF8.h"
  ```
#### 构造函数：<br>
```
  StringUTF8();
  StringUTF8(const char* inchars);
```
#### 运算符重载：<br>
```
  //  可以通过下标引索单个文字
  char* operator[](const int val);
  //  可以直接使用+=追加字符串对象
  StringUTF8* operator+=(const char* inchars);
  StringUTF8* operator+=(const StringUTF8 &str_utf8);
  //  可以直接使用==判断两个字符串是否相等
  bool operator==(const StringUTF8 &str_utf8);
  bool operator==(const char * inchars);
  //  可以使用+来拼接字符串
  StringUTF8 operator+(StringUTF8 & const str1_utf8, StringUTF8 & const str2_utf8);
  //  可以直接使用ostream输出内容
  ostream& operator<<(ostream& cout,StringUTF8& const str_utf8);
  ostream& operator<<(ostream& cout,StringUTF8* const str_utf8);
```
## 其他函数：<br>
#### 判断是否包含传入的字符串<br>
```
    bool contains(const char* inchars);
    bool contains(const StringUTF8 &str_utf8);
```
#### 比较传入的字符串是否与当前相同<br>
```
    bool equal(const StringUTF8 &str_utf8);
    bool equal(const char* inchars);
```
#### 往当前对象追加字符串<br>
```
    void append(const char* inchars);
```
#### 检查字符串是否是以指定子字符串开头<br>
```
    bool starstWith(const char* inchars);
    bool starstWith(const StringUTF8& str_utf8);
```
#### 字符串是否以指定的后缀结束<br>
```
    bool endsWith(const char* inchars);
    bool endsWith(const StringUTF8& str_utf8);
```
#### 插入字符串：<br>
```
  char* insert(int val, char *inchars);
  char* insert(int val, StringUTF8 &str_utf8);
```
#### 返回`char*`指针<br>
```
    char* tochars();
```
#### 返回字数<br>
```
    int length(); 
```
