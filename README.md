# stack-sort
### Задача на понимание алгоритмов + визуализация сортировки стека.<br/>
#### Данный проект был реализован в рамках обучения в Школе 21. Цель данного проекта: написать программу сортировки стека целых чисел.<br/>
В качестве усложнения проекта - использовать технологию доступа к данным стека - работать можем только с первым элементом массива. Для сортировки разрешаеться создать ещё один стек "b", что бы временно "сбрасывать" в него элементы стека "a".<br/>
### Требуется написать 11 функций:<br/>
* sa : поменять местами в стеке "a" - первые 2 элемента между собой.<br/>
* sb : поменять местами в стеке "b" - первые 2 элемента между собой.<br/>
* ss : выполнить sa и sb одновременно.<br/>
* pa : положить первый элемент стека "a" в стек "b".<br/>
* pb : положить первый элемент стека "b" в стек "a".<br/>
* ra : выполнить циклический сдвиг стека "a" влево (первый элемент станет последним).<br/>
* rb : выполнить циклический сдвиг стека "b" влево (первый элемент станет последним).<br/>
* rr : выполнить одновременно ra и rb.<br/>
* rra : выполнить обратный циклический сдвиг стека "a" влево (последний элемент станет первым).<br/>
* rrb : выполнить обратный циклический сдвиг стека "b" влево (последний элемент станет первым).<br/>
* rrr : выполнить одновременно rra и rrb.<br/><br/>

Используя только данные функции необходимо разработать эффективный алгоритм сортировки. В качестве оценки были установлены следующие критерии:<br/>
- для 3-х элементов - не более 3-х действий;<br/>
- для 5-ти элементов - не более 12-ти действий;<br/>
- для 100 элементов - не более 700 действий;<br/>
- для 500 элементов - не более 5500 действий;<br/>

Для доступа, скажем к 5-му элементу - нужно выполнить циклический сдвиг 4 раза.<br/>
Мною был разработан следующий алгоритм:
1.  Находим в стеке "а" максимальную восходящую последовательность (не менее 5 элементов) и циклически смещаем её в конец стека (если таковой последовательности нет, то игнорируем этот шаг)
2.  Сбрасываем все элементы в стек "b", кроме восходящей последовательности (если она не была найдена, то оставляем в стеке "a" последние 5 элементов)
3.  Если в стеке "а" 5 не отсортированные элементы - то сортируем их.
4.  В стеке "b" для каждого элемента рассчитываем - за сколько действий его можно вернуть в стек "а". Учитываем, что для вставки элементов нам нужно будет вращать оба стека. Учитываем, в какую сторону эффективно крутить стек (что-бы нужный элемент встал на 1 место и мы могли его переместить в другой стек). Учитываем, что нам "выгодно" использовать попутное вращение стеков, т.к. это уменьшит общее количество действий для сортировки.
5.  Выбираем элемент с минимальным количеством действий для вставки (если таких несколько - то выбираем первый минимальный) и производим этот набор действий.
6.  Если в стеке "b" есть ещё элементы - возвращаемся к шагу 4.

Используя этот алгоритм я смог уложиться в установленные рамки по количеству действий для каждого случая.<br/>
В качестве дополнительного "бонуса" требовалось написать визуализацию процесса сортировки.<br/>
Для визуализации мною была использована графическая библиотека mlx. Для наглядности в визуализации длинна черты пропорциональная значению числа. Также в примере нет повторяющихся чисел в неотсортированном стеке. Слева стек "a", справа стек "b".<br/> Ссылка на видео: https://youtu.be/kObkftibjaI<br/>
![Скриншот сортировки из видео:](https://github.com/AlexArhipov/stack-sort/blob/main/Screen%20Shot%202021-06-11%20at%2012.05.06%20AM.png)
