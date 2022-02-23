'''
Define
    Users know "what function does" but don't know "How it does"
Purpose
    Hide irrelevant data and class
Meaning
    reduce complexity
    enhances app efficiency 
'''

# abstract base class work 
from abc import ABC, abstractmethod
class Car(ABC):   
    def mileage(self):   
        pass  
  
class Tesla(Car):   
    def mileage(self):   
        print("The mileage is 30kmph")   

t = Tesla()
t.mileage()