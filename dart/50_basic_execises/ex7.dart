import 'dart:io';

void main(List<String> args) {
  int n = int.parse(stdin.readLineSync()!);
  assert(n > 99 && n < 1000, 'Enter a nature number includes 3 numbers');
  List<String> lowerCaseNum = [
    'lẻ',
    'một',
    'hai',
    'ba',
    'bốn',
    'năm',
    'sáu',
    'bảy',
    'tám',
    'chín'
  ];
  List<String> upperCaseNum = [
    '',
    'Một',
    'Hai',
    'Ba',
    'Bốn',
    'Năm',
    'Sáu',
    'Bảy',
    'Tám',
    'Chín'
  ];

  int hundreds = n ~/ 100;
  int tens = n % 100 ~/ 10;
  int units = n % 10;

  if (tens == 1) {
    print('${upperCaseNum[hundreds]} trăm mười ${lowerCaseNum[units]}');
  } else if (tens == 0) {
    if (units != 0)
      print(
          '${upperCaseNum[hundreds]} trăm ${lowerCaseNum[tens]} ${lowerCaseNum[units]}');
    else {
      print('${upperCaseNum[hundreds]} trăm');
    }
  } else {
    print(
        '${upperCaseNum[hundreds]} trăm ${lowerCaseNum[tens]} mươi ${lowerCaseNum[units]}');
  }
}
