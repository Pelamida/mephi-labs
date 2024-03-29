Прямые методы сортировки:
- метод вставки (включения) – Insertion sort;
- метод выбора (выделения) – Selection sort;
- метод обмена (“пузырьковая” сортировка) – Bubble sort.
n элементов в массиве - n-1 проход

//Метод вставки
Определяем, где в упорядоченной части должен находиться текущий элемент, и вставляем его туда
1. взятие i-го элемента из неотсорт. части
2. поиск позиции j в отсорт. части
3. сдвиг элементов массива от (i-1) до j вправо
4. вставка сохр. элемента на позицию j
  Улучшается парой итераций бинпоиска

//Метод выбора
Ищем наименьший элемент и меняем его местами с первым элементом неупорядоченной части
  При наличии повторяющихся элементов улучшается подсчетом количества минимальных

//Метод обмена
Сравниваются два соседних элемента и меняются местами, если они расположены не по порядку
  Улучшается поочередной сменой направления просмотра слева направо и справо налево
