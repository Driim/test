# Yandex Test

## Сборка

cmake .
make

## Использование

./ya-test -e in.txt out.bin - кодирование
./ya-test -d in.bin out.txt - декодирование

Мне не хотелось добовлять зависимостей, по-этому я сделал небольшой набор юнит тестов на assert,
который можно запустить так:
./unit-test 

## Теоретическая оценка

Максимальное число помещающиеся в uint32_t равно 4,294,967,295. Предполагаем что вероятность выпадения любого числа одинаковая,
тогда, если взять медиану этого числового ряда(2,147,483,647) получится что средняя длина(в символах utf-8) текстовой записи числа
будет 10 символам(читай байтам) плюс 1 символ завершения строки(итого 11). При этом эти же числа записанные в бинарном виде будут всегда
занимать 4 байта. Получается что степень сжатия в среднем будет равна ((11 - 4) / 11) * 100 % = ~64%
