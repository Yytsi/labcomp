import random
import os

def generate_random_test_file(filename, num_operations, max_value):
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

def generate_add_only_test_file(filename, num_operations, max_value):
    with open(filename, 'w') as file:
        operations = ['a ' + str(random.randint(1, max_value+1)) for _ in range(num_operations)]
        file.write(f'{len(operations)}\n')
        file.write('\n'.join(operations))

def generate_add_and_get_test_file(filename, initial_adds, num_operations, max_value):
    with open(filename, 'w') as file:
        operations = ['a ' + str(random.randint(1, max_value+1)) for _ in range(initial_adds)]
        operations += ['g' for _ in range(num_operations)]
        file.write(f'{len(operations)}\n')
        file.write('\n'.join(operations))

def generate_add_and_remove_test_file(filename, num_operations, max_value, max_heap_size):
    with open(filename, 'w') as file:
        heap_size = 0
        operations = []
        for _ in range(num_operations):
            if heap_size == 0:  # Prevent removal from an empty heap
                operation = 'a'
            elif heap_size == max_heap_size:  # Prevent adding beyond max heap size
                operation = 'p'
            else:
                operation = random.choice(['a', 'p'])

            if operation == 'a':
                value = random.randint(1, max_value+1)
                operations.append(f'a {value}')
                heap_size += 1
            elif operation == 'p':
                operations.append('p')
                heap_size -= 1

        file.write(f'{len(operations)}\n')
        file.write('\n'.join(operations))


print("Valitse testitiedoston tyyppi:")
print("1. Satunnaiset operaatiot (lisää, poista, hae)")
print("2. Vain lisäysoperaatiot")
print("3. Lisäys- ja hakuoperaatiot")
print("4. Lisäys- ja poisto-operaatiot")

test_file_type = int(input("Anna testitiedoston tyyppi (1-4): "))
filename = input("Anna testitiedoston nimi (esim. big_test.txt): ")
num_operations = int(input("Anna operaatioiden määrä testitiedostossa: "))
max_value = int(input("Anna suurin arvo, joka voidaan lisätä kekoon: "))

if test_file_type == 1:
    generate_random_test_file(filename, num_operations, max_value)
elif test_file_type == 2:
    generate_add_only_test_file(filename, num_operations, max_value)
elif test_file_type == 3:
    initial_adds = int(input("Anna alustavien lisäysoperaatioiden määrä: "))
    generate_add_and_get_test_file(filename, initial_adds, num_operations, max_value)
elif test_file_type == 4:
    max_heap_size = int(input("Anna keon maksimikoko: "))
    generate_add_and_remove_test_file(filename, num_operations, max_value, max_heap_size)
else:
    print("Virheellinen syöte. Anna numero väliltä 1-4.")