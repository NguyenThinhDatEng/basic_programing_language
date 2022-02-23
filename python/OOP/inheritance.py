class Person:
    age = 100
    gender = 'Male'
    def __init__(self, age, gender) -> None:
        self.age = age
        self.gender = gender

class Student(Person):
    # inherit the attributes of Person
    age = 18
    code = '4178'
    def __init__(self, age, gender, code) -> None:
        super().__init__(age, gender) # inherit the constructor of Person
        self.code = code
