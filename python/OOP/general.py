# class - sample - data type
class color:
    pass # use if class doesn't have any attributes or methods

class Phone:
    # attributes
    seqNum = 0
    globalSeqNum = 1
    color = ''

    # constructor
    def __init__(you, trademark, color): # special method __init__
        you.trademark = trademark 
        you.color = color
        you.seqNum = Phone.globalSeqNum # add sequence number for each object
        Phone.globalSeqNum += 1 # should not use this
        
    # method
    # invoke method ~ call function
    # class method
    @classmethod # interact with class
    def fromString(cls, s):
        words = s.split('-')
        words = [word.strip() for word in words]
        trademark, color = words
        return cls(trademark, color)
    # static method
    @staticmethod # don't interact with anything
    def sayHello():
        print('Hello World!')
    # regular method (interact with the object's attributes)
    def getName(self): 
        return 'My name is ' + self.name
    # special method
    def __str__(self) -> str:
        return 'this {} phone {} brand is {}'.format(self.color, self.trademark, self.name)
    def __repr__(self) -> str:
        return 'trademark: {}\nname: {}\ncolor: {}'.format(self.trademark, self.name, self.color)
    # len() ~ __len__, + ~ __add__, ...

phone1 = Phone('Samsung', 'Black')
phone1.name = 'A50' # in python, we can add properties outside the class by direct assignment
print(Phone.getName(phone1)) # class.method(object)

phone2 = Phone('Xiaomi', 'Violet')
phone2.name = 'Readme Note 7'

phone3 = Phone.fromString('iPhone - White')
phone3.name = 'iphone 13'

print(phone1.seqNum)
print(phone2.seqNum)
print(phone3.color)




