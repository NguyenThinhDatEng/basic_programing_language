import 'dart:io';

void main(List<String> args) {
  for (int i = 1; i < 11; i++) {
    for (int j = 2; j < 10; j++) {
      stdout.write('$j * $i = ${i * j}\t');
    }
    print('');
  }
}
