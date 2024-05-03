def taxcalc(price, rate=0.1):        # ここで def taxcalc(rate=0.1, price):  だとエラー
	return price * (1 + rate)
	
print(taxcalc(100.0))
print(taxcalc(100.0,0.08))