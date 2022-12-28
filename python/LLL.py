#Austin Frenchmoses
#Linked List Implemenation

from Node import Node

class LLL:
	def __init__(self):
		self.__head = None

	def pushFront(self, *args):
		for src in args:
			temp = self.__head
			self.__head = Node(src)
			self.__head.setNext(temp)
		return True

	def pushBack(self, *args): 
		for src in args:
			self.__head = self.__pushBack(self.__head,src)
		return True

	def __pushBack(self, head, src): 
		if(head == None): head = Node(src)
		else: head.setNext(self.__pushBack(head.getNext(),src))
		return head

	def popFront(self):
		if(self.__head == None): return False
		self.__head = self.__head.getNext()
		return True

	def popBack(self): 
		if(self.__head == None): return False
		self.__head = self.__popBack(self.__head)
		return True

	def __popBack(self, head): 
		if(not head.hasNext()): head = None
		else: head.setNext(self.__popBack(head.getNext()))
		return head

	def pop(self, find): 
		head = self.retrieve(find)
		if(head == False): return False
		self.__head = self.__pop(self.__head, find)
		return True

	def __pop(self, head, find): 
		if(self.__head == None): return False
		elif(head == find): head = head.getNext()
		else: head.setNext(self.__pop(head.getNext(),find))
		return head

	def retrieve(self, find):
		if(self.__head == None): return False
		return self.__retrieve(self.__head, find)

	def __retrieve(self, head, find):
		if(head == None): return False
		elif(head == find): return head
		else: return self.__retrieve(head.getNext(), find)

	#Overloaded operators
	#<<
	def __str__(self):
		if(self.__head == None): return (f'List is empty')
		return self.__display(self.__head)

	#Recursive display
	def __display(self, head):
		if(head == None): return ''
		print(head,end='')
		return self.__display(head.getNext())

		
