def coutingSort(array):
    if array:
        maior = array[0]
        menor = array[0]

        for e in array:
            if e > maior:
                maior = e
            if e < menor:
                menor = e

        contagem = [0] * (maior - menor + 1)

        # Defining the array of count array

        for e in array:
            contagem[e - menor] += 1

        # Computing the sum of value

        for i in range(1, len(contagem)):
            contagem[i] += contagem[i - 1]

        # Aplicate the magical sort

        saida = [0] * len(array)

        for i in range(len(array) - 1 ,- 1, -1):
            element = array[i]
            cont =  contagem[element - menor]
            saida[cont - 1] = element
            cont -= 1

        for i in range(len(saida)):
            array[i] = saida[i]

        return saida


l = [44, 43, 21, 4, 62, 29, 60, 11, 40, 51]

a = coutingSort(l)
print(a)