#pragma once
#include<string>

class StringUTF8 {

	char* toBIN(const char c) {
		char* binary = new char[9];
		binary[8] = '\0';
		int in = 7;
		for (size_t i = 0; i < 8; i++) {
			binary[in] = (c & (1 << i)) > 0 ? '1' : '0';
			in--;
		}
		return binary;
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
		int Type;
		for (size_t i = 0; i < strlen(str_c); i++) {
			if (str_c[i] == '\0') break;
			Type = getType(toBIN(str_c[i]));
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

	StringUTF8(const char* inchars) {
		this->buffer = 4;
		this->index = new int[size = buffer];
		this->str_c = new char[strlen(inchars)];
		strcpy(this->str_c, inchars);
		this->init();
	}

	char* insert(int val, char *inchars) {
		if (val < -1 || val >= strlength) return this->str_c;
		
		char* savebuffer = NULL;
		int inlen = strlen(inchars);
		int tslen = strlen(this->str_c);
		size_t buffersize = static_cast<size_t>(tslen + inlen);
		size_t startlen = static_cast<size_t>(index[val] + 1);
		savebuffer = new char[buffersize + 3];

		if (val == -1) {
			strcpy(savebuffer, inchars);
			strcat(savebuffer, this->str_c);
		}
		else if (val = strlength - 1) {
			strcpy(savebuffer, this->str_c);
			strcat(savebuffer, inchars);
		}
		else{
			for (size_t i = 0; i < startlen; i++) 
				savebuffer[i] = this->str_c[i];
			for (size_t i = startlen, s = 0; s < strlen(inchars); s++, i++) 
				savebuffer[i] = inchars[s];
			for (size_t i = startlen + strlen(inchars), s = startlen; s < tslen; i++, s++) 
				savebuffer[i] = this->str_c[s];
		}

		savebuffer[buffersize] = '\0';
		this->str_c = savebuffer;
		this->init();
		return this->str_c;
	}

	char* insert(int val, StringUTF8 & str_utf8) {
		return this->insert(val, str_utf8.str_c);
	}

	bool startsWith(const char* inchars) {
		int inlen = strlen(inchars);
		if (inlen > strlen(this->str_c)) return false;
		for (size_t i = 0; i < inlen; i++)
			if (this->str_c[i] != inchars[i]) return false;
		return true;
	}

	bool startsWith(const StringUTF8& str_utf8) {
		return this->startsWith(str_utf8.str_c);
	}

	bool endsWith(const char* inchars) {
		int inlen = strlen(inchars);
		int tslen = strlen(this->str_c);
		if (inlen > tslen) return false;
		for (size_t s = tslen, i = inlen; i < tslen; i--, s--)
			if (this->str_c[s] != inchars[i]) return false;
		return true;
	}

	bool endsWith(const StringUTF8& str_utf8) {
		return this->endsWith(str_utf8.str_c);
	}

	char* tochars() {
		return this->str_c;
	}

	int length() { 
		return this->strlength;
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
			size_t len = static_cast<size_t>(index[val] - index[val - 1]);
			buffer = new char[len + 1];
			size_t _i = 0;
			for (size_t i = static_cast<size_t>(index[val - 1]) + 1; i <= index[val]; i++) {
				buffer[_i] = str_c[i];
				_i++;
			}
			buffer[len] = '\0';
		}
		return buffer;
	}

	void append(const char* inchars) {
		int inlen = strlen(inchars);
		int slen = strlen(this->str_c) + inlen + 1;
		char* temp = new char[slen];
		strcpy(temp, this->str_c);
		strcat(temp, inchars);
		this->str_c = temp;
		this->init();
	}

	StringUTF8* operator+=(const char* inchars) {
		this->append(inchars);
		return this;
	}

	StringUTF8* operator+=(const StringUTF8 & str_utf8) {
		this->append(str_utf8.str_c);
		return this;
	}

	bool equal(const char* inchars) {
		int inlen = strlen(inchars);
		int tslen = strlen(this->str_c);
		if (tslen == inlen) {
			for (size_t i = 0; i < tslen; i++)
				if (this->str_c[i] != inchars[i]) return false;
			return true;
		}
		return false;
	}

	bool equal(const StringUTF8 & str_utf8) {
		return this->equal(str_utf8.str_c);
	}

	bool operator==(const StringUTF8 & str_utf8) {
		return this->equal(str_utf8.str_c);
	}

	bool operator==(const char * inchars) {
		return this->equal(inchars);
	}

	bool contains(const char* inchars) {
		int inlen = strlen(inchars);
		int tslen = strlen(this->str_c);
		if (inlen <= tslen) {
			char* temp = this->str_c;
			while (strlen(temp) >= inlen) {
				if ([&](bool is) -> bool {
					for (size_t i = 0; i < inlen; i++) {
						if (temp[i] != inchars[i]) return is = false;
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

StringUTF8 operator+(StringUTF8 & const str1_utf8, StringUTF8 & const str2_utf8) {
	int slen = strlen(str1_utf8.tochars()) + strlen(str2_utf8.tochars()) + 1;
	char* chars = new char[slen];
	strcpy(chars, str1_utf8.tochars());
	strcat(chars, str2_utf8.tochars());
	return chars;
}

using namespace std;
ostream& operator<<(ostream& cout,StringUTF8& const str_utf8) {
	cout << str_utf8.tochars();
	return cout;
}
ostream& operator<<(ostream& cout,StringUTF8* const str_utf8) {
	cout << str_utf8->tochars();
	return cout;
}
