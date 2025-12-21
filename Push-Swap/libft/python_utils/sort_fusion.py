class t_list:
    def __init__(self, v,n = None):
        self.value = v
        self.next_v = n
    def change_value(self, new_value):
        tmp = self.value
        self.value = new_value
        return tmp
    def change_next(self, new_next):
        tmp = self.next_v
        self.next_v = new_next
        return tmp
    def render(self):
        print("> {}".format(self.value), end=" ")
        if self.next_v:
            self.next_v.render()

def chain_sort(stack1):
    stack2 = t_list(0)

def main(numbers=[0]):
    i = 0
    stack1 = t_list(numbers[i])
    i += 1
    while i < len(numbers):
        stack1 = t_list(numbers[i], stack1)
        i += 1
    stack1 = chain_sort(stack1)
    stack1.render()
main([1,21564,351,5,546,6,54,63658,56,5,12,5,48642,3])
