void main(List<String> args) {
  print('Hello Dart');
  print(1 ~/ 2);
  var quoet = 'if you can\'t'
      ' explain it simply\n'
      "you don't understand it well enough.";
  print(quoet);
  var rawString = r"I'll\nback";
  print(rawString);

  String myFunc([String? title]) {
    return "${title == null ? "" : "$title "}";
  }
}
