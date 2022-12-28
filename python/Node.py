#Austin Frenchmoses
#Basic Node implementation

class Node:
	def __init__(self, newData=None):
		self.__data = newData
		self.__next = None

	def getData(self):
		return self.__data

	def setData(self, newData):
		self.__data = newData

	def getNext(self):
		return self.__next

	def setNext(self, newNext):
		self.__next = newNext

	def hasNext(self):
		if(self.__next == None): 
			return False
		return True

	#Overloaded operators
	#<<
	def __str__(self):
		return (f'{self.__data}')
	#==
	def __eq__(self, other):
		return self.__data == other
	#!=
	def __ne__(self, other):
		return self.__data != other
	#>
	def __gt__(self, other):
		return self.__data > other
	#>=
	def __ge__(self, other):
		return self.__data >= other
	#<
	def __lt__(self, other):
		return self.__data < other
	#<=
	def __le__(self, other):
		return self.__data <= other


