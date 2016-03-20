# Operator overloading
C++ ни дава възможността да променяме поведението на операторите за дефинираните от нас класове.

## Аритметични оператори
Ще дадем пример за събиране (останалите се правят аналогично):

```c++
class vector2d {
public:
	vector2d(int x, int y);
	int GetX();
	int GetY();
	void SetX();
	void SetY();
	friend vector2d operator+ (const vector2d &a, const vector2d &b);
	friend ostream& operator<<(ostream &out, vector2d &v);
	friend istream& operator>>(ostream &out, vector2d &v);
	vector2d& operator++();
	vector2d operator++(int);
private:
	int m_x, m_y;
};

...

vector2d operator+ (const vector2d &a, const vector2d &b) {
	return vector2d(a.m_x + b.m_x, a.m_y + b.m_y);
	/*return {
		a.m_x + b.m_x,
		a.m_y + b.m_y
	}*/
}

```

## Increment/Decrement
Това са съответно префиксните и постфиксните оператори: ++ и --. Математически не е дефинирано какво би трябвало да прави ++ за вектор, но за примера ще приемем, че увеличава с 1 всеки атрибут.
```c++
//prefix
vector2d& vector2d::operator++() {
	m_x++;
	m_y++;
	return *this;
}
//postfix
vector2d vector2d::operator++(int) {
	vector2d temp = *this;
	m_x++;
	m_y++;
	return temp;
}
```

## Output/Input
Можем да предефинираме операторите на потоците за вход и изход >> и <<.
```c++
ostream& operator<< (ostream &out, vector2d &v) {
	out<<"("<<v.m_x<<" "<<v.m_y<<")";
	return out;
}
istream& operator<< (istream &in, vector2d &v) {
	in>>v.m_x>>v.m_y;
	return in;
}
```
##Subscript
Можем да предефинираме оператора [].
```c++
class arr{
public:
	int& operator[] (int index);
private:
	int m_arr[10];
};

...

int& arr::operator[] (int index) {
	if(i >= 0 && i <= 9) {
		return m_arr[index]
	} else {
		//thorw some kind of exception
	}
}

```
Важно е да се отбележи, че [][] не е оператор, а са две последователни извиквания на оператора [] върху различни обекти. Това прави предефинирането на оператора за многомерни матрици доста неудобен.

##Parenthesis call operator
Оператора () може да приема колкото и да е на брой параметри. Това го прави изключително удобен за доста работи, примерно достъп до елементите на матрица:
```c++
class matrix{
public:
	int& operator() (int indexR, int indexC);
private:
	int m_matrix[10][10];
};

...

int& arr::operator() (int indexR, int indexC) {
	return m_matrix[indexR][indexC]
}

```

## Задача
Реализирайте клас Matrix, с основните действия, които могат да се извършват с матрици: събиране, изваждане, умножение на две матрици или на матрица с число. Нека има оператор за достъп веднъж с (), и за упражнение с [][]. Представете матрицата с int**.

*Помислете как се намира детерминанта.
