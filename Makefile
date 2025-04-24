# Anna Beatryz Costa - 2025007883
# Makefile para compilar o projeto de benchmarking com suporte a UTF-8

# Compilador e flags
CC = gcc
CFLAGS = -Wall -O2 -finput-charset=UTF-8

# Arquivos fonte
SRC = main_benchmark_detalhado.c counting_sort.c insertion_sort.c quick_sort.c ES.c
OBJ = $(SRC:.c=.o)

# Nome do executável
EXEC = benchmark_Makefile

# Regra principal
all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Limpeza
clean:
	rm -f *.o $(EXEC)

# Rodar programa
run: all
	./$(EXEC)
