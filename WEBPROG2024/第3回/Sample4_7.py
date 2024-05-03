class Dog:
    def __init__(self, name):
        self.name = name
  
    def bark(self):   # メソッドの定義 
        print(f'{self.name}: わんわん')

a = Dog('シロ')
a.bark()

b = Dog('ポチ')
b.bark()