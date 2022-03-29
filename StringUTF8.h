#pragma once
#include<string>

class StringUTF8 {

	char* toBIN(const char c) {
		char* result = new char[9];
		result[8] = '\0';
		int index = 7;
		for (size_t i = 0; i < 8; i++) {
			result[index] = (c & (1 << i)) > 0 ? '1' : '0';
			index--;
		}
		return result;
	}

	int getType(const char* c_str) {
		for (size_t i = 0; i < strlen(c_str); i++)
			if (c_str[i] == '0') return i;
	}

	void setupBufferSize() {
		int slen = this->size;
		int* temp = new int[slen];
		for (size_t i = 0; i < slen; i++)
			temp[i] = this->index[i];
		delete[] this->index;
		this->index = new int[size += buffer];
		for (size_t i = 0; i < slen; i++)
			this->index[i] = temp[i];
		delete[] temp;
	}

	void putsindex(const int val) {
		if (strlength == 0) index[0] = val;
		else index[strlength] = val;
		++strlength;
		if ((strlength + 1) == size)
			setupBufferSize();
	}

	void init() {
		this->strlength = 0;
		for (size_t i = 0; i < strlen(str_c); i++) {
			int Type = getType(toBIN(str_c[i]));
			if (Type == 0) i += 0;
			if (Type == 2) i += 1;
			if (Type == 3) i += 2;
			if (Type == 4) i += 3;
			putsindex(i);
		}
	}

	char* str_c;
	int* index;
	int strlength;
	int buffer;
	int size;

public:

	StringUTF8() {
		this->str_c = new char('\0');
		this->index = new int(0);
		this->strlength = 0;
		this->buffer = 0;
		this->size = 0;
	}

	StringUTF8(const char* ch) {
		this->buffer = 4;
		this->index = new int[size = buffer];
		this->str_c = new char[strlen(ch)];
		strcpy(this->str_c, ch);
		this->init();
	}

	void insert(int val, char *str) {

	}

	char* tochars() {
		return str_c;
	}

	int length() { 
		return strlength; 
	}

	char* operator[](const int val) {
		if (val >= strlength) return new char('\0');
		char* buffer = NULL;
		if (val == 0) {
			int len = index[val];
			buffer = new char[len + 2];
			for (size_t i = 0; i <= len; i++)
				buffer[i] = str_c[i];
			buffer[len + 1] = '\0';
		}
		else {
			size_t len = index[val] - index[val - 1];
			buffer = new char[len + 1];
			size_t _i = 0;
			for (size_t i = index[val - 1] + 1; i <= index[val]; i++) {
				buffer[_i] = str_c[i];
				_i++;
			}
			buffer[len] = '\0';
		}
		return buffer;
	}

	void append(const char* str) {
		int inlen = strlen(str);
		int slen = strlen(this->str_c) + inlen + 1;
		char* temp = new char[slen];
		strcpy(temp, this->str_c);
		strcat(temp, str);
		this->str_c = temp;
		this->init();
	}

	StringUTF8* operator+=(const char* str) {
		this->append(str);
		return this;
	}

	StringUTF8* operator+=(const StringUTF8 &str) {
		this->append(str.str_c);
		return this;
	}

	bool equal(const char* str) {
		if (strlen(this->str_c) == strlen(str)) {
			for (size_t i = 0; i < strlen(this->str_c); i++)
				if (this->str_c[i] != str[i]) return false;
			return true;
		}
		return false;
	}

	bool equal(const StringUTF8 &str) {
		return this->equal(str.str_c);
	}

	bool operator==(const StringUTF8 &str) {
		return this->equal(str.str_c);
	}

	bool operator==(const char * str) {
		return this->equal(str);
	}

	bool contains(const char* str) {
		int inlen = strlen(str);
		if (inlen <= strlen(this->str_c)) {
			char* temp = this->str_c;
			while (strlen(temp) >= inlen) {
				if ([&](bool is) -> bool {
					for (size_t i = 0; i < inlen; i++) {
						if (temp[i] != str[i]) return is = false;
					}return is;
					}(true)) return true;
				temp++;
			}
		}
		return false;
	}

	bool contains(const StringUTF8 &str_utf8) {
		return this->contains(str_utf8.str_c);
	}

};

StringUTF8 operator+(StringUTF8 & const str1, StringUTF8 & const str2) {
	int slen = strlen(str1.tochars()) + strlen(str2.tochars()) + 1;
	char* result = new char[slen];
	strcpy(result, str1.tochars());
	strcat(result, str2.tochars());
	return result;
}

using namespace std;
ostream& operator<<(ostream& cout,StringUTF8& const str) {
	cout << str.tochars();
	return cout;
}
