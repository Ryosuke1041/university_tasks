from pack1.module1 import func1
from pack1.module2 import func2
# 同じpack1内のファイルなので、上の2行は以下のようにも記述できる
# from .module1 import func1
# from .module2 import func2
# また各モジュール内の全ての関数をimportする場合はワイルドカードを使うことも可能
# from .module1 import *
# from .module2 import *