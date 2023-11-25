import random
import os

def generate_test_file(filename, num_operations, max_value):
    with open(filename, 'w') as file:
        heap_size = 0
        operations = []

        for _ in range(num_operations):
            if heap_size == 0:
                operation = 'a'  # If the heap is empty, add a value to prevent a runtime error from being raised
            else:
                operation = random.choice(['a', 'p', 'g'])

            if operation == 'a':
                value = random.randint(1, max_value+1)
                operations.append(f'a {value}')
                heap_size += 1
            elif operation == 'p':
                operations.append('p')
                heap_size -= 1
            else:
                operations.append('g')

        file.write(f'{len(operations)}\n')
        file.write('\n'.join(operations))

filename = input("Give a name for the test file (such as big_text.txt): ")
num_operations = int(input("Enter the number of operations for the test file (insert, get min, delete min): "))  # Number of operations in the test (insert, get min, delete min)
max_value = int(input("Enter the max value that is inserted to the heap: ")) # Max value that is inserted to the heap

generate_test_file(filename, num_operations, max_value)