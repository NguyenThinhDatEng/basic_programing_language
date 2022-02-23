'''
Define
    the same function name (but different signatures) being used for different types
Represent
    Overide
'''
# Ex1
print(len('NVT'))
print(len([0, 1, 2, 3, 4]))

# Ex2
class Bird:
  def intro(self):
    print("There are many types of birds.")
     
  def flight(self):
    print("Most of the birds can fly but some cannot.")
   
class sparrow(Bird):
  def flight(self):
    print("Sparrows can fly.")

bird = Bird()
spar = sparrow()

bird.intro()
bird.flight()
spar.intro()
spar.flight()
