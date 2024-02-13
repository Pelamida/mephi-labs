Структуры предназначены для работы с комбинациями данных разных типов. Структура состоит из фикс. числа компонентов одного/нескольких компонентов - полей (элементов, членов). Каждое поле имеет свое имя.
struct МеткаСтруктуры {
ТипПоля1 ИмяПоля1;
ТипПоля2 ИмяПоля2;
...
ТипПоляN ИмяПоляN;
} СписокПеременных;

Структуру можно объявить без метки, но только для переменных, содержащихся в списке переменных.
Не следует объединять переменные с одинаковым типом данных в одну строку для повышения наглядности программы

struct complex {
double Re;
double Im;
} z1, z2;
struct complex z;
либо
struct {double Re; double Im;} z;

Обращение к полям структуры:
ИмяПеремСтрукт.ИмяПоля
z.Re = 12.345;

//	Вложенные структуры
struct cVector {
	struct complex p1;
	struct complex p2;
} v;
v.p1.Re = 1234
В составных именах (квалифицируемые, уточненные идентификаторы) указывается вся цепочка имен от имени переменной-структуры до имени требуемого поля

//	Инициализация структуры
struct complex c = {1.23, 45};
struct cVector v = {
	{1.25, 2.5},
	{4.0, 3.75}
}
struct cVector v = {1.25, 2.5, 4.0, 3.75};
v2 = v

//	Массивы как поля структур
struct cPolygon {
	struct complex p[8];
} poly;
poly.p[4].Re = 123

Пример:
struct tMarks { /* структура оценки */
	int MathAn; /* оценка по Мат.анализу */
	int Inform; /* оценка по Информатике */
};
struct tStudentCard {
	char SurName[20]; /* фамилия */
	char Name[20]; /* имя */
	int BirthYear; /* год рождения */
	struct tMarks Marks; /* оценки */
};
struct tStudentCard stud;
stud.Marks.MathAn = 87;
char s[20] = "Sergy";
for (int i=0; i<20; ++i) stud.Name[i]=s[i]; //массив заполн. поэлементно
либо: puts(stud1.Name);

//	Массив структур
struct tStudentCard group[28];
group[0].BirthYear = 2000;
if (group[10].Marks = group[13].Marks) ...

struct tStudentCard group[2] = {
	{"Ivanov", "Ivan", 2000, {8,9}},
	"Petrov", "Petr", 2001, 7, 10
}

//	Указатели на структуры
struct tStudentCard *pstud;
pstud = &stud;
Имя структуры не является ее адресом.
Указатель на структ-элемент массива: pstud = &group[0];
Обращение к полям стркутуры через указатель на нее:
1) через ->
pstud->SurName <=> group1[0].SurName //== Ivanov
2) через разыменование
(*pstud).SurName

//	Структуры и функции
//1) Передача элементов структуры в функцию
double AverageMark(int MMathAn, int MLinAlg, int MPhys, int MInform) {
	return (MMathAn + MLinAlg + MPhys + MInform) / 4.0; };
printf("Средний балл =%lf\n", AverageMark(group1[0].Marks.MathAn,
	group1[0].Marks.LinAlg,
	group1[0].Marks.Phys,
	group1[0].Marks.Inform));
	
//2) Передача адреса структуры в функцию
double AverageMark(struct tStudentCard *pstud) {
	return (pstud->Marks.MathAn + pstud->Marks.LinAlg +
			pstud->Marks.Phys + pstud->Marks.Inform) / 4.0; };
printf("Средний балл =%lf\n", AverageMark(&group[0]) );

Передача только адреса поля group[0].Marks:
double AverageMark(struct tMarks *pmarks) {
	return (pmarks->MathAn + pmarks->LinAlg +
			pmarks->Phys + pmarks->Inform) / 4.0; };
printf("Средний балл =%lf\n", AverageMark(&group1[0].Marks) );

//3) Передача самой стуркутры в качестве аргумента функции
double AverageMark(struct tStudentCard stud) {
	return (stud.Marks.MathAn + stud.Marks.LinAlg +
		stud.Marks.Phys + stud.Marks.Inform) / 4.0; };
printf("Средний балл =%lf\n", AverageMark(group1[0]) );
