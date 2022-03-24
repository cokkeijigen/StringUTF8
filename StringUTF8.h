#pragma once
#include<string>

using namespace std;
class StringUTF8 {

	char* toBIN(char c) {
		char* result = new char[9];
		result[8] = '\0';
		int index = 7;
		for (size_t i = 0; i < 8; i++) {
			result[index] = (c & (1 << i)) > 0 ? '1' : '0';
			index--;
		}
		return result;
	}

	int get_length_type(char* c_str) {
		for (size_t i = 0; i < strlen(c_str); i++)
			if (c_str[i] == '0') return i;
	}

	char* str_c;
	int* index;
	int strlength;
	int buffer;
	int size;

public:

	StringUTF8(){};

	StringUTF8(const char* ch) {
		this->buffer = 4;
		this->index = new int[size = buffer];
		this->str_c = new char[strlen(ch)];
		strcpy(this->str_c, ch);
		this->init();
	}

	void set_index_size() {
		int this_lenth = this->size;
		int* temp = new int[size += buffer];
		for (size_t i = 0; i < this_lenth; i++)
			temp[i] = this->index[i];
		delete[] this->index;
		this->index = new int[size];
		for (size_t i = 0; i < this_lenth; i++)
			this->index[i] = temp[i];
		delete[] temp;
	}

	void add_index(const int value) {
		if (strlength == 0) index[0] = value;
		else index[strlength] = value;
		++strlength;
		if ((strlength + 1) == size)
			set_index_size();
	}

	void init() {
		this->strlength = 0;
		for (size_t i = 0; i < strlen(str_c); i++) {
			int Type = get_length_type(toBIN(str_c[i]));
			if (Type == 0) i += 0;
			if (Type == 2) i += 1;
			if (Type == 3) i += 2;
			if (Type == 4) i += 3;
			add_index(i);
		}
	}

	char* tochars() {
		return str_c;
	}

	int length() { 
		return strlength; 
	}

	char* operator[](int value) {
		if (value >= strlength) return new char[0];
		char* buffer = NULL;
		if (value == 0) {
			int len = index[value];
			buffer = new char[len + 2];
			for (size_t i = 0; i <= len; i++)
				buffer[i] = str_c[i];
			buffer[len + 1] = '\0';
		}
		else {
			size_t len = index[value] - index[value - 1];
			buffer = new char[len + 1];
			size_t _i = 0;
			for (size_t i = index[value - 1] + 1; i <= index[value]; i++) {
				buffer[_i] = str_c[i];
				_i++;
			}
			buffer[len] = '\0';
		}
		return buffer;
	}

	void append(const char* str) {
		int len = strlen(str);
		int this_length = strlen(this->str_c) + len + 1;
		char* temp = new char[this_length];
		strcpy(temp, this->str_c);
		strcat(temp, str);
		this->str_c = temp;
		init();
	}

	StringUTF8 operator+=(const char* str) {
		this->append(str);
		return this->str_c;
	}

	bool equal(const char* str) {
		if (strlen(this->str_c) == strlen(str)) {
			for (size_t i = 0; i < strlen(this->str_c); i++)
				if (this->str_c[i] != str[i]) return false;
			return true;
		}
		return false;
	}

	bool operator==(StringUTF8 str) {
		return this->equal(str.str_c);
	}

	bool operator==(const char * str) {
		return this->equal(str);
	}

	bool contains(const char* str) {
		int in_length = strlen(str);
		if (in_length <= strlen(this->str_c)) {
			char* temp = this->str_c;
			while (strlen(temp) >= in_length) {
				if ([&](bool is) -> bool {
					for (size_t i = 0; i < in_length; i++) {
						if (temp[i] != str[i]) return is = false;
					}return is;
					}(true))
					return true;
						temp++;
			}
		}
		return false;
	}

	bool contains(StringUTF8 str_utf8) {
		return this->contains(str_utf8.tochars());
	}

};

std::ostream& operator<<(std::ostream& cout, StringUTF8& obj) {
	std::cout << obj.tochars();
	return std::cout;
}

StringUTF8 operator+(StringUTF8 str1, StringUTF8 str2) {
	int this_length = strlen(str1.tochars()) + strlen(str2.tochars()) + 1;
	char* temp = new char[this_length];
	strcpy(temp, str1.tochars());
	strcat(temp, str2.tochars());
	return temp;
}
