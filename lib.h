#include <stdio.h>
#include <locale.h>
#include <Windows.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

int* newInt()
{
	return (int*)malloc(sizeof(int));
}

int* newInt(int amount)
{
	return (int*)malloc(amount * sizeof(int));
}

int** newInt(int layers, int amount)
{
	int** matrix = (int**)calloc(layers, sizeof(int*));
	for (int i = 0; i < layers; i++)
	{
		*(matrix + i) = newInt(amount);
	}
	return matrix;
}

float* newFloat()
{
	return (float*)malloc(sizeof(float));
}

float* newFloat(int amount)
{
	return (float*)malloc(amount * sizeof(float));
}

float** newFloat(int layers, int amount)
{
	float** matrix = (float**)calloc(layers, sizeof(float*));
	for (int i = 0; i < layers; i++)
	{
		*(matrix + i) = newFloat(amount);
	}
	return matrix;
}

void setRusLocale()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

int nextInt()
{
	int a;
	scanf_s("%d", &a);
	return a;
}

float nextFloat()
{
	float a;
	scanf_s("%f", &a);
	return a;
}

double nextDouble()
{
	double a;
	scanf_s("%f", &a);
	return a;
}

char nextChar()
{
	float a;
	scanf_s("%c", &a);
	return a;
}

void setCharArray(char* to, char* from)
{
	strcpy_s(to, strlen(from) + 1, from);
}

void getCharArray(const char* message, char* buffer, int length)
{
	printf("%s", message);
	fgets(buffer, length, stdin);
	buffer[strcspn(buffer, "\n")] = 0;
}

void passChar()
{
	char* nullChar = (char*)malloc(sizeof(char));
	gets_s(nullChar, 1);
	free(nullChar);
}

template <typename T>
T* newT()
{
	return (T*)malloc(sizeof(T));
}

template <typename T>
T* newT(int amount)
{
	return (T*)malloc(amount * sizeof(T));
}

template <typename T>
void addToArray(T* array, int length, T toAdd)
{
	array = (T*)realloc(array, (length + 1) * sizeof(T));
	array[length + 1] = toAdd;
}

template <typename T>
void getArrayByElement(T* array, int length) {
	for (int i = 0; i < length; i++)
	{
		printf("Элемент %d: ", i + 1);
		std::cin >> array[i];
	}

	printf("\n");
}

template <typename T>
void getArray(T* array, int length) {
	for (int i = 0; i < length; i++)
	{
		std::cin >> array[i];
	}

	printf("\n");
}

template <typename T>
void printArray(T* array, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("%.2f\t", array[i]);
	}
	printf("\n");
}

template <typename T>
void getMatrixByElement(T** matrix, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		printf("Строка %d: \n", (i + 1));
		getArrayByElement(matrix[i], columns);
	}
}

template <typename T>
void getMatrix(T** matrix, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		printf("Строка %d: \n", (i + 1));
		getArray(matrix[i], columns);
	}
}

template <typename T>
void getWholeMatrix(T** matrix, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		getArray(matrix[i], columns);
	}
}

template <typename T>
void printMatrix(T** matrix, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		printArray(matrix[i], columns);
	}
	printf("\n\n");
}

template <typename T>
void deleteElement(T* array, int length, int position)
{
	for (int i = position; i < length - 1; i++) {
		array[i] = array[i + 1];
	}
}

template <typename T>
void deleteElements(T* array, int length, int from, int to)
{
	for (int i = to; i < length - 1; i++) {
		array[i - from] = array[i - from + 1];
	}
}

template <typename T>
void copy(T* from, T* to, int length)
{
	for (int i = 0; i < length; i++)
	{
		to[i] = from[i];
	}
}

template <typename T>
int find(T* array, int length, T what)
{
	for (int i = 0; i < length; i++)
	{
		if (array[i] == what)
		{
			return i;
		}
	}

	return -1;
}

struct IntArray
{
	int* array;
	int length;

	void create(int size)
	{
		length = size;
		array = newInt(size);
	}

	void add(int a)
	{
		array = (int*)realloc(array, (length + 1) * sizeof(int));
		array[length + 1] = a;
	}

	int get(int i)
	{
		if (i > length - 1 || i < 0)
		{
			printf("Неверный индекс!\n");
			return 0;
		}

		return array[i];
	}

	bool set(int i, int value)
	{
		if (i > length - 1 || i < 0)
		{
			printf("Неверный индекс!\n");
			return false;
		}

		array[i] = value;
		return true;
	}

	int getLast()
	{
		return array[length - 1];
	}

	void print()
	{
		for (int i = 0; i < length; i++)
		{
			printf("%d\t", array[i]);
		}
		printf("\t");
	}

	void print(char* message)
	{
		printf(message);
		print();
	}

	void del(int position)
	{
		for (int i = position; i < length - 1; i++) {
			array[i] = array[i + 1];
		}
		length--;
	}

	void del(int from, int to)
	{
		for (int i = to; i < length - 1; i++) {
			array[i - from] = array[i - from + 1];
		}
		length -= to - from;
	}

	void clear()
	{
		free(array);
		length = 0;
	}

	void sort()
	{
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < length; j++)
			{
				if (array[j] > array[i])
				{
					int buf = array[i];
					array[i] = array[j];
					array[j] = buf;
				}
			}
		}
	}

	int* getArray()
	{
		int* arr = newInt(length);
		copy(array, arr, length);
		return arr;
	}

	IntArray findAll(float a)
	{
		bool finded = false;
		IntArray pos;
		pos.create(1);

		for (int i = 0; i < length; i++)
		{
			if (array[i] == a)
			{
				if (!finded)
				{
					finded = true;
					pos.array[0] = i;
				}
				else
				{
					pos.add(i);
				}
			}
		}

		return pos;
	}
};

struct FloatArray
{
	float* array;
	int length;

	void create(int size)
	{
		length = size;
		array = newFloat(size);
	}

	void add(float a)
	{
		array = (float*)realloc(array, (length + 1) * sizeof(float));
		array[length + 1] = a;
	}

	float get(int i)
	{
		if (i > length - 1 || i < 0)
		{
			printf("Неверный индекс!\n");
			return 0;
		}

		return array[i];
	}

	bool set(int i, float value)
	{
		if (i > length - 1 || i < 0)
		{
			printf("Неверный индекс!\n");
			return false;
		}

		array[i] = value;
		return true;
	}

	float getLast()
	{
		return array[length - 1];
	}

	void print()
	{
		for (int i = 0; i < length; i++)
		{
			printf("%.2f\t", array[i]);
		}
		printf("\n");
	}

	void print(char* message)
	{
		printf(message);
		print();
	}

	void del(int position)
	{
		for (int i = position; i < length - 1; i++) {
			array[i] = array[i + 1];
		}
		length--;
	}

	void del(int from, int to)
	{
		for (int i = to; i < length - 1; i++) {
			array[i - from] = array[i - from + 1];
		}
		length -= to - from;
	}

	void clear()
	{
		free(array);
		length = 0;
	}

	void sort()
	{
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < length; j++)
			{
				if (array[j] > array[i])
				{
					float buf = array[i];
					array[i] = array[j];
					array[j] = buf;
				}
			}
		}
	}

	float* getArray()
	{
		float* arr = newFloat(length);
		copy(array, arr, length);
		return arr;
	}

	IntArray findAll(float a)
	{
		bool finded = false;
		IntArray pos;
		pos.create(1);

		for (int i = 0; i < length; i++)
		{
			if (array[i] == a)
			{
				if (!finded)
				{
					finded = true;
					pos.array[0] = i;
				}
				else
				{
					pos.add(i);
				}
			}
		}

		return pos;
	}
};

template <typename T>
struct Array
{
	T* array;
	int length = 0;
	bool isCreated = false;

	void add(T a)
	{
		if (!isCreated)
		{
			array = (T*)malloc(sizeof(T));
			length = 1;
			isCreated = true;
			array[length - 1] = a;
			return;
		}

		T* buf = (T*)malloc(length * sizeof(T));
		copy(array, buf, length);
		free(array);
		length++;
		array = (T*)malloc((length) * sizeof(T));
		copy(buf, array, length);
		array[length - 1] = a;
	}

	void add(T* arr, int size)
	{
		for (int i = 0; i < size; i++)
		{
			add(arr[i]);
		}
	}

	void add(Array<T> arr)
	{
		for (int i = 0; i < arr.length; i++)
		{
			add(arr.get(i));
		}
	}

	T get(int i)
	{
		if (i > length - 1 || i < 0)
		{
			printf("Неверный индекс!\n");
			T t = {};
			return t;
		}

		return array[i];
	}

	T* getPtr(int i)
	{
		if (i > length - 1 || i < 0)
		{
			printf("Неверный индекс!\n");
			T t = {};
			return &t;
		}

		return &array[i];
	}

	bool set(int i, T value)
	{
		if (i > length - 1 || i < 0)
		{
			printf("Неверный индекс!\n");
			return false;
		}

		array[i] = value;
		return true;
	}

	T getLast()
	{
		return array[length - 1];
	}

	void print(const char separationChars[])
	{
		for (int i = 0; i < length; i++)
		{
			if (i == length - 1)
			{
				std::cout << array[i];
			}
			else
			{
				std::cout << array[i] << separationChars;
			}
		}
		printf("\n");
	}

	void print()
	{
		print("\t");
	}

	void del(int position)
	{
		for (int i = position; i < length - 1; i++) {
			array[i] = array[i + 1];
		}
		length--;
	}

	void del(int from, int to)
	{
		for (int i = to; i < length - 1; i++) {
			array[i - from] = array[i - from + 1];
		}
		length -= to - from;
	}

	void clear()
	{
		free(array);
		length = 0;
	}

	void sort()
	{
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < length; j++)
			{
				if (array[j] > array[i])
				{
					T buf = array[i];
					array[i] = array[j];
					array[j] = buf;
				}
			}
		}
	}

	int* getArray()
	{
		int* arr = newInt(length);
		copy(array, arr, length);
		return arr;
	}

	Array<int> findAll(T a)
	{
		bool finded = false;
		Array pos;

		for (int i = 0; i < length; i++)
		{
			if (array[i] == a)
			{
				pos.add(i);
			}
		}

		return pos;
	}
};

struct String
{
	Array<char> str;

	void set(char* s, int length)
	{
		Array<char> buf;

		for (int i = 0; i < length; i++)
		{
			buf.add(s[i]);
		}

		str = buf;
	}

	void append(char* s, int length)
	{
		for (int i = 0; i < length; i++)
		{
			str.add(s[i]);
		}
	}

	char* toCharArray()
	{
		char* toReturn = newT<char>(str.length);
		copy(str.array, toReturn, str.length);
		return toReturn;
	}

	void addChar(char c)
	{
		str.add(c);
	}

	void del(int position)
	{
		str.del(position);
	}

	void del(int from, int to)
	{
		str.del(from, to);
	}

	void clear()
	{
		free(str.array);
		str.length = 0;
	}
};

String nextString(int length)
{
	String s;
	s.str.length = length;
	s.str.array = newT<char>(length);
	fgets(s.str.array, length, stdin);
	s.str.array[strcspn(s.str.array, "\n")] = 0;
	return s;
}

template <typename T, typename G>
struct Map
{
	T* keys;
	G* values;
	int length;
	bool isCreated = false;

	bool add(T key, G value)
	{
		if (!isCreated)
		{
			keys = (T*)malloc(sizeof(T));
			values = (G*)malloc(sizeof(G));

			length = 1;
			keys[length - 1] = key;
			values[length - 1] = value;
			isCreated = true;
			return true;
		}

		if (keyExists(key))
		{
			return false;
		}

		T* bufT = (T*)malloc(length * sizeof(T));
		G* bufG = (G*)malloc(length * sizeof(G));
		copy(keys, bufT, length);
		copy(values, bufG, length);
		free(keys);
		free(values);

		length++;
		keys = (T*)malloc(length * sizeof(T));
		values = (G*)malloc(length * sizeof(G));
		copy(bufT, keys, length);
		copy(bufG, values, length);
		keys[length - 1] = key;
		values[length - 1] = value;
		return true;
	}

	int add(Map<T, G> map)
	{
		int countOfSuccessfulAdded = 0;

		for (int i = 0; i < map.length; i++)
		{
			if (add(map.keys[i], map.values[i]))
			{
				countOfSuccessfulAdded++;
			}
		}

		return countOfSuccessfulAdded;
	}

	bool keyExists(T key)
	{
		for (int i = 0; i < length; i++)
		{
			if (keys[i] == key)
			{
				return true;
			}
		}

		return false;
	}

	int findKey(T key)
	{
		for (int i = 0; i < length; i++)
		{
			if (keys[i] == key)
			{
				return i;
			}
		}

		return -1;
	}

	bool valueExists(G value)
	{
		for (int i = 0; i < length; i++)
		{
			if (values[i] == value)
			{
				return true;
			}
		}
	}

	T findValue(G value)
	{
		for (int i = 0; i < length; i++)
		{
			if (values[i] == value)
			{
				return keys[i];
			}
		}

		T t = {};
		return t;
	}

	G get(T key)
	{
		if (keyExists(key))
		{
			return values[findKey(key)];
		}
		else
		{
			G g = {};
			return g;
		}
	}

	void print(const char separationChars[])
	{
		for (int i = 0; i < length; i++)
		{
			if (i == length - 1)
			{
				std::cout << keys[i] << ":" << values[i];
			}
			else
			{
				std::cout << keys[i] << ":" << values[i] << separationChars;
			}
		}
		printf("\n");
	}

	void print()
	{
		print("\t");
	}

	void del(T key)
	{
		if (keyExists(key))
		{
			for (int i = findKey(key); i < length - 1; i++) {
				keys[i] = keys[i + 1];
				values[i] = values[i + 1];
			}
			length--;
		}
	}

	void del(T* key, int amount)
	{
		for (int i = 0; i < amount; i++)
		{
			del(key[i]);
		}
	}

	void clear()
	{
		free(keys);
		free(values);
		length = 0;
	}
};

template <typename T>
Array<int> findAll(T* array, int length, T a)
{
	Array<int> pos;

	for (int i = 0; i < length; i++)
	{
		if (array[i] == a)
		{
			pos.add(i);
		}
	}

	return pos;
}