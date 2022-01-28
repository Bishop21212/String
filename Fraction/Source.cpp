#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
#define delimeter cout<<"------------------\n";
class String;
String operator+(const String& left, const String& right);

class String
{
	int size;//������ ������ ������ ������ � ������
	char* str;//����� ������ � ������������ ������

public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};//������ ��� ������ ����������� ��������
		cout << "Constructor:\t" << this << endl;
	}
	String(const char str[])
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; str[i]; i++)this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}
	String(const String& other)//��������� ����������� Deep copy
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << this << endl;
	}
	String(String&& other)noexcept //MoveConstructor
	{
		
		this->size = other.size;
		this->str = other.str;//������ �������� ����� ������, ������������� ������� �������
	//�������� ������ ������, ����� ��� ������ �� ���� ������� ����������
		other.size = 0;
		other.str = nullptr;
		/*this->str = nullptr; 
		*this = std::move(other);*/
		cout << "MoveConstructor:\t" << this << endl;
	}
	~String()
	{
		delete[]str;
		cout << "Destructor:\t" << this << endl;

	}
	//Operators
	String & operator=(const String& other)
	{
		if (this == &other)return *this;//�� �������� �� this � other ����� � ��� �� ��������
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	String& operator=(String&& other)
	{
		if (this == &other)return *this;
		delete this->str;
		this->size = other.size;
		this->str = other.str;

		other.size = 0;
		other.str = 0;
		cout<<"MoveAssignment:\t"<<this<<endl;
		return *this;
	}
	char& operator[](int i)
	{
		return str[i];
	}
	const char& operator[](int i) const//���� ����� � ����� const �� � � ������
	{
		return str[i];
	}
	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}
	//Metods

	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};
String operator+(const String& left, const String& right)
{
	String result(left.get_size() + right.get_size()-1);//������� 1 �������������� ����
	for (int i = 0; i < left.get_size(); i++)
		//result.get_str()[i] = left.get_str()[i];
		result[i] = left[i];
	for (int i = 0; i < right.get_size(); i++)
		//result.get_str()[i + left.get_size() - 1] = right.get_str()[i];
		result[i + left.get_size() - 1] = right[i];
	return result;

	
}
std::ostream& operator<<(std::ostream & os, const String& obj)
{
	return os << obj.get_str();
}
std::istream& operator>>(std::istream& is, String& obj)
{
	is.getline(obj.get_str(), 80);
	int size = strlen(obj.get_str()) + 1;
	String str(size);//������� ������
	for (int i = 0; i < size; i++)
	{
		str[i] = obj[i];
	}
	obj = str;//����������� �������� ������� obj 
	return is;
	//return is >> obj.get_str();
	const int SIZE = 10240;
	char buffer[SIZE] = {};
	is >> buffer;
	obj = buffer;
	return is;
}
std::istream& getline(std::istream& is, String& obj)
{
	const int SIZE = 10240;
	char buffer[SIZE] = {};
	is.getline(buffer, SIZE);
	obj = buffer;
	return is;
}
//#define CONSTRUCTORS_CHECK
#define CLASS_WORK
void main()
{
	setlocale(LC_ALL, "");
	#ifdef CONSRTUCRS_CHECK 
	String str1; //Default constructor 
	str1.print();
	cout << str1 << endl;
	String str2(25);
	str2.print();

	String str3 = "Hello";
	str3 = str3;
	cout << str3 << endl;

	String str4 = str3;//���������� ����������� �����������
	cout << str4 << endl;

	String str5;
	str5 = str3;//������ ��� ���������� �������� ���������
	cout << str5 << endl;
#endif// CONSRTUCRS_CHECK 
	
// CLASS_WORK
	delimeter;
	String str1 = "Hello";
	delimeter;
	String str2 = "World";
	delimeter;
	String str3;
	str3= str1 + str2;
	delimeter;
	cout << str3 << endl;
	delimeter;
	String str4 = str3; //CopyConstructor
	/*str1 += str2;
	cout << str1 << endl;
	delimeter;*/
	
 // CLASS_WORK
	/*String str;
	cout << "������� ������: ";// cin >> str;
	getline(cin, str);
	cout << str;
	delimeter;
	str.print();*/
}