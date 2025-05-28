#include "usart.h"

void Usart::TransferData()
{
  temperature = mproviderT.GetData();
  pressure = mproviderP.GetData();
  humidity = mproviderH.GetData();
  dewPoint = mproviderD.GetData();

  // Текстовые константы в CP866
  constexpr auto pressText = "\u0414\u0430\u0432\u043b\u0435\u043d\u0438\u0435: ";         // "Давление: "
  constexpr auto humidityText = "\u0412\u043b\u0430\u0436\u043d\u043e\u0441\u0442\u044c: ";  // "Влажность: "
  constexpr auto temperatureText = "\u0422\u0435\u043c\u043f\u0435\u0440\u0430\u0442\u0443\u0440\u0430: "; // "Температура: "
  constexpr auto dewPointText = "\u0422\u043e\u0447\u043a\u0430 \u0440\u043e\u0441\u044b:";      // "Точка росы: "
  constexpr auto hPaText = "\u0433\u041f\u0430";                               // "гПа"
  constexpr auto newLine = "\r\n";                                       // Возврат каретки + перевод строки

  // Формирование сообщения с переносами строк
  std::string message = 
    pressText + to_string_with_precision(pressure, 2) + " " + hPaText + newLine +
    humidityText + to_string_with_precision(humidity, 2) + " %" + newLine +
    temperatureText + to_string_with_precision(temperature, 2) + " C" + newLine +
    dewPointText + to_string_with_precision(dewPoint, 2) + " C" + newLine;

  // Отправка через USART
  for(uint8_t i = 0; i < message.size(); i++) 
  {  
    while(!USART2::SR::TXE::DataRegisterEmpty::IsSet()) {}
    USART2::DR::Write(static_cast<uint8_t>(message[i]));
  }
}