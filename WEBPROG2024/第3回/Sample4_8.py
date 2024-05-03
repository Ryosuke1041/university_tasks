class Dog:
    def __init__(self, name):
        self.name = name

    def bark(self):   # メソッドの定義 
        print(f'{self.name}: わんわん')

class GuideDog(Dog):
    def stopAtCurb(self):
        print(f'{self.name}: 歩道の端で止まります')

    def avoidObstacle(self):
        print(f'{self.name}: 障害物をよけます')

a = Dog('シロ')      # Dogクラスのインスタンス その1
a.bark()             

b = Dog('ポチ')      # Dogクラスのインスタンス その2
b.bark()

c = GuideDog('タロ') # GuideDogクラスのインスタンス
c.bark()             # Dogクラスの bark()メソッドが使える
c.stopAtCurb()       # GuideDogクラス独自のメソッド