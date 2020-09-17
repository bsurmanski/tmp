class LList:
    class Node:
        def __init__(self, v):
            self.value = v
            self.next = None

    def __init__(self):
        self.first = None
        self.last = None

    def append(self, v):
        n = LList.Node(v)
        if self.last != None:
            self.last.next = n
            self.last = n
        else: # the list is empty
            self.first = n
            self.last = n
        
    def remove(self, index):
        before = None
        n = self.first

        for i in range(index):
            before = n
            n = n.next
        
        if self.first == n:
            self.first = n.next

        if self.last == n:
            self.last = before

        if before != None:
            before.next = n.next

    def get(self, index):
        n = self.first

        for i in range(index):
            n = n.next

        return n.value

    def __getitem__(self, index):
        return self.get(index)

    def len(self):
        l = 0
        n = self.first

        while n != None:
            l += 1
            n = n.next

        return l


def main():
    lst = LList()
    lst.append(1)
    lst.append(2)
    lst.append(5)
    lst.append(10)
    lst.remove(1)
    lst.append(15)

    for i in range(lst.len()):
        print(lst[i])

if __name__ == '__main__':
    main()
