#pragma once

using Number = double; // Определяем тип Number как double

// Возвращает true, если удалось прочитать число
// и сохранить его в Number.
bool ReadNumber(Number& result);

// Возвращает true, если работа завершилась штатно 
// командой q. Если из-за ошибки, возвращает false.
bool RunCalculatorCycle();