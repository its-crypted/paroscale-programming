import sqlite3
import os
import sys

class db:
	raise_amt = 1.04
	def __init__(self, first, last, pay):
		self.first = first
		self.last = last
		self.pay = pay
		self.email = first + '.' + last + '@comp.com'
	
	def fullname(self):
		return '{} {}'.format(self.first, self.last)

	def apply_raise(self):
		self.pay = int(self.pay * self.raise_amt)

emp1 = db('jane', 'matrix', 293400)
emp2 = db('mary', 'sharp', 50000)

print(emp1.__dict__)

#print(db.raise_amt)
#print(emp1.raise_amt)
#print(emp2.raise_amt)

