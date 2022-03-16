#pragma once
#include<string>

class StringUTF8 {

	int* index;
	char* str_c;
	int strlength;

	char* toBIN(char c) {
		char* result = new char[9];
		result[8] = '\0';
		int index = 7;
		for (int i = 0; i < 8; i++) {
			result[index] = (c & (1 << i)) > 0 ? '1' : '0';
			index--;
		}
		return result;
	}

	int get_length_type(char* c_str) {
		for (int i = 0; i < strlen(c_str); i++) 
			if (c_str[i] == '0') return i;
	}

public:

	StringUTF8(const char* ch) {
		index = new int[1024];
		str_c = new char[strlen(ch) + 1];
		strcpy(str_c, ch);
		this->init();
	}

	void set_index_size() {
		int size = this->strlength + 1024;
		int* temp = new int[size];
		for (size_t i = 0; i <= this->strlength; i++)
			temp[i] = this->index[i];
		delete[] this->index;
		this->index = temp;
		delete[] temp;
	}

	void add_index(const int value) {
		if (strlength == 0) index[0] = value;
		else index[strlength] = value;
		++strlength;
		if (strlength + 1 % 1024 == 0)
			set_index_size();
	}

	void init() {
		char temp;
		strlength = 0;
		for (int i = 0; i < strlen(str_c); i++) {
			temp = str_c[i];
			char* c_bin = toBIN(temp);
			int Type = get_length_type(c_bin); 
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
			buffer = new char[len + 1];
			for (int i = 0; i <= len; i++)
				buffer[i] = str_c[i];
			buffer[len + 1] = '\0';
		}
		else {
			int len = index[value] - index[value - 1];
			buffer = new char[len + 1];
			int _i = 0;
			for (int i = index[value - 1] + 1; i <= index[value]; i++) {
				buffer[_i] = str_c[i];
				_i++;
			}
			buffer[len] = '\0';
		}
		return buffer;
	}

	void add(const char* str) {
		int len = strlen(str);
		int this_length = strlen(this->str_c) + len + 1;
		char* temp = new char[this_length];
		strcpy(temp, this->str_c);
		strcat(temp, str);
		this->str_c = temp;
		init();
	}

	StringUTF8 operator+=(const char* str) {
		this->add(str);
		return this->str_c;
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