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

    def bark(self):            # オーバーライド
        print(f'{self.name}:きゃんきゃん (オーバーライド)')
        super().bark()         # 親クラスのbark()を呼ぶ場合

c = GuideDog('タロ') 
c.bark()                       # オーバーライドされたbark関数の呼び出し