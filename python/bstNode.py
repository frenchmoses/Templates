#Austin Frenchmoses
#BST Node Implementation

class bstNode:
	def __init__(self, newData=None):
		self.__data = newData
		self.__left = None
		self.__right = None

	def getData(self):
		return self.__data

	def setData(self, newData):
		self.__data = newData

	def getLeft(self):
		return self.__left

	def getRight(self):
		return self.__right

	def setLeft(self, newLeft):
		self.__left = newLeft

	def setRight(self, newRight):
		self.__right = newRight

	def isLeaf(self):
		if(self.__left == None):
			if(self.__right == None):
				return True
		return False

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

