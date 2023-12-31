/*    Методические указания по теме 1.    */

"Идентификаторы" - названия переменных, функций, меток...
Они состоят из лат букв, цифр, _, начинаются не с цифры, не совпадают с зарезервированными словами, строчные и прописные буквы различаются
Стандартные идентификаторы - разработчик, пользователя - программист

/* комментарии */

#include <stdio.h> //подключение заголовочного файла директивой препроцессора include
main() //с нее начинают выполняться программа
int main(void) - то же самое, void - отсутствие значения
{
	//something
	return 0;
}

printf("hello, world\n")


//Типы данных
char - символьный - 1 байт, содержащий 1 символ
int - целочисленный
float - вещественный с плавающей точкой
double - вещественный двойной точности с плавающей точкой
//Модификаторы, применяющиеся к базовым типам:
short - к целым
long - к целым и double
signed - к char и любому целочисленному
unsigned - к char и любому целочисленному
//int имеет длину не менее 2 байт

//Константы типа:
long: 1234456789L //long double?
double: 123.4, 1e-2, 5.6e+2
float: F или f на конце
символ: 'w' - целое, равное коду данного символа
управляющая последовательность: \n - конец строки, \t - горизонтальная табуляция, '\0' - символ с нулевым кодом
строка (литерал): "This is string." ""
//в конец строки добавляется символ '\0' - конец строки
//'w' - числовой код буквы, "w" - массив, содержащий один символ и нуль '\0'

//Символические константы - константам можно давать значащие имена с использованием механизма макроопределения (макроса)
#define СимволическоеИмя ТекстДляПодстановки
Каждый раз, когда в программе встретится СимволическоеИмя, оно будет заменено на ТекстДляПодстановки (например, пи)
Символические имена принято составлять из прописных букв.

//Обьявление и инициализация (присвоение значения) переменных
char c;
int a = 10, b, sum;
float radius, x, y = 12.345;
short int i;
long double x1, y1;
unsigned long int a1, b1;
long int n = MAXN+1; //константные выражения


//Операции, выражения, операторы
Одноместные (унарные): плюс +, минус - (например, -а)
Двуместные (бинарные): сложение +, вычитание -, умножение *, деление / (для целочисленных - частное от целочисленного деления, остаток от целочисленного деления % (неприменим к вещественным)


//Порядок вычисления выражения определяется приоритетом и порядком ассоциирования (выполнения) операций
() асс.  ->  приоритет высокий
+ - унарные <- 
* / % ->
+ - бинарные ->  приоритет низкий
Пример: а * (7 - а) / 3 + -b
          3    1    4   5  2
          
#define Преобразования типов
При одновременном использовании знаковых signed и беззнаковых unsigned операндов есть вероятность получения некорректных результатов
Одноместная (унарная) операция приведения типов: (ИмяТипа) выражение. Не изменяет исходную переменную.
(double) a/3 = 0.6667: int a=2 (а не 0)
float -> int отбрасывается дробная часть
double -> float значение числа усекается либо округляется

//Операция присваивания: ИмяПеременной = Выражение, <-, самый низкий приоритет
a = b = c = x*y:   4 3 2 1

//Операторы - выражения вида x=0, printf(...), если после них стоит точка с запятой
Оператор присваивания: ИмяПеременной = выражение;
Несколько операторов можно объедиить в блок с помощью составного оператора (блока), заключив их между фигурными скобками. За составным оператором ; не ставится!

//Основые средства ввода-вывода
printf, scanf работают со стандартными потоками вывода и ввода

//printf
int x=45; float y=1.234;
printf("Angle=%d deg. Length=%f m.\n", x, y);
Angle=45 deg. Length=1.234000 m.
% - место, куда будет поставлен следующий аргумент функции и форма, в которой этот аргумент будет выведен (спецификаторы формата)
%с - символ
%d - десятичное целое со знаком
%e - эксп представление числа (мантисса + порядок)
%E - эксп представление числа (мантисса + порядок)
%f - десятичное вещественное с плавающей точкой
%o - восьмеричное без знака
%s - символьная строка
%u - десятичное целое без знака
%x - шестнадцатиричное без знака (строчные буквы)
%X - шестнадцатиричное без знака (прописные буквы)
%% - знак процента
Между % и буквой спецификатора можно поставить модификатор, из примера выше:
%5d =    45 (в 5 позиций, впереди три пробела)
%05d = 00045 (в 5 позиций, впереди три нуля)
%-5d = 45   (по левому краю в 5 позиций, позади три пробела)

%ld или %lf - для long int или double
%hd - для short int

//scanf()
 scanf("%d %f", &x, &y);
& - операция получения адреса переменной, перед каждой переменной в списке параметров этой функции
Спецификаторы практически такие же, как и у printf
%.3f - с 3 цифрами после запятой
%6.2f - в 6 позиций с 2 цифрами после запятой


//Операции логических выражений
Операции отношения: == != > < >= <=
Логические операции: ! - not, && - and, || - or

()          ->  высокий
!           <-
< <= > >=   ->
== !=       ->
&&          ->
||          ->  низкий

1 = истина, 0 = ложь
Вычисление выражения, содержащего && и ||, выполняется слева направо и прекращается, как только установлено гарантированное значение результата

//Составной оператор (блок операторов) - группа из произвольного числа операторов, которая ограничена операторными скобками {}, за ним ; не ставится

if (a != 0) == if (a)

if (Выражение) {
 ОператорИст1
 ОператорИст2
 ...
 ОператорИстN
 }
 else {
 ОператорЛож1
 ОператорЛож2
 ...
 ОператорЛожM
 }
 
 //Тернарная операция условия
 ВыражУсл ? ВыражИст : ВыражЛож
 if (a > b)
 c = a;
else
 c = b;
 ==> с = (a > b) ? a : b ; /* c = max(a,b) */
приоритет самый низкий, но выше, чем у присваивания, <-

Вложенные операторы: если внутри нет else, то обязательно надо ее в блок
else if

//Оператор множественного выбора
 switch (Выражение) {
 case КонстантВыраж1: Операторы1
 case КонстантВыраж2: Операторы2
 ...
 case КонстантВыражN: ОператорыN
 default: ОператорыИначе
 }
Выражение == КонстантВыражХ => выполн ОператорыХ
Если нет, то ОператорыИначе
Если хотим выполнить только одно действие, то break;

Пример:
#include <stdio.h>
int main(void) {
 int k;
 char flex;
 printf("Введите количество деталей:");
 scanf("%d", &k);
 switch ( (k<=20) ? k : k%10 ) {
 case 1:
 flex = 'а';
 break;
 case 2:
 case 3:
 case 4:
 flex = 'и';
 break;
 default:
 flex = ' ';
 break;
 }
 printf("Количество деталей: %d штук%c\n", k, flex);
 return 0;
}

Если убрать первый break, то flex = 'a' -> flex = 'и' -> break
Такого сквозного выполнения стоит избегать
Стоит ставить break в конце последнего блока, это хороший стиль

//Русский язык и локализация
#include <stdio.h>
#include <locale.h> //подключение стандартной библиотеки
int main(void) {
 setlocale(LC_ALL,""); //вроде нужна, изменяет кодировку и правила форматирования чисел, но и без нее работает
 ......
 return 0;
}









