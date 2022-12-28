#Austin Frenchmoses
#AVL Tree Implementation

from bstNode import bstNode

class AVL:
	def __init__(self):
		self.__root = None

	def push(self, *args):
		for src in args:
			self.__root = self.__push(self.__root, src)
		return True

	def __push(self, root, src):
		if(root == None): root = bstNode(src)
		elif(src >= root): root.setRight(self.__push(root.getRight(), src))
		else: root.setLeft(self.__push(root.getLeft(), src))
		return self.__reBalance(root)

	def pop(self, remove):
		root = self.retrieve(remove)
		if(root == False): return False
		self.__root = self.__pop(self.__root, remove)
		return True

	def __pop(self, root, remove): 
		if(root == None): return root
		elif(root == remove): root = self.getSuccessor(root)
		elif(remove >= root): root.setRight(self.__pop(root.getRight(), remove))
		else: root.setLeft(self.__pop(root.getLeft(), remove))
		return self.__reBalance(root)

	def retrieve(self, find):
		if(self.__root == None): return False
		return self.__retrieve(self.__root, find)

	def __retrieve(self, root, find):
		if(root == None): return False
		elif(root == find): return root
		elif(find >= root): return self.__retrieve(root.getRight(), find)
		else: return self.__retrieve(root.getLeft(), find)

	def getSuccessor(self,root):
		if(root.isLeaf()): root = None
		elif(root.getLeft() == None): root = root.getRight()
		elif(root.getRight() == None): root = root.getLeft()
		else: root.setRight(self.__getSuccessor(root, root.getRight()))
		return root
		
	def __getSuccessor(self,root, IoS):
		if(IoS.getLeft() == None):
			root.setData(IoS.getData())
			return IoS.getRight()
		else: IoS.setLeft(self.__getSuccessor(root, IoS.getLeft()))
		return IoS

	def height(self):
		return self.__height(self.__root)

	def __height(self, root):
		h = -1
		if(root):
			left = self.__height(root.getLeft())
			right = self.__height(root.getRight())
			maxHeight = max(left, right)
			h = maxHeight + 1
		return h;

	def count(self): 
		if(self.__root == None): return 0
		return self.__count(self.__root)

	def __count(self, root): 
		if(root == None): return 0
		left = self.__count(root.getLeft())
		right = self.__count(root.getRight()) 
		return left + right + 1

	def printLevels(self):
		if(self.__root == None): 
			print("List is empty")
			return 0
		levels = self.height()
		for i in range(levels):
			print(f'Level {i}: ', end=None)
			self.__printLevels(self.__root, i)
			print()
		return 1

	def __printLevels(self, root, lvl):
		if(root == None): return
		if(lvl == 0): print(root,end=" ")
		elif(lvl > 0):
			self.__printLevels(root.getLeft(), lvl -1)
			self.__printLevels(root.getRight(), lvl -1)

	def __reBalance(self, root): 
		if(root == None): return root
		bf = self.__balanceFactor(root)
		bfLeft = self.__balanceFactor(root.getLeft())
		bfRight = self.__balanceFactor(root.getRight())
		if(bf > 1):
			if(bfLeft > 0): root = self.__leftRotate(root)
			else: root = self.__leftRightRotate(root)
		elif(bf < -1):
			if(bfRight > 0): root = self.__rightLeftRotate(root)
			else: root = self.__rightRotate(root)
		return root

	def __balanceFactor(self, root):
		if(root == None): return 0
		left = self.__height(root.getLeft())
		right = self.__height(root.getRight())
		return left - right

	def __leftRotate(self, root): 
		temp = root.getLeft()
		root.setLeft(temp.getRight())
		temp.setRight(root)
		return temp

	def __rightRotate(self, root):
		temp = root.getRight()
		root.setRight(temp.getLeft())
		temp.setLeft(root)
		return temp

	def __leftRightRotate(self, root):
		temp = root.getLeft()
		root.setLeft(self.__rightRotate(temp))
		return self.__leftRotate(root)

	def __rightLeftRotate(self, root):
		temp = root.getRight()
		root.setRight(self.__leftRotate(temp))
		return self.__rightRotate(root)

	#Overloaded operators
	#<<
	def __str__(self):
		if(self.__root == None): return (f'List is empty')
		return self.__display(self.__root)

	#Recursive display
	def __display(self, root):
		if(root == None): return ('')
		self.__display(root.getLeft())
		print(root,end=None)
		return self.__display(root.getRight())

		
