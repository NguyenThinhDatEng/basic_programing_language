import 'dart:io';

void main(List<String> args) {
  stdout.write('Format: yyyy-mm-dd: ');
  DateTime date = DateTime.parse(stdin.readLineSync()!);
  int month = date.month;
  int weekDay = date.weekday;
  switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      {
        print('Tháng ${month} có 31 ngày');
        break;
      }
    case 4:
    case 6:
    case 9:
    case 11:
      {
        print('Tháng ${month} có 30 ngày');
        break;
      }
    case 2:
      {
        int year = date.year;
        if (year % 4 == 0 && year % 100 != 0) {
          print('Tháng 2 có 29 ngày');
        } else {
          print('Tháng 2 có 28 ngày');
        }
        break;
      }
  }

  String prefix = 'Hôm nay là thứ ';
  switch (weekDay) {
    case 1:
      {
        print(prefix + 'Hai');
        break;
      }
    case 2:
      {
        print(prefix + 'Ba');
        break;
      }
    case 3:
      {
        print(prefix + 'Tư');
        break;
      }
    case 4:
      {
        print(prefix + 'Năm');
        break;
      }
    case 5:
      {
        print(prefix + 'Sáu');
        break;
      }
    case 6:
      {
        print(prefix + 'Bảy');
        break;
      }
    case 7:
      {
        print(prefix + 'Chủ nhật');
        break;
      }
  }
}
