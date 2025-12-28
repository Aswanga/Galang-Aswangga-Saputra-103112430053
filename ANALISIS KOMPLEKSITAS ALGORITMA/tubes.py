import time
import matplotlib.pyplot as plt
from prettytable import PrettyTable

def factorial_recursive(n):
    if n == 0 or n == 1:
        return 1
    return n * factorial_recursive(n - 1)

def factorial_iterative(n):
    result = 1
    for i in range(1, n + 1):
        result *= i
    return result

n_values = []
recursive_times = []
iterative_times = []

def update_graph():
    plt.figure(figsize=(8, 6))
    plt.plot(n_values, recursive_times, marker='o', label='Recursive')
    plt.plot(n_values, iterative_times, marker='o', label='Iterative')
    plt.title('Perbandingan Waktu Eksekusi Faktorial')
    plt.xlabel('Nilai Input (n)')
    plt.ylabel('Waktu Eksekusi (detik)')
    plt.legend()
    plt.grid(True)
    plt.show()

def print_execution_table():
    table = PrettyTable()
    table.field_names = ["n", "Recursive Time (s)", "Iterative Time (s)"]
    for i in range(len(n_values)):
        table.add_row([n_values[i], recursive_times[i], iterative_times[i]])
    print(table)

while True:
    try:
        n = int(input("Masukkan nilai n (atau -1 untuk keluar): "))

        if n == -1:
            print("Program selesai. Terima kasih!")
            break

        if n < 0:
            print("Masukkan nilai n positif!")
            continue

        n_values.append(n)

        start_time = time.time()
        factorial_recursive(n)
        recursive_times.append(time.time() - start_time)

        start_time = time.time()
        factorial_iterative(n)
        iterative_times.append(time.time() - start_time)

        print_execution_table()
        update_graph()

    except ValueError:
        print("Input tidak valid!")